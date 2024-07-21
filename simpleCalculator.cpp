#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void simpleCal() {
    int a;
    int b;
    char oper;
    cout << "\nEnter Equation : ";
    cin >> a;
    cin >> oper;
    cin >> b;

    if (oper == '+') {
        cout << a + b;
    }
    if (oper == 'x' || oper == '*') {
        cout << a * b;
    }
    if (oper == '-') {
        cout << a - b;
    }
    if (oper == '/') {
        cout << (double)a / (double)b;
    }
    simpleCal();
}

int main() {
    simpleCal();
}