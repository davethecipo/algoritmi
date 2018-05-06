#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 200

void selection_sort(int (*)[]);

// parray è un puntatore ad un array di interi
// puntatore_a_funzione è puntatore a funzione che ritorna void e richiede come argomento un puntatore
// ad array di int
void esegui_ordinamento(void (*puntatore_a_funzione)( int (*)[] ), int (*parray)[] );

// https://stackoverflow.com/questions/859634/c-pointer-to-array-array-of-pointers-disambiguation

int main(void ){
	// dichiaro array come puntatore ad array di interi
	int (* array)[];
	// assegno valore ad array (salvo su array indirizzo di memoria iniziale dell'array)
	array = (int (*)[]) malloc(sizeof(int) * ARRAY_SIZE);
	// TODO assegnare valori all'array
	esegui_ordinamento(selection_sort, array);	
	return 0;
}

void selection_sort(int (*x)[]){
  int y;
  y = (*x)[1];
}

void esegui_ordinamento(void (*puntatore_a_funzione)( int (*)[] ), int (*parray)[] ){
	// TODO chiamare la funzione con l'array
	puntatore_a_funzione(parray);
}