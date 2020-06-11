#ifndef COLOR_H
#define COLOR_H

#include "tuple.h"
#include <stdint.h>

class Color : public Tuple {
    public:
        Color(float r, float g, float b) : Tuple(r,g,b,0){}

        inline float r() {return this->x;}
        inline float g() {return this->y;}
        inline float b() {return this->z;}
        inline uint32_t toHex() {
            uint8_t r = (this->x >= 1.f) ? (uint8_t) 255 : (this->x <= 0.f) ? (uint8_t) 0 : (uint8_t) ((this->x)*255.f);
            uint8_t g = (this->y >= 1.f) ? (uint8_t) 255 : (this->y <= 0.f) ? (uint8_t) 0 : (uint8_t) ((this->y)*255.f);
            uint8_t b = (this->z >= 1.f) ? (uint8_t) 255 : (this->z <= 0.f) ? (uint8_t) 0 : (uint8_t) ((this->z)*255.f);
            
            return (
                0xff000000 | 
                (r << 16) | 
                (g << 8) | 
                b
            );
        }
        friend inline Color operator * (Color const &c1, Color const c2) {return Color(c1.x * c2.x, c1.y * c2.y, c1.z * c2.z);}
        friend inline Color operator * (Color const &c1, float const f) {return Color(c1.x * f, c1.y * f, c1.z * f);}
        friend inline Color operator + (Color const &c1, Color const c2) {return Color(c1.x + c2.x, c1.y + c2.y, c1.z + c2.z);}
        static Color Red() {return Color(1,0,0);}
        static Color Green() {return Color(0,1,0);}
        static Color Blue() {return Color(0,0,1);}
        static Color Black() {return Color(0,0,0);}
        static Color White() {return Color(1,1,1);}
};

#endif // COLOR_H_