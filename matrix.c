#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int input_type();
void first_type_matrix_input();
void second_type_matrix_input();
void third_type_matrix_input();
void fourth_type_matrix_input();


void input_matrix(int rows, int cols, int matrix[MAX_LENGTH][MAX_LENGTH]);
void output_matrix(int rows, int cols, int matrix[MAX_LENGTH][MAX_LENGTH]);

int main() {
    switch (input_type()) {
        case 1: first_type_matrix_input(); break;
        case 2: second_type_matrix_input(); break;
        case 3: third_type_matrix_input(); break;
        case 4: fourth_type_matrix_input(); break;
        default: printf("n/a"); break;
    }
    return 0;
}

int input_type() {
    int type;
    printf("Choose memory allocation type (1-4): ");
    if (scanf("%d", &type) != 1)  return 0;
    return type;
}

void first_type_matrix_input() {
    int rows, cols;
    int matrix[MAX_LENGTH][MAX_LENGTH]; 
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0 || rows > MAX_LENGTH || cols > MAX_LENGTH) {
        printf("n/a");
        return;
    }
    input_matrix(rows, cols, matrix);
    output_matrix(rows, cols, matrix);
}

void second_type_matrix_input() {
    int rows, cols;
    int *matrix;

    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
        printf("n/a");
        return;
    }

    matrix = malloc(rows * cols * sizeof(int));
    if (!matrix) {
        printf("n/a");
        return;
    }
    for (int i = 0; i < rows * cols; i++) {
        if (scanf("%d", &matrix[i]) != 1) {
            printf("n/a");
            free(matrix);
            return;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d", matrix[i * cols + j]);
            if (j < cols - 1) printf(" ");
        }
        if (i < rows - 1) printf("\n");
    }

    free(matrix);
}

void third_type_matrix_input() {
    int rows, cols;
    int **matrix;
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
        printf("n/a");
        return;
    }

    matrix = malloc(rows * sizeof(int *));
    if (!matrix) {
        printf("n/a");
        return;
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = calloc(cols, sizeof(int));
        if (!matrix[i]) {
            printf("n/a");
            for (int j = 0; j < i; j++) free(matrix[j]);
            free(matrix);
            return;
        }
    }

    // Ввод элементов матрицы
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("n/a");
                for (int k = 0; k < rows; k++) free(matrix[k]);
                free(matrix);
                return;
            }
        }
    }

    // Вывод матрицы
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d", matrix[i][j]);
            if (j < cols - 1) printf(" ");
        }
        if (i < rows - 1) printf("\n");
    }

    for (int i = 0; i < rows; i++) free(matrix[i]); // Освобождение памяти
    free(matrix);
}

// 4. Другой способ динамического выделения (пример — массив указателей)
void fourth_type_matrix_input() {
    int rows, cols;
    int *matrix[MAX_LENGTH];

    // Ввод размеров матрицы
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0 || rows > MAX_LENGTH) {
        printf("n/a");
        return;
    }

    // Выделение памяти
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (!matrix[i]) {
            printf("n/a");
            for (int j = 0; j < i; j++) free(matrix[j]);
            return;
        }
    }

    // Ввод и вывод элементов
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("n/a");
                for (int k = 0; k < rows; k++) free(matrix[k]);
                return;
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d", matrix[i][j]);
            if (j < cols - 1) printf(" ");
        }
        if (i < rows - 1) printf("\n");
    }

    for (int i = 0; i < rows; i++) free(matrix[i]); // Освобождение памяти
}

// Универсальные функции для статической матрицы
void input_matrix(int rows, int cols, int matrix[MAX_LENGTH][MAX_LENGTH]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("n/a");
                return;
            }
        }
    }
}

void output_matrix(int rows, int cols, int matrix[MAX_LENGTH][MAX_LENGTH]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d", matrix[i][j]);
            if (j < cols - 1) printf(" ");
        }
        if (i < rows - 1) printf("\n");
    }
}