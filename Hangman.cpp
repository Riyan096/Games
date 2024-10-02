#include <iostream>
#include <string>
using namespace std;

int main(){
    string words[] = {"japan", "turkey", "nepal", "malaysia", "philippines", "australia", "america", "ethiopia", "oman", "indonesia"};
    srand(time(NULL));
    bool revealed, wrongGuess;
    int rndNum;
    int tries = 5;
    string word, secret;
    char guess;
    rndNum = rand()% 10;
    word = words[rndNum];

    cout << "Welcome to hangman...Guess a country name" << endl;
    cout << "\nEach letter is represented by a star." << endl;
    cout << "\nYou have to type only one letter in one try" << endl;
    cout << "\nYou have 5 tries to try and guess the word." << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (int i=0 ; i < word.length(); i++) {
        secret += '*';
    }
    while(tries > 0 && secret != word){
        wrongGuess = false;
        cout << "\n\n" << secret << endl;
        cout << "\nGuess a letter: ";
        cin >> guess;
        for (int i = 0;  i < word.length(); i++) {
            if (guess == word[i] && secret[i] != guess){
                wrongGuess = false;
                secret[i] = guess;
                cout << "\nYou found a letter! Isn't that exciting!" << endl;
                break;
            }
            else{
                wrongGuess = true;
            }
        }
        if (wrongGuess == true) {
            cout << "\nWhoops! That letter isn't there!" << endl;
            tries--;
        }
        cout << "You have " << tries << " guesses left." << endl;
    }
    if (secret == word) {
        cout << "\n" << secret;
        cout << "\nYeah! You got it!";
    }
    else {
        cout << "\nUnlucky, you ran out of guesses! The word was: "<< word << "\nGood luck next time!" << endl;
    }
    return 0;
}