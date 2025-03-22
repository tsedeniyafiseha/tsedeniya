#include <iostream>
using namespace std;

int multiply(int firstNumber, int secondNumber) {
    return firstNumber * secondNumber;
}

double divide(double numerator, double denominator) {
    return numerator / denominator;
}

int main() {
    int wholeNumber1 = 5, wholeNumber2 = 2;
    double decimalNumber1 = 5.0, decimalNumber2 = 2.0;

    cout << "Multiplication result: " << multiply(wholeNumber1, wholeNumber2) << endl;
    cout << "Division result: " << divide(decimalNumber1, decimalNumber2) << endl;
    
    return 0;
}
