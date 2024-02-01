#include <iostream>
using namespace std;

struct Antrian{
    //data
	string nama;
    int umur;
    //pointer
    Antrian *next;
};

int maxQ = 5;
Antrian *head, *tail, *cur, *del, *newNode;

int countQueueLL(){
	if (head == NULL){
		return 0;
	} else{
		int banyak = 0;
		cur = head;
		while (cur != NULL){
			cur = cur->next;
			banyak++;
		}
		return banyak;
	} 
}

// isFull Linked List
bool isFullQueueLL(){
    if (countQueueLL() == maxQ){
    	return true;
	}else{
		return false;
	}
}

// isEmpty Linked List
bool isEmptyQueueLL (){
    if (countQueueLL() == 0){
    	return true;
	}else{
		return false;
	}
}

void enqueueLinkedList(string nama, int umur){
	if (isFullQueueLL()){
		cout << "Antrian penuh!"<<endl;
	}else{
		if (isEmptyQueueLL()){
			head = new Antrian();
			head->nama = nama;
			head->umur = umur;
			head->next = NULL;
			tail = head;
		}else{
			newNode = new Antrian();
			newNode->nama = nama;
			newNode->umur = umur;
			newNode->next = NULL;
			tail->next = newNode;
			tail = newNode;	
		}	
	}
}

void dequeueLinkedList(){
	if (isEmptyQueueLL()){
		cout << "Antrian kosong!"<<endl;
	}else{
		del = head;
		head = head->next;
		delete(del);
	}
}

void printQueueLinkedList(){
	cout << "Data dalam Antrian : \n"<<endl;
	if (isEmptyQueueLL()){
		cout << "Antrian kosong!"<<endl;
	}else{
		cur = head;
		int nomor = 1;
		while (nomor <= maxQ){
			if (cur != NULL ){
				cout<< nomor << ". " << cur->nama << " - " << cur->umur << " tahun" <<endl;
				cur = cur->next; //next node
			}else{
				cout<< nomor << ". " << "(kosong)" <<endl;
			}
			nomor++;
		}
	}
}

void clearQueueLinkedList(){
	if (isEmptyQueueLL()){
		cout << "Antrian kosong!"<<endl;
	}else{
		cur = head;
		while(cur != NULL){
			del = cur;
			cur = cur->next;
			delete del;
		}
		head = NULL;
		tail = NULL;
	}
}

int main(){
	enqueueLinkedList("Budi", 20);
	enqueueLinkedList("Anto", 19);
	enqueueLinkedList("Santi", 17);
	enqueueLinkedList("Wawan", 21);
	enqueueLinkedList("Dodi", 19);
	printQueueLinkedList();
	dequeueLinkedList();
	dequeueLinkedList();
	printQueueLinkedList();
	
	clearQueueLinkedList();
	printQueueLinkedList();
	
	cout <<countQueueLL()<<endl;
}


