#include <iostream>
using namespace std;

//P(xP, yP) l� 1 diem thuoc Ep(a,b). 
//Lap tr�nh nhap toa do diem P roi t�nh t�ch n.P, v?oi a v� p nhap tu b�n ph�m
// Ham tim nghich dao modular cua a modulo p
int modInverse(int a, int p) {
    a = a % p;
    for (int i = 1; i < p; i++) {
        if ((a * i) % p == 1) return i;
    }
    return -1;
}

// Ham cong hai diem tren elliptic curve
void congDiem(int Xp, int Yp, int Xq, int Yq, int a, int p, int &Xr, int &Yr) {
    int lamda,ts,ms;
    if (Xp == Xq && Yp == Yq) { 
	// Truong hop P = Q
        lamda = (3 * Xp * Xp + a) * modInverse(2 * Yp, p) % p;
    } else { 
	// Truong hop P != Q
         lamda = (Yq - Yp + p) * modInverse(Xq - Xp + p, p) % p;
    }

    // Tinh toa do diem R = P + Q
    Xr = (lamda * lamda - Xp - Xq + p) % p;
    Yr = (lamda * (Xp - Xr + p) - Yp + p) % p;
}

// Ham tinh n * P bang cach cong lap lai
void congLap(int Xp, int Yp, int n, int a, int p, int &Xr, int &Yr) {
    Xr = Xp;
    Yr = Yp;

    for (int i = 1; i < n; i++) {
        congDiem(Xr, Yr, Xp, Yp, a, p, Xr, Yr);
    }
}

int main() {
    int Xp, Yp, a, p, n;

    // Nhap du lieu
    cout << "Nhap Xp: "; cin >> Xp;
    cout << "Nhap Yp: "; cin >> Yp;
    cout << "Nhap a: "; cin >> a;
    cout << "Nhap p: "; cin >> p;
    cout << "Nhap n: "; cin >> n;

    // Tinh n * P
    int Xr, Yr;
    congLap(Xp, Yp, n, a, p, Xr, Yr);

    // In ket qua
    cout << n << "P = (" << Xr << ", " << Yr << ")" << endl;

    return 0;
}

