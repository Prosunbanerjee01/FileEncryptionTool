#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encryption.h"

int main() {
    int choice;
    char filename[100], key[100];

    while (1) {
        printf("\n--- File Encryption Tool ---\n");
        printf("1. Encrypt File\n");
        printf("2. Decrypt File\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the filename to encrypt: ");
                scanf("%s", filename);
                printf("Enter the encryption key: ");
                scanf("%s", key);
                encryptFile(filename, key);
                break;
            case 2:
                printf("Enter the filename to decrypt: ");
                scanf("%s", filename);
                printf("Enter the decryption key: ");
                scanf("%s", key);
                decryptFile(filename, key);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
