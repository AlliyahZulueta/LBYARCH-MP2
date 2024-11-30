#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// External Assembly kernel function
extern double compute_distance(double x1, double x2, double y1, double y2);

// C kernel function
void compute_distances_c(int n, double *x1, double *x2, double *y1, double *y2, double *z) {
    for (int i = 0; i < n; i++) {
        z[i] = sqrt((x2[i] - x1[i]) * (x2[i] - x1[i]) + (y2[i] - y1[i]) * (y2[i] - y1[i]));
    }
}

int main() {
    int runs = 30;
    int sizes[] = {1 << 20, 1 << 24, 1 << 28};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int size_idx = 0; size_idx < num_sizes; size_idx++) {
        int n = sizes[size_idx];

        double *x1 = (double *)malloc(n * sizeof(double));
        double *x2 = (double *)malloc(n * sizeof(double));
        double *y1 = (double *)malloc(n * sizeof(double));
        double *y2 = (double *)malloc(n * sizeof(double));
        double *z = (double *)malloc(n * sizeof(double));
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            x1[i] = (double)(rand() % 100) / 10.0;
            x2[i] = (double)(rand() % 100) / 10.0;
            y1[i] = (double)(rand() % 100) / 10.0;
            y2[i] = (double)(rand() % 100) / 10.0;
        }

        // Timing for C kernel
        clock_t start, end;
        double ctime = 0.0;
        for (int i = 0; i < runs; i++) {
            start = clock();
            compute_distances_c(n, x1, x2, y1, y2, z);
            end = clock();
            ctime += (double)(end - start) / CLOCKS_PER_SEC;
        }
        ctime /= runs;


        printf("\n--- Vector Size: 2^%d (n = %d) ---\n", (int)(log2(n)), n);
        printf("x1 x2 y1 y2 (First 10 Elements):\n");
        for (int i = 0; i < 10; i++) {
            printf("x1[%d] = %f x2[%d] = %f y1[%d] = %f y2[%d] = %f\n",
                   i, x1[i], i, x2[i], i, y1[i], i, y2[i]);
        }

        printf("C Kernel Results (First 10 Elements):\n");
        for (int i = 0; i < 10; i++) {
            printf("Z[%d] = %f\n", i, z[i]);
        }
        printf("C Kernel Average Time: %f seconds\n", ctime);

        // Timing for Assembly kernel
        double atime = 0.0;
        for (int i = 0; i < runs; i++) {
            start = clock();
            for (int j = 0; j < n; j++) {
                z[j] = compute_distance(x1[j], x2[j], y1[j], y2[j]);
            }
            end = clock();
            atime += (double)(end - start) / CLOCKS_PER_SEC;
        }
        atime /= runs;


        printf("\nASM Kernel Results (First 10 Elements):\n");
        for (int i = 0; i < 10; i++) {
            printf("Z[%d] = %f\n", i, z[i]);
        }
        printf("ASM Kernel Average Time: %f seconds\n", atime);

        // Free allocated memory
        free(x1);
        free(x2);
        free(y1);
        free(y2);
        free(z);
    }

    return 0;
}
