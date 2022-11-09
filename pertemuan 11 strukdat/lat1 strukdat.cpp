#include <iostream>
using namespace std;

class mahasiswa{
	public:
		string namaMahasiswa;
		void printname(){
			cout << "Nama Mahasiswa: " << namaMahasiswa;
			cout << endl;
		}
};

int main(){
	mahasiswa mhs1;
	mhs1.namaMahasiswa = "Cak Pon";
	mhs1.printname();
	mahasiswa mhs2;
	mhs2.namaMahasiswa = "Rohim";
	mhs2.printname();
	
	return 0;
}