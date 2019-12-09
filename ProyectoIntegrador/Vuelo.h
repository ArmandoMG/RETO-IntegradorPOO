#ifndef Vuelo_h //Nombre de la clase, NO del archivo
#define Vuelo_h

#include "Avion.h"
#include "Fecha.h"

class Vuelo{
	private:
		Avion avion;
		int numPasajeros, numPuertas;
		string idVuelo, origenDestino, llegadaSalida, aerolinea;
    	Fecha fecha;
		
	public:
		Vuelo();
		Vuelo(string _idVuelo, string _aerolinea, string _origenDestino, string _llegadaSalida, Avion _avion, int _numPasajeros);
		Vuelo(string _aerolinea, int _numPasajeros, int _numPuertas, Fecha _fecha,string _idVuelo,string _llegadaSalida);
		void setAvion(Avion _avion);
		void setAerolinea(string _aerolinea);
		void setPasajeros(int _numPasajeros);
		void setPuertas(int _numPuertas);
		void setFecha(Fecha _fecha);
		void setIdVuelo(string _idVuelo);
		void setLlegadaSalida(string _llegadaSalida);
		void setOrigenDestino(string _origenDestino);
		Avion getAvion();
		string getAerolinea();
		int getPasajeros();
		int getPuertas();
		Fecha getFecha();
		string getIdVuelo();
		string getLlegadaSalida();
		string getOrigenDestino();
};
Vuelo::Vuelo(){
	Avion _avion;
	avion = _avion;
	numPasajeros = 0;
	numPuertas = 0;
	Fecha _fecha;
    fecha=_fecha;
	idVuelo = " ";
	llegadaSalida = " ";
}
Vuelo::Vuelo(string _idVuelo, string _aerolinea, string _origenDestino, string _llegadaSalida, Avion _avion, int _numPasajeros){
	idVuelo = _idVuelo;
	aerolinea = _aerolinea;
	origenDestino = _origenDestino;
	llegadaSalida = _llegadaSalida;
	avion = _avion;
	numPasajeros = _numPasajeros;
}
Vuelo::Vuelo(string _aerolinea, int _numPasajeros, int _numPuertas, Fecha _fecha,string _idVuelo,string _llegadaSalida){
	//avion = _avion;
	aerolinea = _aerolinea;
	numPasajeros = _numPasajeros;
	numPuertas = _numPuertas;
	fecha = _fecha;
	idVuelo = _idVuelo;
	llegadaSalida = _llegadaSalida;
}
void Vuelo::setAvion(Avion _avion){
	avion = _avion;
}
void Vuelo::setAerolinea(string _aerolinea){
	aerolinea = _aerolinea;
}
void Vuelo::setPasajeros(int _numPasajeros){
	numPasajeros = _numPasajeros;	
}
void Vuelo::setPuertas(int _numPuertas){
	numPuertas = _numPuertas;
}
void Vuelo::setFecha(Fecha _fecha){
	fecha = _fecha;
}
void Vuelo::setIdVuelo(string _idVuelo){
	idVuelo = _idVuelo;
}
void Vuelo::setLlegadaSalida(string _llegadaSalida){
	llegadaSalida = _llegadaSalida;
}
void Vuelo::setOrigenDestino(string _origenDestino){
	origenDestino = _origenDestino;
}
Avion Vuelo::getAvion(){
	return avion;
}
string Vuelo::getAerolinea(){
	return aerolinea;
}
int Vuelo::getPasajeros(){
	return numPasajeros;
}
int Vuelo::getPuertas(){
	return numPuertas;
}
Fecha Vuelo::getFecha(){
	return fecha;
}
string Vuelo::getIdVuelo(){
	return idVuelo;
}
string Vuelo::getLlegadaSalida(){
	return llegadaSalida;
}
string Vuelo::getOrigenDestino(){
	return origenDestino;
}
#endif
