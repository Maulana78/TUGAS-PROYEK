#include <iostream>
using namespace std;

struct buku{
	int judul,judulH;
};
struct buku x[5];

int jum,waktu,denda,hilang;
int tglP,bulanP,thnP;
int tglK,bulanK,thnK;
int biologi=20000,mtk=15000,sastra=10000,seni=10000,puisi=10000,pantun=10000;

void inputan(){
	for(int i=0; i<jum; i++){
		cout<<"Masukkan No.buku pinjaman "<<i+1<<" : "; cin>>x[i].judul;}
		cout<<"Tanggal peminjaman     : "; cin>>tglP;
		cout<<"Bulan peminjaman       : "; cin>>bulanP;
		cout<<"Tahun peminjaman       : "; cin>>thnP;
		cout<<"\nTanggal pengembalian   : "; cin>>tglK;
		cout<<"Bulan pengembalian     : "; cin>>bulanK;
		cout<<"Tahun pengembalian     : "; cin>>thnK;
		cout<<"Jumlah buku hilang     : "; cin>>hilang;
	for(int i=0; i<hilang; i++){
		cout<<"Judul No.buku hilang    "<<i+1<<" : "; cin>>x[i].judulH;
		}
}

void tanggal(){
	if((tglP>0) && (tglP<=31) && (bulanP>0) && (bulanP<=12) && (thnP>0) && (tglK>0) && (tglK<=31) && (bulanK>0) && (bulanK<=12) && (thnK>0)){
		waktu=((tglK+((bulanK*30)+thnK)) - ((tglP+((bulanP*30)+thnP))));
		cout<<"\njangka waktu : "<<waktu<<" hari\n";
	}else{
		cout<<"\nTanggal salah\n";
	}
}


void pajak(){
	for(int j=7; waktu; j=j+7){
		if((waktu > j) && (waktu <= j+7)){
			if(jum>=hilang){
				denda=(((j/7)*1000)*(jum-hilang));
				cout<<"Denda peminjaman : "<<denda<<endl;
				break;
			}else{
				denda=(((j/7)*1000)*(hilang-jum));
				cout<<"Denda peminjaman : "<<denda<<endl;
				break;
			}
		}else{
			cout<<"waktu pengembalian "<<waktu<<" hari";
			break;
		}
	}
}

void pajakk(){
	for(int i=0; i<hilang; i++){
		if(x[i].judulH == 1){
			cout<<"\nDenda hilang = Rp."<<biologi;
		}else if(x[i].judulH == 2){
			cout<<"\nDenda hilang = Rp."<<mtk;
		}else if(x[i].judulH == 3 || x[i].judulH == 4 || x[i].judulH == 5 || x[i].judulH == 6){
			cout<<"\nDenda hilang = Rp.10000";
		}else{
			cout<<"\nAnda tidak kena denda buku hilang";
		}
	}
}


int main(){
	cout<<"PROGRAM PEMINJAMAN BUKU\n";
	cout<<"-----------------------\n";
	cout<<"Syarat peminjaman : \n1. Peminjaman tidak lebih dari 7 hari\n2. saptu dan minggu tutup\n";
	cout<<"3. Buku yang tersedia yaitu :\n   1) biologi Rp.20000\n   2) mtk     Rp.15000\n   3) sastra  Rp.10000\n   4) seni    Rp.10000\n   5) puisi   Rp.10000\n   6) pantun  Rp.10000";
	
	cout<<"\n\nMasukkan jumlah buku yg dipinjam : "; 
	cin>>jum;
	
	inputan();
	tanggal();
	pajak();
	pajakk();
	
	return 0;
}

