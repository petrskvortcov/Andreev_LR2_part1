#ifndef _ANDREEV_MATHTASK_H_
#define _ANDREEV_MATHTASK_H_

#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Функция для ввода длины стороны прямоугольника
int inputSideLength(const string& sideName) {
    int length;
    while (true) {
        cout << "Введите длину стороны " << sideName << " (целое число): ";
        cin >> length;

        // Проверка на корректность ввода
        if (cin.fail() || length <= 0) {
            cin.clear(); // Сбросить состояние потока
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорировать некорректный ввод
            cout << "Длина стороны должна быть положительным целым числом. Попробуйте снова." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорировать оставшиеся символы в буфере
            return length;
        }
    }
}

// Функция для вычисления площади прямоугольника
int calculateArea(int length, int width) {
    return length * width;
}

#endif