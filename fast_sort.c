#include <stdio.h>
#define MASS_LEN 10
int input_array(int *n, int *array);
void output_array(int n, int *array);
void quicksort_array(int n, int *array);
void heapsort_array(int n, int *array);

int main() {
    int n, array[MASS_LEN];
    if (input_array(&n, array) == 0) {
        quicksort_array(n, array);
        output_array(n, array);
        heapsort_array(n, array);
        output_array(n, array);
        return 0;
    }
}

int input_array(int *n, int *array) {
    if (scanf("%d", n) != 1) {
        printf("n/a");
        return 1;
    }
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &array[i]) != 1) {
            printf("n/a");
            return 1;
        }
    }
    return 0;
}

void output_array(int n, int *array) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
}
void quicksort_array(int n, int *array) {
    int i = 0, j = n - 1, pivot = array[n / 2];
    do {
        while (array[i] < pivot) {
            i++;
        }
        while (array[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) {
        quicksort_array(j + 1, array);
    }
    if (i < n) {
        quicksort_array(n - i, &array[i]);
    }
}
void heapsort_array(int n, int *array) {
    int i, j, k, tmp;
    for (i = n / 2 - 1; i >= 0; i--) {
        k = i;
        tmp = array[i];
        for (; k * 2 + 1 < n; k = j) {
            j = k * 2 + 1;
            if (j + 1 < n && array[j] < array[j + 1]) {
                j++;
            }
            if (tmp < array[j]) {
                array[k] = array[j];
            } else {
                break;
            }
        }
        array[k] = tmp;
    }
    for (i = n - 1; i >= 0; i--) {
        tmp = array[0];
        array[0] = array[i];
        for (k = 0, j = 1; j < i; k = j, j = 2 * k + 1) {
            if (j + 1 < i && array[j] < array[j + 1]) {
                j++;
            }
            if (array[k] < array[j]) {
                tmp = array[k];
                array[k] = array[j];
                array[j] = tmp;
            } else {
                break;
            }
        }
        array[i] = tmp;
    }
}
