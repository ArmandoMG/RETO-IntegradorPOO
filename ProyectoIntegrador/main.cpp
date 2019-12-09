#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <fstream>

using namespace std;

#include "Vuelo.h"

vector<Vuelo> listaVuelos;
vector<string> fechas;

void loadFile();
void showFile();
void flightsPerAirline();
void maxHourPerDay();
void meanLlegadas();
void meanSalidas();
void passengersPerDay();

int main(){
	int opc;
	loadFile();
	while(opc!=7){
		cout<<"\t\t\tMENU\n"<<endl;
		cout<<"\n1. Hora de cada uno de los días con mayor saturación."<<endl;//WIP
		cout<<"2. Cantidad de llegadas por hora promedio."<<endl;//done
		cout<<"3. Cantidad de salidas por hora promedio."<<endl;//done
		cout<<"4. Cantidad de llegadas y salidas por aerolínea."<<endl;//done
		cout<<"5. Cantidad de pasajeros atendidos por días."<<endl;
		cout<<"6. Lista de vuelos."<<endl;//done
		cout<<"7. Salir"<<endl;//done
		cout<<"Que opcion desea? "; cin>>opc;
			
		switch(opc){
			case 1: maxHourPerDay(); break;
			case 2: meanLlegadas(); break;
			case 3: meanSalidas(); break;
			case 4: flightsPerAirline(); break;
			case 5: passengersPerDay(); break;
			case 6: showFile(); break;
			case 7: cout<<"Adios!"<<endl; break;
			default: cout<<"ERROR, TECLEAR UNA OPCION VALIDA"<<endl;
		}
		cout<<"\n";
		system("PAUSE");
		system("cls");
	}
	
	system("PAUSE");
	system("cls");
	return 0;
}

