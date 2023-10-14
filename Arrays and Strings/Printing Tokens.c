#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000]; // Assuming a sentence with a maximum length of 1000 characters
    fgets(sentence, sizeof(sentence), stdin);

    // Replace the newline character at the end with a null character
    if (sentence[strlen(sentence) - 1] == '\n') {
        sentence[strlen(sentence) - 1] = '\0';
    }

    char *token = strtok(sentence, " "); // Split the sentence into words using space as a delimiter

    while (token != NULL) {
        printf("%s\n", token); // Print each word on a new line
        token = strtok(NULL, " "); // Get the next word
    }

    return 0;
}
