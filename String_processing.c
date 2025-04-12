#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Функция сортировки пузырьком для сортировки слов в алфавитном порядке
void sortWords(char words[30][11], int wordCount) {
    char temp[11]; // переменная для обмена

    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = 0; j < wordCount - i - 1; j++) {
            if (strcmp(words[j], words[j + 1]) > 0) {
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp); // Обмен местами слов
            }
        }
    }
}

int main() {
    char input[331];          // для ввода строки
    char words[30][11];            // Массив для хранения слов (макс 30 слов, каждое до 10 символов)
    int wordCount = 0;             // Количество слов
    int valid = 0;                 // Флаг корректного ввода

    do { // Цикл до получения корректного ввода
        printf("String:\n");

        wordCount = 0;

        fgets(input, sizeof(input), stdin); //stdin - для чтения из станд ввода

        // Находим позицию первой точки и обрезаем строку
        char *dot = strchr(input, '.');
        if (dot!=NULL) {
            *dot = '\0';
        }

        // Удаление всех пробелов из строки
        int i, j;
        for (i = j = 0; input[i] != '\0'; i++) {
            if (input[i] != ' ') {
                input[j++] = input[i];
            }
        }
        input[j] = '\0';

        // Вывод изначальной строки после удаления всех пробелов
        printf("\nOriginal string after removing spaces:\n%s\n", input);

        // Проверка на наличие ",," или запятой в начале строки
        if (strstr(input, ",,") != NULL || (input[0] == ',' && strlen(input) > 0)) {
            printf("No empty words! Try again.\n");
            valid = 0;
            continue; // Повторный ввод
        }

        // Проверка наличия хотя бы одного слова (после обрезки точки и удаления пробелов)
        if (strlen(input) == 0) {
            printf("Empty\n");
            valid = 0;
            continue;
        }

        // Проверка на допустимые символы (только буквы, цифры, запятые)
        int invalid = 0;
        for (i = 0; i < (int)strlen(input); i++) {
            if (!isalnum(input[i]) && input[i] != ',') {
                printf("Wrong symbol! Try again.\n");
                invalid = 1;
                break;
            }
        }
        if (invalid) {
            continue; // Повторный ввод
        }
        // Разделяем строку на слова по запятым
        char *token = strtok(input, ",");
        while (token != NULL) {

            // проверка длины
            if (strlen(token) > 10) {
                printf("Too many symbols! (Maximum word length is 10)\n");
                invalid = 1;
                break;
            }

            // Проверка количества слов
            if (wordCount >= 30) {
                printf("Error: Too many words. Try again.\n");
                invalid = 1;
                break;
            }

            // Копируем слово в массив
            strcpy(words[wordCount], token);
            wordCount++;

            token = strtok(NULL, ",");
        }

        if (invalid) {
            continue; // Повторный ввод
        }

        // Сортировка слов пузырьковой сортировкой
        sortWords(words, wordCount);

        // Вывод отсортированных слов
        printf("\nSorted words in alphabetical order:\n");
        for (int i = 0; i < wordCount; i++) {
            printf("%s\n", words[i]);
        }

        valid = 1; // Корректный ввод, выход из цикла
    } while(!valid);


    return 0;
}
