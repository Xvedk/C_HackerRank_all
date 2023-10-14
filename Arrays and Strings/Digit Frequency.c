#include <stdio.h>
#include <string.h>

int main() {
    char num[1000]; // Assuming a string with a maximum length of 1000 characters
    fgets(num, sizeof(num), stdin);

    int digitCount[10] = {0}; // Initialize an array to count the frequency of each digit

    for (int i = 0; i < strlen(num); i++) {
        if (num[i] >= '0' && num[i] <= '9') {
            // If the character is a digit, increment the corresponding count
            digitCount[num[i] - '0']++;
        }
    }

    // Print the frequency of each digit
    for (int i = 0; i < 10; i++) {
        printf("%d ", digitCount[i]);
    }

    return 0;
}
