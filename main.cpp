//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, 
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include "stdlib.h"
#include "time.h"
#include "string.h"
#include "stdio.h"

#include "container.h"

void errMessage1() {
    printf("incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n");
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if(argc != 5) {
        errMessage1();
        return 1;
    }

    Container c;
    clock_t begin = clock();
    if(!strcmp(argv[1], "-f")) {
        FILE *fp;
        fp = fopen(argv[2], "r");
        c.In(fp);
        fclose(fp);
    } else if(!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) {
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        c.InRnd(size);
    }
    else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    FILE *fo;
    fo = fopen(argv[3], "w");
    c.Out(fo);
    // Вторая часть задания.
    fo = fopen(argv[4], "w");
    c.MoveAutos();
    fprintf(fo, "%s", "Filled container:\n");
    c.Out(fo);
    fclose(fo);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    // Измерение времени работы программы
    printf("%f", time_spent);
    return 0;
}
