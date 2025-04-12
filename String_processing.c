#include <stdio.h>
#include <string.h>
#include <ctype.h>

// ������� ���������� ��������� ��� ���������� ���� � ���������� �������
void sortWords(char words[30][11], int wordCount) {
    char temp[11]; // ���������� ��� ������

    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = 0; j < wordCount - i - 1; j++) {
            if (strcmp(words[j], words[j + 1]) > 0) {
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp); // ����� ������� ����
            }
        }
    }
}

int main() {
    char input[331];          // ��� ����� ������
    char words[30][11];            // ������ ��� �������� ���� (���� 30 ����, ������ �� 10 ��������)
    int wordCount = 0;             // ���������� ����
    int valid = 0;                 // ���� ����������� �����

    do { // ���� �� ��������� ����������� �����
        printf("String:\n");

        wordCount = 0;

        fgets(input, sizeof(input), stdin); //stdin - ��� ������ �� ����� �����

        // ������� ������� ������ ����� � �������� ������
        char *dot = strchr(input, '.');
        if (dot!=NULL) {
            *dot = '\0';
        }

        // �������� ���� �������� �� ������
        int i, j;
        for (i = j = 0; input[i] != '\0'; i++) {
            if (input[i] != ' ') {
                input[j++] = input[i];
            }
        }
        input[j] = '\0';

        // ����� ����������� ������ ����� �������� ���� ��������
        printf("\nOriginal string after removing spaces:\n%s\n", input);

        // �������� �� ������� ",," ��� ������� � ������ ������
        if (strstr(input, ",,") != NULL || (input[0] == ',' && strlen(input) > 0)) {
            printf("No empty words! Try again.\n");
            valid = 0;
            continue; // ��������� ����
        }

        // �������� ������� ���� �� ������ ����� (����� ������� ����� � �������� ��������)
        if (strlen(input) == 0) {
            printf("Empty\n");
            valid = 0;
            continue;
        }

        // �������� �� ���������� ������� (������ �����, �����, �������)
        int invalid = 0;
        for (i = 0; i < (int)strlen(input); i++) {
            if (!isalnum(input[i]) && input[i] != ',') {
                printf("Wrong symbol! Try again.\n");
                invalid = 1;
                break;
            }
        }
        if (invalid) {
            continue; // ��������� ����
        }
        // ��������� ������ �� ����� �� �������
        char *token = strtok(input, ",");
        while (token != NULL) {

            // �������� �����
            if (strlen(token) > 10) {
                printf("Too many symbols! (Maximum word length is 10)\n");
                invalid = 1;
                break;
            }

            // �������� ���������� ����
            if (wordCount >= 30) {
                printf("Error: Too many words. Try again.\n");
                invalid = 1;
                break;
            }

            // �������� ����� � ������
            strcpy(words[wordCount], token);
            wordCount++;

            token = strtok(NULL, ",");
        }

        if (invalid) {
            continue; // ��������� ����
        }

        // ���������� ���� ����������� �����������
        sortWords(words, wordCount);

        // ����� ��������������� ����
        printf("\nSorted words in alphabetical order:\n");
        for (int i = 0; i < wordCount; i++) {
            printf("%s\n", words[i]);
        }

        valid = 1; // ���������� ����, ����� �� �����
    } while(!valid);


    return 0;
}
