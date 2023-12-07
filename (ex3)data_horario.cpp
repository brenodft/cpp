// data_horario.cpp

#include "(ex3)data_horario.h"
#include <iostream>

bool Data::isBissexto(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

Data::Data() : dia(1), mes(1), ano(1) {}

Data::Data(int dd, int mm, int aa) {
    int trinta[4] = {4, 6, 9, 11};
    int trintaum[7] = {1, 3, 5, 7, 8, 10, 12};
    int bissexto;

    if ((dd > 31 || dd < 1) || (mm > 12 || mm < 1) || (aa < 0)) {
        dia = 0;
        mes = 0;
        ano = 0;
    } else {
        dia = dd;
        mes = mm;
        ano = aa;
    }

    if ((aa % 4 == 0 && aa % 100 != 0) || (aa % 400 == 0)) {
        bissexto = 1;
    } else {
        bissexto = 0;
    }

    for (int i = 0; i < 4; i++) {
        if ((dd > 30) && (mm == trinta[i]) || (mm == 0)) {
            dia = 0;
            mes = 0;
            ano = 0;
        }
    }

    for (int i = 0; i < 7; i++) {
        if ((dd > 31) && (mm == trintaum[i]) || (mm == 0)) {
            dia = 0;
            mes = 0;
            ano = 0;
        }
    }

    if (mm == 2) {
        if (dd > 28 && mm == 2 && bissexto == 0) {
            dia = 0;
            mes = 0;
            ano = 0;
        } else if (dd > 29 && mm == 2 && bissexto == 1) {
            dia = 0;
            mes = 0;
            ano = 0;
        }
    }
}

void Data::imprimir() {
    std::cout << "\nHoje e dia " << dia << "/" << mes << "/" << ano;
}

void Data::acrescentar(int valor) {
    int diatemp = dia + valor;
    int bissexto;

    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        bissexto = 1;
    } else {
        bissexto = 0;
    }

    int meses[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (bissexto == 1) {
        meses[2] = 29;
    }

    do {
        if (diatemp > meses[mes]) {
            diatemp = diatemp - meses[mes];
            mes++;
            if (mes > 12) {
                ano++;
                mes = 1;
            }
        }
    } while (diatemp > meses[mes]);

    dia = diatemp;
}

int operator-(const Data& data1, const Data& data2) {
    int diasData1 = data1.ano * 365 + data1.mes * 30 + data1.dia;
    int diasData2 = data2.ano * 365 + data2.mes * 30 + data2.dia;
    return diasData1 - diasData2;
}

std::ostream& operator<<(std::ostream& os, const Data& data) {
    os << std::setfill('0') << std::setw(2) << data.dia << '/'
       << std::setw(2) << data.mes << '/' << data.ano;
    return os;
}

Horario::Horario() {
    horas = 0;
    minutos = 0;
    segundos = 0;
}

Horario::Horario(int horaset, int minset, int segset) {
    if (horaset < 24 && horaset >= 0) {
        if (minset < 60 && minset >= 0) {
            if (segset < 60 && segset >= 0) {
                horas = horaset;
                minutos = minset;
                segundos = segset;
            } else {
                horas = 0;
                minutos = 0;
                segundos = 0;
            }
        } else {
            horas = 0;
            minutos = 0;
            segundos = 0;
        }
    } else {
        horas = 0;
        minutos = 0;
        segundos = 0;
    }
}

int Horario::gethoras() const {
    return horas;
}

int Horario::getminutos() const {
    return minutos;
}

int Horario::getsegundos() const {
    return segundos;
}

void Horario::sethora(int h) {
    horas = h;
}

void Horario::setminutos(int m) {
    minutos = m;
}

void Horario::setsegundos(int s) {
    segundos = s;
}

void Horario::acresc(const Horario& horasoma) {
    int somasec = horasoma.segundos + segundos;
    while (somasec >= 60) {
        minutos++;
        somasec -= 60;
    }
    segundos = somasec;

    int somamin = minutos + horasoma.minutos;
    while (somamin >= 60) {
        horas++;
        somamin -= 60;
    }
    minutos = somamin;

    int somahoras = horas + horasoma.horas;
    while (somahoras >= 24) {
        somahoras -= 24;
    }
    horas = somahoras;
}

Horario Horario::operator+(const Horario& horasoma) const {
    Horario somatotal;
    somatotal.horas = horasoma.horas + horas;
    somatotal.minutos = horasoma.minutos + minutos;
    somatotal.segundos = horasoma.segundos + segundos;
    return somatotal;
}

Horario Horario::operator-(const Horario& h2) const {
    int dif = ((horas * 3600) + (minutos * 60) + segundos) - ((h2.horas * 3600) + (h2.minutos * 60) + h2.segundos);
    if (dif < 0) {
        dif *= -1;
    }
    Horario result;
    result.horas = dif / 3600;
    result.minutos = (dif % 3600) / 60;
    result.segundos = dif % 60;
    return result;
}

void Horario::padronizar() {
    int horastemp = horas, mintemp = minutos, sectemp = segundos;
    while (sectemp >= 60) {
        mintemp++;
        sectemp = sectemp - 60;
    }
    while (mintemp >= 60) {
        horastemp++;
        mintemp = mintemp - 60;
    }
    while (horastemp >= 24) {
        horastemp = horastemp - 24;
    }
    horas = horastemp;
    minutos = mintemp;
    segundos = sectemp;
}

Horario Horario::dif(const Horario& h2) const {
    int dif = ((horas * 3600) + (minutos * 60) + segundos) - ((h2.horas * 3600) + (h2.minutos * 60) + h2.segundos);
    if (dif < 0) {
        dif *= -1;
    }
    Horario result;
    result.horas = dif / 3600;
    result.minutos = (dif % 3600) / 60;
    result.segundos = dif % 60;
    return result;
}

std::ostream& operator<<(std::ostream& saida, const Horario& horaatual) {
    saida << horaatual.horas << ":" << horaatual.minutos << ":" << horaatual.segundos;
    return saida;
}

DataHorario::DataHorario() : Data(), Horario() {}

DataHorario::DataHorario(const Data& data, const Horario& horario) : Data(data), Horario(horario) {}

DataHorario::DataHorario(int dd, int mm, int aa, int horas, int minutos, int segundos)
    : Data(dd, mm, aa), Horario(horas, minutos, segundos) {}

DataHorario DataHorario::operator-(const DataHorario& dh) const {
    int difDias = ::operator-(static_cast<const Data&>(*this), static_cast<const Data&>(dh));
    Horario difHoras = Horario::operator-(dh);

    if (difDias < 0) {
        difHoras.sethora(difHoras.gethoras() * -1);
        difHoras.setminutos(difHoras.getminutos() * -1);
        difHoras.setsegundos(difHoras.getsegundos() * -1);
    }

    return DataHorario(difDias, 0, 0, difHoras.gethoras(), difHoras.getminutos(), difHoras.getsegundos());
}

std::ostream& operator<<(std::ostream& os, const DataHorario& dh) {
    os << static_cast<const Data&>(dh) << " " << static_cast<const Horario&>(dh);
    return os;
}
