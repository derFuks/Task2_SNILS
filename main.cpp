#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//task 2 SNILS
bool checkSNILS(const string& snils) {
    string digits;
    // убираем все нецифры
    for (char c : snils) {
        if (isdigit(c)) digits += c;
    }

    if (digits.size() != 11) {
        return false; // проверка на 11 цифр
    }

    // первые 9 цифр
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        int d = digits[i] - '0';
        sum += d * (9 - i);
    }

    // проверка контрольного числа
    int control;
    if (sum < 100) control = sum;
    else if (sum == 100 || sum == 101) control = 0;
    else {
        control = sum % 101;
        if (control == 100) control = 0;
    }

    // последние две цифры
    int givenControl = stoi(digits.substr(9, 2));

    return control == givenControl;
}

int main() {

    string snils;
    cout << "Введите СНИЛС (формат XXX-XXX-XXX YY): ";
    //cin >> snils;
    getline(cin, snils); // из-за пробела не мог пройти валидацию

    if (checkSNILS(snils)) {
        cout << "СНИЛС корректный" << endl;
    } else {
        cout << "СНИЛС некорректный!!!" << endl;
    }

    return 0;
}
