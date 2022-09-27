#include <chrono>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

void guess_letter()
{
	string letters = "abcdefghijklmnopqrstuvwxyz";
	srand(time(NULL));
	int i = rand() % letters.length();
	string letter = string(1, letters[i]);

	string guess;
	bool guessed = false;
	cout << "Target letter: " << letter << endl;
	while (!guessed) {
		cout << "Your letter: ";
		cin >> guess;
		if (guess.compare(letter) == 0) {
			guessed = true;
		}
	}
	return;
}

int main()
{
	int numofLetters = 3;
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < numofLetters; ++i) {
		guess_letter();
	}
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
	cout << "Your time: " << duration.count();
	cout << " milliseconds" << endl;
	return 0;
}
