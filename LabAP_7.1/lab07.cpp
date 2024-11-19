#include <iostream>
#include <vector> // Для роботи з динамічними масивами
#include <algorithm> // Для алгоритмів сортування та пошуку
#include <iomanip>
#include <cstdlib> // Для генерації випадкових чисел
#include <ctime> // Для генерації випадкових чисел

using namespace std;

// Функція для генерації матриці
vector<vector<int>> generateMatrix(int rows, int cols, int minVal, int maxVal) {
    vector<vector<int>> matrix(rows, vector<int>(cols)); // Створюється двовимірний вектор заданого розміру.
    srand(time(0)); // Генератор випадкових чисел
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % (maxVal - minVal + 1) + minVal; // Генерує випадкові числа в межах [minVal, maxVal]
        }
    }
    return matrix;
}

// Функція для виведення матриці
void printMatrix(const vector<vector<int>>& matrix) { // Передача матриці по константному посиланню
    for (const auto& row : matrix) { // Ітерація по кожному рядку матриці
        for (int val : row) { // Ітерація по кожному елементу рядка
            cout << setw(4) << val;
        }
        cout << endl;
    }
}

// Функція для обчислення критеріїв
void processMatrix(vector<vector<int>>& matrix, int& count, int& sum) { // Змінні передаються по посиланню, щоб повернути обчислені значення у головну програму.
    count = 0;
    sum = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] % 2 == 0 && (i + j) % 8 != 0) { // Умова: парні, але сума індексів не кратна 8
                sum += matrix[i][j];
                ++count;
                matrix[i][j] = 0; // Замінюємо на 0
            }
        }
    }
}

// Функція для сортування рядків матриці
void sortMatrixRows(vector<vector<int>>& matrix) {
    sort(matrix[0].begin(), matrix[0].end(), greater<int>()); // Сортуємо перший рядок за спаданням
    if (adjacent_find(matrix[0].begin(), matrix[0].end()) != matrix[0].end()) {
        sort(matrix[1].begin(), matrix[1].end()); // Якщо є однакові елементи, сортуємо другий рядок за зростанням
    }
    if (adjacent_find(matrix[1].begin(), matrix[1].end()) != matrix[1].end()) {
        sort(matrix[2].begin(), matrix[2].end()); // Сортуємо третій рядок за зростанням, якщо є однакові в другому
    }
}

// Основна функція
int main() {
    const int rows = 7;
    const int cols = 6;
    const int minVal = 7;
    const int maxVal = 62;

    // Генеруємо матрицю
    vector<vector<int>> matrix = generateMatrix(rows, cols, minVal, maxVal);
    cout << "Initial matrix:\n";
    printMatrix(matrix);

    // Обробляємо матрицю за критерієм
    int count, sum;
    processMatrix(matrix, count, sum);
    cout << "\nMatrix after processing (replacing with 0 by the criterion):\n"; // Матриця після обробки (заміна на 0 за критерієм):
    printMatrix(matrix);
    cout << "\nThe number of items that meet the criterion: " << count << "\n"; // Кількість елементів, що відповідають критерію:
    cout << "The sum of such elements: " << sum << "\n"; // Сума таких елементів:

    // Сортуємо матрицю
    sortMatrixRows(matrix);
    cout << "\nThe matrix after sorting:\n"; // Матриця після сортування:
    printMatrix(matrix);

    return 0;
}
