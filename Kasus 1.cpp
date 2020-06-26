#include <iostream>
using namespace std;
int n;

struct pegawai{
	char nip[20],nama[30];
	float gaji,gajiB,gajiT,upah,Tgaji;
	int golongan,jam;
};
struct pegawai x[10];

void garis(){
	cout<<"\n--------------------------------------------\n";
}

int inputan(){
    for(int i=0; i<n; i++){
		cout<<"\nPegawai ke-"<<(i+1)<<endl;
		cout<<"Nama Pegawai     : "; cin >> x[i].nama;
		cout<<"No.Induk Pegawai : "; cin >> x[i].nip;
		cout<<"Gaji Pokok       : "; cin >> x[i].gaji;
		cout<<"Golongan         : "; cin >> x[i].golongan;
		cout<<"Berapa Jam kerja : "; cin >> x[i].jam;
	}
	return 0;
}

void totalgaji(){
	 for(int i=0; i<n; i++){
		 if(x[i].golongan== 1 && x[i].jam >= 5){
			 x[i].gajiT = 500000;
			 x[i].upah = (5000*(x[i].jam-5));
			 x[i].Tgaji = x[i].gajiT + x[i].upah;
		}
		else if(x[i].golongan== 2 && x[i].jam >= 5){
			 x[i].gajiT = 300000;
			 x[i].upah = (3000*(x[i].jam-5));
			 x[i].Tgaji = x[i].gajiT + x[i].upah;
		}
		else if(x[i].golongan== 3 && x[i].jam >= 5){
			 x[i].gajiT = 250000;
			 x[i].upah = (2000*(x[i].jam-5));
			 x[i].Tgaji = x[i].gajiT + x[i].upah;
		}
		else if(x[i].golongan== 4 && x[i].jam >= 5){
			 x[i].gajiT = 100000;
			 x[i].upah = (1500*(x[i].jam-5));
			 x[i].Tgaji = x[i].gajiT + x[i].upah;
		}
		else if(x[i].golongan== 5 && x[i].jam >= 5){
			 x[i].gajiT = 50000;
			 x[i].upah = (1000*(x[i].jam-5));
			 x[i].Tgaji = x[i].gajiT + x[i].upah;
		}
		else{
			cout<<"\nperusahaan : 'anda bukan gologan kami'\n";
			break;
		}
	}
}

void gajibersih(){
	for(int i=0; i<n; i++){
		float t,p;
		t=((15*x[i].gaji)/100.0);
		p=((10.0*(t+x[i].gaji))/100.0);
		x[i].gajiB=((t+x[i].gaji)-p);
	}
}
	
void output(){
	garis();
	garis();
	for(int i=0; i<n; i++){
		cout<<"\npegawai ke-"<<(i+1);
		cout<<"\nNo.Induk Pegawai : " << x[i].nip;
		cout<<"\nNama Pegawai     : " << x[i].nama;
		cout<<"\nGaji Pokok       : " << x[i].gaji;
		cout<<"\nGaji Bersih      : " << x[i].gajiB;
		cout<<"\nGaji Tetap       : " << x[i].gajiT;
		cout<<"\nUpah Lembur      : " << x[i].upah;
		cout<<"\nTotal Gaji       : " << x[i].Tgaji<<endl;
	}
}

int main(){
	cout<<"PROGRAM UNTUK MENGHITUNG GAJI BERSIH PEGAWAI";
	garis();
	cout<<"\nSyarat : \n1. minimal kerja 5 jam\n2. maksimal gologan yaitu 5, tiap golongan berbeda pendapatan\n\n";
	cout<<"Masukkan Jumlah Pegawai : ";
	cin>>n;
	inputan();
	gajibersih();
	totalgaji();
	output();
	return 0;
}

