// main.cpp

#include "(ex3)data_horario.h"
#include <iostream>
#include <iomanip>

int main() {
    DataHorario dh1;
    DataHorario dh2(Data(2023, 12, 5), Horario(15, 30, 45));

    std::cout << "dh1: " << dh1 << std::endl;
    std::cout << "dh2: " << dh2 << std::endl;

    DataHorario dh3(Data(2023, 12, 6), Horario(12, 30, 30));
    std::cout << "Diferença entre dh2 e dh3: " << dh2 - dh3 << std::endl;

    return 0;
}
