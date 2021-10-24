#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "vehicle.h"
#include <cstdio>

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
class Container {
public:
    Container();
    ~Container();

    // Ввод содержимого контейнера из указанного потока
    void In(FILE *fp);
    // Случайный ввод содержимого контейнера
    void InRnd(int size);
    // Вывод содержимого контейнера в указанный поток
    void Out(FILE *fp);
    // Сортировка авто по их расстояниям
    void MoveAutos();
    // Получение среднего значения расстояния
    double AverageDistance();
    // Переместить элемент в конец массива
    void MoveToEnd(int index);
private:
    void Clear();    // Очистка контейнера от данных
    int len; // текущая длина
    Vehicle* storage[10000];
};
#endif //__container__