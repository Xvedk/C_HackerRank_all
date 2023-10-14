#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*)malloc(num * sizeof(int));
    for (i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }

    // Reverse the array
    int start = 0;
    int end = num - 1;
    while (start < end) {
        // Swap elements from the beginning and end of the array
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    // Print the reversed array
    for (i = 0; i < num; i++)
        printf("%d ", *(arr + i));

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
