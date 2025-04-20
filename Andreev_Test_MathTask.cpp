#include <iostream>
#include "Andreev_MathTask.h"

#define ASSERT_EQUAL(expected, actual) \
    if ((expected) != (actual)) { \
        std::cerr << "Assertion failed: expected " << (expected) << ", but got " << (actual) << std::endl; \
    } else { \
        std::cout << "Test passed: " << (expected) << " == " << (actual) << std::endl; \
    }

void testCalculateArea() {
    // Тест 1: Обычный случай
    int length1 = 5;
    int width1 = 10;
    int expectedArea1 = 50;
    ASSERT_EQUAL(expectedArea1, calculateArea(length1, width1)); 

    // Тест 2: Другой обычный случай
    int length2 = 7;
    int width2 = 3;
    int expectedArea2 = 21;
    ASSERT_EQUAL(expectedArea2, calculateArea(length2, width2)); 

    // Тест 3: Крайний случай (нулевое значение)
    int length3 = 0;
    int width3 = 10;
    int expectedArea3 = 0;
    ASSERT_EQUAL(expectedArea3, calculateArea(length3, width3)); 
}

int main() {
    testCalculateArea();
    return 0;
}