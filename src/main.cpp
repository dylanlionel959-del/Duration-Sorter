#include <Geode/Geode.hpp>
#include <Geode/modify/LevelBrowserLayer.hpp>
#include "star.hpp"

using namespace geode::prelude;

class $modify(MyLevelBrowserLayer, LevelBrowserLayer) {
    bool init(GJSearchObject* p0) {
        if (!LevelBrowserLayer::init(p0)) {
            return false;
        }

        StarDurationFilter::applyDurationSort(p0);

        return true;
    }
};
