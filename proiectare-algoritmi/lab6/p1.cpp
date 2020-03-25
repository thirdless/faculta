#include<ctime>
#include<iostream>
#include<stdlib.h>

#define LUN 10000

using namespace std;

void interclasare(int a[], int p, int q, int m, int temp[]) {
    int i = p;
    int j = m + 1;
    int k = -1;

    while ((i <= m) && (j <= q)) {
        k++;
        if(a[i] <= a[j]){
            temp[k] = a[i];
            i++;
        }
        else {
            temp[k] = a[j];
            j++;
        }
    }

    while (i <= m) {
        k++;
        temp[k] = a[i];
        i++;
    }

    while (j <= q) {
        k++;
        temp[k] = a[j];
        j++;
    }
}

void merge_sort(int a[], int p, int q) {
    if (p < q) {
        int * temp = new int[q - p];
        int m = (p + q) / 2;

        merge_sort(a, p, m);
        merge_sort(a, m + 1, q);
        interclasare(a, p, q, m, temp);

        for (int i = p; i < q + 1; i++) a[i] = temp[i - p];

    }
}

void interschimba(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void partitioneaza(int * a, int p, int q, int &k){
    int x = a[p],
        i = p + 1,
        j = q;

    while (i <= j) {
        if (a[i] <= x) ++i;
        if (a[j] >= x) --j;
        if (i < j) {
            if ((a[i] > x) && (x > a[j])) {
                interschimba(a[i], a[j]);
                ++i;
                --j;
            }
        }
    }

    k = i - 1;
    a[p] = a[k];
    a[k] = x;

}

void quick_sort1(int a[], int p, int q) {
    if (p < q) {
        int k = (p + q) / 2;
        partitioneaza(a, p, q, k);
        quick_sort1(a, p, k - 1);
        quick_sort1(a, k + 1, q);
    }
}

void quick_sort2(int a[], int p, int q) {
    int k = (p + q) / 2;
    while (p < q) {
        partitioneaza(a, p, q, k);
        
        if (k - p > q - k) {
            quick_sort2(a, k + 1, q);
            q = k - 1;
        }
        else {
            quick_sort2(a, p, k - 1);
            p = k + 1;
        }
    }
}

void lista(int a[], int b[], int c[]) {

    for (int i = 0; i < LUN; i++) {
        a[i] = i;
    }

    for (int i = LUN - 1; i >= 0; i--) {
        b[i] = i;
    }

    for (int i = 0; i < LUN; i++) {
        c[i] = rand() % LUN;
    }
}

int main() {
    int * aleator = new int[LUN + 1],
        * invers = new int[LUN + 1],
        * ordine = new int[LUN + 1];

    int * liste[3] = { ordine, invers, aleator };
    void (*functii[3])(int*, int, int) = { merge_sort, quick_sort1, quick_sort2 };
    double times[9];
    int x = 0;
    clock_t start, stop;


    for (int i = 0; i < 3; i++) {
        lista(ordine, invers, aleator);
        for (int j = 0; j < 3; j++) {
            start = clock();
            (functii[j])(liste[i], 0, LUN - 1);
            stop = clock();
            times[x++] = ((double)(stop - start)) / CLOCKS_PER_SEC;
        }
    }

    cout << "Vector Ordonat: merge: " << times[0] << "s; quick1: " << times[1] << "s; quick2: " << times[2] << "s;\n";
    cout << "Vector Invers: merge: " << times[3] << "s; quick1: " << times[4] << "s; quick2: " << times[5] << "s;\n";
    cout << "Vector Aleator: merge: " << times[6] << "s; quick1: " << times[7] << "s; quick2: " << times[8] << "s;\n";

}
