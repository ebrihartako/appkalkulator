#include <iostream>
#include <iomanip> //library untuk setprecision
#include <conio.h> // library untuk getch, gotoxy
#include <windows.h> //library untuk fungsi handle

using namespace std;

// =fungsi warna=//
void setcolor(unsigned short color)
{
	//fungsi ini digunakanuntuk menampilkanwarna
	//cara cek daftar warna : buka cmd >> color Z >> enter
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
	//[GetStdHandle] berfungsi untuk mendapatkan handle ke layar
}

// =fungsi gotxy= //
void gotoxy(int x, int y)
{ 
	//fungsi ini digunakan dalam pembuatan grafik nantiny dengan cara memindahkan kursor ke titik x dan y
	COORD titik = {x,y};
	/*[COORD] adalah tipe data koordinat*/
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), titik);
	/*[SetConsoleCursorPosition] berfungsi untuk mengeset dari posisi x=0 dan y=0 ke posisi di x dan y yang telah di set*/
}

// =fungsi judul= // 
void judul()
{
	system ("cls");
	//setcolor berfungsi untuk mengubah warna tampilan cmd, angka didalam kurung merupakan tipe warna text dan background
	setcolor (880);
	//(Judul dibuat fungsi sendiri supaya mengehemat codingan, karena nantinya sering digunakan setiap layar dibersihkan)
	cout << "=============================================================================" << endl;
    cout << "=                     PROGRAM CATATAN KEUANGAN ANAK KOS                     =" << endl;
	cout << "=============================================================================" << endl;
	cout << endl;
	setcolor (7);
}

