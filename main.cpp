#include <iostream>
#include <fstream>
#include "my_array.h"
#include "my_matrix.h"
using namespace std;

// Завдання 1 — обробка одновимірного масиву
void task1() {
    int mas[N];
    int size;
    char filename[100];

    cout << "Enter input filename for array (e.g., array_in.txt): ";
    cin.getline(filename, 100);

    // Зчитування масиву з файлу
    if (!get_mas(filename, mas, size)) {
        cerr << "Failed to process array from file" << endl;
        return;
    }

    cout << "Original array (" << size << " elements):" << endl;
    show_mas(mas, size);

    // Обробка масиву — пошук останнього локального максимуму
    processed_task_1(mas, size);
    write_mas(mas, size);

    cout << "Results saved to array_out.txt" << endl;
}

// Завдання 2 — обробка матриці
void task2() {
    int matr[M][N];
    int rows, cols;
    char filename[100];

    cout << "Enter input filename for matrix (e.g., matr_in.txt): ";
    cin.getline(filename, 100);

    // Зчитування матриці з файлу
    if (!get_matr(filename, matr, rows, cols)) {
        cerr << "Failed to process matrix from file" << endl;
        return;
    }

    cout << "Matrix (" << rows << "x" << cols << "):" << endl;
    show_matr(matr, rows, cols);

    // Обробка матриці — мінімум серед максимумів стовпців
    int result = processed_task_2(matr, rows, cols);
    cout << "Min of column maximums: " << result << endl;

    write_result_task_2(filename, result);
    cout << "Result appended to input file" << endl;
}

// Завдання 3 — сортування масиву символів
void task3() {
    char arr[N];
    int n;
    char inputFilename[100];

    cout << "Enter input filename for sorting (e.g., sort_in.txt): ";
    cin.getline(inputFilename, 100);

    ifstream fin(inputFilename);
    if (!fin.is_open()) {
        cerr << "Error opening input file: " << inputFilename << endl;
        return;
    }

    fin >> n;
    if (n <= 0 || n > N) {
        cerr << "Invalid array size in file" << endl;
        fin.close();
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (!(fin >> arr[i])) {
            cerr << "Error reading array element at index " << i << endl;
            fin.close();
            return;
        }
    }
    fin.close();

    // Сортування символів у спадному порядку
    selectionSortDescending(arr, n);

    ofstream fout("array_out.txt");
    if (!fout.is_open()) {
        cerr << "Error creating output file" << endl;
        return;
    }

    fout << n << endl;
    for (int i = 0; i < n; ++i) {
        fout << arr[i] << " ";
    }
    fout.close();

    cout << "Sorted array saved to array_out.txt" << endl;
}

// Головне меню програми
int main() {
    int choice;
    do {
        cout << "\n=== Main Menu ===" << endl;
        cout << "1. Task 1 - Process 1D array" << endl;
        cout << "2. Task 2 - Process matrix" << endl;
        cout << "3. Task 3 - Sort array" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищення буфера після вводу

        switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
