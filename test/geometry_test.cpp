#include <ctest.h>
#include <libgeometry/geometry.h>
#include <libgeometry/parse.h>
#include <string>

#include <stdlib.h>

CTEST(P_and_a_of_circle, Perimeter)
{
    double radius = 2;

    double real = circle_perimeter(radius);

    double exp_perimeter = 12.56;

    ASSERT_DBL_NEAR(exp_perimeter, real);
}

CTEST(P_and_a_of_circle, Area)
{
    double area = 1;

    double real = circle_area(area);

    double exp_area = 3.14;

    ASSERT_DBL_NEAR(exp_area, real);
}


CTEST(Parsing, Identify_name)
{
    Figures real = identify("circle");

    Figures exp_rez = CIRCLE;

    ASSERT_EQUAL(exp_rez, real);
}

CTEST(Parsing, word_to_lower)
{
    std::string test = "AbCdEf";

    std::string real = word_tolower(test);

    std::string exp_rez = "abcdef";

    const char* exp_str = exp_rez.c_str();
    const char* real_str = real.c_str();

    ASSERT_STR(exp_str, real_str);
}

CTEST(Parsing, parse_name_with_space_before)
{
    std::string test = " circle(0 0, 1.5)";

    std::string real = parse_name(&test);

    std::string exp_rez = "circle";

    const char* exp_str = exp_rez.c_str();
    const char* real_str = real.c_str();

    ASSERT_STR(exp_str, real_str);
}

CTEST(Parsing, parse_name_with_space_after)
{
    std::string test = "circle (0 0, 1.5)";

    std::string real = parse_name(&test);

    std::string exp_rez = "circle";

    const char* exp_str = exp_rez.c_str();
    const char* real_str = real.c_str();

    ASSERT_STR(exp_str, real_str);
}
