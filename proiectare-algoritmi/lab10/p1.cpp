#include<iostream>
using namespace std;

#define LEN 5

void Dijkstra(int G, int L[][LEN], int i0, int D[], int P[]) {

        int counter = 1,
                S[LEN] = { i0 };

        bool viz[LEN];

        for (int i = 0; i < G; i++) {
                D[i] = L[i0][i];
                P[i] = i0;
                viz[i] = false;
        }

        viz[i0] = true;

        while (size(S) != G) {
                int i = 0,
                        min = INT_MAX;

                for (int j = 0; j < G; j++) {
                        if (!viz[j] && D[j] != -1 && min > D[j]) {
                                min = D[j];
                                i = j;
                        }
                }

                viz[i] = true;
                S[counter++] = min;
                
                for (int j = 0; j < G; j++) {
                        if (!viz[j] && D[j] > L[i][j]) {
                                D[j] = D[i] + L[i][j];
                                P[j] = i;
                        }
                }


        }
}

int main() {

        int L[LEN][LEN] = {
                { 0,  5,  1, -1, 20},
                {-1,  0,  6, -1, -1},
                {-1, -1,  0,  2,  5},
                {-1, -1, -1,  0, 10},
                {-1, -1, -1, -1,  0}
        },
                i0 = 2,
                G = LEN,
                D[LEN],
                P[LEN];

        Dijkstra(G, L, i0, D, P);

        for (int i = 0; i < G; i++) {
                cout << D[i] << " ";
        }

        cout << "\n";

        for (int i = 0; i < G; i++) {
                cout << P[i] << " ";
        }

        cout << "\n";

        return 0;
}
