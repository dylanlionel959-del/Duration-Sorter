#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>
#include <Geode/modify/GameLevelManager.hpp>

using namespace geode::prelude;

// 0: Disabled, 1: Long to Short, 2: Short to Long
static int g_durationSortMode = 0;

class $modify(MyLevelSearchLayer, LevelSearchLayer) {
    bool init(int type) {
        if (!LevelSearchLayer::init(type)) return false;

        auto clockSprite = CCSprite::createWithSpriteFrameName("GJ_timeIcon_001.png");
        if (!clockSprite) {
            clockSprite = CCSprite::createWithSpriteFrameName("GJ_clockBtn_001.png");
        }

        auto clockBtn = CCMenuItemSpriteExtra::create(
            clockSprite,
            this,
            menu_selector(MyLevelSearchLayer::onDurationFilterToggle)
        );

        auto menu = this->getChildByID("other-filter-menu");
        if (!menu) {
            menu = CCMenu::create();
            menu->setID("duration-filter-menu");
            this->addChild(menu);
        }

        clockBtn->setID("duration-sort-button");
        menu->addChild(clockBtn);
        menu->updateLayout();

        return true;
    }

    void onDurationFilterToggle(CCObject* sender) {
        g_durationSortMode = (g_durationSortMode + 1) % 3;

        std::string modeText = "Duration Filter: Disabled";
        if (g_durationSortMode == 1) {
            modeText = "Duration Filter: Long to Short";
        } else if (g_durationSortMode == 2) {
            modeText = "Duration Filter: Short to Long";
        }

        FLAlertLayer::create("Duration Sort", modeText.c_str(), "OK")->show();
    }
};

class $modify(MyGameLevelManager, GameLevelManager) {
    void getOnlineLevels(GJSearchObject* searchObject) {
        if (searchObject) {
            if (g_durationSortMode == 1) {
                searchObject->m_isLong = true;
                searchObject->m_isXL = true;
                searchObject->m_isTiny = false;
                searchObject->m_isShort = false;
            } else if (g_durationSortMode == 2) {
                searchObject->m_isTiny = true;
                searchObject->m_isShort = true;
                searchObject->m_isLong = false;
                searchObject->m_isXL = false;
            }
        }
        
        GameLevelManager::getOnlineLevels(searchObject);
    }
};
