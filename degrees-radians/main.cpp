#include <iostream>

#include "degrees.h"
#include "radians.h"

int main() {
    auto degrees_0 = Degrees(237893);
    std::cout << degrees_0.get_degrees() << "° = " << degrees_0.get_radians() << " rad\n";
    auto degrees_1 = Degrees(60);
    auto radians_1 = Radians(3.1415926);
    auto res_1 = degrees_1 + radians_1;
    std::cout << std::string(degrees_1) << " + " << std::string(radians_1) << " = " << std::string(res_1) << "\n";
    auto degrees_2 = Degrees(150);
    auto res_2 = res_1 - degrees_2;
    std::cout << std::string(res_1) << " - " << std::string(degrees_2) << " = " << std::string(res_2) << "\n";
    std::cout << std::string(res_2) << " > " << std::string(radians_1) << ": " << (res_2 > radians_1 ? "true" : "false") << "\n";
    auto res_3 = Radians(6) + Degrees(137) - radians_1 + res_2;
    std::cout << std::string(Radians(6)) << " + " << std::string(Degrees(137))
            << " - " << std::string(radians_1) << " + " << std::string(res_2) << " = " << std::string(res_3) << "\n";
}