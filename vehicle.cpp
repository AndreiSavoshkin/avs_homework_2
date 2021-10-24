//------------------------------------------------------------------------------
// vehicle.cpp - содержит процедуры связанные с обработкой транспортных средств
// и создания произвольного транспортного средства
//------------------------------------------------------------------------------

#include "bus.h"
#include "car.h"
#include "truck.h"

//------------------------------------------------------------------------------
Random Vehicle::rnd20(1, 20);
Random Vehicle::rnd3(1, 3);

//------------------------------------------------------------------------------
// Ввод параметров обобщенного траснпортного средства из файла
Vehicle* Vehicle::StaticIn(FILE *fp) {
    int k;
    fscanf(fp, "%d", &k);
    Vehicle* vh = nullptr;
    switch(k) {
        case 1:
            vh = new Bus;
            break;
        case 2:
            vh = new Car;
            break;
        case 3:
            vh = new Truck;
            break;
        default:
            return 0;
    }
    vh->In(fp);
    return vh;
}

// Случайный ввод транспортного средства
Vehicle* Vehicle::StaticInRnd() {
    auto k = Vehicle::rnd3.Get();
    Vehicle* vh;
    switch(k) {
        case 1:
            vh = new Bus;
            break;
        case 2:
            vh = new Car;
            break;
        case 3:
            vh = new Truck;
            break;
        default:
            return 0;
    }
    vh->InRnd();
    int fuelCapacity = 45 + Vehicle::rnd20.Get();
    double fuelConsumption = 2.5 - (Vehicle::rnd20.Get() % 15) / 10.0;
    vh->fuelCapacity = fuelCapacity;
    vh->fuelConsumption = fuelConsumption;
    return vh;
    }
