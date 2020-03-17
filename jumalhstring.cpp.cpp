#include <iostream>
#include <string>

using namespace std;

int main(){
	string a;
	int jumlah;
	
	cout<<"Masukan kalimat = ";
	getline(cin, a);
	
	jumlah = a.length ();
	
	cout<< "Jumlah karakter adalah = "<<jumlah<<endl;
}