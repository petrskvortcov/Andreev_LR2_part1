#include <iostream>
#include "Andreev_MathTask.h"

#ifdef TESTS_ENABLED
#include "Andreev_Test_MathTask.cpp"
#endif

int main(int argc, char** argv) {
    if (argc > 1 && std::string(argv[1]) == "test") {
        // Если указан ключ 'test', запускаем тесты
        #ifdef TESTS_ENABLED
        return runTests();
        #else
        std::cerr << "Тесты отключены" << std::endl;
        return 1;
        #endif
    }

    // Обычная работа программы
    int length = inputSideLength("A");
    int width = inputSideLength("B");
    int area = calculateArea(length, width);
    std::cout << "Площадь прямоугольника со сторонами " << length << " и " << width << " равна " << area << "." << std::endl;

    return 0;
}