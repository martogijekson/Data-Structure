#include <iostream>

using namespace std;

struct Buku{
    //komponen
	string judul, pengarang;
    int tahunTerbit;
	Buku *prev;
	Buku *next;
};

Buku *head, *tail, *cur, *newNode, *del; //variabel global

void createDoubleLS(string judul, string pengarang, int thnTerbit){
	head = new Buku();
	head->judul = judul;
	head->pengarang = pengarang;
	head->tahunTerbit = thnTerbit;
	head->prev = NULL;
	head->next = NULL;
	tail = head;
}

void printDoubleLS(){
	if(head==NULL){
  		cout<<"Double Linked List Kosong!";
  	}else{
	  	cur = head;
	  	while (cur != NULL){
	  		cout<< "Judul Buku : " << cur->judul <<endl;
			cout<< "Pengarang Buku : " << cur->pengarang <<endl;
			cout<< "Tahun Terbit : " << cur->tahunTerbit <<endl;
			cur = cur->next;
		}
	}
}

void addFirst(string judul, string pengarang, int thnTerbit){
	if(head==NULL){
  		cout<<"Double Linked List Kosong!";
  	}else{
	  	newNode = new Buku();
		newNode->judul= judul;
		newNode->pengarang = pengarang;
		newNode->tahunTerbit = thnTerbit;
		newNode->prev = NULL;
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}

void addLast(string judul, string pengarang, int thnTerbit){
	if(head==NULL){
  		cout<<"Double Linked List Kosong!";
  	}else{
	  	newNode = new Buku();
		newNode->judul= judul;
		newNode->pengarang = pengarang;
		newNode->tahunTerbit = thnTerbit;
		newNode->prev = tail;
		newNode->next = NULL;
		tail->next = newNode;
		tail = newNode;
	}
}

void delFirst(){
	if(head==NULL){
  		cout<<"Double Linked List Kosong!";
  	}else{
		del = head;
		head = head->next;
		head->prev = NULL;
		delete del;
	}
}

void delLast(){
	if(head==NULL){
  		cout<<"Double Linked List Kosong!";
  	}else{
		del = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete del;
	}
}

void insertAtPosition(string judul, string pengarang, int thnTerbit, int position){
    if(position <= 0){
        cout << "Posisi harus lebih besar dari 0." << endl;
        return;
    }

    newNode = new Buku();
    newNode->judul = judul;
    newNode->pengarang = pengarang;
    newNode->tahunTerbit = thnTerbit;

    if(head == NULL){
        // Jika linked list kosong, node baru akan menjadi head dan tail
        newNode->prev = NULL;
        newNode->next = NULL;
        head = newNode;
        tail = newNode;
        return;
    }

    if(position == 1){
        // Jika posisi yang diinginkan adalah di awal linked list
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    cur = head;
    int count = 1;

    while(count < position - 1 && cur != NULL){
        cur = cur->next;
        count++;
    }

    if(cur == NULL){
        // Jika posisi melebihi jumlah node yang ada
        cout << "Posisi melebihi panjang linked list. Node akan ditambahkan di akhir." << endl;
        newNode->prev = tail;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
        return;
    }

    newNode->prev = cur;
    newNode->next = cur->next;
    if(cur->next != NULL){
        cur->next->prev = newNode;
    }
    cur->next = newNode;
}


int main() {
  	createDoubleLS("Struktur Data 1","Abdul Kadir",2008);
	printDoubleLS();
	cout<<"\n\n"<<endl;

	addFirst("Sistem Informasi","Jogiyanto",2010);
	printDoubleLS();
	cout<<"\n\n"<<endl;

	addLast("Basis Data","Jogiyanto",2012);
	printDoubleLS();
	cout<<"\n\n"<<endl;


  	insertAtPosition("Algoritma Pemrograman", "Martogi J.S", 2021, 2); // Contoh penyisipan di posisi kedua
    printDoubleLS();
    cout << "\n\n" << endl;

   	return 0;
}
