#include <bits/stdc++.h>
using namespace std;

double tab[784];
const pair <int, int> limit = { 60000,10000 };
double rate = 0.5;
double wynik=0;
double expt[10];
ifstream inimg, inlbl;
int l, r, spare,iter=0;
const int weig = 81285;
const int rozm[4] = { 784,100,25,10 };
pair<double, double> wagi[weig];

class node {
public:
	double wynik = 0;
	double impact = 0;
	int bias;
	vector <pair<int, int> > back_con;

	void act_func() {
		wynik = wynik / (1 + abs(wynik));
	}
};
vector <node> model[4];
int xd;

//declarations
void train();
void expect();
void go_forward();
void go_back();
void built_model();
void get_weights();
void write_weights();
int give_ans();
void read_data();
void check_ac();
void build_weights();

int main()
{
	/*while (wynik < 1) {
		check_ac();
		//system("CLS");
		cout << "Iteracja: " << iter << "\n";
		cout << "Wynik: " << wynik << "\n";
		iter++;
		train();
		rate /= 2;
		//cout << "New Line\n";
	}
	*/
	check_ac();
	cout << wynik << "\n";
	system("pause");
	//built_model();
}

void check_ac() {
	int N, k, odp;
	double l = 0, m = 0;
	inimg.open("../../../test/test-images.txt");
	inlbl.open("../../../test/test-labels.txt");
	inimg >> N >> N >> N;
	inlbl >> N;

	built_model();
	get_weights();

	//N = min(N, limit.second);
	for (int i = 1; i <= N; i++) {
		if (i % 1000 == 0) {
			//cout << l << " " << m << "\n";
			//cout << "Test " << i << "\n";
		}
		read_data();
		go_forward();
		inlbl >> k;
		m+=1;
		odp = give_ans();
		//cout << k << " " << odp << "\n";
		if (k == odp) {
			l+=1;
		}
	}
	inimg.close();
	inlbl.close();
	wynik = l / m;
}

void train() {
	int N;
	inimg.open("../../../train/train-images.txt");
	inlbl.open("../../../train/train-labels.txt");
	inimg >> N >> N >> N;
	inlbl >> N;
	built_model();
	get_weights();
	//N = min(N, limit.first);
	for (int i = 1; i <= N; i++) {
		read_data();
		go_forward();
		expect();
		go_back();
		if (i % 100 == 0) {
			//cout << "Train " << i << "\n";
			write_weights();
		}
	}
	inimg.close();
	inlbl.close();
}

void expect() {
	int N;
	inlbl >> N;
	for (int i = 0; i < 10; i++) {
		expt[i] = -1.0;
		if (i == N) {
			expt[i] = 1.0;
		}
	}
}

void go_back() {
	for (int i = 0; i < 10; ++i) {
		model[3][i].impact = model[3][i].wynik - expt[i];
	}
	for (int i = 3; i > 0; --i) {
		//cout << model[0].size() << "\n";
		for (int z = 0; z < model[i].size(); z++) {
			model[i][z].impact /= (abs(model[3][i].wynik) + 1);
			model[i][z].impact /= (abs(model[3][i].wynik) + 1);


			wagi[model[i][z].bias].second = model[i][z].impact;
			for (int j = 0; j < model[i][z].back_con.size(); j++) {
				wagi[model[i][z].back_con[j].second].second = model[i][z].impact * model[i - 1][model[i][z].back_con[j].first].wynik;
				model[i - 1][model[i][z].back_con[j].first].impact += wagi[model[i][z].back_con[j].second].first * model[i][z].impact;
			}
		}
	}
}

void read_data() {
	for (int i = 0; i < 784; i++) {
		inimg >> tab[i];
		model[0][i].wynik = tab[i]/255;
	}
}

void go_forward() {
	for (int i = 1; i < 4; i++) {
		for (int z = 0; z < model[i].size(); z++) {
			model[i][z].wynik = wagi[model[i][z].bias].first;
			model[i][z].impact = 0;
			for (int j = 0; j < model[i][z].back_con.size(); j++) {
				//cout<<wagi[model[i][z].back_con[j].second].first<<" "<< model[i - 1][model[i][z].back_con[j].first].wynik << "\n";
				model[i][z].wynik += wagi[model[i][z].back_con[j].second].first * model[i - 1][model[i][z].back_con[j].first].wynik;
			}
			model[i][z].act_func();
		}
		//cout << "Changing layers\n";
	}
	//cout << model[0].size() << "\n";
}

int give_ans() {
	int ans = -1;
	double high = -99999;
	for (int i = 0; i < 10; i++) {
		//cout<<model[3][i].wynik<<" ";
		if (model[3][i].wynik > high) {
			high = model[3][i].wynik;
			ans = i;
		}
	}
	//cout<<"\n";
	return ans;
}

void built_model() {
	node obj1;
	for (int i = 0; i < 4; i++) {
		model[i].clear();
		for (int z = 0; z < rozm[i]; z++) {
			model[i].push_back(obj1);
		}
	}
	build_weights();
}

void build_weights() {
	int poz = 0;
	for (int i = 1; i < 4; i++) {
		for (int z = 0; z < rozm[i - 1]; z++) {
			for (int j = 0; j < rozm[i]; j++) {
				model[i][j].back_con.push_back(make_pair(z, poz));
				poz++;
			}
		}
		for (int z = 0; z < rozm[i]; z++) {
			model[i][z].bias = poz;
			poz++;
		}
	}
}

void get_weights() {
	fstream wg;
	wg.open("../../../weights/weights.txt", ios::in);
	for (int i = 0; i < weig; i++) {
		wg >> wagi[i].first;
		wagi[i].second = 0;
	}
	wg.close();
}

void write_weights() {
	fstream wg;
	wg.open("../../../weights/weights.txt", ios::out);
	for (int i = 0; i < weig; i++) {
		wagi[i].first = wagi[i].first - wagi[i].second * rate;
		wagi[i].second = 0;
		wg << wagi[i].first << "\n";
	}
	wg.close();
}