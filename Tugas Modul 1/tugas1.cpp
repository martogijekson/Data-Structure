#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Struktur data untuk menyimpan informasi mahasiswa
struct Mahasiswa {
    string nim;
    string nama;
    float nilai;
};

// Fungsi untuk menginputkan data mahasiswa
vector<Mahasiswa> input_data() {
    vector<Mahasiswa> data_mahasiswa;
    int jumlah_mahasiswa;

    cout << "\nMasukkan jumlah mahasiswa: ";
    cin >> jumlah_mahasiswa;
    cout << "----------------------------------------";

    for (int i = 0; i < jumlah_mahasiswa; i++) {
        Mahasiswa mahasiswa;
        cout << "\nMasukkan NIM mahasiswa ke-" << i + 1 << ": ";
        cin >> mahasiswa.nim;
        cout << "Masukkan Nama mahasiswa ke-" << i + 1 << ": ";
        cin.ignore(); // Untuk membersihkan newline karakter
        getline(cin, mahasiswa.nama);
        cout << "Masukkan Nilai mahasiswa ke-" << i + 1 << ": ";
        cin >> mahasiswa.nilai;
        data_mahasiswa.push_back(mahasiswa);
        cout << "Data mahasiswa berhasil dimasukkan.\n";
        cout << "----------------------------------------";
    }

    return data_mahasiswa;
}

// Fungsi untuk melihat seluruh data mahasiswa
void lihat_data(const vector<Mahasiswa>& data_mahasiswa) {
    cout << "\nData Mahasiswa:\n";
    if (data_mahasiswa.empty()) {
        cout << "Data mahasiswa kosong. Silakan masukkan data terlebih dahulu.\n";
    } else {
        for (size_t i = 0; i < data_mahasiswa.size(); i++) {
            const Mahasiswa& mahasiswa = data_mahasiswa[i];
            cout << "----------------------------------------\n";
            cout << "Mahasiswa ke-" << i + 1 << ":\n";
            cout << "NIM   : " << mahasiswa.nim << "\n";
            cout << "Nama  : " << mahasiswa.nama << "\n";
            cout << "Nilai : " << mahasiswa.nilai << endl;
        }
    }
}

// Fungsi untuk merekap data mahasiswa
void rekap_data(const vector<Mahasiswa>& data_mahasiswa) {
    if (data_mahasiswa.empty()) {
        cout << "Data mahasiswa kosong. Silakan masukkan data terlebih dahulu.\n";
        return;
    }

    auto max_it = max_element(data_mahasiswa.begin(), data_mahasiswa.end(), [](const Mahasiswa& a, const Mahasiswa& b) {
        return a.nilai < b.nilai;
    });

    auto min_it = min_element(data_mahasiswa.begin(), data_mahasiswa.end(), [](const Mahasiswa& a, const Mahasiswa& b) {
        return a.nilai < b.nilai;
    });

    float total_nilai = 0;
    for (const Mahasiswa& mahasiswa : data_mahasiswa) {
        total_nilai += mahasiswa.nilai;
    }
    float rata_rata = total_nilai / data_mahasiswa.size();

    cout << "\nRekap Data Mahasiswa:\n";
    cout << "----------------------------------------\n";
    cout << "Nilai Terbesar:\n";
    cout << "NIM   : " << max_it->nim << "\n";
    cout << "Nama  : " << max_it->nama << "\n";
    cout << "Nilai : " << max_it->nilai << "\n";

    cout << "----------------------------------------\n";
    cout << "Nilai Terkecil:\n";
    cout << "NIM   : " << min_it->nim << "\n";
    cout << "Nama  : " << min_it->nama << "\n";
    cout << "Nilai : " << min_it->nilai << "\n";

    cout << "----------------------------------------\n";
    cout << "Nilai Rata-rata: " << rata_rata << "\n";
}

void cetak_garis_pemisah() {
    cout << "----------------------------------------\n";
}

int main() {
    vector<Mahasiswa> data_mahasiswa;

    cout << "Selamat datang di Program Manajemen Data Mahasiswa!\n";
    cout << "By : Martogi Jekson C.Siagian\n";

    while (true) {
        cout << "\nMenu Pilihan:\n";
        cout << "1. Input Data Nilai Mahasiswa\n";
        cout << "2. Lihat Seluruh Data Mahasiswa\n";
        cout << "3. Rekap Data Mahasiswa\n";
        cout << "4. Keluar\n";

        int pilihan;
        cout << "Pilih menu (1/2/3/4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                data_mahasiswa = input_data();
                break;
            case 2:
                lihat_data(data_mahasiswa);
                break;
            case 3:
                rekap_data(data_mahasiswa);
                break;
            case 4:
                cout << "Terima kasih telah menggunakan program ini. Sampai jumpa!\n";
                return 0; // Keluar dari program
            default:
                cout << "Pilihan tidak valid. Silakan pilih menu yang benar.\n";
        }
    }

    return 0;
}
