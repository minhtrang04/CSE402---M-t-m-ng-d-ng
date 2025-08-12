#include <iostream>
#include <math.h>
using namespace std;

// Nhap mot chuoi plaintext tu bàn phím. Lap trình mã hóa chuoi bang thuat toán 3 cap don gian o bài 1
// Hien chuoi mã hóa ra màn hình. (Tách chuoi thành tung khoi 16 bit roi áp dung thuat toán)
//Giai mã và hien chuoi giai mã ra màn hình

//Ham F
char F(char R,char Ki)
{
    return R+Ki;
}
string MHKhoi(char P0,char P1,char k){
	char L[3],R[3],K[3];
    L[0]=P1;
    R[0]=P0;
    K[0]=k;
    string C="XX";
    //Ma hoa N lan
    for (int i = 1; i <= 2; i++)
    {
        K[i] = K[0]<<i;
		L[i] = R[i-1];
        R[i] = L[i-1] ^ F(R[i-1],K[i]);
     }
   
    C[0] = L[2];
    C[1] = R[2];
    return C;
}
string GMKhoi(char C0,char C1,char k0){
	char L[3],R[3],K[3];
	string P="XX";
    L[2]=C0;
    R[2]=C1;
    K[0]=k0;
    
    //Ma hoa N lan
    for (int i = 2; i >= 1; i--)
    {
        K[i] = K[0]<<i;
        L[i-1] = R[i] ^ F(L[i],K[i]);
        R[i-1] = L[i];
    }
    //Rn+1 = Ln;L+1=Rn;
    P[0] = R[0];
    P[1] = L[0];
    return P;
}
string MHK(char P0,char P1,char K1,char K2,char K3){
	string C="XX";
	//MA HOA 3DES
    C=MHKhoi(P0,P1,K1);
    C=MHKhoi(C[0],C[1],K2);
    C=MHKhoi(C[0],C[1],K3);
    return C;
}
string GMK(char C0,char C1,char K1,char K2,char K3){
	string P="XX";
	string C="XX";
    //GM 3DES
    C=GMKhoi(C0,C1,K3);
    C=GMKhoi(C[0],C[1],K2);
    P=GMKhoi(C[0],C[1],K1);
     return P;
}
int main()
{
	string P,C="",D="";
	char K1,K2,K3;

    cout<<"Plaintext: ";
    getline(cin,P);
   
    //Nhap khoa K - Dai 8 bit
    cout<<"Nhap khoa K1: ";cin>>K1;
    cout<<"Nhap khoa K2: ";cin>>K2;
    cout<<"Nhap khoa K3: ";cin>>K3;
    
    // Bo sung ký tu 'X' neu do dài chuoi le
   if(P.size()%2!=0){
   	P=P+'X';
   }
   for(int i=0;i<P.size();i+=2){
   	string block=MHK(P[i],P[i+1],K1,K2,K3);
   	C += block;
   }
   cout<<"Chuoi Ma Hoa: "<<C<<endl;
   
   for (int i = 0; i < C.size(); i += 2) {
        string block = GMK(C[i], C[i + 1], K1, K2, K3);
         D += block;
    }
    cout << "Chuoi Giai ma: " << D << endl;
    
    return 0;
    
}

