#include <iostream>
#include <vector>
using namespace std;

struct pereche {
    int x, y;
};

vector<pereche*> interclGrafice(vector<pereche*> S, vector<pereche*> T) {

    vector<pereche*> temp;
    int j = 0, k = 0;
    
    pereche* p = new pereche;
    p->x = 0;
    p->y = 0;
    temp.push_back(p);
    
    while (j < S.size() && k < T.size()) {
        int L = 1;
        if (L == 1) {
            if (S[j]->x < T[k]->x) {
                temp.push_back(S[j]);
                j++;
            }
            else if (S[j]->x == T[k]->x) {
                if (S[j]->y > T[k]->y) {
                    temp.push_back(S[j]);
                    j++;
                    k++;
                }
                else if (S[j]->y < T[k]->y) {
                    temp.push_back(T[k]);
                    L = 2;
                    j++;
                    k++;
                }
                else {
                    k++;
                    j++;
                }
            }
            else if (S[j]->x > T[k]->x || j > S.size()) {
                if (S[j - 1]->y > T[k]->y) k++;
                else if (S[j - 1]->y < T[k]->y) L = 2;
                else {
                    k++;
                    j++;
                }
            }
        }
        if (L == 2) {
            if (T[k]->x < S[j]->x) {
                temp.push_back(T[k]);
                k++;
            }
            else if (T[k]->x == S[j]->x) {
                if (T[k]->y > S[j]->y) {
                    temp.push_back(T[k]);
                    j++;
                    k++;
                }
                else if (T[k]->y < S[j]->y) {
                    temp.push_back(S[j]);
                    L = 2;
                    j++;
                    k++;
                }
            }
            else if (T[k]->x > S[j]->x || k > S.size()) {
                if (T[k - 1]->y > S[j]->y) j++;
                if (T[k - 1]->y < S[j]->y) L = 1;
            }
        }
    }

    while (j < S.size())
    {
        int size = temp.size();
        if (size > 0 && S[j]->y > temp[size - 1]->y) temp.push_back(S[j]);
        
        j++;
    }
    while (k < T.size())
    {
        int size = temp.size();
        if (size > 0 && T[k]->y > temp[size - 1]->y) temp.push_back(T[k]);

        k++;
    }

    return temp;
}

vector<pereche*> puncte(vector<pereche*>param, int x, int y) {
    vector<pereche*> temp;
    pereche* punct;

    for (int i = 0; i < param.size(); i++)
    {
        punct = new pereche;
        punct->x = param[i]->x + x;
        punct->y = param[i]->y + y;
        temp.push_back(punct);
    }

    return temp;
}

bool contine(vector<pereche*> param, int x, int y)
{
    for (int i = 0; i < param.size(); i++)
    {
        if (param[i]->x == x && param[i]->y == y) return true;
    }
    return false;
}

void afisare(vector<pereche*>param, const char * text, int index) {
    cout << text << "[" << index << "] = ";
    for (int i = 0; i < param.size(); i++) {
        cout << "(" << param[i]->x << "," << param[i]->y << ")";
    }
    cout << endl;
}

void rucsac(int M, int n, int w[], int p[], int x[]) {
    vector<pereche*>* S = new vector<pereche*>[n + 1];
    vector<pereche*>* T = new vector<pereche*>[n];

    pereche* temp = new pereche;
    temp->x = 0;
    temp->y = 0;
    S[0].push_back(temp);

    temp = new pereche;
    temp->x = w[0];
    temp->y = p[0];
    T[0].push_back(temp);

    afisare(S[0], "S", 0);

    for (int i = 1; i < n; i++) {
        S[i] = interclGrafice(S[i - 1], T[i - 1]);
        T[i] = puncte(S[i], w[i], p[i]);
        afisare(T[i], "T", i);
        afisare(S[i], "S", i);
    }
    
    S[n] = interclGrafice(S[n - 1], T[n - 1]);
    afisare(S[n], "S", n);

    pereche* sol = NULL;
    for (int i = 0; i < S[n].size(); i++) {
        if (S[n][i]->x <= M) {
            sol = S[n][i];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (contine(S[i], sol->x, sol->y))
        {
            x[i] = 0;
        }
        else {
            x[i] = 1;
        }
    }

    cout << "\nSolutia este: (" << sol->x << "," << sol->y << ")";
    
}


int main()
{
    #define N 3
    #define CAPACITY 10

    int w[N] = { 3,5,6 };
    int p[N] = { 10,30,20 };
    int x[N] = { 0 };

    rucsac(CAPACITY, N, w, p, x);
    
    cout << " -> ";
    for (int i = 0; i < N; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}
