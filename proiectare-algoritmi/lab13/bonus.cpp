#include<iostream> 
using namespace std;

void afisare(int Q[4][4]){
    
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++) cout << Q[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

bool verificare(int Q[4][4], int i, int j){
    int k, l;

    for (k = 0; k < j; k++)
        if (Q[i][k])
            return false;

    for (k = i, l = j; k >= 0 && l >= 0; k--, l--)
        if (Q[k][l])
            return false;

    for (k = i, l = j; l >= 0 && k < 4; k++, l--)
        if (Q[k][l])
            return false;

    return true;
}

bool regine(int Q[4][4], int j){
    
    if (j >= 4){
        afisare(Q);
        return true;
    }

    bool reset = false;
    for (int i = 0; i < 4; i++){
        if (verificare(Q, i, j)){
            Q[i][j] = 1;
            reset = regine(Q, j + 1) || reset;
            Q[i][j] = 0;
        }
    }

    return reset;
}


int main(){
    int Q[4][4] = {
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }
    };

    if (regine(Q, 0) == false) {
        cout << "nu exista solutie";
        return 1;
    }
}
