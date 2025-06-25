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
void panggilPasien() {
    if (head == nullptr) {
        cout << "Tidak ada pasien untuk dipanggil.\n";
        return;
    }
    Pasien* dipanggil = head;
    cout << "Memanggil pasien: " << dipanggil->nama << endl;
    head = head->next;
    delete dipanggil;
}
void hitungPasien() {
    int jumlah = 0;
    Pasien* temp = head;

    while (temp != nullptr) {
        jumlah++;
        temp = temp->next;
    }

    cout << "Jumlah pasien dalam antrian: " << jumlah << endl;
}
void hapusSemua() {
    while (head != nullptr) {
        Pasien* hapus = head;
        head = head->next;
        delete hapus;
    }
    cout << "Semua antrian telah dihapus.\n";
}

