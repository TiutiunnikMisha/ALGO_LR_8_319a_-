#pragma once
#ifndef MY_MATRIX_H
#define MY_MATRIX_H

#include "config.h" // Максимальна кількість стовпців
#include "config.h" // Максимальна кількість рядків

// Функція для зчитування матриці з файлу
bool get_matr(char* filename, int in_matr[M][N], int& in_m, int& in_n);

// Функція для запису результату в кінець файлу
void write_result_task_2(char* filename, int res);

// Функція для виводу матриці на консоль
void show_matr(const int matr[M][N], const int m, const int n);

// Функція для обробки матриці (мінімум серед максимумів стовпців)
int processed_task_2(const int matr[M][N], const int m, const int n);

#endif // MY_MATRIX_H
