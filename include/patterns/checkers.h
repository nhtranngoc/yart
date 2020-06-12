#pragma once

#include "pattern.h"

class CheckersPattern : public Pattern {
    public:
    CheckersPattern(Color a_, Color b_) :
        Pattern(a_, b_) {}
    Color PatternAtPoint(Tuple const&);
};