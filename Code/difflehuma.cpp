#include <iostream>

using namespace std;
//so nguyên to p = , thuc hien các buoc trao doi khóa = tt Diffie-Hellman
//input p = 353,a=3,Xa=97,Xb=233
//ouput Ya=40,Yb=248,khoa chung Ka=160,Kb=160
// Hàm tính luy thua 
int lthua(int base,int exp,int mod){
	int kq=1;
	base = base % mod;
	while(exp>0){
		if(exp%2==1)
		kq=(kq*base)%mod;
		exp = exp/2;
		base = (base * base) % mod;
	}
	return kq;
}

int modIn(int a,int p){
	return lthua(a,p-2,p);
}
int main() {
	int p,a,xa,xb;
    cout<<"Nhap modulo p: ";cin>>p;
    cout<<"Nhap ptnt cua p: ";cin>>a;
    cout<<"Nhap khoa bi mat cua A: ";cin>>xa;
    cout<<"Nhap khoa bi mat cua B: ";cin>>xb;
    //tinh khoa ck
    int ya = lthua(a,xa,p);
    int yb = lthua(a,xb,p);
    //tinh khoa chung
    int ka = lthua(yb,xa,p);
    int kb = lthua(ya,xb,p);
    //hien thi khoa
    cout<<"\nTHANH PHAN CONG KHAI:"<<endl;
    cout<<"Modulo p: "<<p<<endl;
    cout<<"Ptu nguyen thuy a: "<<a<<endl;
    cout<<"Khoa cong khai Y(A): "<<ya<<endl;
    cout<<"Khoa cong khai Y(B): "<<yb<<endl;
    
    cout<<"\nTHANH PHAN BI MAT:"<<endl;
    cout<<"Khoa bi mat X(A): "<<xa<<endl;
    cout<<"Khoa bi mat X(B): "<<xb<<endl;
    cout<<"Khoa chung K(A): "<<ka<<endl;
    cout<<"Khoa chung K(B): "<<kb<<endl;
    
    if(ka==kb){
    	cout<<"Trao doi key thanh cong";
	}
	else{
		cout<<"That bai";
	}
    return 0;
}

