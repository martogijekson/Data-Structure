#include <iostream>

using namespace std;

int main() {
    char kata[100];
    char karakter;

    cout << "Masukkan sebuah kata: ";
    cin >> kata;

    cout << "Masukkan karakter yang ingin dicari: ";
    cin >> karakter;

    char* ptr = kata;
    int counter = 0;

    while (*ptr != '\0') {
        if (*ptr == karakter) {
            counter++;
        }
        ptr++;
    }

    if (counter > 0) {
        cout << "Karakter '" << karakter << "' ditemukan sebanyak " << counter << " kali dalam kata '" << kata << "'." << endl;
    } else {
        cout << "Karakter '" << karakter << "' tidak ditemukan dalam kata '" << kata << "'." << endl;
    }

    return 0;
}
