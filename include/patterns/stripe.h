#pragma once

#include "pattern.h"

class Pattern;

class StripePattern : public Pattern {
    public:
    StripePattern(Color a_, Color b_) :
        Pattern(a_, b_) {}
    Color PatternAtPoint(Tuple const &point) override;
};