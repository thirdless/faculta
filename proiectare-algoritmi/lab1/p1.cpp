#include<iostream>
using namespace std;

struct lista{
	
	lista * next, * prev;
	int data;
};


void adauga(lista * &pointer, int data, int pos){
	int increment = 0;
	
	lista * nou = new lista;
	lista * cap = pointer;
	lista * pozitie;
	
	nou->next = NULL;
	nou->prev = NULL;
	nou->data = data;
	
	
	
	while(cap != NULL){
		if(increment == pos){
			pozitie = cap;
			if(pozitie->prev != NULL){
				(pozitie->prev)->next = nou;
				nou->prev = pozitie->prev;
			}
		
			pozitie = nou;
			nou->next = pozitie;
			pozitie->prev = nou;
			pozitie = nou;
		}
		cap = cap->next;
	}
	
	if(cap == NULL){
		cap = nou;
	}
	
	pointer = cap;
	
	
}


/*void adauga(lista * &pointer, int data, int pos){
	int increment = 0;

	lista * nou = new lista;
	lista * cap = pointer;
	lista * pozitie;
	nou->next = NULL;
	nou->prev = NULL;
	nou->data = data;

	if(cap == NULL){
		cap = nou;
		cap->next = NULL;
		cap->prev = NULL;
	} else while(cap != NULL){
		if(increment == pos){
			pozitie = cap;
			cap = nou;
			cap->next = pozitie;
			cap->prev = pozitie->prev;
			pozitie->prev = cap;
			
			break;
		}
		increment++;
		cap = cap->next;
	}
	pointer = cap;

}*/

void show(lista * cap){
	while(cap != NULL){
		cout << cap->data << " ";
		cap = cap->next;
	}
}

int main(){
	lista * ceva = NULL;
	adauga(ceva, 7, 0);
	adauga(ceva, 10, 0);
	adauga(ceva, 14, 1);
	show(ceva);
	return 0;
}
