#include <stdio.h>
#define MASS_LEN 10
int input_array(int *array);
void output_array(int *array);
void quicksort_array(int *array, int left, int right);
void heapsort_array(int *array);
void heapify(int *array, int n, int i);

int main() {
    int array[MASS_LEN];
    if (input_array(array) == 0) {
        quicksort_array(array, 0, MASS_LEN - 1);
        output_array(array);
        heapsort_array(array);
        output_array(array);
        return 0;
    }
}

int input_array(int *array) {
    for (int i = 0; i < MASS_LEN; i++) {
        if (scanf("%d", &array[i]) != 1) {
            printf("n/a");
            return 1;
        }
    }
    return 0;
}

void output_array(int *array) {
    for (int i = 0; i < MASS_LEN; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
void quicksort_array(int *array, int left, int right) {
    if (left < right) {
        int i = left, j = right;
        int pivot = array[(left + right) / 2];
        do {
            while (array[i] < pivot) {
                i++;
            }
            while (array[j] > pivot) {
                j--;
            }
            if (i <= j) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
            }
        } while (i <= j);

        // Рекурсивно сортируем левую и правую части
        if (left < j) {
            quicksort_array(array, left, j);
        }
        if (i < right) {
            quicksort_array(array, i, right);
        }
    }
}
void heapsort_array(int *array) {
    int n = MASS_LEN;
    
    // Построение кучи
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(array, n, i);
    }

    // Извлечение элементов из кучи
    for (int i = n - 1; i > 0; i--) {
        // Меняем корень (максимальный элемент) с последним элементом
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        // Восстанавливаем кучу для оставшихся элементов
        heapify(array, i, 0);
    }
}

void heapify(int *array, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Если левый дочерний элемент больше корня
    if (left < n && array[left] > array[largest]) {
        largest = left;
    }

    // Если правый дочерний элемент больше самого большого элемента
    if (right < n && array[right] > array[largest]) {
        largest = right;
    }

    // Если самый большой элемент не корень
    if (largest != i) {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;

        // Рекурсивно восстанавливаем кучу для затронутого поддерева
        heapify(array, n, largest);
    }
}
