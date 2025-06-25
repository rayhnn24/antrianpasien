#include <iostream>  
using namespace std;  

struct Pasien {
    string nama;
    Pasien* next;
    Pasien* head = nullptr;
};
