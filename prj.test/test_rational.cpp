#include <iostream>
#include <sstream>
#include <rational/rational.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <cstdint>

TEST_CASE("rational ctor") {
    CHECK_THROWS(Rational(1, 0));
    CHECK(Rational(2, 1) + Rational(3, 4) == Rational(11, 4));
    CHECK(Rational(8, 9) - 3 == Rational(-19, 9));
    CHECK(3 + Rational(3, 3) == Rational(4, 1));
    CHECK(Rational(2, 1) * Rational(3, 2) == Rational(3, 1));
    CHECK(Rational(3, 5) / Rational(-3, 5) == Rational(-1, 1));
    Rational z(2, -3);
    CHECK(z == Rational(-2, 3));
    Rational x(2, 4);
    CHECK(x / z == Rational(-3, 4));
    CHECK((Rational(2, 3) >= Rational(1, 1)) == 0);
    CHECK((Rational(2, 3) < Rational(1, 1)) == 1);
    CHECK(Rational(3, -6) == Rational(-1, 2));
}