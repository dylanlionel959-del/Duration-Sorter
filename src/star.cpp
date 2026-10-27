#include "star.hpp"

using namespace geode::prelude;

void StarDurationFilter::applyDurationSort(GJSearchObject* searchObj) {
    if (!searchObj) return;

    // Configure to target rated levels
    searchObj->m_rated = true;
    
    // Apply duration criteria or sorting modifications as needed by the game bindings
}
