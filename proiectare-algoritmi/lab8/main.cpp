#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Tree
{
    Tree* left, * right;
    int val;

};
struct comp {
    bool operator()(const Tree* a, Tree* b) const {
        return a->val > b->val;
    }
};

int main() {

    int a[] = { 32,67,21,1,90,23 };
    vector<Tree*> v;
    for (int i = 0; i < 6; i++)
    {
        Tree* n = new Tree;
        n->val = a[i];
        n->left = 0;
        n->right = 0;
        v.push_back(n);
    }

    cout << "Termeni: ";
    for (Tree* i : v) cout << i->val << " ";
    cout << endl;

    make_heap(v.begin(), v.end(), comp());

    int s = 0;

    while (v.size() != 1)
    {
        pop_heap(v.begin(), v.end(), comp());

        Tree* top1 = v.back();
        v.pop_back();
        cout << "Top 1: " << top1->val << endl;

        pop_heap(v.begin(), v.end(), comp());

        Tree* top2 = v.back();
        v.pop_back();
        cout << "Top 2: " << top2->val << endl;

        Tree* n = new Tree;
        n->val = top1->val + top2->val;
        n->left = top1;
        n->right = top2;
        s += n->val;
        cout << "s = " << s << endl;
        v.push_back(n);
        make_heap(v.begin(), v.end(), comp());

        cout << "Interclasare: ";
        for (Tree* i : v) cout << i->val << " ";
        cout << endl;

    }
    cout << endl << "LEP = " << s;
}
