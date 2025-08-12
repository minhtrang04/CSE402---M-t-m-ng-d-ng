#include <iostream>
#include <math.h>
using namespace std;

//Nhap 2 kí tu,lap trình mô phong các phuong pháp mã hóa/giai mã 
//3 cap su dung thuat toán Feistel don gian
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
    
    //Giai ma N lan
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
int main()
{
	string P,C;
	char K1,K2,K3;
    //Nhap 1 chuoi co 2 ki tu (kich co m = 2w = 16b)
    cout<<"Plaintext: ";
    getline(cin,P);
   
    //Nhap khoa K - Dai 8 bit
    cout<<"Nhap khoa K1: ";cin>>K1;
    cout<<"Nhap khoa K2: ";cin>>K2;
    cout<<"Nhap khoa K3: ";cin>>K3;
    //MA HOA 3DES
    C=MHKhoi(P[0],P[1],K1);
    C=MHKhoi(C[0],C[1],K2);
    C=MHKhoi(C[0],C[1],K3);
    cout<<"CHUOI MA HOA LA: "<<C<<endl;
    //GM 3DES
    C=GMKhoi(C[0],C[1],K3);
    C=GMKhoi(C[0],C[1],K2);
    P=GMKhoi(C[0],C[1],K1);
     cout<<"CHUOI GIAI MA LA: "<<P;
   
    return 0;
    
}

