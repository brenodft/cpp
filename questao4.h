#ifndef questao4_h
#define questao4_h

using namespace std;

#include <iostream>

class Conta{
    public:
    string pix;
    Conta(int);
    float saldo();
    void sacar(float);
    void depositar(float);
    int getConta();

    private:
    int numero;
    float saldo;
};

class Corrente:public Conta{
    
};

class Poupanca:public Conta{
    public:
    int* getAniversarios();
    int* aplicaJuros();
    private:
    int aniversario[8];
    float* valor;
};

class Especial:public Conta{
    public:
    float limite;
    Especial(float);
};

class Pessoa{
    public:
    Conta* Contas;
    string getNome();
    Pessoa(string Nome, string CPF);
    private:
    string nome;
};

class Fisica:Pessoa{
    public:
    Fisica(string CPF);
    string getcpf();
    private:
    string CPF;
};

class Juridica:Pessoa{
    public:
    Juridica(string CPF);
    string getCNPJ();
    private:
    string CNPJ;
};

class Historico{
    public:
    void operar(Conta conta, int operacao, float valor);
    private:
    int* numero_conta, operacao;
    float* valor;
};

#endif

