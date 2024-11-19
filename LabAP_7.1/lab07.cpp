// Lab_7_1.cpp
// Лабораторна робота № 7.1
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 11
// Захарчук Олександр Анатолійович

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void ChangeColumns(int** a, const int col1, const int col2, const int rowCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL)); // Ініціалізація генератора випадкових чисел
    const int Low = 7;
    const int High = 62;
    const int rowCount = 7;
    const int colCount = 6;

    // Виділення пам’яті для матриці
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    // Створення та виведення початкової матриці
    Create(a, rowCount, colCount, Low, High);
    cout << "Initial matrix:" << endl;
    Print(a, rowCount, colCount);

    // Обчислення критеріїв
    int S = 0; // Сума елементів
    int k = 0; // Кількість елементів
    Calc(a, rowCount, colCount, S, k);
    cout << "Matrix after processing (replacing elements by 0):" << endl;
    Print(a, rowCount, colCount);
    cout << "Sum elements = " << S << endl;
    cout << "Kilkist = " << k << endl;

    // Сортування матриці
    Sort(a, rowCount, colCount);
    cout << "\nMatrix after sorting columns:" << endl;
    Print(a, rowCount, colCount);

    // Звільнення пам’яті
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1); // Генерує випадкове число в межах [Low, High]
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            if (a[i][j] % 2 == 0 && (i + j) % 8 != 0) // Критерій: парний і сума індексів не кратна 8
            {
                S += a[i][j]; // Додаємо елемент до суми
                k++; // Збільшуємо кількість елементів
                a[i][j] = 0; // Замінюємо на 0
            }
        }
    }
}

void Sort(int** a, const int rowCount, const int colCount)
{
    // Перестановка стовпчиків
    for (int i0 = 0; i0 < colCount - 1; i0++)
        for (int i1 = 0; i1 < colCount - i0 - 1; i1++)
        {
            // Перевірка умов сортування
            if (
                (a[0][i1] < a[0][i1 + 1]) || // Перший рядок за спаданням
                (a[0][i1] == a[0][i1 + 1] && a[1][i1] > a[1][i1 + 1]) || // Другий рядок за зростанням
                (a[0][i1] == a[0][i1 + 1] && a[1][i1] == a[1][i1 + 1] && a[2][i1] > a[2][i1 + 1]) // Третій рядок за зростанням
                )
                ChangeColumns(a, i1, i1 + 1, rowCount); // Переставляємо стовпчики
        }
}

void ChangeColumns(int** a, const int col1, const int col2, const int rowCount)
{
    int tmp;
    for (int i = 0; i < rowCount; i++) // Проходимо по кожному рядку.
    {
        // Міняємо місцями значення у двох стовпчиках для кожного рядка.
        tmp = a[i][col1];
        a[i][col1] = a[i][col2];
        a[i][col2] = tmp;
    }
}
