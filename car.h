#ifndef __car__
#define __car__

//------------------------------------------------------------------------------
// car.h - содержит описание легкового автомобиля
//------------------------------------------------------------------------------

#include "rnd.h"
#include "vehicle.h"
#include "stdio.h"

//------------------------------------------------------------------------------
// машина
class Car: public Vehicle {
private:
    short maxSpeed; // максимальная скорость
protected:
    static Random rnd100;
public:
    virtual ~Car() {}
    // Ввод параметров автомобиля из файла
    virtual void In(FILE *fp);
    // Случайный ввод параметров автомобиля
    virtual void InRnd();
    // Вывод параметров автомобиля в файл
    virtual void Out(FILE *fp);
    // Вычисление максимального расстояния автомобиля
    virtual double Distance();
};

#endif //__car__
