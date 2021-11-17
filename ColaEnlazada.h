#ifndef _COLAENLAZADA_H_
#define _COLAENLAZADA_H_
#include "Lista.cpp"

template<class T>
class ColaEnlazada{
	private:
		Lista<T> cola;
		int talla = 0;
	public:
		ColaEnlazada(){}
		void insertar(T elemento);
		T eliminarSalida();
		void limpiarCola();
		T salidaCola();
		bool colaVacia();
		int tallaCola();
};
#endif
