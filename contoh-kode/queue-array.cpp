#include <iostream>
#define MAX 5
using namespace std;

struct Queue{
    int front;
    int back;
    string data[MAX];
};

// create sebuah queue struktur dan disimpan pada variabel antrian;
Queue antrian;

void init(){
    antrian.front = antrian.back = 0;
}

bool isFull(){
    return antrian.back == MAX;
}

bool isEmpty (){
    return antrian.back == 0;
}

void enqueue(string data) {
	if (isFull()){
		cout << "Antrian penuh!"<<endl;
	} else {
		antrian.data[antrian.back] = data;
		antrian.back++;
	}
}

void dequeue() {
	if (isEmpty()){
		cout << "Antrian masih kosong!\n"<<endl;
	}
	else{
		//menggeser antrian data ke depan
		for (int i = antrian.front; i < antrian.back; i++){
			antrian.data[i] = antrian.data[i + 1];
		}
		//menempatkan back pada data terakhir yang digeser
		antrian.back--;
	}
}

int countQueue(){
	if (isEmpty()){
		return 0;
	} else if (isFull()){
		return MAX;
	} else {
		return antrian.back;
	}
}

void printQueue (){
    if(isEmpty()) {
        cout << "Antrian kosong!\n" <<endl;
    }else{
    	cout << "Jumlah Data dalam Antrian : "<< countQueue() << " data" <<endl;
        cout << "Data dalam Antrian : "<<endl;
       	for (int i = antrian.front; i < antrian.back; i++){
            cout << i+1 << ". " << antrian.data[i] <<endl;
   		}
   		cout << endl;
    }
}

void clear () {
    antrian.front = antrian.back = 0;
}

int main(){
	init();
	enqueue("Budi");
	enqueue("Santi");
	printQueue();
	dequeue();
	printQueue();
	dequeue();
	//clear();
	printQueue();
	
	/*enqueue("Budi");
	enqueue("Santi");
	enqueue("Anto");
	printQueue();*/
}


