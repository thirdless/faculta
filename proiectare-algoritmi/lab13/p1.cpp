#include<iostream>
#include<ctime>
using namespace std;

#define LEN 4

void submultimiOpt(int s, int k, int r, int M, int w[], int x[]) {
    x[k] = 1;
    if (s + w[k] == M) {
        for (int i = 0; i < LEN; i++) cout << x[i] << " ";
        cout << endl;
    }
    else if (s + w[k] + w[k + 1] <= M) {
        submultimiOpt(s + w[k], k + 1, r - w[k], M, w, x);
    }

    if ((s + r - w[k] >= M) && (s + w[k + 1] <= M)) {
        x[k] = 0;
        submultimiOpt(s, k + 1, r - w[k], M, w, x);
    }
}

void submultimi(int s, int k, int r, int M, int w[], int x[]) {
    x[k] = 1;
    if (s + w[k] == M) {
        for (int i = 0; i < LEN; i++) cout << x[i] << " ";
        cout << endl;
    }
    else if (s + w[k] <= M) {
        submultimi(s + w[k], k + 1, r - w[k], M, w, x);
    }

    if (s + r - w[k] >= M) {
        x[k] = 0;
        submultimi(s, k + 1, r - w[k], M, w, x);
    }
}

int main()
{
    int s = 0, k = 0, r = 0;
    int w[LEN] = { 4,7,11,14 },
        x[LEN] = { 0 },
        x1[LEN] = { 0 }, 
        M = 25;

    for (int i = 0; i < LEN; i++) r += w[i];

    cout << "Optim:" << endl;
    submultimiOpt(s, k, r, M, w, x);
    cout << "Neoptim:" << endl;
    submultimi(s, k, r, M, w, x1);
}
