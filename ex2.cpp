#include <iostream>
using namespace std;

class Horario {
public:
    Horario();
    Horario(int, int, int);
    int gethoras() const;
    int getminutos() const;
    int getsegundos() const;
    void sethora(int);
    void setminutos(int);
    void setsegundos(int);
    Horario dif(Horario);
    Horario operator+(const Horario&) const;
    Horario operator-(const Horario&) const;
    friend ostream& operator<<(ostream& saida, Horario& horaatual);
    void acresc(const Horario&);
    void padronizar();
private:
    int horas, minutos, segundos;
};
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

    cout << "Soma realizada com sucesso!";
    return;
}
Horario Horario::operator+(const Horario& horasoma) const {
    Horario somatotal;
    somatotal.horas = horasoma.horas + horas;
    somatotal.minutos = horasoma.minutos + minutos;
    somatotal.segundos = horasoma.segundos + segundos;
    return somatotal;
}
Horario Horario::operator-(const Horario& h2) const {
    int dif = ((horas*3600) + (minutos*60) + segundos) - ((h2.horas*3600)+(h2.minutos*60)+h2.segundos);
    if (dif<0){
        dif*= -1;
    }
    Horario result;
    result.horas = dif/3600;
    result.minutos = (dif%3600)/60;
    result.segundos = dif%60;
    return result;
}
void Horario::padronizar(){
    int horastemp = horas,mintemp = minutos,sectemp = segundos;
    while(sectemp>=60){
        mintemp++;
        sectemp = sectemp-60;
    }
    while(mintemp>=60){
        horastemp++;
        mintemp = mintemp-60;
    }
    while(horastemp>=24){
        horastemp = horastemp-24;
    }
    horas = horastemp;
    minutos = mintemp;
    segundos = sectemp;
}
Horario Horario::dif(Horario h2){
    int dif = ((horas*3600) + (minutos*60) + segundos) - ((h2.horas*3600)+(h2.minutos*60)+h2.segundos);
    if (dif<0){
        dif*= -1;
    }
    Horario result;
    result.horas = dif%3600;
    result.minutos = (dif%3600)/60;
    result.segundos = dif%60;
    return result;
}
 ostream& operator<<(ostream& saida, Horario& horaatual){
    saida << horaatual.horas << ":" << horaatual.minutos << ":" << horaatual.segundos;
    return saida;
}
int main() {
    Horario hora1, hora2, hora3;
    char ponto = ':';
    int h1,h2,m1,m2,s1,s2;
    cout << "Digite um Horario: (Hora:Minuto:Segundo)";
    cin>> h1 >> ponto >> m1 >> ponto >> s1;
    cout << "Digite outro Horario: (Hora:Minuto:Segundo)";
    cin>> h2 >> ponto >> m2 >> ponto >> s2;
    hora1.sethora(h1);
    hora1.setminutos(m1);
    hora1.setsegundos(s1);
    hora2.sethora(h2);
    hora2.setminutos(m2);
    hora2.setsegundos(s2);
    hora3 = hora1 + hora2;
    hora3.padronizar();
    cout << "\nResultado da Soma: " << hora3.gethoras() << " horas, " << hora3.getminutos() << " minutos, " << hora3.getsegundos() << " segundos." << endl;
    hora3 = hora1 - hora2;
    cout << "\nResultado da Subtracao: " << hora3.gethoras() << " horas, " << hora3.getminutos() << " minutos, " << hora3.getsegundos() << " segundos." << endl;
    cout << "\nLista de Horarios\n" << "Horario 1: " << hora1 << "\nHorario 2: " << hora2 << "\nHorario 3: " << hora3 << endl; 
    return 0;
}
