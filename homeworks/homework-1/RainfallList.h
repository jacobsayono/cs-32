#ifndef RAINFALLLIST_H
#define RAINFALLLIST_H

#include "Sequence.h"
#include <limits>

const unsigned long NO_RAINFALLS = std::numeric_limits<unsigned long>::max();

class RainfallList {
    public:
        RainfallList();

        bool add(unsigned long rainfall);
        bool remove(unsigned long rainfall);

        int size() const;
        unsigned long minimum() const;
        unsigned long maximum() const;

    private:
        Sequence sequence;

        bool isValidRainfall(unsigned long rainfall) const;
        unsigned long getExtremeRainfall(bool isMax) const;
};

#endif /* RAINFALLLIST_H */