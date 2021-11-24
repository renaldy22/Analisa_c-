#include <iostream>
#include <string>
#include <vector>

using namespace std;

class antrian {
	private :
		vector<string> data;
		int depan, belakang;
		int maksElemen;
	public :
		//konstructor
		antrian(int ukuran){
			depan = 0;
			belakang = 0;
			maksElemen = ukuran;
			data.resize(ukuran); //ukuran vector
		}
		
		// buat fungsi input data
		
		void insert (string x){
			int posisiBelakang;
			
			// geser belakang ke posisi berikutnya 
			if (belakang == maksElemen) // jika  
				posisiBelakang = 1;
			else
				posisiBelakang = belakang + 1;
				
			// cek apakah belakang sama dengan depan
			if (posisiBelakang == depan)
				cout <<"antrian penuh" << endl;
			else
				{
					belakang = posisiBelakang;
					
					// masukan data
					data[belakang] = x;
				} 
				
		}
		
		string remove (){
			if (empty())
			{
				cout <<" antrian kosong" << endl;
				return "";
			}
			
			if (depan == maksElemen)
				depan = 1;
			else 
				depan = depan + 1;
			return data[depan];
		}
		
		bool empty(){
			if (depan == belakang)
				return true;
			else 
				return false;
		}
};

int main(){
	int ukuran = 11;
	antrian daftar(ukuran); // membuat objek
	
	// memasukkan 5 nama ke antrian
	
	daftar.insert("renaldy"); 
	daftar.insert("adit");
	daftar.insert("dudi");
	daftar.insert("heru");
	daftar.insert("muhammad");
	daftar.insert("agung");
	daftar.insert("dayat");
	daftar.insert("lilis");
	daftar.insert("jessica");
	daftar.insert("heru");
	daftar.insert("dudung");
	// kosongkan daftar antrian dan tampilkan
	
	while(!daftar.empty()){
		string nama = daftar.remove();
		cout << nama << endl;
	}    
}
