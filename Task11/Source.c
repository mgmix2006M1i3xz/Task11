#include <stdio.h>
#include <locale.h>

#define N 10 // Директива препроцессора
#define SIZE 100

int mainz1() {
    setlocale(LC_ALL, "RUS");
    float A[N];
    float temp;
    float sum = 0.0;

    // 2. Заполнение массива с консоли
    printf("Введите %d вещественных чисел:\n", N);
    for (int i = 0; i < N; i++) {
        printf("a[%d] = ", i + 1);
        scanf("%f", &temp);
        A[i] = temp;
    }

    // 6. Вычисление среднего арифметического (сделаем до преобразования)
    for (int i = 0; i < N; i++) {
        sum += A[i];
    }
    float avg = sum / N;

    // 4. Вывод результатов в виде таблицы
    printf("\n| Индекс | Исходное значение | Новое значение (x2) |\n");
    printf("|--------|-------------------|---------------------|\n");
    for (int i = 0; i < N; i++) {
        // 3. Преобразование: удвоить значение
        float new_value = A[i] * 2;
        printf("| %6d | %17.2f | %19.2f |\n", i, A[i], new_value);
    }

    printf("\nСреднее арифметическое исходных элементов: %.2f\n", avg);

    return 0;
}

double my_arcsin(double x) {
    // Для простоты используем стандартную функцию, 
    // но по заданию ЛБ8 можно было бы использовать разложение в ряд.
    return asin(x);
}

int mainz2() {
    setlocale(LC_ALL, "RUS");
    double arr[SIZE];
    double sum_pos = 0.0, sum_neg = 0.0;
    int count_pos = 0, count_neg = 0;

    double x_start = -0.9;
    double x_end = 0.9;
    double step = (x_end - x_start) / (SIZE - 1);

    // 1. Генерация массива
    for (int i = 0; i < SIZE; i++) {
        double x = x_start + i * step;
        arr[i] = my_arcsin(x);
    }

    // 2. Анализ элементов
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] > 0) {
            sum_pos += arr[i];
            count_pos++;
        }
        else {
            sum_neg += arr[i];
            count_neg++;
        }
    }

    // 3. Вычисление среднего
    double avg_pos = (count_pos > 0) ? (sum_pos / count_pos) : 0.0;

    // 4. Вывод в виде строки
    printf("\nИмя массива: arr[SIZE]\n");
    printf("Накопленное значение (положительные): %.4lf\n", sum_pos);
    printf("Накопленное значение (отрицательные): %.4lf\n", sum_neg);
    printf("Число положительных элементов: %d\n", count_pos);
    printf("Число отрицательных элементов: %d\n", count_neg);
    printf("Вычисленное среднее (положительных): %.4lf\n", avg_pos);

    return 0;
}
int mainz3() {
    setlocale(LC_ALL, "RUS");
    int n;

    printf("Введите количество элементов массива n: ");
    scanf("%d", &n);

    int A[n]; // Объявление массива (VLA)

    printf("Введите %d целых чисел:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Инициализация произведения (не нулем, а единицей!)
    long long product = 1;
    int found = 0; // Флаг, чтобы понять, были ли вообще положительные элементы

    for (int i = 0; i < n; i++) {
        if (A[i] > 0) {
            product *= (i + 1); // Порядковый номер = индекс + 1
            found = 1;
        }
    }

    if (found) {
        printf("Произведение порядковых номеров положительных элементов: %lld\n", product);
    }
    else {
        printf("В массиве нет положительных элементов.\n");
    }

    return 0;
}
int main() {

    mainz1();
    mainz2();
    mainz3();

    return 0;
}