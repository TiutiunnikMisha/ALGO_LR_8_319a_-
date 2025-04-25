#pragma once
#ifndef MY_ARRAY_H
#define MY_ARRAY_H

#include "config.h" // Максимальний розмір масиву

/* Функція для зчитування масиву з файлу */
bool get_mas(char* filename, int in_mas[N], int& in_n);

/* Функція для запису масиву у файл */
void write_mas(const int in_mas[N], const int n);

/* Функція для виведення масиву на консоль */
void show_mas(const int in_mas[N], const int n);

/* Функція для знаходження останнього локального максимуму */
int findLastLocalMax(const int mas[N], int n);

/* Функція для сортування масиву символів у порядку спадання */
void selectionSortDescending(char arr[], int n);

/* Функція для видалення елементу з масиву за індексом */
void remove_item(int mas[N], int& n, int index);

/* Функція для обробки завдання 1 (пошук останнього локального максимуму) */
void processed_task_1(int mas[N], int& n);

#endif // MY_ARRAY_H
