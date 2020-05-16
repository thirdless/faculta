#include<iostream>
#include<queue>

using namespace std;

#define NODES 6

struct Node {
    int elt;
    Node* succ;
};

struct Digraf {
    Node* a;
    int* L;
    int Ln;
    int* np;
    int n;
};

void initGraf(Digraf &D, int graf[][NODES]) {
    D.a = new Node[NODES];
    D.np = new int[NODES];
    D.L = new int[NODES];
    D.n = NODES;
    D.Ln = 0;

    for (int i = 0; i < NODES; i++) {
        D.a[i].elt = i;
        D.a[i].succ = NULL;
        D.np[i] = 0;
        D.L[i] = 0;
    }

    for (int i = 0; i < NODES; i++) {
        Node* last = &D.a[i];
        for (int j = 0; j < NODES; j++) {
            if (graf[i][j] == 1) {
                Node * temp = new Node;
                temp->elt = j;
                temp->succ = NULL;
                last->succ = temp;
                last = temp;
                D.np[j]++;
            }
        }
    }
}

int elimina(queue<int> &C) {
    int u = C.front();
    C.pop();
    return u;
}

int sortareTopologicaBFS(Digraf& D) {
    queue<int> C;

    for (int u = 0; u < D.n; u++) {
        if (D.np[u] == 0) {
            C.push(u);
        }
    }

    for (int k = 0; k < D.n; k++) {
        if (C.size() == 0) return 1;
        int u = elimina(C);
        D.L[D.Ln++] = u;
        Node* p = &D.a[u];
        while (p != NULL) {
            int v = p->elt;
            D.np[v]--;
            if (D.np[v] == 0) C.push(v);
            p = p->succ;
        }
    }

    return 0;
}

int main() {
    int graf[NODES][NODES] = {
        {0,1,0,1,0,0},
        {0,0,1,0,0,0},
        {0,0,0,1,1,0},
        {0,0,0,0,1,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0}
    };

    Digraf digraf;
    initGraf(digraf, graf);

    int sortare = sortareTopologicaBFS(digraf);
    if (sortare == 1) {
        cout << "Graful contine cicluri" << endl;
        return 1;
    }

    for (int i = 0; i < NODES; i++) {
        cout << (char)(digraf.L[i] + 'A') << " ";
    }
    cout << endl;

    return 0;
}