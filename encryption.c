void encryptFile(const char *filename, const char *key) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char outputFilename[100];
    snprintf(outputFilename, sizeof(outputFilename), "%s.enc", filename);

    FILE *outputFile = fopen(outputFilename, "wb");
    if (outputFile == NULL) {
        perror("Error creating output file");
        fclose(file);
        return;
    }

    int keyLength = strlen(key);
    if (keyLength == 0) {
        printf("Encryption key cannot be empty!\n");
        fclose(file);
        fclose(outputFile);
        return;
    }

    int ch, i = 0;
    while ((ch = fgetc(file)) != EOF) {
        fputc(ch ^ key[i % keyLength], outputFile);
        i++;
    }

    fclose(file);
    fclose(outputFile);

    printf("File encrypted successfully! Output file: %s\n", outputFilename);
}

void decryptFile(const char *filename, const char *key) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char outputFilename[100];
    snprintf(outputFilename, sizeof(outputFilename), "%s.dec", filename);

    FILE *outputFile = fopen(outputFilename, "wb");
    if (outputFile == NULL) {
        perror("Error creating output file");
        fclose(file);
        return;
    }

    int keyLength = strlen(key);
    if (keyLength == 0) {
        printf("Decryption key cannot be empty!\n");
        fclose(file);
        fclose(outputFile);
        return;
    }

    int ch, i = 0;
    while ((ch = fgetc(file)) != EOF) {
        fputc(ch ^ key[i % keyLength], outputFile);
        i++;
    }

    fclose(file);
    fclose(outputFile);

    printf("File decrypted successfully! Output file: %s\n", outputFilename);
}
