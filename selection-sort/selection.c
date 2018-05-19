#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
struct array_semplice {
	int64_t * p_array; // p_array punta a interi con segno a 64bit
	// ovvero da −(2^63) a 2^63 − 1
	int64_t lunghezza; // (2^63 o.d.g 10^18 )
	// se ogni numero occupa 64bit (== 8byte), una macchina con 8GB di RAM
	// può contenere un miliardo di numeri (o.d.g 10^9)
};

void selection_sort(struct array_semplice *);
void assegna_valori(struct array_semplice *);
void esegui_ordinamento(void (*puntatore_a_funzione)(struct array_semplice *), struct array_semplice *);
void stampa_array(struct array_semplice *);

// https://stackoverflow.com/questions/859634/c-pointer-to-array-array-of-pointers-disambiguation

void assegna_valori(struct array_semplice * array){
	for (int64_t i=0; i<(*array).lunghezza; i++){
		int64_t * p_current = (*array).p_array + i;
		*p_current = rand();
	}
}

void stampa_array(struct array_semplice *arr){
	for (int64_t i=0; i<(*arr).lunghezza; i++){
		int64_t valore;
		valore = *((*arr).p_array + i);
		printf("%63li\n", valore);
	}
}

void esegui_ordinamento(void (*puntatore_a_funzione)( struct array_semplice *), struct array_semplice * arr){
	puntatore_a_funzione(arr);
}

// https://github.com/cofyc/argparse

int main(int argc, char *argv[]){
	srand(0);
	int64_t array_size = 1;
	if (argc == 2){
		// al massimo ottengo 2^64-1
		array_size = strtol(argv[1], NULL, 10);
	};
	struct array_semplice array;
	array.lunghezza = array_size;
	array.p_array = malloc(sizeof(int64_t) * array_size);

	if (array.p_array == NULL){
		printf("Non sono riuscito ad allocare l'array di dimensione %li\n", array_size);
		return 1;
	}

	assegna_valori(&array);
	esegui_ordinamento(selection_sort, &array);
	//stampa_array(&array);
	free(array.p_array);	
	return 0;
}

void selection_sort(struct array_semplice *array){
	for (int64_t i=0; i<(*array).lunghezza-1; i++){
		int64_t * p_current;
		p_current = (*array).p_array + i;
		int64_t * p_lowest = p_current;
		for (int64_t j=i+1; j<(*array).lunghezza; j++){
			if ( *((*array).p_array + j) < *p_lowest ){
				p_lowest = (*array).p_array + j;
			}
		}
		if (p_lowest != p_current){
			int64_t temp = *p_current;
			*p_current = *p_lowest;
			*p_lowest = temp;
		}
	}
}
