#include "star.hpp"
#include <Geode/binding/GameLevelManager.hpp>
#include <Geode/binding/GJSearchObject.hpp>
#include <Geode/binding/GJGameLevel.hpp>
#include <Geode/binding/GJListLayer.hpp>
#include <Geode/binding/CustomListView.hpp>
#include <Geode/binding/LevelManagerDelegate.hpp>
#include <Geode/ui/Notification.hpp>
#include <unordered_set>

using namespace geode::prelude;

namespace {
    // De más larga a más corta (modo Clásico)
    constexpr const char* LENGTHS[] = {"4", "3", "2", "1", "0"};
    constexpr int LENGTH_COUNT = 5;

    // Páginas (10 niveles cada una) que se descargan por categoría
    constexpr int PAGES_PER_LENGTH = 5;

    bool g_busy = false;

    // ---------- Pantalla propia con la lista ya ordenada ----------
    class SortedLevelsLayer : public CCLayer {
    protected:
        Ref<CCArray> m_levels;

        bool init(CCArray* levels) {
            if (!CCLayer::init()) return false;
            m_levels = levels;

            auto winSize = CCDirector::sharedDirector()->getWinSize();

            // Fondo
            auto bg = CCSprite::create("GJ_gradientBG.png");
            if (bg) {
                bg->setAnchorPoint({0, 0});
                bg->setScaleX(winSize.width / bg->getContentSize().width);
                bg->setScaleY(winSize.height / bg->getContentSize().height);
                bg->setColor({0, 102, 255});
                bg->setZOrder(-1);
                this->addChild(bg);
            }

            // Lista de niveles (en el orden del array)
            float listW = 356.f;
            float listH = 220.f;
            auto listView = CustomListView::create(m_levels, BoomListType::Level, listH, listW);
            auto list = GJListLayer::create(
                listView, "Rateados: XL > Tiny", {0, 0, 0, 180}, listW, listH, 0
            );
            list->setPosition({winSize.width / 2 - listW / 2, winSize.height / 2 - listH / 2});
            this->addChild(list);

            // Botón de volver
            auto menu = CCMenu::create();
            auto backBtn = CCMenuItemSpriteExtra::create(
                CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png"),
                this,
                menu_selector(SortedLevelsLayer::onBack)
            );
            menu->addChild(backBtn);
            menu->setPosition({25, winSize.height - 25});
            this->addChild(menu);

            this->setKeypadEnabled(true);
            return true;
        }

    public:
        static SortedLevelsLayer* create(CCArray* levels) {
            auto ret = new SortedLevelsLayer();
            if (ret && ret->init(levels)) {
                ret->autorelease();
                return ret;
            }
            CC_SAFE_DELETE(ret);
            return nullptr;
        }

        static CCScene* scene(CCArray* levels) {
            auto scene = CCScene::create();
            scene->addChild(SortedLevelsLayer::create(levels));
            return scene;
        }

        void onBack(CCObject*) {
            CCDirector::sharedDirector()->popScene();
        }

        void keyBackClicked() override {
            this->onBack(nullptr);
        }
    };

    // ---------- Descarga de niveles categoría por categoría ----------
    class Collector : public CCObject, public LevelManagerDelegate {
    public:
        static void start() {
            if (g_busy) return;
            g_busy = true;
            auto c = new Collector();
            Notification::create("Cargando niveles...", NotificationIcon::Loading)->show();
            c->requestNext();
        }

    private:
        int m_step = 0;
        int m_page = 0;
        Ref<CCArray> m_levels = CCArray::create();
        std::unordered_set<int> m_seen;

        void requestNext() {
            auto search = GJSearchObject::create(SearchType::Search);
            search->m_starFilter = true;       // solo rateados
            search->m_length = LENGTHS[m_step];
            search->m_page = m_page;

            auto glm = GameLevelManager::get();
            glm->m_levelManagerDelegate = this;
            glm->getOnlineLevels(search);
        }

        void handle(CCArray* levels) {
            bool empty = true;
            if (levels) {
                for (auto level : CCArrayExt<GJGameLevel*>(levels)) {
                    empty = false;
                    int id = level->m_levelID.value();
                    if (m_seen.insert(id).second) {
                        m_levels->addObject(level);
                    }
                }
            }
            advance(empty);
        }

        void advance(bool emptyPage) {
            m_page++;
            if (emptyPage || m_page >= PAGES_PER_LENGTH) {
                m_step++;
                m_page = 0;
            }
            if (m_step >= LENGTH_COUNT) {
                finish();
            } else {
                requestNext();
            }
        }

        void finish() {
            GameLevelManager::get()->m_levelManagerDelegate = nullptr;
            g_busy = false;

            // Se hace en el hilo principal para no borrar este objeto
            // mientras GD todavía está dentro del callback.
            queueInMainThread([this]() {
                if (m_levels->count() == 0) {
                    Notification::create("No se encontraron niveles", NotificationIcon::Error)->show();
                } else {
                    CCDirector::sharedDirector()->pushScene(
                        CCTransitionFade::create(0.5f, SortedLevelsLayer::scene(m_levels))
                    );
                }
                this->release();
            });
        }

        void fail() {
            GameLevelManager::get()->m_levelManagerDelegate = nullptr;
            g_busy = false;
            queueInMainThread([this]() {
                Notification::create("Error al cargar niveles", NotificationIcon::Error)->show();
                this->release();
            });
        }

        void loadLevelsFinished(CCArray* levels, const char*) override { handle(levels); }
        void loadLevelsFinished(CCArray* levels, const char*, int) override { handle(levels); }
        void loadLevelsFailed(const char*) override { fail(); }
        void loadLevelsFailed(const char*, int) override { fail(); }
    };
}

namespace StarDurationFilter {
    void openSortedByLength() {
        Collector::start();
    }
}