// =fungsi main= //
int main ()
{
	
    //IDENTITAS
    awal:
    	/*[system("cls")] berfunsgi untuk membersihkan layar pada program*/
    	judul();
    	setcolor (7);
    	string nama;
    	cout << "Masukan Nama Anda : ";
		getline (cin,nama);
		/*[getline] berfungsi untuk mengambil inputan dapam satu garis*/
		cout << endl;

	//PERIODE
	string periode;
	string waktu;
	
	pilperiode :
		judul();
		/*[judul()] maksudnya memanggil fungsi judul*/
		cout << "---------------------------  PILIH PERIODE WAKTU  ---------------------------" << endl;		
		cout << endl;
		cout << "Pilih periode waktu yang ingin anda manajemen kuangannya :" << endl;
		cout << endl;
    	cout << "1. Harian" << endl;
    	cout << "2. Mingguan" << endl;
    	cout << "3. Bulanan" << endl;
    	cout << endl;
    	cout << "Pilihan Anda : ";
    	cin >> periode;
    	cout << endl;

    	//(Percabangan untuk menentukan isi didalam wadah waktu)
		if(periode == "1")
    	{
    		waktu = "hari";
    		goto pilmasuk;
    		/*[goto] berfungsi untuk pindah dan menjalankan codingan yang dituju*/
		}
		if (periode == "2")
		{
			waktu = "minggu";
			goto pilmasuk;
		}
		if (periode == "3")
		{
			waktu = "bulan";
			goto pilmasuk;
		}
		else
		{
			setcolor (12);
			cout << "Pilihan yang anda inginkan tidak ada." << endl;
			cout << endl;
			setcolor (7);
			getch();															
			cout << endl;
			goto pilperiode;
		}

    //PEMASUKAN
    int pemasukan;
    
    pilmasuk:
		cout << "--------------------------------  PEMASUKAN  --------------------------------" << endl;
    	cout << endl;
    	cout << "Pemasukan anda pada " << waktu << " ini : Rp.";
		cin >> pemasukan;
		cout << endl;

	//MENAMPILKAN KATEGORI PENGELUARAN
	pengeluaran :
	judul();
	int pengeluaran; 
	int jumlah = 6;
	string ubah;
	string kat[100]={"Makanan","Pakaian","Listrik","Kesehatan","Hobi","Dll"};
	/*[string kat[100]] adalah wadah/tempat nama-nama kategori disimpan*/
	
	cout << "-------------------------------  PENGELUARAN  -------------------------------" << endl;
	cout << endl;
	cout << "Daftar Kategori Pengeluaran : " << endl;
	cout << endl;
	
	//(Perulangan untuk menampilkan daftar kategori)
	for (int i=0;i<jumlah;i++)
	{
		cout << i+1 << ". " << kat[i] << endl;
	}		
	
	cout << endl;
	cout << "Apakah anda ingin mengubah kategori diatas ( Yes(Y) / No(N) ) ? ";
	cin >> ubah;
	cout << endl;

	//UBAH KATEGORI
	edit :
		if (ubah=="y"||ubah=="Y"||ubah=="yes"||ubah=="Yes")
		/*[if (ubah=="y"||ubah=="Y")] ubah adalah wadah yang didalamnya berisi jawaban pada [tanya:]*/
		/*[||] adalah [atau], jadi maksud dari if diatas [y atau Y], tujuannya adalah memudahkan pengguna jikalau lupa untuk mengisi [Y] besar*/
		/*aturan Atau/or apabila salah satu True makan True*/
		{	
			system ("cls");
			judul();
			cout << "------------------------------  UBAH KATEGORI  ------------------------------" << endl;
			cout << endl;
			setcolor (12);
			cout << "Input banyak kategori tidak lebih kecil dari 2 dan lebih besar dari 8." << endl << endl;
			setcolor (7);
			cout << "Berapa banyak kategori pengeluaran yang anda inginkan : ";
			cin >> jumlah;
			cout << endl;
			
			/*Percabangan di dalam percabangan*/
			/*Percabangan untuk mengantisipasi kesalah dalam menginputkan banyak kaegori yang mungkin terlalu sedikit ataupun banyak*/
			if (jumlah>8)
			{
				setcolor (12);
				cout << "Kategori yang anda inginkan terlalu banyak." << endl;
				cout << "Gunakan nama kategori 'dll' untuk kategori yang tidak terlalu penting." << endl << endl; 
				setcolor (7);
				getch ();
				goto edit;
			}
			else if (jumlah<2)
			{
				setcolor (12);
				cout << "Kategori yang anda inginkan terlalu dikit, usahakan lebih dari 1." << endl << endl;
				setcolor (7);
				getch ();
				goto edit;
			}
			else
		
			cout << "Inputkan nama untuk tiap-tiap kategori : " << endl;
			cout << endl;
			//(perulangan untuk menginput nama kategori yang tadinya ingin diedit
			for (int i=0;i<jumlah;i++)
			{
				cout << "Kategori " << i+1 << " : ";
				cin >> kat[i];
			}
		}
		else if (ubah=="N"||ubah=="n"||ubah=="no"||ubah=="No")
		//sama seperti [y atau Y], disni digunakan [N atau n]
		{
			goto input;
		}
		else
		{
			setcolor (12);
			cout << "Inputan anda salah, tolong input sesuai dengan yang diperintahkan";
			setcolor (7);
			getch();
			getch ();
			goto pengeluaran;
		}
	
	Baru:
	system ("cls");
	judul();	
	cout << endl;
	cout << "----------------------------  PENGELUARAN BARU  -----------------------------" << endl;
	cout << endl;
	cout << "Daftar Kategori Pengeluaran Baru : " << endl;
	cout << endl;
	//(perulangan untuk menampilkan kategori baru)
	for (int i=0;i<jumlah;i++)
	{
		cout << i+1 << ". " << kat[i] << endl;
	}
	
		cout << endl;	
		cout << "Apakah anda sudah yakin dengan Daftar Kategori Pengeluaran diatas," << endl;
		cout << "Apakah anda ingin mengubah kategori lagi ( Yes(Y) / No(N) ) ? ";
		cin >> ubah;
		cout << endl;
		
	if (ubah=="y"||ubah=="Y"||ubah=="Yes"||ubah=="yes")
	{
		goto edit;
	}
	else if (ubah=="n"||ubah=="N"||ubah=="No"||ubah=="no")
	{
		goto input;
	}
	else
	{
		cout << "Inputan anda salah, tolong input sesuai dengan yang diperintahkan";
		goto Baru;
	}
	
	//INPUT PENGELUARAN
	input :
		system ("cls");
		cout << "---------------------------  INPUT PENGELUARAN  -----------------------------" << endl;
		cout << endl;
		cout << "Masukan Biaya Pengeluaran Perkategori dibawah : " << endl;
		cout << endl;
		float input [100];
		
		//perulangan didalam perulangan
		//perulangan pertama untuk menampilkan nama kategori
		for (int i=0;i<jumlah;i++)
		{
			cout << i+1 << ". " << kat[i] << " : Rp." ;
			//perulangan kedua untuk menginput biaya pertiap nama kategori yang ditampilkan tadi
			for(int k=i;k<=i;k++)
			{
				cin >> input [i];
			}	
		}
		system("cls");	
			
	cout << endl;
		
	//HASIL AKHIR	
	judul();
	cout << "-----------------------------  KEUANGAN ANDA  -------------------------------" << endl;		
	cout << endl;
		
	//TOTAL,MIN,MAX
	int tambah,min,max,besar,kecil;
	tambah=0;
	min = input [0];
	max = input [0];
	string katmax;
	
	//perulangan untuk mencari total pengeluaran dan pengeluaran tertinngi dan terendah	
	for (int j=0;j<jumlah;j++)
	{
		//pertama tambah untuk mencari Total
		tambah = tambah + input[j];
		
		//kedua percabangan untuk menentukan pengeluaran tertinggi dan terendah
		if (input [j]<min)
		{
			min=input[j];
		}
		else if (input[j]>max)
		{
			max=input[j];
			katmax=kat[j];
		}
	}
	cout << " "<< "Halo " << nama << endl;	
	cout << endl;
	cout << " "<< "Jumlah Pemasukan anda pada" << waktu << " ini : " << pemasukan << endl;
	cout << " "<< "Total Pengeluaran anda pada " << waktu << "  ini : " << tambah << endl; 
	cout << " "<< "Pengeluaran Terbesar anda sebesar " << max << " pada kategori "<< katmax << endl;   
	
	//percabngan untuk menentukan apakah kita boros atau tidak dengan membandingan pemasukan dan pengeluaran dengan total(tambah)
	if (pemasukan >= tambah)
	{
		cout << " Sisa uang anda pada " << waktu << " ini adalah " << pemasukan-tambah << endl;
		cout << endl;
		cout << " Anda sudah cukup baik dalam mengatur keuangan anda" << endl;
		cout << " Pertahankan untuk lebih hemat lagi ya " << nama << endl;
	}
		else if (pemasukan < tambah)
	{
		cout << " Pengeluaran anda melebihi pemasukan anda" << endl;
		cout << endl;
		cout << " Anda sangat Boros" << endl;
		cout << " Berusaha untuk hemat dalam mengatur keuangan anda "<< endl;
	}
	
	
	//PONDASI GRAFIK
	cout << endl;
	cout << "---------------------------  GRAFIK PERSENTASE  -----------------------------" << endl;
	cout << endl;
	
	//perulangan untuk membuat angka 0,5,10,15,..,100 dari bawah ke atas pada grafik
	//angka tersebut merupakan sumbu x (nilai persentase) yang merupakan titik ukur tinggi persentase kategori nanti
	for(float m=0;m<=20;m++)
	{
		int n;
		n = m*5;
		gotoxy(1,38-m);cout<<n;  	 
	}
	
	//perulangan hampir sama dengan ynag diatas hanya saja yang dicetak bukan angka tapi [|] sebagai garis untuk mempermudah dalam memahami grafik						
	for(int o=0;o<=20;o++) 
	{
		gotoxy(4,38-o);cout<<"|";
	}
	
	//perulangan ini terdiri dari dua fungsinya untuk mencetak [-] 
	for(int p=0;p<=70;p++) 
	{
		for(int q=0;q<=20;q++)
		{
			gotoxy(6+p,18+q);cout<<"-"; 
		}
	}
	
	//perualngan ini sama seperti diata fungsinya untuk mencetak [ ]
	//tujuannya mengantisipasi apabila ada garis [-] yang kebawah sehingga tidak merusak grafik
	for (int p=0;p<=80;p++)
	{
		for (int q=0;q<=5;q++)
		{
			gotoxy(6+p,39+q);cout<<" ";
		}
	}
	
	//GRAFIK PERSENTASE KATEGORI
	
	int i=0;
	//perulangan do while dibuat sebagai sumbu y atau titik tempat grafik batang kategori berdiri
	//yang nantinya dijalankan dengan fungsi gotoxy pada perulangan for
	do
	{	
		//pada perulangan for akan dicetak grafik batang berupa simbol [|#|] dari bawah keatas sesuai dengan berapa besar persentase kategori
		//catatan rumus : 	persentase didapat dari = (input[i]/tambah*100)
		//					banyak batang yang berupa simbol [|#|] = persentase/5
		//contoh misal input [i] = 10, tambah=100
		//					maka persentase = (10/100*100) = 10
		//					maka byk batang = 10/5 = 2
		//					maka simbol [|#|] akan dicetak sebanyak 2 kali
		for(float x=0;x<=((input[i]/tambah*100)/5);x++)
		{
			setcolor (i+8);
			int p=(i*9)+9;
			int q=(i*9)+9;
			gotoxy(p,38-x);cout<<"|#|";
			gotoxy(q,39);
			setcolor (7);
			cout << "Kat-" << i+1;
		}
		i++;
	}
	while (i<jumlah);
	setcolor (7);
	
	cout << endl;
	cout << endl;
	cout << " Keterangan persentase pengeluaran : " << endl;
	//perulangani
	
	for (int i=0;i<jumlah;i++)
	{	
		cout << " - " ;
		setcolor (i+1);
		cout << "|#|";
		setcolor (7);
		cout << " : " << setprecision(2) << input[i]/tambah*100 << "%" << " dari " << kat[i]<<endl;
		/*[setprecision(2)] berfungsi untuk menampilkan hanya 2 angka dibelakang koma*/
	}
	
	//AKHIR PROGRAM
	
	programakhir:
		cout << endl;
		cout << "Apakah anda ingin mengakhiri program ini (Ya = 1 / Tidak = 2) ?";
		cin >> ubah;
		
	if(ubah=="y"||ubah=="Y"||ubah=="Yes"||ubah=="yes")
	{
		goto awal;
	}
	else if (ubah=="n"||ubah=="N"||ubah=="No"||ubah=="no")
	{
		goto end;
	}
	else 
	{	
		setcolor (12);
		cout << "Pilihan anda tidak ada" << endl;
		setcolor (7);
		getch();
		goto programakhir;
		system ("cls");
	}
	end:
		getch ();
		/*[getch()] berfungsi untuk memberhentikan pemrograman agar tidak langsung keluar/berpindah*/
		return 0;
}

