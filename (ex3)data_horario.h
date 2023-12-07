// data_horario.h

#ifndef DATA_HORARIO_H
#define DATA_HORARIO_H

#include <iostream>
#include <iomanip>

class Data {
private:
    int dia, mes, ano;

    bool isBissexto(int year) const;

public:
    Data();
    Data(int dd, int mm, int aa);

    friend Data operator+(const Data& data, int valor);
    friend int operator-(const Data& data1, const Data& data2);
    friend std::ostream& operator<<(std::ostream& os, const Data& data);

    void imprimir();
    void acrescentar(int valor);
};

class Horario {
public:
    Horario();
    Horario(int horaset, int minset, int segset);
    int gethoras() const;
    int getminutos() const;
    int getsegundos() const;
    void sethora(int h);
    void setminutos(int m);
    void setsegundos(int s);
    Horario dif(const Horario& h2) const;
    Horario operator+(const Horario& horasoma) const;
    Horario operator-(const Horario& h2) const;
    friend std::ostream& operator<<(std::ostream& saida, const Horario& horaatual);
    void acresc(const Horario& horasoma);
    void padronizar();
private:
    int horas, minutos, segundos;
};

class DataHorario : public Data, public Horario {
public:
    DataHorario();
    DataHorario(const Data& data, const Horario& horario);

    DataHorario(int dd, int mm, int aa, int horas, int minutos, int segundos);
    DataHorario operator-(const DataHorario& dh) const;
    friend std::ostream& operator<<(std::ostream& os, const DataHorario& dh);
};

#endif
