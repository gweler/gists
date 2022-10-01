#include <iostream>
#include <vector>

using namespace std;

/* Scrivi un codice diversi.cpp che, dati due vettori di interi, stampi a schermo
i valori presenti nel primo vettore ma non nel secondo. Usa un array di appoggio
dichiarato come oggetto della classe vector e manipolalo usando i metodi della
classe. Nel codice usa come caso di prova i due vettori {2,10,6,8,4} e {1,2,3,4,5,6}. */

class MyVector {

	private:

	vector<int> vektor;

	public:

	MyVector(vector<int> v) {
		vektor = v;
	}

	int at(int i) {
		return vektor.at(i);
	}

	int size() {
		return vektor.size();
	}

	bool contains(int e) {
		for (int i : vektor) {
			if (e == i) {
				return true;
			}
		}
		return false;
	}
};

int main(int argc, char *argv)
{
	bool there_were_none = true;

	MyVector v1 = MyVector({2, 10, 6, 8, 4});
	MyVector v2 = MyVector({1, 2, 3, 4, 5, 6});

	cout << "Elements present in v1 but not in v2 are:";
	for (int i = 0; i < v1.size(); ++i) {
		if (!v2.contains(v1.at(i))) {
			cout << " " << v1.at(i);
			there_were_none = false;
		}
	}

	if (there_were_none) {
		cout << " None";
	} else {
		cout << "." << endl;
	}

	return 0;
}
