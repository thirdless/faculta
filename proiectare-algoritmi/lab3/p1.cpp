#include <stdio.h>
#include <stdlib.h>
 
#define f 2
 
enum TipNod {Frunza, Interior};
 
struct nod {
  enum TipNod tipNod;
  int nrChei;
  int chei[2*f-1];
  struct nod *fii[2*f];
};
 
typedef struct nod Nod;
 
void creeazaBarbore(Nod **t);
void insereazaBarbore(Nod **t, int k);
Nod* cautareBarbore(Nod *t, int k);
void afiseaza(Nod *t, int spatii);
void valideazaRezultat(Nod *v, int k, int gasit);
 
void spargeNod(Nod *u, int i, Nod *v);
void insereazainNodIncomplet(Nod *v, int k);
 
 
 
void creeazaBarbore(Nod **t) {
  *t = (Nod *)malloc(sizeof(Nod));
  (*t)->tipNod = Frunza;
  (*t)->nrChei = 0;
}
 
void spargeNod(Nod *u, int i, Nod *v) {
 
  if (u == NULL || v == NULL) return;
 
  //completati codul
  
  Nod * w = (Nod*) malloc(sizeof(Nod));
  w->tipNod = v->tipNod;
  w->nrChei = f - 1;

  for(int j = 0; j <= f-2; i++){
  	w->chei[j] = v->chei[j+f];
  }

  if(v->tipNod == Interior){
  	for(int j = 0; j <= f-1; j++){
		w->fii[j] = v->fii[j];
	}
  }

  v->nrChei = f-1;

  for(int j = u->nrChei; j >= i+1; j++){
  	w->fii[j+1] = u->fii[j];
  }
 
  u->fii[i+1] = w;

  for(int j = u->nrChei-1; j >= i; j++){
  	u->chei[j+1] = u->chei[j];
  }

  u->chei[i] = v->chei[f-1];
  u->nrChei = u->nrChei + 1;

}
 
 
void insereazainNodIncomplet(Nod *v, int k) {
 
  if (v == NULL) return;
 
  // completeaza

  int i = v->nrChei - 1;
  if(v->topNod == Frunza){
  	while(i >= 0 && k < v->chei[i]){
  		v->chei[i+1] = v->chei[i];
  		i++;
  	}
  }

}
 
void insereazaBarbore(Nod **t, int k) {
 
  if (*t == NULL) {
    creeazaBarbore(t);
  }
 
  Nod **v = t;
 
  //completati codul
  
  if((*v)->nrChei == 2 * f - 1){
  	Nod * u = (Nod*)malloc(sizeof(Nod));
	*t = u;
	u->tipNod = Interior;
	u->nrChei = 0;
	u->fii[0] = (*v);
	spargeNod(u, 0, (*v));
	insereazainNodIncomplet(u, k);
  }
  else insereazainNodIncomplet(*v, k);

}
 
Nod* cautareBarbore(Nod *v, int k) {
 
    if (v == NULL) {
        return NULL;
    }
 
    int i = 0;
 
    while (i < v->nrChei && k > v->chei[i]) {
        i++;
    }
 
    if (i < v->nrChei && k == v->chei[i]) {
        return v;
    }
 
    if (v->tipNod == Frunza) {
        return NULL;
    }
    else {
        return cautareBarbore(v->fii[i], k);
    }
}
 
void valideazaRezultat(Nod *v, int k, int gasit) {
 
    if (v == NULL) {
   
        if (!gasit)
            printf("CORECT: Cheia %d nu a fost gasita.\n", k);
        else
            printf("INCORECT: Cheia %d nu a fost gasita.\n", k);    
           
        return;
    }
 
    if (v != NULL && !gasit) {
        printf("INCORECT: Un nod nenul a fost gasit pentru o cheie (%d) care nu exista.\n", k);            
        return;
    }
 
    char *desc = (char*)malloc(300 * sizeof(char));
 
    int i, j;
   
    for (i = 0; i < v->nrChei; i++) {
   
        if (k == v->chei[i]) {
            sprintf(desc, "Cheia %d a fost gasita in nodul [ ", k);
 
            for (j = 0; j < v->nrChei; j++) {
                sprintf(desc, "%s %d", desc, v->chei[j]);
            }
 
            sprintf(desc, "%s ] pe pozitia %d.", desc, i);
           
            if (gasit) {
                printf("CORECT: %s\n", desc);          
                return;
            }
            else {
                printf("INCORECT: %s\n", desc);
                return;
            }
        }
    }
   
    sprintf(desc, "Cheia %d nu a fost gasita in nodul [ ", k);
    for (j = 0; j < v->nrChei; j++) {
        sprintf(desc, "%s %d", desc, v->chei[j]);
    }
   
    printf("INCORECT: %s].\n", desc);        
}
 
 
void afiseaza(Nod *t, int spatii)
{
  if (t == NULL) return;
 
  int i;
 
  for(i = 1; i <= spatii; i++)
      printf(" ");
 
  printf("[ ");
  for (i = 0; i < t->nrChei; i++)
      printf("%d ", t->chei[i]);
  printf("]\n");
 
  for (i = 0; i <= t->nrChei; i++)
    afiseaza(t->fii[i], spatii + 2);
}
 
int main(void) {
 
  int a[] = {2, 4, 5, 23, 11, 6, 7, 90, 100, 1};
 
  Nod *bTree = NULL;
 
  for (int i = 0; i < (sizeof(a)/sizeof(int)); i++) {
    insereazaBarbore(&bTree, a[i]);
  }
 
  afiseaza(bTree, 2);
 
  valideazaRezultat(cautareBarbore(bTree, 23), 23, 1);
  valideazaRezultat(cautareBarbore(bTree, 7), 7, 1);
  valideazaRezultat(cautareBarbore(bTree, 101), 101, 0);
  valideazaRezultat(cautareBarbore(bTree, 0), 0, 0);
 
  return 0;
}
