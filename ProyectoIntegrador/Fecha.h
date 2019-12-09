#ifndef Fecha_h //Nombre de la clase, NO del archivo 
#define Fecha_h

#include<string>

class Fecha{
private:
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
public:
    Fecha();
    Fecha(string fecha_str, string hora_str);
    Fecha(int dia, int mes, int ano, int hora, int minuto);
    void setDia(int);
    void setMes(int);
    void setAno(int);
    void setHora(int);
    void setMinuto(int);
    int getDia();
    int getMes();
    int getAno();
    int getHora();
    int getMinuto();
    string datos();
};

Fecha::Fecha(){
    dia = 0;
    mes = 0;
    ano = 0;
    hora = 0;
    minuto = 0;
}
Fecha::Fecha(string fecha_str, string hora_str) {
    ano = stoi(fecha_str.substr(0,4));
    mes = stoi(fecha_str.substr(5,7));
    dia = stoi(fecha_str.substr(8,10));
    hora = stoi(hora_str.substr(0,2));
    minuto = stoi(hora_str.substr(3,5));
}
Fecha::Fecha(int dia, int mes, int ano, int hora, int minuto){
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
    this->hora = hora;
    this->minuto = minuto;
}
void Fecha::setDia(int dia){
    this->dia = dia;
}
void Fecha::setMes(int mes){
    this->mes = mes;
}
void Fecha::setAno(int ano){
    this->ano = ano;
}
void Fecha::setHora(int hora){
    this->hora = hora;
}
void Fecha::setMinuto(int minuto){
    this->minuto = minuto;
}
int Fecha::getDia(){
    return dia;
}
int Fecha::getMes(){
    return mes;
}
int Fecha::getAno(){
    return ano;
}
int Fecha::getHora(){
    return hora;
}
int Fecha::getMinuto(){
    return minuto;
}
string Fecha::datos(){
    string laLas;
    if(hora == 1){
        laLas = "la ";
    }
    else{
        laLas = "las ";
    }

    return  to_string(ano) + "/" + to_string(mes) + "/" + to_string(dia)
          + " a " + laLas + to_string(hora) + ":" + to_string(minuto) + ".";
}

#endif
