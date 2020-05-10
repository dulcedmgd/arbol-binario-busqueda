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
int sumaMultiplosTres(Nodo **raiz);

int main(int argc, char** argv) {
	Nodo *raiz = NULL;
	int valor;
	
	for(int i=0; i<5; i++)
    {
        cout << " Numero del nodo " << i+1 << ": ";
        cin >> valor;
        insertar( &raiz, valor);
    }
    cout << " ** Arbol Ingresado ** " << endl << endl;
	imprimirArbol( &raiz, 0);
	
	cout << endl << " ** Nodos Multiplos de 3 ** " << endl << endl;
	cout << endl << "Suma de los Multiplos de 3: " << sumaMultiplosTres(&raiz);
	return 0;
}

Nodo* crearNodo(int valor){ //crea un nuevo nodo del arbol
	Nodo *nuevo = new Nodo;
	
	nuevo->valor = valor; //asigna el valor entero
	nuevo->hijoIzq = NULL; //inicializa los hijos como nulos (porque inicialmente no tiene hijos)
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

int sumaMultiplosTres(Nodo **raiz){
	if(*raiz!=NULL){ //condicion de paro de recursividad, si el nodo actual no existe se retorna de la funcion
		int valorRaiz; //variable para almacenar los valores multiplos de tres
		if((*raiz)->valor % 3 == 0){ //si la raiz o nodo actual es multiplo de 3, entonces imprime el valor y asigna el valor actual al auxiliar entero
			cout << (*raiz)->valor << " + ";
			valorRaiz = (*raiz)->valor;
		}else{
			valorRaiz = 0; // si no es multiplo de 3, asigno cero para que no influya en la suma
		}
		int sumaIzq = sumaMultiplosTres(&(*raiz)->hijoIzq); //obtengo la suma del lado izquierdo del arbol
		int sumaDer = sumaMultiplosTres(&(*raiz)->hijoDer); //obtengo la suma del lado derecho del arbol
		return valorRaiz + sumaIzq + sumaDer; //retorna la suma de la raiz + el lado izquierdo + el lado derecho
	}
    return 0;
}
