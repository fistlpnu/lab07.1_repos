#include "pch.h" // Для Visual Studio
#include "CppUnitTest.h" // Бібліотека для тестування
#include "../LabAP_7.1/lab07.cpp" // Шлях до основного файлу з функціями

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixTests
{
    TEST_CLASS(MatrixTests)
    {
    public:
        // Тест для перевірки генерації матриці
        TEST_METHOD(GenerateMatrixTest)
        {
            int rows = 3, cols = 3, minVal = 7, maxVal = 10;
            auto matrix = generateMatrix(rows, cols, minVal, maxVal);

            // Перевірка розмірів матриці
            Assert::AreEqual((int)matrix.size(), rows, L"Matrix row size mismatch");
            Assert::AreEqual((int)matrix[0].size(), cols, L"Matrix column size mismatch");

            // Перевірка значень у межах діапазону
            for (const auto& row : matrix) {
                for (int val : row) {
                    Assert::IsTrue(val >= minVal && val <= maxVal, L"Value out of range");
                }
            }
        }

        // Тест для перевірки обробки матриці
        TEST_METHOD(ProcessMatrixTest)
        {
            vector<vector<int>> matrix = {
                {2, 8, 7},
                {10, 5, 4},
                {3, 6, 12}
            };
            int count = 0, sum = 0;

            processMatrix(matrix, count, sum);

            // Оновлені очікування
            Assert::AreEqual(count, 4, L"Count mismatch");
            Assert::AreEqual(sum, 26, L"Sum mismatch");

            // Перевірка заміни елементів на 0
            Assert::AreEqual(matrix[0][0], 0, L"Element (0,0) should be 0");
            Assert::AreEqual(matrix[0][1], 0, L"Element (0,1) should be 0");
            Assert::AreEqual(matrix[2][1], 0, L"Element (2,1) should be 0");
        }


        // Тест для перевірки сортування рядків матриці
        TEST_METHOD(SortMatrixRowsTest)
        {
            vector<vector<int>> matrix = {
                {5, 3, 8},
                {4, 2, 6},
                {9, 1, 7}
            };

            sortMatrixRows(matrix);

            // Очікувані результати після сортування
            vector<int> expectedFirstRow = { 8, 5, 3 };  // Перший рядок за спаданням
            vector<int> expectedSecondRow = { 2, 4, 6 }; // Другий рядок за зростанням

            // Перевірка першого рядка
            for (size_t i = 0; i < matrix[0].size(); ++i) {
                Assert::AreEqual(matrix[0][i], expectedFirstRow[i], L"First row mismatch");
            }

            // Перевірка другого рядка
            for (size_t i = 0; i < matrix[1].size(); ++i) {
                Assert::AreEqual(matrix[1][i], expectedSecondRow[i], L"Second row mismatch");
            }
        }

    };
}
