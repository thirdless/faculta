#include<iostream>
#include<iomanip>
using namespace std;

#define N 4

void FloydWarshwall(int L[][N], int n, int P[][N]) {
    int temp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && L[i][j] != INT_MAX) P[i][j] = i;
            else P[i][j] = -1;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (L[i][k] == INT_MAX || L[k][j] == INT_MAX) temp = INT_MAX;
                else temp = L[i][k] + L[k][j];

                if (temp < L[i][j]) {
                    L[i][j] = temp;
                    P[i][j] = P[k][j];
                }

                if (i == j && L[i][j] < 0) throw "Graful are circuite negative";
            }
        }
    }
}

void show(int a[][N], int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            cout << std::setw(3);
            if (a[i][j] == INT_MAX) cout << "INF";
            else cout << a[i][j];
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int L[N][N] = {
        {0,             5, INT_MAX,      10},
        {INT_MAX,       0,       3, INT_MAX},
        {INT_MAX, INT_MAX,       0,       1},
        {INT_MAX, INT_MAX, INT_MAX,       0}
    };
    int P[N][N] = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    int n = N;

    try {
        cout << "L inainte de Floyd-Warshall: " << endl;
        show(L, N);

        FloydWarshwall(L, n, P);

        cout << "L dupa Floyd-Warshall: " << endl;
        show(L, N);
        
        cout << "P: " << endl;
        show(P, N);
    }
    catch (const char * e) {
        cout << "Exception meet: " << e << endl;
    }
}
