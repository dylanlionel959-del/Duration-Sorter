#include <Geode/Geode.hpp>
#include <Geode/modify/LevelBrowserLayer.hpp>
#include "star.hpp"

using namespace geode::prelude;

class $modify(MyLevelBrowserLayer, LevelBrowserLayer) {
    bool init(GJSearchObject* p0) {
        if (!LevelBrowserLayer::init(p0)) {
            return false;
        }

        // Apply the sorting logic cleanly without causing compiler conflicts
        StarDurationFilter::applyDurationSort(p0);

        return true;
    }
};
