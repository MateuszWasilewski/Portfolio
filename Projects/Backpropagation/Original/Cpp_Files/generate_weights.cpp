// Mateusz Wasilewski

#include <bits/stdc++.h>

using namespace std;

double wg;
int change,wynik;
const int lim = 1e6;
const int row = 28;
const int col = 28;
const int hl1 = 100;
const int hl2 = 25;
const int ol = 10;
int rozm[4] = { 784,100,25,16 };

void gen(fstream &out);

int main()
{
	fstream out;
	out.open("weights/weights.txt", ios::out);
	srand(time(0));
	int poz = 0;
	for (int i = 1; i < 4; i++) {
		for (int z = 0; z < rozm[i - 1]; z++) {
			for (int j = 0; j < rozm[i]; j++) {
				gen(out);
			}
		}
		for (int z = 0; z < rozm[i]; z++) {
			gen(out);
		}
	}

	out.close();
}

void gen(fstream &out) {
	wynik++;
	wg = rand() % lim;
	wg /= lim;
	wg *= 100;
	change = rand() % 2;
	if (change) {
		wg *= -1;
	}
	out << wg << "\n";
}
