#include <Geode/Geode.hpp>
#include <Geode/modify/LevelBrowserLayer.hpp>

using namespace geode::prelude;

// Declaramos la función externa o clase que está en star.cpp
namespace StarDurationFilter {
    void applyLongRatedFilter(GJSearchObject* searchObj);
}

class $modify(MyLevelBrowserLayer, LevelBrowserLayer) {
    bool init(GJSearchObject* p0) {
        if (!LevelBrowserLayer::init(p0)) return false;

        auto winSize = CCDirector::sharedDirector()->getWinSize();
        auto menu = CCMenu::create();

        // Creamos el botón con tu icono de estrellas desde la carpeta resources
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
        // Llamamos a la lógica de filtrado cuando hacen clic
        if (this->m_searchObject) {
            StarDurationFilter::applyLongRatedFilter(this->m_searchObject);
        }

        FLAlertLayer::create(
            "Duration Sorter",
            "¡Filtro de niveles rateados largos aplicado!",
            "OK"
        )->show();
        
        // Opcional: recargar la capa de niveles para reflejar los cambios de búsqueda
        // this->loadLevels(this->m_searchObject);
    }
};
