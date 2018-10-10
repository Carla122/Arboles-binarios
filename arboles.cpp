#include <iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct nodo {
	int valor;
	struct nodo *nodoI;
	struct nodo *nodoD;
};

//Prototipos
void menu();
nodo *crearNodo(int n);
void insertar(nodo *&arbol, int n);
nodo *arbol=NULL;
int main (){
	menu();
	getch();
	
return 0; 
}
void menu(){
	int dato,opcion;
	do{
		cout<<"\t MENU"<<endl;
		cout<<"1. Insertar un nuevo nodo"<<endl;
		cout<<"2. Salir"<<endl;
		cout<<"Opcion"<<endl;
		cin>>opcion;
		switch(opcion){
			case 1: cout<<"Inserte un numero: ";
			cin>>dato;
			insertar(arbol,dato);
			cout<<endl;
			system("pause");
			break;
		}
		system("cls");
	}while(opcion !=2);
	
}
//Funcion para crear un nuevo nodo
nodo *crearNodo(int n){
		nodo *nuevoNodo= new nodo();
		nuevoNodo->valor=n;
		nuevoNodo->nodoD=NULL;
		nuevoNodo->nodoI=NULL;
		return nuevoNodo;
}
//INSERTAR NODOS EN EL ARBOL
void insertar(nodo *&arbol, int n){
	//comprobar si el arbol esta vacio
	//Si el arbol esta vacio se crea un nuevo nodo mandando 
	//llamar a la funcion de crearNodo y asi se puede tener el nodo Raiz(n)
	if (arbol=NULL){
		nodo *nuevoNodo=crearNodo(n);
		arbol=nuevoNodo;
	}
	//si el arbol ya tiene nodos
	else{
		///Obtener el valor de la raiz
		int valoRaiz=arbol->valor;
		//SI n ES MENOR A LA RAIZ SE VA HACIA LA IZQUIERDA
		if(n<valoRaiz){
			insertar(arbol->nodoI,n);
		}
		//SI n es mayor a la raiz se inserta en lado derecho
		else{
			insertar(arbol->nodoD,n);
		}
	}
}
