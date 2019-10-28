#include<conio.h>
#include<iostream>

using namespace std;

class Stiva {
private:
	int n;
	int * data;
public:
	Stiva();
	void push(int x);
	int pop();
	int top();
	void print();
	~Stiva();
};

Stiva::Stiva() {
	if (data) delete[] data;
	data = new int[1024];
	n = 0;
}

Stiva::~Stiva() {
	delete[] data;
	data = nullptr;
	n = 0;
}

void Stiva::push(int x) {
	data[n] = x;
	n++;
}

int Stiva::pop() {
	if (n != 0) {
		return data[n - 1];
		n--;
	}
	else return -1;
}

int Stiva::top() {
	if(n > 0) return data[n - 1];
}

void Stiva::print() {
	for (int i = n - 1; i >= 0; i--) cout << data[i] << " ";
	cout << endl;
}

int main() {
	Stiva s;
	s.push(4);
	s.push(3);
	cout << s.top() << endl;
	s.push(9);
	cout << s.pop() << endl;
	s.push(2);
	s.print();
	_getch();
	return 0;
}
