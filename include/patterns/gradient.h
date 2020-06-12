#pragma once

#include "pattern.h"

class GradientPattern : public Pattern {
    public:
    GradientPattern(Color a_, Color b_) :
        Pattern(a_, b_) {}
    Color PatternAtPoint(Tuple const&);
};