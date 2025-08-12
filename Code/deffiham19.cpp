#include <iostream>
#include <cmath>

using namespace std;
//so nguy�n to p = , thuc hien c�c buoc trao doi kh�a = tt Diffie-Hellman
//input p = 353,a=3,Xa=97,Xb=233
//ouput Ya=40,Yb=248,khoa chung Ka=160,Kb=160
// H�m t�nh luy thua 
int lthua(int base, int exp, int mod) {
    int kq = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) // Neu exp le
            kq = (kq * base) % mod;
        exp = exp / 2;   // Chia exp cho 2
        base = (base * base) % mod;
    }
    return kq;
}

int main() {
    int p ,a ; 
    cout<<"Nhap modul P(so nguyen to): ";cin>>p;
    cout<<"Nhap so ntnt cua p: ";cin>>a;
    
    // Kh�a b� mat cua A v� B
    int xa ; // Kh�a b� mat cua Alice
    cout<<"Nhap khoa bi mat cua A:";cin>>xa;
    int xb ; // Kh�a b� mat cua Bob
     cout<<"Nhap khoa bi mat cua B:";cin>>xb;
     
    // A v� B t�nh to�n kh�a c�ng khai
    int Ya = lthua(a, xa, p); // Ya = a^xa mod p
    int Yb = lthua(a, xb, p); // Yb = a^xb mod p
    
     // T�nh to�n kh�a chung
    int Ka = lthua(Yb,xa, p); // Kh�a chung A t�nh: B^a mod p
    int Kb = lthua(Ya, xb, p);   // Kh�a chung B t�nh: A^b mod p

    // A v� B trao doi kh�a c�ng khai
    cout << "Khoa cong khai cua (A): " << Ya << endl;
    cout << "Khoa cong khai cua (B): " << Yb << endl;
    cout << "Khoa chung tinh duoc boi A: " << Ka << endl;
    cout << "Khoa chung tinh duoc boi B: " << Kb << endl;

    if (Ka == Kb) {
        cout << "Trao doi khoa thanh cong! Khoa chung la: " << Ka << endl;
    } else {
        cout << "Co loi trong qua trinh trao doi khoa!" << endl;
    }

    return 0;
}

