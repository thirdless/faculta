#include<iostream>
#include<string.h>
using namespace std;

struct Nod{
	Nod * fii[30];
};

void insert(Nod * t, char * word){
	int word_size = strlen(word);
	for(int i = 0; i < word_size; i++){
		if(t->fii[word[i] - 'a'] == NULL){
			Nod * nt = new Nod;
			t->fii[word[i] - 'a'] = nt;
			t = nt;
		}
	}
}

Nod * cautTri(char * a, Nod * t){
	int i = 0;
	Nod * p = t;
	while((p != NULL) && i < strlen(a)){
		p = p->fii[a[i] - 'a'];
		i++;
	}
	return p;
}


void cautare(char * a, Nod * t){
	Nod * lol = cautTri(a, t);
	if(lol == NULL) cout << "Cuvantul " << a << " NU exista!\n";
	else cout << "Cuvantul " << a << " exista!\n";
}

int main(){
	char tabel[5][4] = {"abc", "bac", "rac", "lac"};
	Nod * tree = new Nod;
	for(int i = 0; i < 4; i++){
		insert(tree, tabel[i]);
	}

	char * abc = new char[4];
	strcpy(abc, "abc");

	char * ac = new char[4];
	strcpy(ac, "bsadhas");


	cautare(abc, tree);
	cautare(ac, tree);

}
