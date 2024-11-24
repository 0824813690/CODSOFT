
 // TASK2 SIMPLE CALCULATOR
#include <iostream>
using namespace std;

int main() {
    char choice;

    do {
        double number1, number2;
        char operation;

    cout << "Enter first number:   " << endl;
    cin >> number1;
    cout << "choose operation below (+, -, *, /):  "<< endl;
    cin >> operation;
    cout << "Enter second number:    "<< endl;
    cin >>  number2;

    double result;
    bool validOperation = true;

    switch(operation) {
        case '+':
            result = number1 + number2;
            break;
        case '-':
            result = number1 - number2;
            break;
        case '*':
            result = number1 * number2;
            break;
        case '/':
            if (number2 != 0) {
                result = number1 / number2;
            } else {
                cout << "Error: any number divide by zero is invalid " << endl;
                validOperation = false;
            }
            break;
        default:
            cout << "Error: operation dont exist " << endl;
            validOperation = false;
    }

    if (validOperation) {
        cout << "Result: " << result << endl;
    }

        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using the calculator. Goodbye!" << endl;
    return 0;
}
