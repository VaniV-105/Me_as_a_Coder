#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100  // Maximum number of words
#define MAX_LENGTH 50  // Maximum length of each word

int main() {
    char words[MAX_WORDS][MAX_LENGTH]; // Array of strings to store words
    int numWords;

    printf("Enter the number of words: ");
    scanf("%d", &numWords);

    // Clear the input buffer
    while (getchar() != '\n');

    printf("Enter %d words:\n", numWords);
    for (int i = 0; i < numWords; ++i) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", words[i]);
    }

    printf("Entered words are:\n");
    for (int i = 0; i < numWords; ++i) {
        printf("%d: %s\n", i + 1, words[i]);
    }

    return 0;
}
