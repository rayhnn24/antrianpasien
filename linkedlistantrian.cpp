#include <iostream>  
using namespace std;  

struct Pasien {
    string nama;
    Pasien* next;
};

Pasien* head = nullptr;
void tambahPasien(string nama) {
    Pasien* baru = new Pasien{nama, nullptr};

    if (head == nullptr) {
        head = baru;
    } else {
        Pasien* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = baru;
    }
    cout << "Pasien \"" << nama << "\" ditambahkan ke antrian.\n";
}
void tampilkanAntrian() {
    if (head == nullptr) {
        cout << "Antrian kosong.\n";
        return;
    }

    cout << "Daftar Antrian Pasien:\n";
    Pasien* temp = head;
    int no = 1;

    while (temp != nullptr) {
        cout << no++ << ". " << temp->nama << endl;
        temp = temp->next;
    }
}
