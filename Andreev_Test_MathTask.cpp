#include "Andreev_MathTask.h"
#include "CUTE/cute/cute.h"
#include "CUTE/cute/ide_listener.h"
#include "CUTE/cute/cute_runner.h"
#include <iostream>
#include <sstream>

using namespace std;

// Функция для имитации ввода данных
void simulateInput(const string& input) {
    stringstream ss(input);
    cin.rdbuf(ss.rdbuf()); // перенаправляет поток cin на симулированный поток
}

// Тест для проверки реакции на пустой ввод
void testEmptyInput() {
    simulateInput("\n");
    try {
        inputSideLength("A");
        FAIL("Ожидалась ошибка при пустом вводе");
    } catch(...) {} // ловим любое исключение, которое вызвано нашей обработкой ошибок
}

// Тест для проверки реакции на ввод нецифровых символов
void testNonDigitInput() {
    simulateInput("abc\n");
    try {
        inputSideLength("A");
        FAIL("Ожидалась ошибка при вводе нецифрового символа");
    } catch(...) {}
}

// Тест для проверки реакции на отрицательные значения
void testNegativeInput() {
    simulateInput("-5\n");
    try {
        inputSideLength("A");
        FAIL("Ожидалась ошибка при вводе отрицательного числа");
    } catch(...) {}
}

// Тест для проверки успешного ввода положительного целого числа
void testValidInput() {
    simulateInput("7\n");
    ASSERT_EQUAL(7, inputSideLength("A"));
}

// Тест для проверки правильности расчёта площади
void testCalculateArea() {
    ASSERT_EQUAL(20, calculateArea(4, 5));
    ASSERT_EQUAL(0, calculateArea(0, 5));
}

// Основной блок запуска тестов
int runTests() {
    cute::suite s;
    s.push_back(CUTE(testEmptyInput));
    s.push_back(CUTE(testNonDigitInput));
    s.push_back(CUTE(testNegativeInput));
    s.push_back(CUTE(testValidInput));
    s.push_back(CUTE(testCalculateArea));

    cute::ide_listener lis;
    cute::makeRunner(lis)(s, "All Tests");
    return lis.summarizeFailures(); 
}