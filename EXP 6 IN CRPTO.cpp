#include <stdio.h>

int modInverse(int a, int m) {
    int x;
    for (x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

int main() {
    char cipher[100];
    int i;

    // Keys obtained from frequency analysis
    int a = 3;
    int b = 15;

    int a_inv = modInverse(a, 26);

    printf("Enter Ciphertext (uppercase): ");
    scanf("%s", cipher);

    printf("Plaintext: ");

    for (i = 0; cipher[i] != '\0'; i++) {
        if (cipher[i] >= 'A' && cipher[i] <= 'Z') {
            int c = cipher[i] - 'A';
            int p = (a_inv * (c - b + 26)) % 26;
            printf("%c", p + 'A');
        } else {
            printf("%c", cipher[i]);
        }
    }

    return 0;
}
