#include <iostream>
#include <string.h>

using namespace std;

struct Nodo{
	int valor;
	Nodo *hijoIzq;
	Nodo *hijoDer;	
};

Nodo* crearNodo(int valor);
void insertar(Nodo **raiz, int valor);
void imprimirArbol(Nodo **arbol, int n);

int main(int argc, char** argv) {
	Nodo *raiz = NULL;
	int valor;
	
	for(int i=0; i<10; i++)
    {
        cout << " Numero del nodo " << i+1 << ": ";
        cin >> valor;
        insertar( &raiz, valor);
    }
	imprimirArbol( &raiz, 0);
	return 0;
}

Nodo* crearNodo(int valor){
	Nodo *nuevo = new Nodo;
	
	nuevo->valor = valor;
	nuevo->hijoIzq = NULL;
	nuevo->hijoDer = NULL;
	
	return nuevo;
}

void insertar(Nodo **raiz, int valor){
	if(*raiz == NULL){ //primer numero ingresado será la raíz del arbol
	   *raiz = crearNodo(valor);
	}else if(valor < (*raiz)->valor){ //si el numero es menor a la raíz ingresa como hijo izquierdo, se llama de forma recursiva la función para buscar en profundidad con los hijos
	  insertar(&(*raiz)->hijoIzq, valor);
	}else if(valor > (*raiz)->valor){ //si el numero es mayor a la raíz ingresa como hijo derecho, se llama de forma recursiva la función para buscar en profundidad con los hijos
	  insertar(&(*raiz)->hijoDer, valor);
	}
}


void imprimirArbol(Nodo **raiz, int n){
	if(*raiz==NULL){ //condicion de paro de recursividad, si el nodo actual no existe se retorna de la funcion
	  return;
	}
	imprimirArbol(&(*raiz)->hijoDer, n+1); //llama a imprimir los hijos derechos del arbol
	
	for(int i=0; i<n; i++){ //Espacios en blanco para tratar de visualizar profundidad de los nodos hijos
		cout<<"   ";
	}
	
	cout << (*raiz)->valor << endl; // imprime valor del nodo
	
	imprimirArbol(&(*raiz)->hijoIzq, n+1); //llama a imprimir los hijos derechos del arbol
}
