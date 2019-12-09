#ifndef Avion_h //Nombre de la clase, NO del archivo
#define Avion_h

class Avion{
	private:
		string modelo;
		int numAsientos;
		
	public:
		Avion();
		Avion(string _modelo);
		Avion(string _modelo, int _numAsientos);
		void setModelo(string _modelo);
		void setNumAsientos(int _numAsientos);
		string getModelo();
		int getNumAsientos();
};
Avion::Avion(){
	modelo = "0";
	numAsientos = 0;
}
Avion::Avion(string _modelo){
	modelo = _modelo;
}
Avion::Avion(string _modelo, int _numAsientos){
	modelo = _modelo;
	numAsientos = _numAsientos;
}
void Avion::setModelo(string _modelo){
	modelo = _modelo;
}
void Avion::setNumAsientos(int _numAsientos){
	numAsientos = _numAsientos;
}
string Avion::getModelo(){
	return modelo;
}
int Avion::getNumAsientos(){
	return numAsientos;
}

#endif
