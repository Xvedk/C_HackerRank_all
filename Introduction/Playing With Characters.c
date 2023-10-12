#include <stdio.h>

int main() {
    char ch;
    char str[100];
    char sentence[100];

    // Read a character
    scanf(" %c", &ch);

    // Read a string
    scanf("%s", str);

    // Clear the newline character from the input buffer
    scanf("\n");

    // Read a sentence
    scanf("%[^\n]%*c", sentence);

    // Print the character, string, and sentence
    printf("%c\n", ch);
    printf("%s\n", str);
    printf("%s\n", sentence);

    return 0;
}
