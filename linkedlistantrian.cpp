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
