#include<iostream>
using namespace std;

int main(){

	int lung, temp;
	
	cout << "\nNumar linii:";
	cin >> lung;
	
	int matrice[lung];
	
	for(int i = 0; i < lung; i++){
		for(int j = 0; j < lung; j++){
			cout << "matrice[" << i "][" << j << "] = ";
			cin >> matrice[i][j];
		}
	}
	
	for(int a = 0; a < lung / 2; a++){
		temp = matrice[a][a];
		for(int i = a; i < lung - a - 1; i++) matrice[a][i] = matrice[a][i + 1]; 
		for(int i = a; i < lung - a - 1; i++) matrice[i][lung - a] = matrice[i + 1];
		for(int i = lung - a - 1; i >= a; i--) matrice[lung - a][i] = matrice[lung - a][i - 1];
		for(int i = lung - a - 1; i >= a; i--) matrice[i][a] = matrice[i - 1][a];
		matrice[a]
	}

}
