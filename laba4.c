#include <stdio.h>
#include <stdlib.h> //Для использования функций динамического распределения памяти

int ValidateInput();
double ValidateInputElement();

double* NewArray(int size) {
    double* array = malloc(size * sizeof(double)); //Выделения памяти, array - начальный адрес
    if (array == NULL) {
        printf("Ошибка!");
        exit(1);
    }
    printf("Введите элементы массива:\n");
    for (int i = 0; i < size; i++) {
        array[i] = ValidateInputElement();
    }

    return array;
}

void Output(double* array, int size) {
    printf("Массив: ");
    for (int i = 0; i < size; i++) {
        printf("%lf ", array[i]);
    }
    printf("\n");
}

void Delete(double** array, int* size) {   // Ук на ук, чтобы изменить ук на массив внутри функции, те *array станет ук
    double a, b;
    printf("Введите числа a и b (для задания отрезка [a; b]):\n");
    a = ValidateInputElement();
    b = ValidateInputElement();

    if (a > b){
        printf("Ошибка ввода! Задаётся отрезок [a; b], где а<=b.\n");
        return Delete(array,size);
    }

    int newSize = 0;
    for (int i = 0; i < *size; i++) {
        if ((*array)[i] < a || (*array)[i] > b) { // Сохраняем элементы вне диапазона [a; b]
            (*array)[(newSize++)] = (*array)[i]; // Перемещаем переменные
        }
    }

    if (newSize == 0) {          // Если массив полностью удалён
        printf("Массив полностью удалён.\n");
        free(array);
        size = 0;
        *array = NULL;

    } else {
        *array = (double*)realloc(*array, newSize * sizeof(double));
        if (*array == NULL) {
            printf("Ошибка!");
            exit(1);
        }
        *size = newSize; // Обновим размер массива
    }
}


int main() {
    system("chcp 65001 > nul");

    int size = ValidateInput(); // Ввели размер массива

    double* array = 0;         // Перед выделением памяти необходимо обнулить указатель
    array = NewArray(size);
    Output(array, size);
    Delete(&array, &size);
    Output(array, size);

    if ((size)!= 0) {
            free(array);
    }
    return 0;
}

// Проверка размера
int ValidateInput() {
    double input = 0;
    char extra;

    printf("Введите размер маccива: ");

    // Проверяю наличие лишних символов
    if (scanf("%lf%c", &input, &extra) != 2 || extra != '\n') {
        printf("Ошибка ввода! Введено некорректное значение.\n");
        while (getchar() != '\n'); // Очистка потока ввода
        return ValidateInput();
    }

    // Проверка, является ли число целым
    if (input != (int)input || input<=0) {
        printf("Ошибка ввода! Число должно быть целым и положительным.\n");
        return ValidateInput();
    }

    return (int)input; // Возвращаем целое число
}

// Проверка элементов и a,b
double ValidateInputElement() {
    double input = 0;
    char extra;

    // Проверяю наличие лишних символов
    if (scanf("%lf%c", &input, &extra) != 2 || extra != '\n') {
        printf("Ошибка ввода! Введено некорректное значение.\n");
        printf("Введите заново:\n");
        while (getchar() != '\n'); // Очистка потока ввода
        return ValidateInputElement();
    }

    return (double)input; // Возвращаем вещ-ое число
}
