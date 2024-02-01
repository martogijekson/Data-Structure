#include <iostream>
using namespace std;

struct Buku {
    string judul, pengarang;
    int tahunTerbit;
    Buku *prev;
    Buku *next;
};

void sisipNode(Buku* &head, string judul, string pengarang, int tahunTerbit, int posisi) {
    Buku *temp = new Buku();
    temp->judul = judul;
    temp->pengarang = pengarang;
    temp->tahunTerbit = tahunTerbit;
    temp->prev = NULL;
    temp->next = NULL;

    if (posisi == 1) {
        temp->next = head;
        if (head != NULL) {
            head->prev = temp;
        }
        head = temp;
        return;
    }

    Buku *cur = head;
    for (int i = 1; i < posisi - 1 && cur != NULL; ++i) {
        cur = cur->next;
    }

    if (cur == NULL) {
        cout << "Posisi melebihi panjang linked list" << endl;
        return;
    }

    temp->next = cur->next;
    temp->prev = cur;
    if (cur->next != NULL) {
        cur->next->prev = temp;
    }
    cur->next = temp;
}

int main() {
    Buku *node1, *node2;
    node1 = new Buku();
    node2 = new Buku();

    node1->judul = "Basis Data";
    node1->pengarang = "Budi Raharjo";
    node1->tahunTerbit = 2015;
    node1->prev = NULL;
    node1->next = node2;

    node2->judul = "Struktur Data";
    node2->pengarang = "Susanto";
    node2->tahunTerbit = 2016;
    node2->prev = node1;
    node2->next = NULL;

    // Menyisipkan node baru pada posisi tertentu
    sisipNode(node1, "Algoritma Pemrograman", "Andi", 2017, 2);

    // Menampilkan isi linked list setelah penyisipan node baru
    Buku *cur = node1;
    while (cur != NULL) {
        cout << "Judul Buku : " << cur->judul << endl;
        cout << "Pengarang Buku : " << cur->pengarang << endl;
        cout << "Tahun Terbit : " << cur->tahunTerbit << endl;
        cur = cur->next;
    }

    return 0;
}
