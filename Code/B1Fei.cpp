#include <iostream>
#include <math.h>
using namespace std;

//Hàm F
char F (char R,char ki){
	return R + ki;
}

//ham MH
string hamMH(char P0,char P1,char k){
	char L[3],R[3],K[3];
	string C="XX";
	L[0]=P1;
	R[0]=P0;
	K[0]=k;
	
	//MH n lân
	for(int i=1 ; i<=2 ; i++){
		K[i] = K[0]<<i;
		L[i] = R[i-1];
		R[i] = L[i-1]^F(R[i-1],K[i]);
	}
	C[0]=L[2];
	C[1]=R[2];
	return C;
	
}

//ham GM
string hamGM(char C0,char C1,char k0){
		char L[3],R[3],K[3];
	string P="XX";
	L[2]=C0;
	R[2]=C1;
	K[0]=k0;
	
	//GM n lân
	for(int i=2 ; i>=1 ; i--){
		K[i] = K[0]<<i;
		L[i-1] = R[i]^F(L[i],K[i]);
		R[i-1] = L[i];
	}
	P[0]=R[0];
	P[1]=L[0];
	return P;
	
}
int main(){
	string P,C;
	char k1,k2,k3;
	cout<<"Nhap chuoi plaintext: ";getline(cin,P);
	
	//Nhap khoa
		cout<<"Nhap khoa K1: ";cin>>k1;
		cout<<"Nhap khoa K2: ";cin>>k2;
		cout<<"Nhap khoa K3: ";cin>>k3;
		
	//Ma hoa 
	C=hamMH(P[0],P[1],k1);
	C=hamMH(C[0],C[1],k2);
	C=hamMH(C[0],C[1],k3);
	cout<<"CHUOI MA HOA LA: "<<C<<endl;
	
	//Giai ma
	C=hamGM(C[0],C[1],k3);
	C=hamGM(C[0],C[1],k2);
	P=hamGM(C[0],C[1],k1);
	cout<<"CHUOI GIAI MA LA: "<<P<<endl;
	return 0;
}
