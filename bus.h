#ifndef __bus__
#define __bus__

//------------------------------------------------------------------------------
// bus.h - содержит описание автобуса  и его интерфейса
//------------------------------------------------------------------------------

#include "rnd.h"
#include "vehicle.h"
#include "stdio.h"

// автобус
class Bus: public Vehicle {
private:
    short passengersCapacity; // пассажировместимость
public:
    virtual ~Bus() {}
    // Ввод параметров автобуса из файла
    virtual void In(FILE *fp);
    // Случайный ввод параметров автобуса
    virtual void InRnd();
    // Вывод параметров автобуса в файл
    virtual void Out(FILE *fp);
    // Вычисление расстояния автобуса
    virtual double Distance();
};

#endif //__bus__
