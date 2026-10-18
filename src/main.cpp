#include <Geode/Geode.cpp>
#include <Geode/modify/LevelBrowserLayer.hpp>

using namespace geode::prelude;

class $modify(MyLevelBrowserLayer, LevelBrowserLayer) {
    bool init(GJSearchObject* p0) {
        if (!LevelBrowserLayer::init(p0)) return false;

        // Obtenemos el tamaño de la pantalla para posicionar el botón
        auto winSize = CCDirector::sharedDirector()->getWinSize();

        // Creamos un menú flotante en la interfaz
        auto menu = CCMenu::create();

        // Creamos el botón usando tu icono de estrellas desde la carpeta resources
        auto starButton = CCMenuItemSpriteExtra::create(
            CCSprite::create("star_icon.png"_spr),
            this,
            menu_selector(MyLevelBrowserLayer::onDurationSortClicked)
        );

        // Posicionamos el botón en la esquina superior izquierda (puedes ajustarlo a tu gusto)
        starButton->setPosition({35, winSize.height - 45});
        
        menu->addChild(starButton);
        menu->setPosition({0, 0});
        
        // Añadimos el menú a la capa del navegador de niveles
        this->addChild(menu, 100);

        return true;
    }

    // Función que se ejecuta al presionar el botón de la estrella
    void onDurationSortClicked(CCObject* sender) {
        FLAlertLayer::create(
            "Duration Sorter",
            "¡Filtro de duración activado con éxito!",
            "OK"
        )->show();

        // Aquí puedes implementar más adelante la lógica para reordenar 
        // o filtrar los niveles según su duración en el buscador.
    }
};
