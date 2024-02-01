#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const int MAX_LENGTH = 100;
    char input[MAX_LENGTH];

    cout << "Masukkan kata/kalimat: ";
    cin.getline(input, MAX_LENGTH);

    int length = strlen(input);

    char* reversePtr = input + length - 1;

    cout << "Output terbalik: ";
    while (reversePtr >= input) {
        cout << *reversePtr;
        reversePtr--;
    }

    cout << endl;

    return 0;
}
