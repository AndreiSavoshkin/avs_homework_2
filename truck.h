#ifndef __truck__
#define __truck__

//------------------------------------------------------------------------------
// truck.h - содержит описание грузовика
//------------------------------------------------------------------------------

#include "rnd.h"
#include "vehicle.h"
#include "stdio.h"

// грузовик
class Truck: public Vehicle {
private:
    int loadCapacity; // грузоподъемность
protected:
    static Random rnd10;
public:
    virtual ~Truck() {}
    // Ввод параметров грузовика из файла
    virtual void In(FILE *fp);
    // Случайный ввод параметров грузовика
    virtual void InRnd();
    // Вывод параметров грузовика в файл
    virtual void Out(FILE *fp);
    // Вычисление расстояния грузовика
    virtual double Distance();
};
#endif //__truck__
