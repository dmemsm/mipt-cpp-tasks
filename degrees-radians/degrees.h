#pragma once

class Radians;

class Degrees {
    double value;

public:
    explicit Degrees(double value);

    Degrees(Radians radians);

    double get_degrees() const;

    double get_radians() const;

    Degrees operator+(Degrees right) const;

    Degrees operator-(Degrees right) const;

    Degrees operator*(Degrees right) const;

    Degrees operator/(Degrees right) const;

    bool operator>(Degrees right) const;

    bool operator>=(Degrees right) const;

    bool operator<(Degrees right) const;

    bool operator<=(Degrees right) const;

    bool operator==(Degrees right) const;
};