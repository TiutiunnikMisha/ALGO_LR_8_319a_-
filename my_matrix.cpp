#include "my_matrix.h"
#include <fstream>
#include <iostream>
#include <climits>
using namespace std;

/*
 * Зчитує матрицю з вказаного файлу
 * Формат файлу: перші два числа - розміри, потім елементи по рядках
 */
bool get_matr(char* filename, int in_matr[M][N], int& in_m, int& in_n) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return false;
    }

    fin >> in_m >> in_n;
    if (in_m <= 0 || in_m > M || in_n <= 0 || in_n > N) {
        cerr << "Invalid matrix dimensions in file" << endl;
        fin.close();
        return false;
    }

    for (int i = 0; i < in_m; ++i) {
        for (int j = 0; j < in_n; ++j) {
            if (!(fin >> in_matr[i][j])) {
                cerr << "Error reading matrix element at (" << i << "," << j << ")" << endl;
                fin.close();
                return false;
            }
        }
    }

    fin.close();
    return true;
}

/*
 * Дописує результат обчислень у кінець вхідного файлу
 */
void write_result_task_2(char* filename, int res) {
    ofstream fout(filename, ios::app);
    if (!fout.is_open()) {
        cerr << "Error opening file for appending: " << filename << endl;
        return;
    }
    fout << "\nResult: " << res << endl;
    fout.close();
}

/*
 * Виводить матрицю на консоль у вигляді таблиці
 */
void show_matr(const int matr[M][N], const int m, const int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matr[i][j] << "\t";
        }
        cout << endl;
    }
}

/*
 * Знаходить мінімальний серед максимальних елементів стовпців
 */
int findMinOfColumnMaxs(const int matr[M][N], const int m, const int n) {
    int minOfMax = INT_MAX;

    for (int j = 0; j < n; ++j) {
        int colMax = matr[0][j];
        for (int i = 1; i < m; ++i) {
            if (matr[i][j] > colMax) {
                colMax = matr[i][j];
            }
        }
        if (colMax < minOfMax) {
            minOfMax = colMax;
        }
    }

    return minOfMax;
}

/*
 * Обробка завдання 2 - знаходження мінімального серед максимумів стовпців
 */
int processed_task_2(const int matr[M][N], const int m, const int n) {
    return findMinOfColumnMaxs(matr, m, n);
}
