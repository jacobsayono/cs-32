#include "RainfallList.h"
#include <iostream>

RainfallList::RainfallList() {
    
}

bool RainfallList::add(unsigned long rainfall) {
    if (rainfall > 400) {
        return false;
    }

    if (sequence.size() >= DEFAULT_MAX_ITEMS) {
        return false;
    }

    int pos = 0;
    for (; pos < sequence.size(); pos++) {
        unsigned long current;
        if (sequence.get(pos, current) && current >= rainfall) {
            break;
        }
    }
    if (sequence.insert(pos, rainfall) == -1) {
        return false;
    }

    return true;
}



bool RainfallList::remove(unsigned long rainfall) {
    if (!isValidRainfall(rainfall)) {
        return false;
    }
    if (sequence.erase(rainfall)) {
        return true;
    }
    return false;
}

int RainfallList::size() const {
    return sequence.size();
}

unsigned long RainfallList::minimum() const {
    return getExtremeRainfall(false);
}

unsigned long RainfallList::maximum() const {
    return getExtremeRainfall(true);
}

bool RainfallList::isValidRainfall(unsigned long rainfall) const {
    return (rainfall >= 0 && rainfall <= 400);
}

unsigned long RainfallList::getExtremeRainfall(bool isMax) const {
    unsigned long extreme = NO_RAINFALLS;
    int n = sequence.size();
    for (int i = 0; i < n; i++) {
        unsigned long value;
        sequence.get(i, value);
        if (isMax && value > extreme) {
            extreme = value;
        }
        else if (!isMax && value < extreme) {
            extreme = value;
        }
    }
    return extreme;
}
