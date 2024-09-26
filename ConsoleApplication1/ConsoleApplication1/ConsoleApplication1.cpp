#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;


// Функция для генерации случайной матрицы стоимостей
void generate_matrix(int** matrix, int num_cities) {
    srand(time(0));
    for (int i = 0; i < num_cities; ++i) {
        for (int j = i + 1; j < num_cities; ++j) {
            matrix[i][j] = matrix[j][i] = rand() % 100 + 1;
        }
    }
}

// Функция для вычисления общей стоимости маршрута
int calculate_total_cost(int** matrix, int* route, int num_cities) {
    int total_cost = 0;
    for (int i = 0; i < num_cities - 1; ++i) {
        total_cost += matrix[route[i]][route[i + 1]];
    }
    total_cost += matrix[route[num_cities - 1]][route[0]]; // Возврат в начальный город
    return total_cost;
}
