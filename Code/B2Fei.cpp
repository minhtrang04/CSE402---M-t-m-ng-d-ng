#include <iostream>
#include <math.h>
using namespace std;

//Ham F
char F(char R,char ki){
	return R+ki;
}
//ham MH
string hamMH(char P0,char P1,char k){
	char L[3],R[3],K[3];
	string C="XX";
	L[0]=P1;
	R[0]=P0;
	K[0]=k;
	for(int i=1;i<=2;i++){
		K[i]=K[0]<<i;
		L[i]=R[i-1];
		R[i]=L[i-1]^F(R[i-1],K[i]);
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
	for(int i=2;i>=1;i--){
		K[i]=K[0]<<i;
		L[i-1]=R[i]^F(L[i],K[i]);
		R[i-1]=L[i];
	}
	P[0]=R[0];
	P[1]=L[0];
	return P;
}
//MH khôi
string MHK(char P0,char P1,char k1,char k2,char k3){
	string C="XX";
	C=hamMH(P0,P1,k1);
	C=hamMH(C[0],C[1],k2);
	C=hamMH(C[0],C[1],k3);
	return C;
}
//GM khoi
string GMK(char C0,char C1,char k1,char k2,char k3){
	string C="XX";
	string P="XX";
	C=hamGM(C0,C1,k3);
	C=hamGM(C[0],C[1],k2);
	P=hamGM(C[0],C[1],k1);
	return P;
}
int main(){
   string P,C="",D="";
   char k1,k2,k3;
   cout<<"Nhap plaintext: ";getline(cin,P);
   
   cout<<"Nhap khoa K1: ";cin>>k1;
   cout<<"Nhap khoa K2: ";cin>>k3;
   cout<<"Nhap khoa K3: ";cin>>k2;
   
   if(P.size()%2!=0){
   	P+='X';
   }
   
   //chuoi mh
   for(int i=0 ; i< P.size();i+=2){
   	string block = MHK(P[i],P[i+1],k1,k2,k3);
   	C+=block;
   }
   cout<<"Chuoi ma hoa la: "<<C<<endl;
   //chuoi gm
      for(int i=0 ; i< C.size();i+=2){
   	string block = GMK(C[i],C[i+1],k1,k2,k3);
   	D+=block;
   }
   cout<<"Chuoi giai ma la: "<<D<<endl;
	return 0;
}
