//------------------------------------------------------------------------------
// bus.cpp - содержит функции обработки автобуса
//------------------------------------------------------------------------------

#include "bus.h"

//------------------------------------------------------------------------------
// Ввод параметров автобуса из файла
void Bus::In(FILE *fp) {
    fscanf(fp, "%hx%d%f", passengersCapacity, fuelCapacity, fuelConsumption);
}

// Случайный ввод параметров автобуса
void Bus::InRnd() {
    passengersCapacity = rnd20.Get() + 1;
}

//------------------------------------------------------------------------------
// Вывод параметров автобуса в форматируемый поток
void Bus::Out(FILE *fp) {
    fprintf(fp, "%s%d%s%d%s%.2f%s%.2f", "It is a bus: passengers capacity = ", passengersCapacity,
            ", fuel capacity = ", fuelCapacity,
            ", fuel consumption = ", fuelConsumption,
            ". Max distance = ", Distance());
}

//------------------------------------------------------------------------------
// Вычисление расстояния автобуса
double Bus::Distance() {
    return fuelCapacity / fuelConsumption * 100;
}
