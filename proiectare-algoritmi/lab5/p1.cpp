#include<iostream>
using namespace std;

void insertionSort(int a[], int n){
        for(int k = 1; k <= n - 1; k++){
                int i = k - 1;
                int temp = a[k];
                while((i >= 0) && (temp < a[i])){
                        a[i + 1] = a[i];
                        i--;
                }
                if(i != k - 1){
                        a[i + 1] = temp;
                }
        }
}

int main(){
        int g[5] = {1,5,79,20,0};
        insertionSort(g, 5);
        for(int i = 0; i < 5; i++){
                cout << g[i] << " ";
        }
}
