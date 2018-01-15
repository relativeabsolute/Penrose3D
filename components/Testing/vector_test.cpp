#define BOOST_TEST_MODULE PenroseTest
#include <boost/test/included/unit_test.hpp>
#include <Penrose_Vector.hpp>
#include <iostream>

using namespace Penrose::Math;

BOOST_AUTO_TEST_SUITE(vector_tests)

BOOST_AUTO_TEST_CASE(constructor_test) {
    std::cout << "Running constructor test." << std::endl;
    Vector<float, 3> vec {{ 0, 1, 2 }};

    for (size_t i = 0; i < 3; i++) {
        BOOST_CHECK_CLOSE(vec[i], i, 0.0001f);
    }
}

BOOST_AUTO_TEST_CASE(add_test) {
    std::cout << "Running addition test." << std::endl;
    Vector<float, 3> first {{ 1, 2, 3 }};
    Vector<float, 3> second {{ 2, 3, 4 }};

    auto result = first + second;
    BOOST_CHECK_CLOSE(result[0], 3, 0.0001f);
    BOOST_CHECK_CLOSE(result[1], 5, 0.0001f);
    BOOST_CHECK_CLOSE(result[2], 7, 0.0001f);
}

BOOST_AUTO_TEST_CASE(subtraction_test) {
    std::cout << "Running subtraction test." << std::endl;
    Vector<float, 3> first {{ 1, 2, 3 }};
    Vector<float, 3> second {{ 1, 3, 2 }};

    auto result = first - second;
    BOOST_CHECK_CLOSE(result[0], 0, 0.0001f);
    BOOST_CHECK_CLOSE(result[1], -1, 0.0001f);
    BOOST_CHECK_CLOSE(result[2], 1, 0.0001f);
}

BOOST_AUTO_TEST_SUITE_END()
