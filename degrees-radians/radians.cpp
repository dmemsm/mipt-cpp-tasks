#include <cmath>
#include "radians.h"
#include "degrees.h"

Radians::Radians(double value): value{value} {}

Radians::Radians(Degrees degrees): value{degrees.get_degrees() * M_PI / 180} {}

double Radians::get_radians() const {
    return value;
}

double Radians::get_degrees() const {
    return value * 180 / M_PI;
}

Radians Radians::operator+(Radians right) const {
    return Radians(value + right.get_radians());
}

Radians Radians::operator-(Radians right) const {
    return Radians(value - right.get_radians());
}

Radians Radians::operator*(Radians right) const {
    return Radians(value * right.get_radians());
}

Radians Radians::operator/(Radians right) const {
    return Radians(value / right.get_radians());
}

bool Radians::operator>(Radians right) const {
    return value > right.value;
}

bool Radians::operator>=(Radians right) const {
    return value >= right.value;
}

bool Radians::operator<(Radians right) const {
    return value < right.value;
}

bool Radians::operator<=(Radians right) const {
    return value <= right.value;
}

bool Radians::operator==(Radians right) const {
    return value == right.value;
}
