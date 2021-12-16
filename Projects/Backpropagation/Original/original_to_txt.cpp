#include <bits/stdc++.h>
using namespace std;

int magic,images,row,col;
int number;


unsigned int input(ifstream& in, unsigned int size);
int main() {
	ifstream in;
	fstream out;
	in.open("../../../test/t10k-images.idx3-ubyte", ios::binary);
	out.open("../../../test/test-images.txt", ios::out);
	magic = input(in, 4);
	images = input(in, 4);
	row = input(in, 4);
	col = input(in, 4);		
	out << images << "\n" << row << " " << col << "\n";

	for (int i = 0; i < images; i++) {
		if (!(i % 1000)) {
			cout << i << "\n";
		}
		for (int z = 0; z < row; z++) {
			for (int j = 0; j < col; j++) {
				number = input(in, 1);
				out << number << " ";
			}
			out << "\n";
		}
		out << "\n";
	}

	in.close();
	out.close();

	in.open("../../../test/t10k-labels.idx1-ubyte", ios::binary);
	out.open("../../../test/test-labels.txt", ios::out);
	magic = input(in, 4);
	images = input(in, 4);
	out << images << "\n\n";
	for (int i = 0; i < images; i++) {
		if (!(i % 1000)) {
			cout << i << "\n";
		}
		number = input(in, 1);
		out << number << "\n";
	}

	in.close();
	out.close();
}

unsigned int input(ifstream& in, unsigned int size) {
	unsigned int ans = 0;
	for (int i = 0; i < size; i++) {
		unsigned char x;
		in.read((char*)&x, 1);
		unsigned int temp = x;
		ans <<= 8;
		ans += temp;
	}
	return ans;
}