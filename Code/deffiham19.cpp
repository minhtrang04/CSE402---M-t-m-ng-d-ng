#include <iostream>
#include <cmath>

using namespace std;
//so nguyên to p = , thuc hien các buoc trao doi khóa = tt Diffie-Hellman
//input p = 353,a=3,Xa=97,Xb=233
//ouput Ya=40,Yb=248,khoa chung Ka=160,Kb=160
// Hàm tính luy thua 
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
    
    // Khóa bí mat cua A và B
    int xa ; // Khóa bí mat cua Alice
    cout<<"Nhap khoa bi mat cua A:";cin>>xa;
    int xb ; // Khóa bí mat cua Bob
     cout<<"Nhap khoa bi mat cua B:";cin>>xb;
     
    // A và B tính toán khóa công khai
    int Ya = lthua(a, xa, p); // Ya = a^xa mod p
    int Yb = lthua(a, xb, p); // Yb = a^xb mod p
    
     // Tính toán khóa chung
    int Ka = lthua(Yb,xa, p); // Khóa chung A tính: B^a mod p
    int Kb = lthua(Ya, xb, p);   // Khóa chung B tính: A^b mod p

    // A và B trao doi khóa công khai
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

