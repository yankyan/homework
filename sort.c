#include <stdio.h>
#define MASS_LEN 10
int input_array(int *n, int *array);
void output_array(int n, int *array);
void sort_array(int n, int *array);

int main() {
    int n, array[MASS_LEN];
    if (input_array(&n, array) == 0) {
        sort_array(n, array);
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

void sort_array(int n, int *array) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
