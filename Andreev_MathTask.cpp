#include <iostream>
#include "Andreev_MathTask.h"

using namespace std;

int main() {
    int length = inputSideLength("A");
    int width = inputSideLength("B");
    int area = calculateArea(length, width);
    cout << "Площадь прямоугольника со сторонами " << length << " и " << width << " равна " << area << "." << endl;

    return 0;
}