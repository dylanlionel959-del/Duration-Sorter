#include "star.hpp"
#include <Geode/binding/GameLevelManager.hpp>
#include <Geode/binding/GJSearchObject.hpp>
#include <Geode/binding/GJGameLevel.hpp>
#include <Geode/binding/LevelBrowserLayer.hpp>
#include <Geode/binding/LevelManagerDelegate.hpp>
#include <Geode/ui/Notification.hpp>

using namespace geode::prelude;

namespace {
    // De más larga a más corta (modo Clásico)
    constexpr const char* LENGTHS[] = {"4", "3", "2", "1", "0"};
    constexpr int LENGTH_COUNT = 5;

    // Páginas (10 niveles cada una) que se descargan por categoría
    constexpr int PAGES_PER_LENGTH = 3;

    bool g_busy = false;

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
        std::vector<int> m_ids;

        void requestNext() {
            auto search = GJSearchObject::create(SearchType::Search);
            search->m_starFilter = true;
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
                    m_ids.push_back(level->m_levelID.value());
                    empty = false;
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

            if (m_ids.empty()) {
                Notification::create("No se encontraron niveles", NotificationIcon::Error)->show();
                this->release();
                return;
            }

            std::string ids;
            for (size_t i = 0; i < m_ids.size(); i++) {
                if (i) ids += ",";
                ids += std::to_string(m_ids[i]);
            }

            auto search = GJSearchObject::create(SearchType::MapPackOnClick, ids);
            auto scene = LevelBrowserLayer::scene(search);
            CCDirector::sharedDirector()->replaceScene(
                CCTransitionFade::create(0.5f, scene)
            );
            this->release();
        }

        void fail() {
            GameLevelManager::get()->m_levelManagerDelegate = nullptr;
            g_busy = false;
            Notification::create("Error al cargar niveles", NotificationIcon::Error)->show();
            this->release();
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
