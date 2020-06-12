#pragma once

#include "pattern.h"

class RingPattern : public Pattern {
    public:
    RingPattern(Color a_, Color b_) :
        Pattern(a_, b_) {}
    Color PatternAtPoint(Tuple const&);
};