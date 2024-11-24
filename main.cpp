
 //TASK ONE: NUMBER GUESSING GAME

#include <iostream>
#include <cstdlib>
#include <ctime>
 using namespace std;
int main() {

    srand(time(0));

    int randomNumber = rand() % 100 + 1;
    int guess = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a random number between 1 and 100." << endl;
    cout << "can you guess it? then you can START!" << endl;
    cout << "\n";
    cout << "*****GOODLUCK*****"<< endl;
   while (true) {
        cout << "Enter your guess:    ";
        cin >> guess;

        if (guess > randomNumber) {
            cout << "\nToo high! Try again.\n\n";
        } else if (guess < randomNumber) {
            cout << "\nToo low! Try again.\n\n";
        } else {
            cout << "\nCongratulations! You guessed the correct number: "
                      << randomNumber << "\n\n";
            break;
        }
    }


    return 0;
}
