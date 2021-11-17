#ifndef _NODO_H
#define _NODO_H

template<class T>
class Nodo{
	protected:
		T dato;
		Nodo<T>* enlace;
	public:
		Nodo(T t){
			dato = t;
			enlace = 0; // 0 is the null point in C++
		}
		Nodo(T p, Nodo* n){
			dato = p;
			enlace = n;
		}
		
		T datoNodo() const{
			return dato;
		}
		Nodo* enlaceNodo() const{
			return enlace;
		}
		void ponerEnlace(Nodo* agtn){
			enlace = agtn;
		}
};
#endif
