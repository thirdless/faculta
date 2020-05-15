#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<fstream>

using namespace std;

#define STACK 256

struct Tree
{
				Tree* left, * right;
				char letter;
				int freq;
};

struct comp {
				bool operator()(const Tree* a, const Tree* b) const {
								return a->freq > b->freq;
				}
};

void sortTree(vector<Tree*> tree) {
    Tree* aux;
    for (int i = 0; i < tree.size(); i++) {
        for (int j = 0; j < tree.size() - 1; j++) {
            if (tree[j]->freq > tree[j + 1]->freq) {
                aux = tree[j];
                tree[j] = tree[j + 1];
                tree[j + 1] = aux;
            }
        }
    }
}

void createHeap(map<char, int>frecv, vector<Tree*> &output) {
				map<char, int>::iterator it;
				vector<Tree*> list;

				for (it = frecv.begin(); it != frecv.end(); it++) {
								Tree* nou = new Tree;
								nou->letter = it->first;
								nou->freq = it->second;
								nou->left = 0;
								nou->right = 0;
								
								list.push_back(nou);
				}

    sortTree(list);

				make_heap(list.begin(), list.end(), comp());

				while (list.size() != 1) {
								pop_heap(list.begin(), list.end(), comp());

								Tree* left = list.back();
								list.pop_back();

								pop_heap(list.begin(), list.end(), comp());

								Tree* right = list.back();
								list.pop_back();

								Tree* nou = new Tree;
								nou->freq = left->freq + right->freq;
								nou->left = left;
								nou->right = right;
								list.push_back(nou);
								make_heap(list.begin(), list.end(), comp());
				}

				output = list;
}

void frequencies(const char * name, map<char,int> &output) {
				int array[STACK] = { 0 };

				FILE * file = NULL;
				errno_t err;
				char c;

				err = fopen_s(&file, name, "r");
				if (err != 0) {
								cout << "File not available\n";
								exit(0);
				}
				
				while ((c = fgetc(file)) != EOF) {
        array[(int)c] += 1;
				}

				fclose(file);

				char n;
				for (int i = 0; i < STACK; i++) {
								if (array[i] != 0) {
												n = (char)i;
												output[n] = array[i];
								}
				}
}

string getCode(int data[], int len) {
    string code = "";
    for (int i = 0; i < len; i++) {
        if (data[i] == 0) code += "0";
        else code += "1";
    }
    return code;
}

void generateCodes(map<char, string> &codes, Tree* top, int data[], int index) {
				if (top->left) {
								data[index] = 0;
								generateCodes(codes, top->left, data, index + 1);
				}
				if (top->right) {
								data[index] = 1;
								generateCodes(codes, top->right, data, index + 1);
				}
				if (!top->left && !top->right) {
								codes[top->letter] = getCode(data, index);
				}
}

void encodeText(const char * inputname, const char * outputname, map<char, string> codes) {
    
    FILE* input = NULL;
    errno_t err1;
    char c;

    err1 = fopen_s(&input, inputname, "r");
    ofstream output(outputname);

    while ((c = fgetc(input)) != EOF) {
        output << codes[c] << " ";
    }

    fclose(input);
}

int main() {
				int temp_data[100];
				map<char, int> frecv;
    map<char, string> codes;
				vector<Tree*> tree;

				frequencies("input.txt", frecv);
				createHeap(frecv, tree);
				generateCodes(codes, tree[0], temp_data, 0);
    encodeText("input.txt", "output.txt", codes);
}
