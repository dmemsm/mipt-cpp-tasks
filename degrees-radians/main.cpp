#include <iostream>

#include "degrees.h"
#include "radians.h"

int main() {
    auto degrees_0 = Degrees(237893);
    std::cout << degrees_0.get_degrees() << "° = " << degrees_0.get_radians() << " rad\n";
    auto degrees_1 = Degrees(60);
    auto radians_1 = Radians(3.1415926);
    auto res_1 = degrees_1 + radians_1;
    std::cout << degrees_1.get_degrees() << "° + " << radians_1.get_degrees()
            << "° (" << radians_1.get_radians() << " rad) = " << res_1.get_degrees() << "°\n";
    auto degrees_2 = Degrees(150);
    auto res_2 = res_1 - degrees_2;
    std::cout << res_1.get_degrees() << "° - " << degrees_2.get_degrees()
            << "° = " << res_2.get_degrees() << "° (" << res_2.get_radians() << " rad)\n";
    std::cout << res_2.get_degrees() << "° > " << radians_1.get_degrees() << "°: " << (res_2 > radians_1 ? "true" : "false") << "\n";
    auto res_3 = Radians(6) + Degrees(137) - radians_1 + res_2;
    std::cout << Radians(6).get_radians() << " rad + " << Degrees(137).get_degrees()
            << "° - " << radians_1.get_radians() << " rad + " << res_2.get_degrees() << "° = " << res_3.get_degrees()
            << "° (" << res_3.get_radians() << " rad)\n";
}