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
int main() {
    int pilihan;
    string nama;

    // Menu berulang selama user belum memilih keluar (0)
    do {
        cout << "\n=== MENU ANTRIAN PASIEN KLINIK ===\n";
        cout << "1. Tambah Pasien\n";
        cout << "2. Tampilkan Antrian\n";
        cout << "3. Panggil Pasien\n";
        cout << "4. Hitung Pasien\n";
        cout << "5. Hapus Semua\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        // Validasi jika input bukan angka
        if (cin.fail()) {
            cin.clear();              // Reset status error input
            cin.ignore(10000, '\n');  // Buang input yang salah
            cout << "Input tidak valid.\n";
            continue;
        }

        switch (pilihan) {
            case 1:
                // Tambah pasien
                cout << "Masukkan nama pasien: ";
                cin >> ws;            // Membersihkan newline tersisa
                getline(cin, nama);   // Ambil nama lengkap
                tambahPasien(nama);
                break;

            case 2:
                // Tampilkan daftar antrian
                tampilkanAntrian();
                break;

            case 3:
                // Panggil pasien pertama
                panggilPasien();
                break;

            case 4:
                // Hitung jumlah pasien
                hitungPasien();
                break;

            case 5: {
                // Konfirmasi sebelum menghapus semua
                char yakin;
                cout << "Yakin ingin menghapus semua antrian? (y/n): ";
                cin >> yakin;
                if (yakin == 'y' || yakin == 'Y')
                    hapusSemua();
                else
                    cout << "Penghapusan dibatalkan.\n";
                break;
            }

            case 0:
                // Keluar dari program
                cout << "Keluar dari program.\n";
                break;

            default:
                // Jika pilihan tidak sesuai
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 0);

    return 0;
}
