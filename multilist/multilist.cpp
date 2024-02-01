#include <iostream>
#include <conio.h>
#include <string.h>
#define nil NULL

using namespace std;

struct Anak
{
	char Nama[25];
	int Umur;
	Anak* NextAnak;
};

struct Pegawai
{
	int NIP;
	char Nama[25];
	Anak* FirstAnak;
	Pegawai* NextPeg;
};

typedef Anak* adrAnak;
typedef Anak* ListAnak;
typedef Pegawai* adrPeg;
typedef Pegawai* ListPeg;

void CreateEmpty(ListPeg &LP)
{
	LP=nil;
}

bool IsEmpty(ListPeg LP)
{
	return(LP==nil);
}

bool HaveChild(adrPeg P)
{
	return(P->FirstAnak!=nil);
}

adrPeg FindPeg(ListPeg LP,int nip)
{
	if(IsEmpty(LP))
	{
		return nil;
	}
	else 
	{
		if(LP->NIP==nip)
		{	
			return LP;
		}
		else
		{
			FindPeg(LP->NextPeg,nip);
		}
	}
}

adrPeg AlokasiPeg(int nip,char nama[25])
{
	adrPeg P;
	P=new(Pegawai);
	if(P==nil)
		return nil;
	else
	{
		P->NIP=nip;
		strcpy(P->Nama,nama);
		P->FirstAnak=nil;
		P->NextPeg=nil;
	}
	return P;
}

adrAnak AlokasiAnak(char nama[25], int umur)
{
	adrAnak A;
	A=new(Anak);
	if(A==nil)
		return nil;
	else
	{
		strcpy(A->Nama,nama);
		A->Umur=umur;
		A->NextAnak=nil;
	}
	return A;
}

void InsertPegFirst(ListPeg &LP,adrPeg P)
{
	P->NextPeg=LP;
	LP=P;
}


void InsertAnak(ListPeg &LP,int nip,adrAnak A)
{
	adrPeg P;
	adrAnak LastAnak;
	P=FindPeg(LP,nip);
	if(!HaveChild(P))
		P->FirstAnak=A;
	else
	{
		LastAnak=P->FirstAnak;
		while(LastAnak->NextAnak!=nil)
		{
			LastAnak=LastAnak->NextAnak;
		}
		LastAnak->NextAnak=A;
	}
}

void PrintAll(ListPeg LP)
{
	adrPeg P;
	adrAnak A;
	if(!IsEmpty(LP))
	{
		P=LP;
		while(P!=nil)
		{
			cout<<"\n\nNAma Pegawai : "<<P->Nama;
			cout<<"\nNip Pegawai : "<<P->NIP;
			if(HaveChild(P))
			{
				A=P->FirstAnak;
				while(A!=nil)
				{
					cout<<"\nNama Anak : "<<A->Nama;
					cout<<"\nUmur : "<<A->Umur;
					A=A->NextAnak;
				}
			}
			P=P->NextPeg;
		}
	}
}

int main()
{
	int pilih,umur,nip;
	char namaPeg[25],namaAnak[25];
	adrPeg P;
	adrAnak A;
	ListPeg l;

	CreateEmpty(l);
	do
		{
			system("cls");
			cout<<endl; cout<<"------M E N U------"<<endl;
			cout<<"1. Insert Pegawai"<<endl;
			cout<<"2. Insert Anak"<<endl;
			cout<<"3. PrintAll"<<endl;
			cout<<"0. E X I T"<<endl<<endl;
			cout<<"Masukkan Pilihan : ";
			cin>>pilih;

			switch(pilih)
			{
			case 1: {
						cout<<"----Data Pegawai----";
						cout<<"\nMasukkan Nama : "; cin>>namaPeg;
						cout<<"Masukkan NIP : ";cin>>nip;
						P=AlokasiPeg(nip,namaPeg);
						InsertPegFirst(l,P);
						getch(); break;
					}
			case 2: {
						cout<<"Masukkan NIP : ";cin>>nip;
						cout<<"----Data Anak----";
						cout<<"\nMasukkan Nama : "; cin>>namaAnak;
						cout<<"Masukkan umur : ";cin>>umur;
						A=AlokasiAnak(namaAnak,umur);
						InsertAnak(l,nip,A);
						getch();break;
					}
			case 3 : {
						PrintAll(l);
						cout<<endl;
						getch();break;
					 }
			}
		}while(pilih!=0);
	return 0;
}
