#include <iostream>
#include <string>
using namespace std;

struct mahasiswa {
    string nrp;
    string nama;
    string nohp;
    string gender;
    string agama;
};

struct Node {
    struct mahasiswa data;
    struct Node* next;
};

void tampilkanData(struct Node* head) {
    struct Node* current = head;
    if (!current) {
        cout << "Belum ada data yang dimasukkan. Harap masukkan data terlebih dahulu." << endl;
        return;
    }

    cout << "Berikut adalah data yang telah diinputkan" << endl;
    int i = 1;
    while (current) {
        cout << "\n==========Data ke-" << i << "==========" << endl;
        cout << "NRP : " << current->data.nrp << endl;
        cout << "Nama: " << current->data.nama << endl;
        cout << "No HP: " << current->data.nohp << endl;
        cout << "Gender: " << current->data.gender << endl;
        cout << "Agama : " << current->data.agama << endl;
        current = current->next;
        i++;
    }
}

void tambahData(struct Node*& head, int& jumlah_mhs) {
    struct Node* newNode = new Node;
    cout << "\n==========Silahkan masukkan data==========" << endl;
    cin.ignore();
    cout << "NRP: "; getline(cin, newNode->data.nrp);
    cout << "Nama: "; getline(cin, newNode->data.nama);
    cout << "No HP: "; getline(cin, newNode->data.nohp);
    cout << "Gender (P/L): "; getline(cin, newNode->data.gender);
    cout << "Agama: "; getline(cin, newNode->data.agama);
    cout << endl;

    newNode->next = nullptr;
    if(!head){
        head = newNode;
    }
    else {
        struct Node* current = head;
        while (current->next){
            current = current -> next;
        }
        current->next = newNode;
    }
    jumlah_mhs ++;
}

void ubahData(struct Node* head, int jumlah_data) {
    int menu;
    int i;
    cout << "\nPilih Data yang ingin di ubah : " << endl;
    cout << "1. NRP" << endl;
    cout << "2. Nama" << endl;
    cout << "3. No HP" << endl;
    cout << "4. Gender" << endl;
    cout << "5. Agama" << endl;
    cout << "6. Semua" << endl;
    cout << endl;

    cout << "Pilih menu : "; cin >> menu;
    cout << "\nMasukkan Data ke berapa yang ingin diubah : "; cin >> i;

    struct Node* current = head;
    int j = i-1;
    int count = 0;

    while (count < j && current) {
        current = current->next;
        count++;
    }

    if (current) {
        switch(menu) {
            case 1:
                cin.ignore();
                cout << "NRP: "; getline(cin, current->data.nrp); 
                break;
            case 2:
                cin.ignore();
                cout << "Nama: "; getline(cin, current->data.nama);
                break;
            case 3:
                cin.ignore();
                cout << "No Hp: "; getline(cin, current->data.nohp);
                break;
            case 4:
                cin.ignore();
                cout << "Gender: "; getline(cin, current->data.gender);
                break;
            case 5:
                cin.ignore();
                cout << "Agama: "; getline(cin, current->data.agama);
                break;
            case 6:
                cin.ignore();
                cout << "NRP: "; getline(cin, current->data.nrp);
                cout << "Nama: "; getline(cin, current->data.nama);
                cout << "No HP: "; getline(cin, current->data.nohp);
                cout << "Gender (P/L): "; getline(cin, current->data.gender);
                cout << "Agama: "; getline(cin, current->data.agama);
                cout << endl;
                break;
        }
    } else {
        cout << "Data tidak ditemukan." << endl;
    }
}

void hapusData(struct Node*& head, int& jumlah_mhs) {
    int i;
    cout << "Masukkan data ke berapa yang ingin dihapus : "; cin >> i;

    if (i <= jumlah_mhs) {
        if (i == 1) {
            struct Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            struct Node* current = head;
            struct Node* previous = nullptr;
            int count = 1;
            while (count < i) {
                previous = current;
                current = current->next;
                count++;
            }
            previous->next = current->next;
            delete current;
        }
        jumlah_mhs--;
        cout << "Data telah terhapus" << endl;
    }

    if (jumlah_mhs == 0) {
        head = nullptr;
    }
}

void cariData(struct Node* head) {
    int i;
    cout << "Masukkan data ke berapa yang ingin dilihat : "; cin >> i;

    struct Node* current = head;
    int count = 1;
    while (count < i && current) {
        current = current->next;
        count++;
    }

    if (current) {
        cout << "\n==========Data ke-" << i << "==========" << endl;
        cout << "NRP : " << current->data.nrp << endl;
        cout << "Nama: " << current->data.nama << endl;
        cout << "No HP: " << current->data.nohp << endl;
        cout << "Gender: " << current->data.gender << endl;
        cout << "Agama : " << current->data.agama << endl;
        cout << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }
}

int main() {
    struct Node* head = nullptr;
    int menu;
    int jumlah_data = 0;
    do {
        cout << "\nPilih menu :\n";
        cout << "1. Tampilkan Data\n";
        cout << "2. Tambah Data Baru\n";
        cout << "3. Ubah Data\n";
        cout << "4. Hapus Data\n";
        cout << "5. Cari Data\n";
        cout << "6. Keluar\n";
        cout << "Masukkan pilihan (angka): ";
        cin >> menu;

        switch (menu) {
            case 1:
                tampilkanData(head);
                break;
            case 2:
                tambahData(head, jumlah_data);
                break;
            case 3:
                if (jumlah_data > 0) {
                    ubahData(head, jumlah_data);
                } else {
                    cout << "\nTidak ada data yang dapat diubah. Inputkan data terlebih dahulu." << endl;
                }
                break;
            case 4:
                if (jumlah_data > 0) {
                    hapusData(head, jumlah_data);
                } else {
                    cout << "\nTidak ada data yang dapat dihapus. Belum ada data yang diinputkan" << endl;
                }
                break;
            case 5:
                if (jumlah_data > 0) {
                    cariData(head);
                } else {
                    cout << "\nData tidak ada. Data belum diinputkan" << endl;
                }
                break;
            case 6:
                cout << "\nTerima kasih. Anda telah keluar dari program.\n";
                break;
            default:
                cout << "\nPilihan tidak ada di Menu, silahkan coba lagi.\n";
                break;
        };
    } while (menu != 6);

    // Dealokasi memori untuk semua node sebelum keluar dari program
    struct Node* current = head;
    while (current) {
        struct Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
