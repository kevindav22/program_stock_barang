#include <iostream>
#include <conio.h>
#include <windows.h>
#define max 200
using namespace std;

//KELOMPOK 15
//1.Kevin david richard fernanda putra 21.11.4501
//2. Ridwan Prastino Oktavianto 21.11.4518
//3. Hizkia Fernanda Kuntoro 21.11.4471
//4. Naufal Yuma Abida Ahsan 21.11.4515
//5. Muhammad Fadilah Urrizki 21.11.4489

//Loading
int Loading() {
	int i, j;
	for (i = 1; i <= 100; i++) {
		cout << "Sabar Ya Gan..... " << i << "%";
		cout << endl;
		for (j = 0; j < i; j++) {

		}
		system("cls");
	}
}
//stuct
struct tumpukan {
	int atas;
	string data[max];
	string tipe[max];
	int harga[max];
}T;


void awal() {
	T.atas = -1;
}
int kosong() {
	if (T.atas == -1)
		return 1;
	else
		return 0;
}
int penuh() {
	if (T.atas == max - 1)
		return 1;
	else
		return 0;
}
void input(string data, int harga, string tipe) {
	if (kosong() == 1) {
		T.atas++;
		T.data[T.atas] = data;
		T.harga[T.atas] = harga;
		T.tipe[T.atas] = tipe;
		cout << "\nData " << T.data[T.atas] << " Tersimpan" << endl;
	}
	else if (penuh() == 0) {
		T.atas++;
		T.data[T.atas] = data;
		T.harga[T.atas] = harga;
		T.tipe[T.atas] = tipe;
		cout << "\nData " << T.data[T.atas] << " Tersimpan" << endl;
	}
	else {
		cout << "Data Penuh";
	}
}

//sorting
void tampil(int pilih) {
	int tempHrg;
	string tempDta;
	string tempTipe;
	if (kosong() == 0) {

		//ascending
		if (pilih == 2) {
			for (int i = 0; i <= T.atas; i++) {
				for (int j = 0; j <= T.atas - 1; j++) {
					if (T.harga[j] > T.harga[j + 1]) {
						//pindah data kode produk
						tempHrg = T.harga[j];
						T.harga[j] = T.harga[j + 1];
						T.harga[j + 1] = tempHrg;

						//pindah data jenis
						tempDta = T.data[j];
						T.data[j] = T.data[j + 1];
						T.data[j + 1] = tempDta;

						//pindah data tipe
						tempTipe = T.tipe[j];
						T.tipe[j] = T.tipe[j + 1];
						T.tipe[j + 1] = tempTipe;
					}
				}
			}
		}
		//Descending
		else {
			for (int i = 0; i <= T.atas; i++) {
				for (int j = 0; j <= T.atas - 1; j++) {
					if (T.harga[j] < T.harga[j + 1]) {
						//pindah data kode produk
						tempHrg = T.harga[j];
						T.harga[j] = T.harga[j + 1];
						T.harga[j + 1] = tempHrg;

						//pindah data jenis
						tempDta = T.data[j];
						T.data[j] = T.data[j + 1];
						T.data[j + 1] = tempDta;

						//pindah data tipe
						tempTipe = T.tipe[j];
						T.tipe[j] = T.tipe[j + 1];
						T.tipe[j + 1] = tempTipe;
					}
				}
			}	
		}

		cout << "===============================================" << endl << endl;
		for (int i = 0; i <= T.atas; i++) {
			cout << i + 1 << " Kode Produk = " << T.data[i] << endl;
			cout << "  Jenis       = " << T.tipe[i] << endl;
			cout << "  Harga       = Rp. " << T.harga[i] << endl;
			cout << endl;
		}
		cout << "===============================================" << endl;
		cout << endl;
	}
	else {
		cout << "===========================" << endl;
		cout << "=====Data Masih Kosong=====" << endl;
		cout << "===========================" << endl;
	}
}
void bersih() {
	T.atas = -1;
	cout << "\nData Dikosongkan";
}

//fungsi getline ()adalah untuk menginput data string agar bisa di spasi
//cin ignore berfungsi ketika kita menginput data string dengan getline agar si getline tidak terlewati

//Searching
void cari() {
	if (kosong() == 0) {
		string pencari;
		int syrt;
		cout << "Masukkan Kode Produk = ";
		cin.ignore();
		getline(cin, pencari);

		for (int i = 0; i <= T.atas; i++) {
			if (T.data[i] == pencari) {
				cout << " Produk  " << T.data[i] << " Ditemukan" << endl;
				cout << " ===================================" << endl;
				cout << " Kode Produk  = " << T.data[i]<< endl;
				cout << " Jenis        = " << T.tipe[i]<< endl;
				cout << " Harga        = " << T.harga[i] << endl;
				cout << " ===================================" << endl;
				syrt++;
			}
		}
		if (syrt == 0) {
			cout << "\nProduk " << pencari << " Tidak Ditemukan" << endl;
		}
	}
	else {
		cout << "===========================" << endl;
		cout << "======= Data Kosong =======" << endl;
		cout << "===========================" << endl;
	}
}

int main() {
	int pil, harga, jum;
	
	string data, tipe;
	Loading();
	awal();
	do
	{

		cout << "\t =========================================" << endl;
		cout << "\t =========  Stock Kuota Internet =========" << endl;
		cout << "\t =========================================" << endl;
		cout << endl;

		cout << "1. Input Data  \n2. Daftar Produk Harga Terendah \n3. Daftar Produk Harga Tertinggi \n4. Hapus Data \n5. Cari Data \n6. Keluar" << endl;
		cout << "\n============================";
		cout << "\nMasukkan Pilihan = ";
		cin >> pil;
		cout << "=============================" << endl;
		switch (pil) {
		case 1:
			cout << "\nMasukkan Jumlah Data : ";
			cin >> jum;
			for (int i = 0; i < jum; i++) {
				cout << " \nData ke- " << i + 1 << endl;
				cout << "=====================================" << endl;
				cout << " Masukkan Kode Produk = ";
				cin.ignore();
				getline(cin, data);
				cout << " Masukkan Jenis       = ";
				getline(cin, tipe);
				cout << " Masukkan Harga       = Rp. ";
				cin >> harga;
				cout << "=================================" << endl;
				input(data, harga, tipe);
			}
			system("cls");
			break;
		case 2:
			cout << "\nDaftar Produk dengan harga terendah : " << endl;
			tampil(pil);
			cout << "\nTekan Enter untuk Ke Menu";
			getch();
			system("cls");
			break;
		case 3:
			cout << "\nDaftar Produk dengan harga tertinggi : " << endl;
			tampil(pil);
			cout << "\nTekan Enter untuk Ke Menu";
			getch();
			system("cls");
			break;
		case 4:
			bersih();
			cout << "\nTekan Enter untuk ke Menu";
			getch();
			system("cls");
			break;
		case 5:
			cari();
			cout << "\nTekan Enter untuk ke Menu";
			getch();
			system("cls");
			break;
		case 6:
			cout << "Anda telah keluar ";
			break;
		default :
			cout << "\nMohon Masukkan Angka 1-6" << endl;
			Sleep(1000);
			system("cls");
		}
	} 
	while (pil != 6);
	getch();
}
