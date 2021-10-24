//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Конструктор контейнера
Container::Container(): len{0} { }

//------------------------------------------------------------------------------
// Деструктор контейнера
Container::~Container() {
    Clear();
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Container::Clear() {
    for(int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Container::In(FILE *fp) {
    while(!feof(fp)) {
        if((storage[len] = Vehicle::StaticIn(fp)) != 0) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void Container::InRnd(int size) {
    while(len < size) {
        if((storage[len] = Vehicle::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::Out(FILE *fp) {
    fprintf(fp, "%s%d%s", "Container contains ", len, " elements.\n");
    fprintf(fp, "%s%.2f%s", "Average distance = ", AverageDistance(), "\n");
    for(int i = 0; i < len; i++) {
        fprintf(fp, "%d%s", i, ": ");
        storage[i]->Out(fp);
        fprintf(fp, "%s", "\n");
    }
}

//------------------------------------------------------------------------------
// Получение среднего значения расстояния
double Container::AverageDistance() {
    double averageValue = 0.0;
    for (int i = 0; i < len; ++i) {
        averageValue += storage[i]->Distance();
    }
    averageValue /= len;
    return averageValue;
}

//------------------------------------------------------------------------------
// Сортировка авто по их расстояниям
void Container::MoveAutos() {
    double averageValue = AverageDistance();
    for (int j = 0; j < len; ++j) {
        for (int i = 0; i < len; ++i) {
            if (storage[i]->Distance() < averageValue) {
                MoveToEnd(i);
            }
        }
    }
}

//------------------------------------------------------------------------------
// Переместить элемент в конец массива
void Container::MoveToEnd(int index) {
    Vehicle* temp;
    for (int i = index; i < len - 1; ++i) {
        temp = storage[i];
        storage[i] = storage[i + 1];
        storage[i + 1] = temp;
    }
}
