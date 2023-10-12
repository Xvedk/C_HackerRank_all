#include <stdio.h>

int main() {
    int num1, num2;
    float num3, num4;

    // Read two integers
    scanf("%d %d", &num1, &num2);

    // Read two floating-point numbers
    scanf("%f %f", &num3, &num4);

    // Calculate and print the sum and difference of integers
    int sum_int = num1 + num2;
    int diff_int = num1 - num2;
    printf("%d %d\n", sum_int, diff_int);

    // Calculate and print the sum and difference of floating-point numbers
    float sum_float = num3 + num4;
    float diff_float = num3 - num4;
    printf("%.1f %.1f\n", sum_float, diff_float);

    return 0;
}
