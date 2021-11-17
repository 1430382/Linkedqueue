#include<iostream>
#include "Cola_Enlazada.cpp"
using namespace std;

int main(){
	ColaEnlazada<int> cola;
	int x = 0, y;
	if(cola.colaVacia()){
		while(x < 5){
			cin >> y;
			cola.insertar(y);
			x++;
		}
		cout << "Cola: " << cola.salidaCola() << endl;
		cout << "Cola: " << cola.eliminarSalida() << endl;
		cout << "Cola: " << cola.salidaCola() << endl;
	}
}