void loadFile(){
	string aerolinea,fecha, hora, idVuelo, lleg_sali,modeloAvion, destinoOrigen;
	int pasajeros;
	
    ifstream in_file;
    in_file.open("vuelos.txt");
    while(in_file>>idVuelo>>aerolinea>>destinoOrigen>>lleg_sali>>modeloAvion>>pasajeros){
      	Avion avion(modeloAvion);
    	Vuelo vuelo(idVuelo,aerolinea,destinoOrigen,lleg_sali,avion,pasajeros);
		listaVuelos.push_back(vuelo);	
    }
    in_file.close();
    
    ifstream in_File;
    in_File.open("llegadas_salidas.txt");
    while(in_File>>fecha>>hora>>idVuelo>>lleg_sali){
    	Fecha fecha1(fecha,hora);
    	fechas.push_back(fecha);
    	for(int i=0;i<listaVuelos.size();i++){
    		if(idVuelo == listaVuelos[i].getIdVuelo()){
    			listaVuelos[i].setFecha(fecha1);
			}
		}
	}
    in_File.close();
}
void showFile(){
	for(int i=0;i<listaVuelos.size();i++){
		cout<<"\nId del Vuelo: "<<listaVuelos[i].getIdVuelo()<<endl;
		cout<<"\nAerolinea: "<<listaVuelos[i].getAerolinea()<<endl;
		cout<<"Origen/Destino: "<<listaVuelos[i].getOrigenDestino()<<endl;
		cout<<"Llegada/Salida: "<<listaVuelos[i].getLlegadaSalida()<<endl;
		cout<<"Modelo de Avion: "<<listaVuelos[i].getAvion().getModelo()<<endl;
		cout<<"Numero de pasajeros: "<<listaVuelos[i].getPasajeros()<<endl;
		cout<<"Fecha(aaaa/mm/dd): "<<listaVuelos[i].getFecha().getAno()<<"/"<<listaVuelos[i].getFecha().getMes()<<"/"<<listaVuelos[i].getFecha().getDia()<<endl;
		cout<<"Hora(hh:ss): "<<listaVuelos[i].getFecha().getHora()<<":"<<listaVuelos[i].getFecha().getMinuto()<<endl;
	}
}
void flightsPerAirline(){
	//Como el archivo esta ordendao si se puede hacer esto, en caso de que no este ordenado, se usaria el algorimto que esta comentado cambiando las variables
	int cont=1,a=0,j;
	for(int i=0;i<listaVuelos.size()-1;i++){
		//cout<<i<<endl;
		if(listaVuelos[i].getAerolinea()==listaVuelos[i+1].getAerolinea()){
			cont++;
			if(listaVuelos[i].getLlegadaSalida()=="A"){
				a++;
			}
		}else{
			if(listaVuelos[i].getLlegadaSalida()=="A"){
				a++;
			}
			cout<<"Aerolinea: "<<listaVuelos[i].getAerolinea()<<"------ No. de Vuelos: "<<cont<<endl;
			cout<<"Llegadas: "<<a<<"------ Salidas: "<<cont-a<<endl;
			cont=1;
			a=0;
		}
		j=i;
	}
	cout<<"Aerolinea: "<<listaVuelos[j].getAerolinea()<<"------ No. de Vuelos: "<<cont<<endl;
	cout<<"Llegadas: "<<a<<"------ Salidas: "<<cont-a<<endl;
	/*
	vector<int> airlinesFreq;
	int cont=0,llegadas=0;
	for(int i=0; i<listaVuelos.size(); i++){
		airlinesFreq.push_back(-1);//inicializa las frecuencias en -1 con un size igual al de lista vuelos
	}
    for(int i=0; i<listaVuelos.size(); i++){
        cont = 1;//contador de los duplicados (inicia en 1 porque y existe un elemento)
        llegadas = 0;
        for(int j=i+1; j<listaVuelos.size(); j++){
            if(listaVuelos[i].getAerolinea()==listaVuelos[j].getAerolinea()){//En caso de encontrar algo repetido
                cont++; 
                airlinesFreq[j] = 0;//Sirve para no contar la misma cosa(frecuencia)
                if(listaVuelos[i].getLlegadaSalida()=="llegada"){
                	llegadas++;
				}
            }
        } 
	    //Si la frecuencia de este elemento aun no se ha contaado
	    if(airlinesFreq[i] != 0){
			//airlinesFreq[i] = cont; //por si queremos llevar un 'track' y guardar las frecuencias en un array de cada vuelo
			cout<<"Aerolinea: "<<listaVuelos[i].getAerolinea()<<"------ No. de Vuelos: "<<cont<<endl;
			cout<<"Llegadas: "<<llegadas<<"------ Salidas: "<<cont-llegadas<<endl;
		}
    }
	*/
}
void maxHourPerDay(){
	//TODO esto se pude hacer mucho más corto y sencillo si asumimos que las fechas estaran ordenadas(o si es solo una o si pasamos como parametro el dia) pero quise hacerlo asi para que sea escalable lo más facil posible
	vector<int> horas;
	vector<string> dates;
	int cont=0,hora,maxHour=-1,maxIndex=-1;
	
	dates.push_back(fechas[0]);
	for(int i=1;i<fechas.size();i++){
		for(int j=0; j<dates.size();j++){
			if(dates[j]==fechas[i]){
				cont++;
			}
		}
		if(cont==0){
			dates.push_back(fechas[i]);
		}
		cont=0;
	}
	for(int i = 0; i<24; i++){
		horas.push_back(0);
	}
	for(int i = 0; i<dates.size(); i++){
		for(int j = 0;j<fechas.size();j++){
			if(dates[i]==fechas[j]){
				hora=listaVuelos[j].getFecha().getHora();
				horas[hora]+=1;
				if(horas[hora]>maxHour){
					maxHour=horas[hora];
					maxIndex=hora;
				}
			}
		}
		//Solo para que tenga un formato bonito
		if(maxIndex==23){
			cout<<"Fecha: "<<dates[i]<<" ------> Hora saturada: "<<maxIndex<<":00 - 00:00"<<endl;
		}else{
			cout<<"Fecha: "<<dates[i]<<" ------> Hora saturada: "<<maxIndex<<":00 - "<<maxIndex+1<<":00"<<endl;
		}
		fill(horas.begin(),horas.end(),0);
		maxHour=-1; 
	}
}
void meanLlegadas(){
	//Tambien podria hacer el promedio de horas que son salidas en esta misma funcion, pero para que se etnienda mejor lo hice asi, y para usar ambas de manera independiente
	vector<int> horas;
	vector<string> f;
	
	int cont=0,llegadas=0;
	float mean;
	
	for(int i = 0; i<listaVuelos.size(); i++){
		horas.push_back(listaVuelos[i].getFecha().getHora());
	}
	
	f.push_back(fechas[0]);
	for(int i = 0; i<fechas.size(); i++){
		for(int j = 0; j<f.size();j++){
			if(f[j]==fechas[i]){
				cont++;
			}
		}
		if(cont==0){
			f.push_back(fechas[i]);
		}
		cont=0;
	}
	for(int i = 0; i<listaVuelos.size(); i++){
		if(listaVuelos[i].getLlegadaSalida()=="A"){
			llegadas++;                                              
		}
	}
	
	mean = llegadas/(24.0*f.size());
	cout<<"Llegadas por hora promedio: "<<mean<<endl;
}
void meanSalidas(){
	vector<int> horas;
	vector<string> f;
	
	int cont=0,llegadas=0;
	float mean;
	
	for(int i = 0; i<listaVuelos.size(); i++){
		horas.push_back(listaVuelos[i].getFecha().getHora());
	}
	
	f.push_back(fechas[0]);
	for(int i = 0; i<fechas.size(); i++){
		for(int j = 0; j<f.size();j++){
			if(f[j]==fechas[i]){
				cont++;
			}
		}
		if(cont==0){
			f.push_back(fechas[i]);
		}
		cont=0;
	}
	for(int i = 0; i<listaVuelos.size(); i++){
		if(listaVuelos[i].getLlegadaSalida()=="S"){
			llegadas++;                                              
		}
	}
	
	mean = llegadas/(24.0*f.size());
	cout<<"Salidas por hora promedio: "<<mean<<endl;
}
void passengersPerDay(){
	int suma=0,j;
	for(int i=0;i<listaVuelos.size()-1;i++){
		if(listaVuelos[i].getFecha().getAno()==listaVuelos[i+1].getFecha().getAno() && listaVuelos[i].getFecha().getMes()==listaVuelos[i+1].getFecha().getMes() && listaVuelos[i].getFecha().getDia()==listaVuelos[i+1].getFecha().getDia()){
			suma+=listaVuelos[i].getPasajeros();
		}else{
			suma+=listaVuelos[i+1].getPasajeros();
			cout<<"Fecha(aaaa/mm/dd): "<<listaVuelos[i].getFecha().getAno()<<"/"<<listaVuelos[i].getFecha().getMes()<<"/"<<listaVuelos[i].getFecha().getDia()<<" ------ Pasajeros: "<<suma<<endl;
		}
		j=i;
	}
	suma+=listaVuelos[j].getPasajeros();
	cout<<"Fecha(aaaa/mm/dd): "<<listaVuelos[j].getFecha().getAno()<<"/"<<listaVuelos[j].getFecha().getMes()<<"/"<<listaVuelos[j].getFecha().getDia()<<" ------ Pasajeros: "<<suma<<endl;
}
