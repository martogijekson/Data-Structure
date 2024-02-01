#include <iostream>

using namespace std;

// deklarasi single linked list
struct Buku{
    //komponen
	string judul, pengarang;
    int tahunTerbit;
	Buku *next;
};

Buku *head, *tail, *cur, *newNode, *del; //variabel global

//create single linked list
void createCircularSingleLS(string judul, string pengarang, int thnTerbit){
	head = new Buku();
	head->judul = judul;
	head->pengarang = pengarang;
	head->tahunTerbit = thnTerbit;
	tail = head;
	tail->next = head;
}

void printCircular() {
   	cur = head;
   	if(cur==NULL){
  		cout<<"Linked List Kosong!";
  	}else{
	   do {
	      	cout<< "Judul Buku : " << cur->judul <<endl;
			cout<< "Pengarang Buku : " << cur->pengarang <<endl;
			cout<< "Tahun Terbit : " << cur->tahunTerbit <<endl;
	      	cur = cur->next;
	   } while(cur != head);
	}
}


//tambah awal/depan Single linked list
void addFirst(string judul, string pengarang, int thnTerbit){
	if(head==NULL){
  		cout<<"Linked List Kosong!";
  	}else{
	  	newNode = new Buku();
		newNode->judul= judul;
		newNode->pengarang = pengarang;
		newNode->tahunTerbit = thnTerbit;
		newNode->next = head;
		tail->next = newNode;
		head = newNode;
	}
}

void addLast(string judul, string pengarang, int thnTerbit){
	if(head==NULL){
  		cout<<"Linked List Kosong!";
  	}else{
	  	newNode = new Buku();
		newNode->judul= judul;
		newNode->pengarang = pengarang;
		newNode->tahunTerbit = thnTerbit;
		newNode->next = head;
		tail->next = newNode;
		tail = newNode;
	}
}

void delFirst(){
	if(head==NULL){
  		cout<<"Linked List Kosong!";
  	}else{
		del = head;
		head = head->next;
		tail->next = head;
		delete del;
	}
}

void delLast(){
	if(head==NULL){
  		cout<<"Linked List Kosong!";
  	}else{
		del = tail;
		cur = head;
		while(cur->next != tail){
			cur = cur->next;
		}
		tail = cur;
		tail->next = head;
		delete del;
	}
}


void addMiddle(string judul, string pengarang, int thnTerbit, int posisi){
	if(head==NULL){
  		cout<<"Linked List Kosong!";
  	}else{
  		if (posisi == 1){
			cout<<"Posisi tidak di tengah!";
		}
		newNode = new Buku();
		newNode->judul= judul;
		newNode->pengarang = pengarang;
		newNode->tahunTerbit = thnTerbit;

		int nomor = 1;
		cur = head;

		while(nomor < posisi-1){
			cur = cur->next;
			nomor++;
		}

		newNode->next = cur->next;
		cur->next = newNode;
	}
}

void deleteAtPosition(int posisi){
	if(head == NULL){
  		cout<<"Linked List Kosong!";
  	}else{
		if (posisi == 1) {
			delFirst(); // Jika posisi yang dihapus adalah posisi pertama, panggil fungsi deleteFirst()
			return;
		}

		cur = head;
		Buku *prev = NULL;
		int nomor = 1;

		while(nomor < posisi && cur->next != head){
			prev = cur;
			cur = cur->next;
			nomor++;
		}

		if(nomor != posisi){
			cout << "Posisi tidak valid!" << endl;
			return;
		}

		prev->next = cur->next;

		if(cur == tail){
			tail = prev; // Jika node yang dihapus adalah tail, perbarui tail
		}

		delete cur;
	}
}



int main(){
	createCircularSingleLS("Struktur Data 1","Abdul Kadir",2008);
	printCircular();
	cout<<"\n\n"<<endl;

	addFirst("Sistem Informasi","Jogiyanto",2010);
	printCircular();
	cout<<"\n\n"<<endl;

	addLast("Sistem Informasi 2","Jogiyanto",2015);
	printCircular();
	cout<<"\n\n"<<endl;

	delFirst();
	printCircular();
	cout<<"\n\n"<<endl;

	delLast();
	printCircular();
	cout<<"\n\n"<<endl;

	addFirst("Sistem Informasi","Jogiyanto",2010);
	printCircular();
	cout<<"\n\n"<<endl;


	addMiddle("XXX","abc",2010,2);
	printCircular();
	cout<<"\n\n"<<endl;

	deleteAtPosition(2); // Menghapus node pada posisi ke-3
    printCircular();
    cout<<"\n\n"<<endl;

}

