#include<iostream>
using namespace std;

struct Atom {
	int data;
	Atom* left, *right;
};

Atom* removeGreatest(Atom*& r)
{
	Atom* p;
	if (r->right == 0) {
		p = r;
		r = r->left;
		return p;
	}
	else return removeGreatest(r->right);
}

void deleteRoot(Atom*& root)
{
	Atom* p = root;
	if (root->left == 0) root = root->right;
	else if (root->right == 0) root = root->left;
	else {
		root = removeGreatest(root->left);
		root->left = p->left;
		root->right = p->right;
	}
	delete p;
}


void del(Atom*& root, int a)
{
	if (root == NULL)
		cout << "Eroare: Valoarea " << a << " nu este in arbore!";
	else if (a < root->data) del(root->left, a);
	else if (a > root->data) del(root->right, a);
	else deleteRoot(root);
}

Atom* make_nod(int a)
{
	Atom p = new Atom;
	p->data = a;
	p->left = p->right = 0;
	return p;
}

Atom search(Atom r, int k)
{
	if (r == 0 || r->data == k)
		return r;
	else if (k < (r->data))
		return search(r->left, k);
	else if (k > (r->right, k))
		return search(r->right, k);
}

void insert(Atom r, int a)
	if (r == 0) {	
		r = make_nod(a);
	}
	else if (a > r->data) {
		insert(r->right, a);
	}
	else if(a < r->data){
		insert(r->right, a);
	}
}


int main() {
	Atom * p;
	insert(p, 100);
	insert(p, 200);
}
