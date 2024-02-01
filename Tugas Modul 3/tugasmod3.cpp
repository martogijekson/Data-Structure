#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> peti;
    int volume_peti = 0;

    while (true) {
        cout << "===== MENU =====" << endl;
        cout << "1. Masukkan ukuran peti" << endl;
        cout << "2. Masukkan satu kotak kayu ke peti" << endl;
        cout << "3. Keluarkan satu kotak kayu dari peti" << endl;
        cout << "4. Kondisi peti" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";

        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan volume peti maksimum: ";
                cin >> volume_peti;
                break;

            case 2:
                if (volume_peti <= 0) {
                    cout << "Volume peti belum diatur. Silakan atur volume peti terlebih dahulu." << endl;
                } else {
                    int volume_kotak;
                    cout << "Masukkan volume kotak yang akan dimasukkan ke peti: ";
                    cin >> volume_kotak;

                    if (volume_peti - volume_kotak >= 0) {
                        peti.push(volume_kotak);
                        volume_peti -= volume_kotak;
                        cout << "Volume kotak yang dimasukkan: " << volume_kotak << " m3" << endl;
                        cout << "Volume peti yang tersisa: " << volume_peti << " m3" << endl;
                    } else {
                        cout << "Volume kotak terlalu besar untuk dimasukkan ke peti." << endl;
                    }
                }
                break;

            case 3:
                if (!peti.empty()) {
                    int volume_kotak = peti.top();
                    peti.pop();
                    volume_peti += volume_kotak;
                    cout << "Kotak kayu yang dikeluarkan adalah kotak ke-" << peti.size() + 1 << " dengan volume " << volume_kotak << " m3" << endl;
                    cout << "Sisa volume peti sekarang: " << volume_peti << " m3" << endl;
                } else {
                    cout << "Peti sudah kosong." << endl;
                }
                break;

            case 4:
                cout << "1) Jumlah kotak kayu pada peti besar : " << peti.size() << " kotak" << endl;
                if (!peti.empty()) {
                    cout << "2) Volume masing-masing kotak kayu : " << endl;
                    int kotak_ke = 1;
                    stack<int> tempStack = peti;
                    while (!tempStack.empty()) {
                        cout << "- kotak " << kotak_ke << " ber-volume: " << tempStack.top() << " m3" << endl;
                        tempStack.pop();
                        kotak_ke++;
                    }
                } else {
                    cout << "2) Peti kosong." << endl;
                }
                cout << "3) Volume maksimum peti besar yang tersisa : " << volume_peti << " m3" << endl;
                break;

            case 5:
                return 0;

            default:
                cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
                break;
        }
    }

    return 0;
}
