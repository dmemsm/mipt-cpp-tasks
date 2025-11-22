#include <cmath>
#include <string>
#include "degrees.h"
#include "radians.h"

#include <gtest/gtest.h>

TEST(ConstructorAndGettersTest, DegreesConstructorAndGetters) {
    EXPECT_EQ(Degrees(0).get_degrees(), 0);
    EXPECT_EQ(Degrees(0).get_radians(), 0);
    EXPECT_EQ(Degrees(180).get_degrees(), 180);
    EXPECT_NEAR(Degrees(180).get_radians(), 3.1415, 0.001);
    EXPECT_EQ(Degrees(-180).get_degrees(), -180);
    EXPECT_NEAR(Degrees(540).get_radians(), 9.4247, 0.001);
}

TEST(ConstructorAndGettersTest, RadiansConstructorAndGetters) {
    EXPECT_EQ(Radians(0).get_radians(), 0);
    EXPECT_EQ(Radians(0).get_degrees(), 0);
    EXPECT_EQ(Radians(180).get_radians(), 180);
    EXPECT_NEAR(Radians(M_PI).get_degrees(), 180, 0.001);
    EXPECT_EQ(Radians(-M_PI).get_radians(), -M_PI);
    EXPECT_NEAR(Radians(M_PI*1.5).get_degrees(), 1.5*180, 0.001);
}

TEST(ComparisonTest, MoreThanOrEquals) {
    EXPECT_EQ(Radians(0) > Degrees(0), false);
    EXPECT_EQ(Degrees(0) > Radians(0), false);
    EXPECT_EQ(Radians(0) > Degrees(-180), true);
    EXPECT_EQ(Degrees(180) > Radians(180), false);
    EXPECT_EQ(Radians(-30) > Degrees(-30), false);
    EXPECT_EQ(Radians(0) >= Degrees(0), true);
    EXPECT_EQ(Degrees(0) >= Radians(0), true);
    EXPECT_EQ(Radians(M_PI) >= Degrees(180), true);
    EXPECT_EQ(Degrees(180) >= Radians(M_PI), true);
}

TEST(ComparisonTest, LessThanOrEquals) {
    EXPECT_EQ(Radians(0) < Degrees(0), false);
    EXPECT_EQ(Degrees(0) < Radians(0), false);
    EXPECT_EQ(Radians(0) < Degrees(-180), false);
    EXPECT_EQ(Degrees(180) < Radians(180), true);
    EXPECT_EQ(Radians(-30) < Degrees(-30), true);
    EXPECT_EQ(Radians(0) <= Degrees(0), true);
    EXPECT_EQ(Degrees(0) >= Radians(0), true);
    EXPECT_EQ(Radians(M_PI) <= Degrees(180), true);
    EXPECT_EQ(Degrees(180) <= Radians(M_PI), true);
}

TEST(ComparisonTest, Equals) {
    EXPECT_EQ(Radians(0) == Degrees(0), true);
    EXPECT_EQ(Degrees(0) == Radians(0), true);
    EXPECT_EQ(Degrees(180) == Degrees(-180), false);
    EXPECT_EQ(Degrees(180) == Radians(-M_PI), false);
    EXPECT_EQ(Radians(M_PI) == Radians(M_PI/2), false);
    EXPECT_EQ(Radians(M_PI) == Degrees(180), true);
    EXPECT_EQ(Degrees(360) == Radians(2*M_PI), true);
}

TEST(OperationsTest, Sum) {
    EXPECT_EQ(Radians(0) + Degrees(0), Radians(0));
    EXPECT_EQ(Degrees(0) + Radians(0), Degrees(0));
    EXPECT_NEAR((Radians(M_PI) + Degrees(180)).get_degrees(), 360, 0.001);
    EXPECT_NEAR((Degrees(360) + Radians(M_PI/2)).get_degrees(), 450, 0.001);
    EXPECT_NEAR((Degrees(180) + Degrees(90)).get_degrees(), 270, 0.001);
    EXPECT_NEAR((Radians(M_PI*3) + Radians(M_PI/2)).get_degrees(), 630, 0.001);
}

TEST(OperationsTest, Subtraction) {
    EXPECT_EQ(Radians(0) - Degrees(0), Radians(0));
    EXPECT_EQ(Degrees(0) - Radians(0), Degrees(0));
    EXPECT_NEAR((Radians(M_PI) - Degrees(180)).get_degrees(), 0, 0.001);
    EXPECT_NEAR((Degrees(360) - Radians(M_PI/2)).get_degrees(), 270, 0.001);
    EXPECT_NEAR((Degrees(180) - Degrees(90)).get_degrees(), 90, 0.001);
    EXPECT_NEAR((Radians(M_PI*3) - Radians(M_PI/2)).get_degrees(), 450, 0.001);
    EXPECT_NEAR((Radians(0) - Radians(M_PI)).get_degrees(), -180, 0.001);
    EXPECT_NEAR((Degrees(30) - Radians(M_PI)).get_degrees(), -150, 0.001);
}

TEST(OperationsTest, Multiply) {
    EXPECT_EQ(Radians(0) * Degrees(0), Radians(0));
    EXPECT_EQ(Degrees(0) * Radians(0), Degrees(0));
    EXPECT_EQ(Degrees(4948730) * Radians(0), Degrees(0));
    EXPECT_EQ(Radians(409582048) * Degrees(0), Radians(0));
    EXPECT_NEAR((Radians(M_PI/6) * Degrees(6)).get_radians(), 0.055, 0.001);
    EXPECT_NEAR((Degrees(30) * Radians(M_PI/30)).get_degrees(), 180, 0.001);
    EXPECT_NEAR((Degrees(30) * Degrees(5)).get_degrees(), 150, 0.001);
    EXPECT_NEAR((Radians(M_PI/6) * Radians(2)).get_degrees(), 60, 0.001);
    EXPECT_EQ((Degrees(45) * 2).get_degrees(), 90);
    EXPECT_EQ((Radians(M_PI / 4) * 2).get_degrees(), 90);
    EXPECT_EQ((2 * Degrees(45)).get_degrees(), 90);
    EXPECT_EQ((2 * Radians(M_PI / 4)).get_degrees(), 90);
}

TEST(OperationsTest, Division) {
    EXPECT_EQ(Radians(0) / Degrees(1893398), Radians(0));
    EXPECT_EQ(Degrees(0) / Radians(43948737), Degrees(0));
    EXPECT_NEAR((Radians(M_PI/6) / Degrees(6)).get_radians(), 5, 0.001);
    EXPECT_NEAR((Radians(M_PI/6) / Radians(M_PI/3)).get_degrees(), 28.6478, 0.001);
    EXPECT_NEAR((Radians(M_PI/6) / Radians(0.5)).get_degrees(), 60, 0.001);
    EXPECT_NEAR((Degrees(30) / Radians(M_PI/6)).get_degrees(), 1, 0.001);
    EXPECT_NEAR((Degrees(180) / Degrees(90)).get_degrees(), 2, 0.001);
    EXPECT_EQ((Degrees(180) / 2).get_degrees(), 90);
    EXPECT_EQ((Radians(M_PI / 2) / 2).get_degrees(), 45);
}

TEST(ConversionTest, ToString) {
    EXPECT_EQ(std::string(Degrees(0)), "0° (0 rad)");
    EXPECT_EQ(std::string(Radians(0)), "0° (0 rad)");
    EXPECT_EQ(std::string(Degrees(180)), "180° (3.14 rad)");
    EXPECT_EQ(std::string(Radians(M_PI / 2)), "90° (1.57 rad)");
}