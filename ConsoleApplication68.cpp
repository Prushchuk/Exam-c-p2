#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

vector<string> words = { "apple", "banana", "orange", "grape", "kiwi", "strawberry" };

string selectRandomWord() {
    srand(time(0));
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

bool isLetterInWord(char letter, const string& word) {
    for (int i = 0; i < word.length(); ++i) {
        if (word[i] == letter)
            return true;
    }
    return false;
}

void displayWord(const string& word, const vector<char>& guessedLetters) {
    for (int i = 0; i < word.length(); ++i) {
        char c = word[i];
        if (find(guessedLetters.begin(), guessedLetters.end(), c) != guessedLetters.end()) {
            cout << c << " ";
        }
        else {
            cout << "_ ";
        }
    }
    cout << endl;
}

int main() {
    string word = selectRandomWord();
    vector<char> guessedLetters;
    int attempts = 0;
    time_t startTime = time(0);

    cout << "Try to guess the word.\n";

    while (true) {
        displayWord(word, guessedLetters);
        cout << "Enter a letter: ";
        char letter;
        cin >> letter;

        if (isLetterInWord(letter, word)) {
            guessedLetters.push_back(letter);
            cout << "Correct guess!\n";
        }
        else {
            cout << "Incorrect guess!\n";
            attempts++;
        }

        bool guessed = true;
        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            if (find(guessedLetters.begin(), guessedLetters.end(), c) == guessedLetters.end()) {
                guessed = false;
                break;
            }
        }

        if (guessed) {
            cout << "Congratulations! You guessed the word.\n";
            break;
        }

        if (attempts == 6) {
            cout << "You have run out of attempts. The word was: " << word << endl;
            break;
        }
    }

    time_t endTime = time(0);
    double elapsedTime = difftime(endTime, startTime);

    cout << "Game statistics:\n";
    cout << "Time taken: " << elapsedTime << " seconds\n";
    cout << "Number of attempts: " << attempts << endl;
    cout << "Word: " << word << endl;
    cout << "Guessed letters: ";
    for (int i = 0; i < guessedLetters.size(); ++i) {
        cout << guessedLetters[i] << " ";
    }
    cout << endl;
}