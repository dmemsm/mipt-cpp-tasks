#pragma once

class Degrees;

class Radians {
    double value;

public:
    explicit Radians(double value);

    Radians(Degrees degrees);

    double get_radians() const;

    double get_degrees() const;

    Radians operator+(Radians right) const;

    Radians operator-(Radians right) const;

    Radians operator*(Radians right) const;

    Radians operator*(double right) const;

    friend Radians operator*(double left, Radians right);

    Radians operator/(Radians right) const;

    Radians operator/(double right) const;

    bool operator>(Radians right) const;

    bool operator>=(Radians right) const;

    bool operator<(Radians right) const;

    bool operator<=(Radians right) const;

    bool operator==(Radians right) const;
};