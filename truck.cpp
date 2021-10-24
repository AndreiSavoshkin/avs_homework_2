//------------------------------------------------------------------------------
// truck.cpp - содержит процедуру ввода параметров
//------------------------------------------------------------------------------

#include "truck.h"

Random Truck::rnd10(1, 10);

//------------------------------------------------------------------------------
// Ввод параметров грузовика из файла
void Truck::In(FILE *fp) {
    fscanf(fp, "%d%d%f", loadCapacity, fuelCapacity, fuelConsumption);
}

// Случайный ввод параметров грузовика.
void Truck::InRnd() {
    loadCapacity = rnd10.Get() + 1;
}

//------------------------------------------------------------------------------
// Вывод параметров прямоугольника в форматируемый поток.
void Truck::Out(FILE *fp) {
    fprintf(fp, "%s%d%s%d%s%.2f%s%.2f",
            "It is a truck: load capacity = ", loadCapacity,
            ", fuel capacity = ", fuelCapacity,
            ", fuel consumption = ", fuelConsumption,
            ". Max distance = ", Distance());
}

//------------------------------------------------------------------------------
// Вычисление расстояния грузовика.
double Truck::Distance() {
    return fuelCapacity / fuelConsumption * 100;
}
