#include <cmath>
#include "degrees.h"
#include "radians.h"

const double precision = 0.001;

Degrees::Degrees(double value): value{value} {}

Degrees::Degrees(Radians radians): value{radians.get_radians() * 180 / M_PI} {}

double Degrees::get_degrees() const {
    return value;
}

double Degrees::get_radians() const {
    return value * M_PI / 180;
}

Degrees Degrees::operator+(Degrees right) const {
    return Degrees(value + right.get_degrees());
}

Degrees Degrees::operator-(Degrees right) const {
    return Degrees(value - right.get_degrees());
}

Degrees Degrees::operator*(Degrees right) const {
    return Degrees(value * right.get_degrees());
}

Degrees Degrees::operator/(Degrees right) const {
    return Degrees(value / right.get_degrees());
}

bool Degrees::operator>(Degrees right) const {
    return value > right.value;
}

bool Degrees::operator<(Degrees right) const {
    return value < right.value;
}

bool Degrees::operator==(Degrees right) const {
    return std::abs(value - right.value) < precision;
}

bool Degrees::operator>=(Degrees right) const {
    return *this > right or *this == right;
}

bool Degrees::operator<=(Degrees right) const {
    return *this < right or *this == right;
}