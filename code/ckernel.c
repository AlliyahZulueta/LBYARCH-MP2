#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void compute_distances_c(int n, double *x1, double *x2, double *y1, double *y2, double *z) {
    for (int i = 0; i < n; i++) {
        z[i] = sqrt((x2[i] - x1[i]) * (x2[i] - x1[i]) + (y2[i] - y1[i]) * (y2[i] - y1[i]));
    }
}

int main() {
   
    return 0;
}
