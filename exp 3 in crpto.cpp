#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keyMatrix[5][5] = {
    {'M','O','N','A','R'},
    {'C','H','Y','B','D'},
    {'E','F','G','I','K'},
    {'L','P','Q','S','T'},
    {'U','V','W','X','Z'}
};

void findPosition(char ch, int *row, int *col) {
    if (ch == 'J')
        ch = 'I';

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (keyMatrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

int main() {
    char text[100];
    int r1, c1, r2, c2;

    printf("Enter plaintext (uppercase, even number of letters): ");
    scanf("%s", text);

    printf("Ciphertext: ");

    for (int i = 0; i < strlen(text); i += 2) {
        findPosition(toupper(text[i]), &r1, &c1);
        findPosition(toupper(text[i + 1]), &r2, &c2);

        if (r1 == r2) {
            printf("%c%c",
                keyMatrix[r1][(c1 + 1) % 5],
                keyMatrix[r2][(c2 + 1) % 5]);
        }
        else if (c1 == c2) {
            printf("%c%c",
                keyMatrix[(r1 + 1) % 5][c1],
                keyMatrix[(r2 + 1) % 5][c2]);
        }
        else {
            printf("%c%c",
                keyMatrix[r1][c2],
                keyMatrix[r2][c1]);
        }
    }

    return 0;
}
