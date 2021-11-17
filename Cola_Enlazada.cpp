#include<iostream>
#include "ColaEnlazada.h"
using namespace std;

template<class T>
void ColaEnlazada<T>::insertar(T elemento){
	cola.insertarInicio(elemento);
	talla++;
}

template<class T>
T ColaEnlazada<T>::eliminarSalida(){
	T tmp;
	tmp = cola.getUltimoDato();
	cola.eliminarNodo(tmp);
	talla--;
	return tmp;
}

template<class T>
void ColaEnlazada<T>::limpiarCola(){
	if(!colaVacia()){
		Nodo<T>* n;
		n = cola.buscarDato(cola.getDato());
		while(cola.buscarDato(n -> datoNodo()) != NULL)
			eliminarSalida();
		talla = 0;
	}
}

template<class T>
T ColaEnlazada<T>::salidaCola(){
	if(!colaVacia())
		return cola.getUltimoDato();
	else
		return 0;
}

template<class T>
bool ColaEnlazada<T>::colaVacia(){
	if(!cola.listaVacia())
		return true;
	else
		return false;
}

template<class T>
int ColaEnlazada<T>::tallaCola(){
	return talla;
}
