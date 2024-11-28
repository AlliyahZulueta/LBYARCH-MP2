#include <stdio.h>

extern double compute_distance(double x1, double x2, double y1, double y2);

void compute_distances_c(int n, double *x1, double *x2, double *y1, double *y2, double *z) {
    for (int i = 0; i < n; i++) {
        z[i] = sqrt((x2[i] - x1[i]) * (x2[i] - x1[i]) + (y2[i] - y1[i]) * (y2[i] - y1[i]));
    }
}

int main() {
    int runs = 30; 
    
    float n;
    double *x1 = (double *)malloc(n * sizeof(double));
    double *x2 = (double *)malloc(n * sizeof(double));
    double *y1 = (double *)malloc(n * sizeof(double));
    double *y2 = (double *)malloc(n * sizeof(double));
    double *z = (double *)malloc(n * sizeof(double));
    
    clock_t start, end;
    float cresult = 0.0f;
	int i;
    
    // Time the C kernel
    start = clock();
    for ( i = 0; i < runs; i++)
	{
        cresult = compute_distance_c(n, x1, x2, y1, y2, z);
    }
    end = clock();
    double ctime = (double) (end - start) / CLOCKS_PER_SEC/ runs;
    printf("C Average distance Time: %f (secs) \n", ctime);

 
    double x1[] = {4.0, 6.0};
    double x2[] = {2.0, 3.0};
    double y1[] = {3.0, 5.0};
    double y2[] = {1.0, 4.0};
    double results[2];

    start = clock();
    int i;
    for (i = 0; i < 2; i++) {
        results[i] = compute_distance(x1[i], x2[i], y1[i], y2[i]);
        printf("Distance[%d]: %f\n", i, results[i]);
    }
    end = clock();
    doube time = (double) (end - start) / CLOCKS_PER_SEC/runs;
    printf("ASM Average distance Time: %f (secs)\n", ctime);

    return 0;
}
