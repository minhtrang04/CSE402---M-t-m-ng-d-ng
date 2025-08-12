#include <iostream>
#include <string>
#include <vector>

using namespace std;
//Nhap chuoi Plaintext va Key ,ma hoa va giai ma ch�ng 
// H�m khoi tao S-box dua tr�n kh�a K
void ktaoSBox(vector<int> &S, const string &key) {
    int keyLength = key.length();
    for (int i = 0; i < 256; i++) {
        S[i] = i;
    }

    int j = 0;
    for (int i = 0; i < 256; i++) {
        j = (j + S[i] + key[i % keyLength]) % 256;
        swap(S[i], S[j]);
    }
}

// H�m RC4 (m� h�a hoac giai m�)
string RC4(const string &input, const string &key) {
    vector<int> S(256);
    ktaoSBox(S, key);

    int i = 0, j = 0;
    string output = input;

    for (size_t k = 0; k < input.length(); k++) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        swap(S[i], S[j]);

        int rnd = S[(S[i] + S[j]) % 256];
        output[k] ^= rnd; // XOR voi dau ra cua S-box
    }

    return output;
}

int main() {
    string p, key;

    cout << "Nhap chuoi plaintext: ";
    getline(cin, p);
    cout << "Nhap chuoi khoa: ";
    getline(cin, key);

    // M� h�a
    string ciphertext = RC4(p, key);
    cout << "Chuoi da ma hoa: " << ciphertext << endl;

    // Giai m�
    string deText = RC4(ciphertext, key);
    cout << "Chuoi giai ma: " << deText << endl;

    return 0;
}

