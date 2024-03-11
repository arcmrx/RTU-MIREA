#include <iostream> // Подключение библиотеки для ввода/вывода
#include <cstdlib>  // Содержит функции для работы с памятью, генерации случайных чисел и другие
#include <ctime>    // Содержит функции для работы со временем
#include <cmath>    // Содержит математические функции
using namespace std;
// Константы
#define POP_SIZE 500   // Численность населения
#define GEN_MAX 5000   // Максимальное количество поколений
#define MUT_RATE 0.05  // Частота мутаций
#define ELIT_RATE 0.01 // Уровень элитарности
double evaluate(double x, double y)
{
    return 3 * x * x + x * y + 2 * y * y - x - 4 * y; // Функция оценки
}
void mutate(double &x, double &y)
{
    if (rand() % 10000 < MUT_RATE * 10000) // Мутация с учетом частоты мутаций
    {
        x += (rand() % 1000 - 500) / 100.0; // Изменение значения x
    }
    if (rand() % 10000 < MUT_RATE * 10000) // Мутация с учетом частоты мутаций
    {
        y += (rand() % 1000 - 500) / 100.0; // Изменение значения y
    }
}
int main()
{
    cout << "\x1B[2J\x1B[H";           // Очистка терминала
    setlocale(LC_ALL, "ru");           // Использование языкового стандаота
    srand(time(0));                    // Инициализация генератора случайных чисел
    double population[POP_SIZE][2];    // Массив для хранения популяции
    for (int i = 0; i < POP_SIZE; i++) // Инициализация начальной популяции
    {
        population[i][0] = rand() % 1000 - 500; // Значение x в пределах [-500, 499]
        population[i][1] = rand() % 1000 - 500; // Значение y в пределах [-500, 499]
    }
    int generation = 0;          // Счетчик поколений
    double bestFitness = 0;      // Лучшая приспособленность
    double bestSolution[2];      // Лучшее решение
    while (generation < GEN_MAX) // Цикл по поколениям
    {
        double fitnesses[POP_SIZE];        // Массив для хранения значений
        for (int i = 0; i < POP_SIZE; i++) // Расчет для каждого индивида
        {
            fitnesses[i] = -evaluate(population[i][0], population[i][1]); // Оценка приспособленности
        }
        int bestIndex = 0;                 // Индекс лучшего решения
        for (int i = 1; i < POP_SIZE; i++) // Поиск индекса лучшего решения
        {
            if (fitnesses[i] > fitnesses[bestIndex]) // Если найдено лучшее решение
            {
                bestIndex = i; // Обновление индекса лучшего решения
            }
        }
        // Если найдено новое лучшее решение, выводится номер поколения и лучшее решение
        if (fitnesses[bestIndex] > bestFitness)
        {
            bestFitness = fitnesses[bestIndex];         // Обновление лучшей приспособленности
            bestSolution[0] = population[bestIndex][0]; // Обновление лучшего решения по x
            bestSolution[1] = population[bestIndex][1]; // Обновление лучшего решения по y
            std::cout
                << "Поколение " << generation << ": (" << bestSolution[0] << ", " << bestSolution[1] << ") Экстремум:" << bestFitness << std::endl; // Вывод информации о лучшем решении
        }
        double newPopulation[POP_SIZE][2];  // Массив для хранения новой популяции
        int elitism = ELIT_RATE * POP_SIZE; // Размер элитной части популяции
        for (int i = 0; i < elitism; i++)   // Копирование элиты в новую популяцию
        {
            newPopulation[i][0] = population[bestIndex][0];
            newPopulation[i][1] = population[bestIndex][1];
        }
        for (int i = elitism; i < POP_SIZE; i++) // Генерация новых особей
        {
            int parent1 = rand() % POP_SIZE;                                             // Выбор первого родителя
            int parent2 = rand() % POP_SIZE;                                             // Выбор второго родителя
            newPopulation[i][0] = (population[parent1][0] + population[parent2][0]) / 2; // Смешивание значений x
            newPopulation[i][1] = (population[parent1][1] + population[parent2][1]) / 2; // Смешивание значений y
            mutate(newPopulation[i][0], newPopulation[i][1]);                            // Мутация новой особи
        }
        // Заменяем старую популяцию новой популяцией
        for (int i = 0; i < POP_SIZE; i++) // Обновление популяции
        {
            population[i][0] = newPopulation[i][0];
            population[i][1] = newPopulation[i][1];
        }
        generation++; // Увеличение номера поколения
    }
    std::cout << "Лучшее решение: (" << bestSolution[0] << ", " << bestSolution[1] << ") Экстремум: " << bestFitness << std::endl;
    return 0;
}