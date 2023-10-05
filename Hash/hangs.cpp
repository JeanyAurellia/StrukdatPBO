#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> userToHash;
const int SIZE_ARR = 26;

int customHash(const string& str) {
    int hashValue = 0;
    for (char c : str) {
        hashValue += static_cast<int>(c); 
    }
    hashValue = hashValue * hashValue; 
    return hashValue % SIZE_ARR;
}

void printAll()
{
    cout << "User to Hash Mapping:" << endl;
    for (const auto &pair : userToHash)
    {
        cout << pair.first << " - " << pair.second << endl;
    }
}

void menu()
{
    while (true)
    {
        int input_user;

        cout << endl;
        cout << "MENU" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Show Hash" << endl;
        cout << "4. Exit" << endl
             << endl;

        cout << "Pilih: " << endl;
        cin >> input_user;
        cout << endl;

        if (input_user == 1)
        {
            string username, password;

            cout << "Masukkan Username: " << endl;
            cin >> username;
            cout << "Masukkan Password: " << endl;
            cin >> password;

            int index = customHash(password); // Menggunakan fungsi hash kustom

            if (userToHash.find(username) == userToHash.end())
            {
                userToHash[username] = index;
                cout << "Registrasi berhasil!" << endl;
            }
            else
            {
                cout << "Akun sudah ada!" << endl;
            }
        }
        else if (input_user == 2)
        {
            string username, password;

            cout << "Masukkan Username: " << endl;
            cin >> username;
            cout << "Masukkan Password: " << endl;
            cin >> password;

            if (userToHash.find(username) != userToHash.end())
            {
                int expectedHash = userToHash[username];
                int actualHash = customHash(password);

                if (expectedHash == actualHash)
                {
                    cout << "Login berhasil!" << endl;
                }
                else
                {
                    cout << "Login gagal!" << endl;
                }
            }
            else
            {
                cout << "Akun tidak ditemukan!" << endl;
            }
        }
        else if (input_user == 3)
        {
            string username;

            cout << "Masukkan Username untuk menampilkan hash: " << endl;
            cin >> username;

            if (userToHash.find(username) != userToHash.end())
            {
                int hash = userToHash[username];
                cout << "Hash dari password untuk username '" << username << "' adalah: " << hash << endl;
            }
            else
            {
                cout << "Username tidak ditemukan!" << endl;
            }
        }
        else if (input_user == 4)
        {
            printAll();
            break;
        }
        else
        {
            cout << "Invalid!" << endl;
        }
    }
}

int main()
{
    menu();
    return 0;
}
