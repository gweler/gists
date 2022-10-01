#include <iostream>
#include <vector>

using namespace std;

void print_exercise_text() {
	const string exercise_text = ""
		"Scrivere un programma in cui viene creato un array dinamico,\n"
		"in questo array continueranno a venir aggiunti valori finchè\n"
		"l'utente non inserirà il valore terminatore -100, che quindi\n"
		"non deve essere presente nell'array. L'array verrà quindi\n"
		"ordinato in modo decrescente (dal num più grande al num più\n"
		"piccolo) e verranno cancellati tutti i numeri pari presenti\n"
		"nell'arryay, poi verranno inseriti 3 valori uno all'inizio,\n"
		"uno alla fine e uno in mezzo all'array.\n";

	cout << exercise_text << endl;
}

void print_vector(vector<int> v) {
	cout << endl << "Vector elements: ";
	for (int i : v) {
		cout << i << " ";
	}
	cout << endl << endl;;
}

int main(int argc, char *argv)
{
	bool elements_swapped, value_found;
	int entered_value, swap_holder, middle_index;
	int beginning_value, middle_value, end_value;
	const int TERMINATING_VALUE = -100;
	vector<int> vektor;
	vector<int>::iterator iter;

	print_exercise_text();

	cout << "--- Vector input ---" << endl;

	do {
		cout << "Enter an integer (-100 exits): ";
		cin >> entered_value;
		if (entered_value != TERMINATING_VALUE) {
			vektor.push_back(entered_value);
		} else {
			cout << "User entered -100, input completed." << endl;
		}

	} while (entered_value != TERMINATING_VALUE);

	if (vektor.empty()) {
		cout << "User did not enter any values, program exits." << endl;
		return 0;
	}

	print_vector(vektor);

	cout << "--- Sorting the vector ---" << endl;

	do {
		elements_swapped = false;
		for (int i = 0; i < vektor.size() - 1; ++i) {
			if (vektor.at(i) < vektor.at(i + 1)) {
				swap(vektor.at(i), vektor.at(i + 1));
				elements_swapped = true;
			}
		}
	} while (elements_swapped);

	print_vector(vektor);

	cout << "--- Remove (erase) all even numbers in the vector ---" << endl;

	do {
		value_found = false;
		for (iter = vektor.begin(); iter != vektor.end(); ++iter) {
			if (*iter % 2 == 0) {
				vektor.erase(iter);
				value_found = true;
				break;
			}
		}
	} while (value_found);

	print_vector(vektor);

	cout << "--- Insert three values ---" << endl;

	cout << "Integer to insert at the beginning: ";
	cin >> beginning_value;

	cout << "Integer to insert in the middle   : ";
	cin >> middle_value;

	cout << "Integer to insert at the end      : ";
	cin >> end_value;

	vektor.insert(vektor.begin(), beginning_value);
	vektor.insert(vektor.end(), end_value);

	if (vektor.size() % 2 == 0) {
		middle_index = vektor.size() / 2;
	} else {
		middle_index = (vektor.size() - 1) / 2;
	}
	vektor.insert(vektor.begin() + middle_index, middle_value);

	print_vector(vektor);

	return 0;
}
