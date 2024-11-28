#include <iostream>  //ввод-вывод в терминал
#include <cmath>     //математические функции
#include <vector>    //динамические массивы
#include <algorithm> //различные алгоритмы
#include <random>    //генерация случайных чисел
using namespace std;
// Функция, которую нужно оптимизировать
double fitnessFunction(double x, double y)
{
    return 3 * pow(x, 2) + x * y + 2 * pow(y, 2) - x - 4 * y;
}
// Генерация случайного числа в заданном диапазоне
double randomDouble(double min, double max)
{
    static random_device rd;
    static mt19937 gen(rd());
    uniform_real_distribution<double> dis(min, max);
    return dis(gen);
}
// Структура для представления генома (решения)
struct Genome
{
    double x;
    double y;
    double fitness;
    Genome(double x, double y) : x(x), y(y)
    {
        fitness = fitnessFunction(x, y);
    }
    bool operator<(const Genome &other) const
    {
        return fitness < other.fitness;
    }
};
// Генерация начальной популяции
vector<Genome> generateInitialPopulation(int populationSize, double minX, double maxX, double minY,
                                         double maxY)
{
    vector<Genome> population;
    for (int i = 0; i < populationSize; ++i)
    {
        double x = randomDouble(minX, maxX);
        double y = randomDouble(minY, maxY);
        population.emplace_back(x, y);
    }
    return population;
}
// Скрещивание двух геномов
Genome crossover(const Genome &parent1, const Genome &parent2)
{
    double x = (parent1.x + parent2.x) / 2.0;
    double y = (parent1.y + parent2.y) / 2.0;
    return Genome(x, y);
}
// Мутация генома
void mutate(Genome &genome, double mutationRate, double minX, double maxX, double minY, double maxY)
{
    if (randomDouble(0.0, 1.0) < mutationRate)
    {
        genome.x = randomDouble(minX, maxX);
        genome.y = randomDouble(minY, maxY);
        genome.fitness = fitnessFunction(genome.x, genome.y);
    }
}
// Генетический алгоритм для оптимизации функции
Genome geneticAlgorithm(int populationSize, int numGenerations, double mutationRate, double minX,
                        double maxX,
                        double minY, double maxY)
{
    vector<Genome> population = generateInitialPopulation(populationSize, minX, maxX, minY, maxY);
    for (int generation = 0; generation < numGenerations; ++generation)
    {
        sort(population.begin(), population.end());
        // Выбор лучших геномов для скрещивания
        int numParents = populationSize / 2;
        vector<Genome> parents(population.begin(), population.begin() + numParents);
        // Скрещивание и мутация потомков
        vector<Genome> offspring;
        for (int i = 0; i < numParents - 1; ++i)
        {
            for (int j = i + 1; j < numParents; ++j)
            {
                Genome child = crossover(parents[i], parents[j]);
                mutate(child, mutationRate, minX, maxX, minY, maxY);
                offspring.push_back(child);
            }
        }
        // Замена худших геномов потомками
        copy(offspring.begin(), offspring.end(), population.begin() + numParents);
        // Обновление значений
        for (int i = numParents; i < populationSize; ++i)
        {
            population[i].fitness = fitnessFunction(population[i].x, population[i].y);
        }
    }
    sort(population.begin(), population.end());
    return population[0];
}
int main()
{
    cout << "\x1B[2J\x1B[H";
    setlocale(LC_ALL, "ru");
    int populationSize = 10;
    int numGenerations = 1000;
    double mutationRate = 0.1;
    double minX = -10.0;
    double maxX = 10.0;
    double minY = -10.0;
    double maxY = 10.0;
    double sumbestGenome = 0, sumbestGenomex = 0, sumbestGenomey = 0;
    Genome bestGenome = geneticAlgorithm(populationSize, numGenerations, mutationRate, minX,
                                         maxX, minY, maxY);
    cout << "Решение при:\nx = " << round(bestGenome.x * 1000) / 1000 << "\ny = " << round(bestGenome.y * 1000) / 1000 << endl;
    cout << "Экстремум функции: " << round(bestGenome.fitness * 1000) / 1000 << endl
         << endl;
    return 0;
}