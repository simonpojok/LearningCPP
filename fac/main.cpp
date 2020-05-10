/*
 * Computes and prints n! for a give n.
 * Uses several basics elements of C++.
*/
#include <iostream>
int main() {
    using namespace std;
    int factArg;
    int fact(1);
    do {
        cout << "Factorial of: ";
        cin >> factArg;
        if (factArg < 0 ) {
            cout << "No negative values, please!" << endl;
        }
    } while(factArg < 0);

    int i = 2;
    while (i <= factArg ) {
        fact = fact * i;
        i = i + 1;
    }
    cout << "The factorial of " << factArg << " is: " << fact << endl;
    return 0;
}
