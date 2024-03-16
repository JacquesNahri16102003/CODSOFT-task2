#include <cstdlib>
#include <iostream>

using namespace std;

double addition(double, double);
double subtraction(double, double);
double multiplication(double, double);
double division(double, double);
double power(double, int); // recursive approach
double powAux(double, int); // auxiliary function for the power function

int main(int argc, char** argv) {
    cout << "Welcome to the calculator program." << endl;

    while (1) {
        double a = 0;
        double b = 0;
        char op;
        int result = 0;

        cout << "Enter the desired operation (+ , - , * , / , ^) or 0 to exit: ";
        cin >> op;

        if (op == '0') {
            cout << "Thank you for using this calculator.";
            break;
        }

        cout << "Enter the first number: ";
        cin >> a;

        cout << "Enter the second number: ";
        cin >> b;
        cout << endl;

        if (op == '+') {
            result = addition(a, b);
            cout << a << " + " << b << " = " << result << endl;
            cout << endl;
        } else if (op == '-') {
            result = subtraction(a, b);
            cout << a << " - " << b << " = " << result << endl;
            cout << endl;
        } else if (op == '*') {
            result = multiplication(a, b);
            cout << a << " * " << b << " = " << result << endl;
            cout << endl;
        } else if (op == '/') {
            result = division(a, b);
            if (result == -1) {
                cout << "Math error: Division by zero." << endl;
            } else {
                cout << a << " / " << b << " = " << result << endl;
            }
            cout << endl;
        } else if (op == '^') {
            result = power(a, (int) b);
            cout << a << " ^ " << b << " = " << result << endl;
            cout << endl;
        }
    }
    return 0;
}

double addition(double a, double b) {
    return a + b;
}

double subtraction(double a, double b) {
    return a - b;
}

double multiplication(double a, double b) {
    return a * b;
}

double division(double a, double b) {
    if (b == 0) {
        return -1;
    }

    return a / b;
}

double power(double x, int n) {
    if (n == 0)
        return 1;
    if (n > 0)
        return powAux(x, n);
    if (n < 0)
        return 1 / powAux(x, -n);
}

double powAux(double x, int n) {
    if (n == 0)
        return 1;
    return x * powAux(x, n - 1);
}
