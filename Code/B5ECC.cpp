#include <iostream>
using namespace std;

//P(xP, yP) là 1 diem thuoc Ep(a,b).
// Lap trình nhap toa do diem P roi tính bâc n cua diem P dó, voi a và p nhap tu bàn phím.

//Hàm tính nghich dao modulo a^-1 mod p
int modInverse(int a, int p) {
    for (int i = 1; i < p; i++) {
        if ((a * i) % p == 1) return i;
    }
    return -1; // Không tìm duoc
}

// Hàm cong hai diem P và Q trên elliptic curve
void addPoints(int Xp, int Yp, int Xq, int Yq, int a, int p, int &Xr, int &Yr) {
    if (Xp == -1 && Yp == -1) 
	{ Xr = Xq; Yr = Yq; return; } // P là vô cuc
    if (Xq == -1 && Yq == -1) 
	{ Xr = Xp; Yr = Yp; return; } // Q là vô cuc
    if (Xp == Xq && (Yp + Yq) % p == 0) 
	{ Xr = -1; Yr = -1; return; } // P + (-P) = O

    int lambda;
    if (Xp == Xq && Yp == Yq) { 
	// Truong hop P = Q
        lambda = (3 * Xp * Xp + a) * modInverse(2 * Yp, p) % p;
    } else { 
	// Truong hop P != Q
        lambda = (Yq - Yp + p) * modInverse(Xq - Xp + p, p) % p;
    }

    Xr = (lambda * lambda - Xp - Xq + p) % p;
    Yr = (lambda * (Xp - Xr + p) - Yp + p) % p;
}

// Tính bac cua diem P
int level(int Xp, int Yp, int a, int p) {
    int Xr = Xp, Yr = Yp, n = 1; // Bat dau tu n = 1

    while (!(Xr == -1 && Yr == -1)) { // Lap den khi nP = O
        addPoints(Xr, Yr, Xp, Yp, a, p, Xr, Yr);
        n++;
    }

    return n; // Tra ve bac
}

int main() {
    int Xp, Yp, a, p;

    cout << "Nhap Xp: "; cin >> Xp;
    cout << "Nhap Yp: "; cin >> Yp;
    cout << "Nhap a: "; cin >> a;
    cout << "Nhap p: "; cin >> p;

    // Tính bac cua P
    int order = level(Xp, Yp, a, p);

    // In ket qua
    cout << "Bac cua P la: " << order << endl;

    return 0;
}

