#include <iostream>
#include <string>
using namespace std;

struct mahasiswa
{
    string nrp;
    string nama;
    string nohp;
    string gender;
    string agama;
};

void tampilkanData(struct mahasiswa *mhs, int &jumlah_mhs)
{
    cout << "Berikut adalah data yang telah diinputkan" << endl;

    for(int i=0;i<jumlah_mhs;i++)
    {
        cout << "\n==========Data ke-" << i+1 << "==========" << endl;
        cout <<"NRP : " << mhs[i].nrp << endl;
        cout << "Nama: " << mhs[i].nama << endl;
        cout <<"No HP: " << mhs[i].nohp << endl;
        cout <<"Gender: " << mhs[i].gender << endl;
        cout <<"Agama :" << mhs[i].agama << endl;
    };
}

void tambahData(struct mahasiswa *mhs, bool &check, int &jumlah_mhs)
{
    cout << "\n==========Silahkan masukkan data==========" << endl;
    cin.ignore();
    cout << "NRP: "; getline(cin, mhs[jumlah_mhs].nrp);
    cout << "Nama: "; getline(cin, mhs[jumlah_mhs].nama);
    cout << "No HP: "; getline(cin, mhs[jumlah_mhs].nohp);
    cout << "Gender (P/L): "; getline(cin, mhs[jumlah_mhs].gender);
    cout << "Agama: "; getline(cin, mhs[jumlah_mhs].agama);
    cout << endl;

    jumlah_mhs++;
    check = true;
}

void ubahData(struct mahasiswa *mhs, bool &check, int jumlah_data)
{
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

    int j = i-1;
    switch(menu)
    {
        case 1:
        cin.ignore();
        cout << "NRP: "; getline(cin, mhs[j].nrp); 
        break;

        case 2:
        cin.ignore();
        cout << "Nama: "; getline(cin, mhs[j].nama);
        break;

        case 3:
        cin.ignore();
        cout << "No Hp: "; getline(cin, mhs[j].nohp);
        break;

        case 4:
        cin.ignore();
        cout << "Gender: "; getline(cin, mhs[j].gender);
        break;

        case 5:
        cin.ignore();
        cout << "Agama: "; getline(cin, mhs[j].agama);
        break;

        case 6:
        cin.ignore();
        cout << "NRP: "; getline(cin, mhs[j].nrp);
        cout << "Nama: "; getline(cin, mhs[j].nama);
        cout << "No HP: "; getline(cin, mhs[j].nohp);
        cout << "Gender (P/L): "; getline(cin, mhs[j].gender);
        cout << "Agama: "; getline(cin, mhs[j].agama);
        cout << endl;
        break;
    }

}

void hapusData(struct mahasiswa *mhs, bool &check, int &jumlah_mhs)
{
    int i;
    cout << "Masukkan data ke berapa yang ingin dihapus : "; cin >> i;

    if (i <= jumlah_mhs)
    {
        for(int j=i-1; j<jumlah_mhs-1; j++)
        {
            mhs[j] = mhs[j+1];
        }

        jumlah_mhs--;
        cout << "Data telah terhapus" << endl;
    }

    if(jumlah_mhs == 0){
        check = false;
    } else {
        check = true;
    }
}

void cariData(struct mahasiswa *mhs, bool &check)
{
    int i;
    cout << "Masukkan data ke berapa yang ingin dilihat : "; cin >> i;

    int j = i-1;
    cout << "\n==========Data ke-" << i << "==========" << endl;
    cout <<"NRP : " << mhs[j].nrp << endl;
    cout << "Nama: " << mhs[j].nama << endl;
    cout <<"No HP: " << mhs[j].nohp << endl;
    cout <<"Gender: " << mhs[j].gender << endl;
    cout <<"Agama :" << mhs[j].agama << endl;
    cout << endl;
}

int main ()
{
    struct mahasiswa mhs[10];
    bool check = false;
    int menu;
    int jumlah_data = 0;
    do{
        cout << "\nPilih menu :\n";
        cout << "1. Tampilkan Data\n";
        cout << "2. Tambah Data Baru\n";
        cout << "3. Ubah Data\n";
        cout << "4. Hapus Data\n";
        cout << "5. Cari Data\n";
        cout << "6. Keluar\n";
        cout << "Masukkan pilihan (angka): ";
        cin >> menu ;

        switch (menu)
        {
        case 1 :
            if(check){
                tampilkanData(mhs, jumlah_data);
            } else {
                cout << "\nTidak ada data yang diinput. Data tidak dapat ditampilkan." << endl;
            }
            break;
        case 2 :
            tambahData(mhs, check, jumlah_data);
            break;
        case 3 :
            if(check){
                ubahData(mhs, check, jumlah_data);
            } else{
                cout << "\nTidak ada data yang dapat diubah. Inputkan data terlebih dahulu." << endl;
            }
            break;
        case 4 :
            if(check){
                hapusData(mhs, check, jumlah_data);
            } else {
                cout << "\nTidak ada data yang dapat dihapus. Belum ada data yang diinputkan" << endl;
            }
            break;
        case 5 :
            if(check){
                cariData(mhs, check);
            } else{
                cout << "\nData tidak ada. Data belum diinputkan" << endl;
            }
            break;
        case 6 :
            cout << "\nTerima kasih. Anda telah keluar dari program.\n";
            break;
        default:
            cout << "\nPilihan tidak ada di Menu, silahkan coba lagi.\n";
            break;
        };
    } while (menu != 6);
    return 0;
};
