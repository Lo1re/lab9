#include <stdio.h>
#include <stdlib.h>

int totalsum(int** arr, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        int size = arr[i][0];
        for (int j = 1; j <= size; j++) {
            total += arr[i][j];
        }
    }
    return total;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: program_name n size1 elem1_1 elem1_2 ... size2 elem2_1 ...\n");
        return 1;
    }

    int n = atoi(argv[1]);  
    if (n <= 0 || n > 4) {
        printf("Wrong input data\n");
        return 1;
    }

    int* array[4];
    int argIndex = 2; 

    for (int i = 0; i < n; i++) {
        if (argIndex >= argc) {
            printf("Not enough arguments for array %d\n", i + 1);
            return 1;
        }

        int size = atoi(argv[argIndex]);
        argIndex++;

        array[i] = (int*)malloc((size + 1) * sizeof(int));
        if (!array[i]) {
            printf("Memory error\n");
            return 1;
        }

        array[i][0] = size;

        for (int j = 1; j <= size; j++) {
            if (argIndex >= argc) {
                printf("Not enough elements for array %d\n", i + 1);
                return 1;
            }
            array[i][j] = atoi(argv[argIndex]);
            argIndex++;
        }
    }

    printf("\nYour arrays:\n");
    for (int i = 0; i < n; i++) {
        int size = array[i][0];
        printf("Array %d: ", i + 1);
        for (int j = 1; j <= size; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    int total = totalsum(array, n);
    printf("\nSum of all elements: %d\n", total);

    // Звільнення пам'яті
    for (int i = 0; i < n; i++) {
        free(array[i]);
    }
	getchar();
    return 0;
}
