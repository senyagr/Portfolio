#include <stdio.h>

int ValidateInputElement();
int ValidateInput();


void InputMatrix(int matrix[10][10], int size) {
    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = ValidateInputElement();
        }
    }
}

void OutOldMatrix(int matrix[10][10], int size) {
    printf("Исходная матрица:\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void OutMatrix(int matrix[10][10], int size) {
    printf("Вывод матрицы:\n");
    int size_x = size;
    int size_y = size;
    int start_x = 0;
    int start_y = 0;

    while (size_x > 0 && size_y > 0) {
        // Вывод нижней строки
        for (int j = start_x; j < start_x + size_x; ++j) {
            printf("%d ", matrix[start_y + size_y - 1][j]);
        }
        // Вывод правого столбца
        for (int j = start_y + size_y - 2; j >= start_y; --j) {
            printf("%d ", matrix[j][start_x + size_x - 1]);
        }
        // Вывод верхней строки
        for (int j = start_x + size_x - 2; j >= start_x; --j) {
            printf("%d ", matrix[start_y][j]);
        }
        // Вывод левого столбца
        for (int j = start_y + 1; j < start_y + size_y - 1; ++j) {
            printf("%d ", matrix[j][start_x]);
        }
        size_x -= 2;
        size_y -= 2;
        start_x++;
        start_y++;
    }
}

int main() {
    system("chcp 65001"); // UTF-8, чтоб кириллицу выводило

    int size;
    size = ValidateInput();

    int matrix[10][10] = {0};

    InputMatrix(matrix, size);
    OutOldMatrix(matrix, size);
    OutMatrix(matrix, size);

    return 0;
}

// Проверка размера
int ValidateInput() {
    double input = 0;
    char extra;

    printf("Введите размер матрицы: ");

    // Проверяю наличие лишних символов
    if (scanf("%lf%c", &input, &extra) != 2 || extra != '\n') {
        printf("Ошибка ввода! Введено некорректное значение.\n");
        while (getchar() != '\n'); // Очистка потока ввода
        return ValidateInput();
    }

    // Проверка, является ли число целым
    if (input != (int)input) {
        printf("Ошибка ввода! Число должно быть целым.\n");
        return ValidateInput();
    }

    // Проверка диапазона
    if (input < 2 || input > 9) {
        printf("Ошибка ввода! Число должно быть от 2 до 9.\n");
        return ValidateInput();
    }

    return (int)input; // Возвращаем целое число
}

// Проверка элементов
int ValidateInputElement() {
    double input = 0;
    char extra;

    // Проверяю наличие лишних символов
    if (scanf("%lf%c", &input, &extra) != 2 || extra != '\n') {
        printf("Ошибка ввода! Введено некорректное значение. Введите заново.\n");
        while (getchar() != '\n'); // Очистка потока ввода
        return ValidateInputElement();
    }

    // Проверка, является ли число целым
    if (input != (int)input) {
        printf("Ошибка ввода! Число должно быть целым.Введите заново.\n");
        return ValidateInputElement();
    }

    return (int)input; // Возвращаем целое число
}
