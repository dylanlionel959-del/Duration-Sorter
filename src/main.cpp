#include <Geode/Geode.hpp>
#include <Geode/modify/LevelBrowserLayer.hpp>
#include "star.hpp"

using namespace geode::prelude;

class $modify(MyLevelBrowserLayer, LevelBrowserLayer) {
    bool init(GJSearchObject* p0) {
        if (!LevelBrowserLayer::init(p0)) return false;

        auto winSize = CCDirector::sharedDirector()->getWinSize();
        auto menu = CCMenu::create();

        auto starButton = CCMenuItemSpriteExtra::create(
            CCSprite::create("star_icon.png"_spr),
            this,
            menu_selector(MyLevelBrowserLayer::onDurationSortClicked)
        );

        starButton->setPosition({35, winSize.height - 45});

        menu->addChild(starButton);
        menu->setPosition({0, 0});
        this->addChild(menu, 100);

        return true;
    }

    void onDurationSortClicked(CCObject* sender) {
        if (this->m_searchObject) {
            StarDurationFilter::applyLongRatedFilter(this->m_searchObject);
        }

        FLAlertLayer::create(
            "Duration Sorter",
            "¡Filtro de niveles rateados largos aplicado!",
            "OK"
        )->show();
    }
};
