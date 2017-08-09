#ifndef INTENSITY_HPP
#define INTENSITY_HPP

struct Intensity{
    float a_;
    float b_;
    float c_;

    Intensity():
        a_{0.0f}, b_{0.0f}, c_{0.0f}{}

    Intensity(float a, float b, float c):
        a_{a}, b_{b}, c_{c}{}

};

#endif
