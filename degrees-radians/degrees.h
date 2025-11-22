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

    Degrees operator*(double right) const;

    friend Degrees operator*(double left, Degrees right);

    Degrees operator/(Degrees right) const;

    Degrees operator/(double right) const;

    bool operator>(Degrees right) const;

    bool operator>=(Degrees right) const;

    bool operator<(Degrees right) const;

    bool operator<=(Degrees right) const;

    bool operator==(Degrees right) const;

    explicit operator std::string() const;
};