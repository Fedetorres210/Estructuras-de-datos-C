//LISTAS SIMPLES Y DOBLES

#include <stdio.h>
#include <stdlib.h>
//TIPO DE DATO int, char, struct, Nieve
typedef struct yeti{
	int dato;
	struct yeti * siguiente;
	
}Nieve;


Nieve *insertarDatoI(int dato, Nieve * lista);
Nieve *insertarDatoU(int dato, Nieve * lista);
void imprimirLista(Nieve* lista);
Nieve *eliminarDato(int dato, Nieve *lista);



int main(){
	
	Nieve * lista=NULL;
	lista= insertarDatoU(10,lista);
	lista= insertarDatoU(13,lista);
	lista= insertarDatoU(278,lista);
	lista= eliminarDato(45,lista);
	imprimirLista(lista);
	
	return 0;
}


Nieve *insertarDatoI(int dato, Nieve * lista){
	Nieve *ayudante;
	if(lista==NULL){
		lista= (Nieve*)malloc(sizeof(Nieve));
		lista->dato=dato;
		lista->siguiente=NULL;
	}else{
		ayudante=lista;
		while(ayudante->siguiente!=NULL){
			ayudante=ayudante->siguiente;
		}
		ayudante->siguiente= (Nieve*)malloc(sizeof(Nieve));
		ayudante->siguiente->dato=dato;
		ayudante->siguiente->siguiente=NULL;

	}
	return lista;
	
}

void imprimirLista(Nieve* lista){
	Nieve *ayudante;
	ayudante=lista;
	while(ayudante!=NULL){
		printf("%d->",ayudante->dato);
		ayudante=ayudante->siguiente;
	}
}

Nieve *insertarDatoU(int dato, Nieve * lista){
	Nieve *nuevaNieve,*ayudante;
	nuevaNieve=(Nieve*)malloc(sizeof(Nieve));
	nuevaNieve->dato=dato;
	nuevaNieve->siguiente=NULL;
	if (lista!=NULL){
		nuevaNieve->siguiente=lista;
	}
	return nuevaNieve;
	
	
	
}

Nieve *eliminarDato(int dato, Nieve *lista){
	Nieve* ayudante;
	ayudante=lista;
	if (ayudante->dato==dato){
		ayudante->siguiente=ayudante->siguiente->siguiente;
	}
	else{
		while(ayudante->siguiente->dato!=dato){
		ayudante=ayudante->siguiente;
	}
	ayudante->siguiente= ayudante->siguiente->siguiente;
	}
	
	return lista;	
}