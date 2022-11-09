#include <iostream>
#include <list>
using namespace std;

class mahasiswa {
    public:
    void printname() {
        cout << "Nama Mahasiswa: " << Name << " NRP: " << NRP << endl;
    }

    string getName() {
        return Name;
    }

    mahasiswa(string Nama, string NoID) { 
        Name = Nama;
        NRP = NoID;
    }

    private:
    string Name;
    string NRP;
};

int main() {
    mahasiswa mhs1("Cak Pon", "053");
    mhs1.printname();
}