#include "star.hpp"
#include <Geode/binding/GJSearchObject.hpp>
#include <Geode/binding/LevelBrowserLayer.hpp>
#include <Geode/ui/Notification.hpp>

using namespace geode::prelude;

namespace {
    struct LengthStep {
        const char* value; // valor del filtro de duración en GD
        const char* name;
    };

    // De más larga a más corta (solo modo Clásico)
    constexpr LengthStep STEPS[] = {
        {"4", "XL"},
        {"3", "Long"},
        {"2", "Medium"},
        {"1", "Short"},
        {"0", "Tiny"},
    };
    constexpr int STEP_COUNT = sizeof(STEPS) / sizeof(STEPS[0]);

    int g_step = 0;
}

namespace StarDurationFilter {
    void openNextLengthRated() {
        auto const& step = STEPS[g_step];
        g_step = (g_step + 1) % STEP_COUNT;

        auto search = GJSearchObject::create(SearchType::Search);
        search->m_starFilter = true;      // solo rateados
        search->m_length = step.value;    // duración de esta vuelta

        log::info("Abriendo niveles rateados: {}", step.name);

        auto scene = LevelBrowserLayer::scene(search);
        CCDirector::sharedDirector()->replaceScene(
            CCTransitionFade::create(0.5f, scene)
        );

        Notification::create(
            std::string("Rateados: ") + step.name,
            NotificationIcon::None
        )->show();
    }
}
