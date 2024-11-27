#include <stdio.h>

extern double compute_distance(double x1, double x2, double y1, double y2);

int main() {
    double x1[] = {4.0, 6.0};
    double x2[] = {2.0, 3.0};
    double y1[] = {3.0, 5.0};
    double y2[] = {1.0, 4.0};
    double results[2];
    int i;


    for (i = 0; i < 2; i++) {
        results[i] = compute_distance(x1[i], x2[i], y1[i], y2[i]);
        printf("Distance[%d]: %f\n", i, results[i]);
    }

    return 0;
}
