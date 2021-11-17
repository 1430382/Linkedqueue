#include "Nodo.h"
#include<iostream>
using namespace std;

template<class T>
class Lista{
	protected:
		Nodo<T>* primero;
	public:
		Lista(){
			primero = NULL;
		}
		void crearLista();
		void visualizar();
		bool listaVacia();
		void listaOrdenada();
		void insertarFinal(T dato);
		void insertarInicio(T dato);
		void insertarValor(T datoAnterior, T d);
		Nodo<T>* buscarDato(T d);
		void eliminarNodo(T d);
		T getDato();
		T getValores(int indice);
		Nodo<T>* getNodo(int indice);
		T getUltimoDato();
};

template<class T>
void Lista<T>::crearLista(){
	T x;
	primero = 0;
	cout << "termination with -1" << endl;
	do{
		cin >> x;
		if(x != -1)
			primero = new Nodo<T>(x, primero);
	} while(x != -1);
	// order the list after create it
	listaOrdenada();
}
template<class T>
void Lista<T>::listaOrdenada(){
	Nodo<T>* n;
	Nodo<T>* nE;
	Nodo<T>* aux;
	Nodo<T>* auxNext;
	Nodo<T>* ant;
	nE = n = primero;
	ant = 0;
	T valNext;
	T antDato;
	while(nE -> enlaceNodo() != NULL){
		while(n -> enlaceNodo() != NULL){
			valNext = (n -> enlaceNodo()) -> datoNodo();
			if(n -> datoNodo() > valNext){
				antDato = n -> datoNodo();
				aux = n;
				n = n -> enlaceNodo();
				eliminarNodo(antDato);
				aux -> ponerEnlace(n -> enlaceNodo());
				n -> ponerEnlace(aux);
			} else
				n = n -> enlaceNodo();
		}
		n = primero;
		nE = nE -> enlaceNodo();
	}
}

template<class T>
void Lista<T>::visualizar(){
	Nodo<T>* n;
	n = primero;
	while(n != NULL){
		cout << n -> datoNodo() << " - Direction: " << n << " - link to: " << n -> enlaceNodo() << endl;
		n = n -> enlaceNodo();
	}
}

template<class T>
bool Lista<T>::listaVacia(){
	if(primero == NULL)
		return false;
	else
		return true;
}

template<class T>
void Lista<T>::insertarInicio(T dato){
	primero = new Nodo<T>(dato, primero);
}

template<class T>
void Lista<T>::insertarFinal(T dato){
	Nodo<T>* n;
	Nodo<T>* ultimo;
	n = primero;
	while(n -> enlaceNodo() != NULL)
		n = n -> enlaceNodo();
	ultimo = new Nodo<T>(dato);
	n -> ponerEnlace(ultimo);
}

template<class T>
void Lista<T>::insertarValor(T datoAnterior, T d){
	Nodo<T>* n;
	Nodo<T>* nuevo; // New link
	Nodo<T>* ant; // Previous Link
	Nodo<T>* post; // Posterior Link
	bool ban = false;
	ant = buscarDato(datoAnterior);
	if(ant == NULL)
		ban = true;
	if(!ban){
		nuevo = new Nodo<T>(d);
		post = ant -> enlaceNodo();
		ant -> ponerEnlace(nuevo);
		while(post != NULL){
			ant = ant -> enlaceNodo();
			ant -> ponerEnlace(post);
			post = post -> enlaceNodo();
		}
	}
}

template<class T>
Nodo<T>* Lista<T>::buscarDato(T d){
	Nodo<T>* n;
	n = primero;
	while(n != NULL){
		if(d == n -> datoNodo())
			return n;
		n = n -> enlaceNodo();
	}
}

template<class T>
void Lista<T>::eliminarNodo(T d){
	Nodo<T>* n;
	Nodo<T>* obj;
	Nodo<T>* ultimo;
	Nodo<T>* aux;
	Nodo<T>* penultimo;
	n = primero;
	// Buscar el ultimo y penultimo enlace
	// Search the last and second last linked
	while(n -> enlaceNodo() != NULL){
		penultimo = n;
		n = n -> enlaceNodo();
	}
	ultimo = n;
	obj = buscarDato(d);
	if(obj == primero){
		primero = primero -> enlaceNodo();
	} else if(obj == ultimo){
		penultimo -> ponerEnlace(NULL);
	} else{
		Nodo<T>* anterior;
		n = primero;
		while(n -> enlaceNodo() != NULL){
			if(obj == n -> enlaceNodo()){
				anterior = n;
				break;
			}
			n = n -> enlaceNodo();
		}
		anterior -> ponerEnlace(obj -> enlaceNodo());
	}
}
template<class T>
T Lista<T>::getDato(){
	Nodo<T>* n;
	n = primero;
	return n -> datoNodo();
}

// It only use it in a loop
template<class T>
T Lista<T>::getValores(int indice){
	Nodo<T>* n;
	int cont = 0;
	n = primero;
	while(n != NULL){
		if(cont == indice)
			return n -> datoNodo();
		n = n -> enlaceNodo();
		cont++;
	}
}

// It only use it in a loop
template<class T>
Nodo<T>* Lista<T>::getNodo(int indice){
	Nodo<T>* n;
	int cont = 0;
	n = primero;
	while(n != NULL){
		if(cont == indice)
			return n;
		n = n -> enlaceNodo();
		cont++;
	}
}

template<class T>
T Lista<T>::getUltimoDato(){
	Nodo<T>* n;
	n = primero;
	while(n -> enlaceNodo()){
		n = n -> enlaceNodo();
	}
	return n -> datoNodo();
}
