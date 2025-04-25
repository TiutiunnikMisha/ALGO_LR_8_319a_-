#include "my_array.h"
#include <fstream>
#include <iostream>
using namespace std;

/*
 * Зчитує масив з файлу
 * Повертає true при успішному зчитуванні
 * Зберігає дані у in_mas та розмір у in_n
 */
bool get_mas(char* filename, int in_mas[N], int& in_n) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Error! Can't open file " << filename << endl;
        return false;
    }

    fin >> in_n;
    if (in_n > N) {
        cout << "Error! Array size exceeds maximum limit (" << N << ")" << endl;
        fin.close();
        return false;
    }

    for (int i = 0; i < in_n; i++) {
        fin >> in_mas[i];
    }

    fin.close();
    return true;
}

/*
 * Записує масив у файл array_out.txt
 * Формат: перший рядок - розмір, другий - елементи
 */
void write_mas(const int in_mas[N], const int n) {
    ofstream fout("array_out.txt");
    if (!fout.is_open()) {
        cout << "Error! Can't create output file" << endl;
        return;
    }

    fout << n << endl;
    for (int i = 0; i < n; i++) {
        fout << in_mas[i] << " ";
    }

    fout.close();
}

/*
 * Виводить масив на консоль
 * Елементи розділені пробілами
 */
void show_mas(const int in_mas[N], const int n) {
    for (int i = 0; i < n; i++) {
        cout << in_mas[i] << " ";
    }
    cout << endl;
}

/*
 * Шукає останній локальний максимум (елемент, більший за сусідів)
 * Повертає позицію (починаючи з 1) або -1, якщо не знайдено
 */
int findLastLocalMax(const int mas[N], int n) {
    for (int i = n - 2; i > 0; i--) {
        if (mas[i] > mas[i - 1] && mas[i] > mas[i + 1]) {
            return i + 1;
        }
    }
    return -1;
}

/*
 * Сортує масив символів у порядку спадання (від Z до A)
 * Використовує алгоритм сортування вибором
 */
void selectionSortDescending(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            swap(arr[i], arr[maxIdx]);
        }
    }
}

/*
 * Видаляє елемент з масиву за вказаним індексом
 * Зсуває всі наступні елементи на одну позицію вліво
 * Зменшує розмір масиву (n) на 1
 */
void remove_item(int mas[N], int& n, int index) {
    for (int i = index + 1; i < n; i++) {
        mas[i - 1] = mas[i];
    }
    n--;
}

/*
 * Виконує обробку масиву для завдання 1:
 * - знаходить останній локальний максимум
 * - виводить результат на консоль
 */
void processed_task_1(int mas[N], int& n) {
    int pos = findLastLocalMax(mas, n);
    if (pos != -1) {
        cout << "Last local maximum found at position: " << pos << endl;
        cout << "Value: " << mas[pos - 1] << endl;
    }
    else {
        cout << "No local maxima found in the array!" << endl;
    }
}
