#include <iostream>
#include <iomanip>

class Data {
private:
    int dia, mes, ano;

    bool isBissexto(int year) const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

public:
    Data() : dia(1), mes(1), ano(1) {}
    Data(int dd, int mm, int aa);

    friend Data operator+(const Data& data, int valor);
    friend int operator-(const Data& data1, const Data& data2);
    friend std::ostream& operator<<(std::ostream& os, const Data& data);

    void imprimir();
    void acrescentar(int valor);
};

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

Data operator+(const Data& data, int valor) {
    int diatemp = data.dia + valor;
    int mes = data.mes;
    int ano = data.ano;

    while (diatemp > 0) {
        int diasNoMes = (mes == 2 && data.isBissexto(ano)) ? 29 : 28;
        if (mes != 2) {
            diasNoMes = (mes <= 7) ? ((mes % 2 == 1) ? 31 : 30) : ((mes % 2 == 0) ? 31 : 30);
        }

        if (diatemp > diasNoMes) {
            diatemp -= diasNoMes;
            ++mes;
            if (mes > 12) {
                ++ano;
                mes = 1;
            }
        } else {
            break;
        }
    }

    return Data(diatemp, mes, ano);
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

int main() {
    int dd, mm, aa, acres;
    char barra;
    std::cout << "Digite uma data (dd/mm/aa): ";
    std::cin >> dd >> barra >> mm >> barra >> aa;

    Data data(dd, mm, aa);

    std::cout << "\nDigite o valor a ser acrescentado: ";
    std::cin >> acres;

    Data novaData = data + acres;

    std::cout << "Data: " << novaData << std::endl;

    Data outraData;
    std::cout << "\nDigite outra data (dd/mm/aa): ";
    std::cin >> dd >> barra >> mm >> barra >> aa;
    Data dataDiff(dd, mm, aa);

    int difDias = novaData - dataDiff;
    std::cout << "\nDiferença de dias entre as datas: " << difDias << " dias\n";

    return 0;
}
