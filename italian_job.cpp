#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int num, bigger_size, smaller_size, fine, meta;
	vector<int> primo, secondo, fusione;
	vector<int> bigger_vector, smaller_vector;
	bool finished;

	cout << endl << "--- PRIMA PARTE ---" << endl;

	/* Scrivere un programma che crea due array dinamici "primo" e
	"secondo", l'array "primo" viene popolato da valori presi da tastiera
	finché non viene inserito un numero che sia dispari e multiplo di 5. */

	finished = false;
	while (!finished) {
		cout << "Inserisci il valore: ";
		cin >> num;
		if (num % 2 != 0 && num % 5 == 0) {
			finished = true;
		} else {
			primo.push_back(num);
		}
	}

	cout << "Il mio vettore e' lungo: " << primo.size() << endl;
	cout << "Valori di vettore primo:";
	for (int i = 0; i < primo.size(); ++i) {
		cout << " " << primo[i];
	}

	cout << endl << "--- SECONDA PARTE ---" << endl;

	/* L'array "secondo " viene popolato da valori presi da tastiera,
	finche non inseriamo un valore che è un multiplo dei valori già presenti
	in array "secondo". */

	finished = false;
	while (!finished) {
		cout << "Inserisci il valore: ";
		cin >> num;
		for (int i = 0; i < primo.size(); ++i) {
			if (num % primo[i] == 0) {
				finished = true;
				break;
			}
		}
		if (!finished) {
			secondo.push_back(num);
		}
	}

	cout << "Il mio vettore e' lungo: " << secondo.size() << endl;
	cout << "Valori di vettore secondo:";
	for (int i = 0; i < secondo.size(); ++i) {
		cout << " " << secondo[i];
	}

	cout << endl << "--- PARTE TERZA ---" << endl;

	/* Creare un terzo array "fusione" che contiene i valori di "primo" e
	"secondo" in modo alternato finche è possibile, esempio
	"primo"=2,4,6,8,2,13,21 mentre "secondo"= 1,3,5,7 "fusione" risulterà
	essere=2,1,4,3,6,5,8,7,2,13,21 */

	if (primo.size() > secondo.size()) {
		bigger_size = primo.size();
		smaller_size = secondo.size();
		bigger_vector = primo;
		smaller_vector = secondo;
	} else {
		bigger_size = secondo.size();
		bigger_size = primo.size();
		bigger_vector = secondo;
		smaller_vector = primo;
	}

	for (int i = 0; i < bigger_size; ++i) {
		fusione.push_back(bigger_vector[i]);
		if (i < smaller_size) {
			fusione.push_back(smaller_vector[i]);
		}
	}

	cout << "Il mio vettore e' lungo: " << fusione.size() << endl;
	cout << "Valori di vettore fusione:";
	for (int i = 0; i < fusione.size(); ++i) {
		cout << " " << fusione[i];
	}

	cout << endl << "--- PARTE QUATTRO ---" << endl;

	/* Verranno aggiunti 2 valori a "fusione" a scelta dell'utente e in
	posizioni sempre scelte dall'utente. */

	int valore, posizione;
	cout << "In quale posizione vuoi inserire ";
	cout << "il PRIMO valore nel vettore fusione? ";
	cin >> posizione;
	cout << "Quale valore vuoi inserire nel vettore fusione? ";
	cin >> valore;
	fusione.insert(fusione.begin() + posizione, valore);

	cout << "In quale posizione vuoi inserire ";
	cout << "il SECONDO valore nel vettore fusione? ";
	cin >> posizione;
	cout << "Quale valore vuoi inserire nel vettore fusione? ";
	cin >> valore;
	fusione.insert(fusione.begin() + posizione, valore);

	cout << "Il mio vettore e' lungo: " << fusione.size() << endl;
	cout << "Valori di vettore fusione:";
	for (int i = 0; i < fusione.size(); ++i) {
		cout << " " << fusione[i];
	}

	cout << endl << "--- PARTE QUINTA ---" << endl;

	/* Da "fusione" verranno cancellati i valori in posizione iniziale,
	finale, e a metà (mi raccomando attenzione agli indici). */

	fusione.erase(fusione.begin());

	fine = fusione.size() - 1;
	fusione.erase(fusione.begin() + fine);

	fine = fusione.size() - 1;
	if (fine % 2 == 0) {
		meta = fine / 2;
		fusione.erase(fusione.begin() + meta);
	}

	cout << "Il mio vettore e' lungo: " << fusione.size() << endl;
	cout << "Valori di vettore fusione:";
	for (int i = 0; i < fusione.size(); ++i) {
		cout << " " << fusione[i];
	}

	cout << endl << "--- PARTE SESTA ---" << endl;

	/* Da "fusione" verranno tutti i valori pari. */

	for (int i = 0; i < fusione.size(); ++i) {
		if (fusione[i] % 2 != 0) {
			fusione.erase(fusione.begin() + i);
		}
	}

	cout << "Il mio vettore e' lungo: " << fusione.size() << endl;
	cout << "Valori di vettore fusione:";
	for (int i = 0; i < fusione.size(); ++i) {
		cout << " " << fusione[i];
	}
}
