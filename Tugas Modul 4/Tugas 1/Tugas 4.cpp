#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct TNode {
 int data;
 TNode *next;
};

TNode *head, *tail;

void createList() {
 head = NULL;
 tail = NULL;
}

int isEmpty() {
 if(head == NULL) {
   return 1;
 } else {
   return 0;
 }
}

void insertDepan(int data) {
 TNode *baru;
 baru = new TNode;
 baru->data = data;
 baru->next = head;
 head = baru;
 if(head->next == NULL) {
   tail = head;
 }
 cout<<"Data masuk\n";
}

void insertBelakang(int data) {
 TNode *baru;
 baru = new TNode;
 baru->data = data;
 if(isEmpty()==0){
   tail->next = baru;
   tail=baru;
   tail->next = NULL;
 }else{
   head = baru;
   tail = baru;
   tail->next = NULL;
 }
 cout<<"Data masuk\n";
}

 void tampil(){
 TNode *bantu;
 bantu=head;
 if(isEmpty()==0){
 while(bantu!=NULL){
 cout<<bantu->data<<"->";
 bantu=bantu->next;
 }
 cout<<"NULL";
 }else {
cout <<"Masih kosong\n";
}
}

void hapusDepan(){
 TNode *hapus;
 int d;
 if (isEmpty()==0){
 if(head!=tail){
   hapus=head;
   d=hapus->data;
   head=head->next;
   delete hapus;
   cout<<"Data yang dihapus = "<<d<<endl;
 } else {
   delete head;
   head = NULL;
   tail = NULL;
   cout<<"List telah kosong\n";
 }
 }else {
 cout <<"Masih kosong\n";
 }
}

void hapusBelakang(){
 TNode *hapus;
 int d;
 if (isEmpty()==0){
 if(head!=tail){
   hapus=tail;
   d=hapus->data;
   tail=tail->next;
   delete hapus;
   tail->next=NULL;
   cout<<"Data yang dihapus = "<<d<<endl;
 } else {
   delete head;
   head = NULL;
   tail = NULL;
   cout<<"List telah kosong\n";
 }
 }else {
 cout <<"Masih kosong\n";
 }
}

void clear() {
 TNode *bantu;
 if(isEmpty()==0){
   bantu = head;
   while(bantu!=NULL){
     bantu = head->next;
     delete head;
     head = bantu;
   }
   head = NULL;
   tail = NULL;
 } else {
   cout <<"Masih kosong\n";
 }
}

int countLength() {
 int length = 0;
 TNode *bantu = head;
 while(bantu != NULL) {
   length++;
   bantu = bantu->next;
 }
 return length;
}

int countTotal() {
 int total = 0;
 TNode *bantu = head;
 while(bantu != NULL) {
   total += bantu->data;
   bantu = bantu->next;
 }
 return total;
}

int main() {
 int pil, data, length, total;
 do {
   system("cls");
cout<<" ========================="<<endl;
cout<<" = PROGRAM LINKED LIST   ="<<endl;
cout<<" ========================="<<endl;
cout<<" = 1. Insert Depan       ="<<endl;
cout<<" = 2. Insert Belakang    ="<<endl;
cout<<" = 3. Delete Depan       ="<<endl;
cout<<" = 4. Delete Belakang    ="<<endl;
cout<<" = 5. Tampil Data        ="<<endl;
cout<<" = 6. Clear              ="<<endl;
cout<<" = 7. Count Length       ="<<endl;
cout<<" = 8. Count Total        ="<<endl;
cout<<" = 9. Exit               ="<<endl;
cout<<" ========================="<<endl;
   cout<<"Masukkan pilihan anda: ";
   cin>>pil;

   switch(pil) {
     case 1:
       cout<<"Masukkan data: ";
       cin>>data;
       insertDepan(data);
       break;
     case 2:
       cout<<"Masukkan data: ";
       cin>>data;
       insertBelakang(data);
       break;
     case 3:
       hapusDepan();
       break;
     case 4:
       hapusBelakang();
       break;
     case 5:
       tampil();
       break;
     case 6:
       clear();
       break;
     case 7:
       length = countLength();
       cout<<"Panjang linked list = "<<length<<endl;
       break;
     case 8:
       total = countTotal();
       cout<<"Jumlah keseluruhan nilai = "<<total<<endl;
       break;
   }
   getch();
 } while(pil != 9);

 return 0;
}
