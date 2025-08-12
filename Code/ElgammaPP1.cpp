#include<iostream>
#include<math.h>
using namespace std;

//Nhap mot so nguy�n p tu b�n ph�m. H�y hien ra m�n h�nh tat ca c�c gi� tri cua 
//a thuoc [1,p-1] v� c�c luy thua tuong ung cua a (gom a, a^2, a^3,�a^p-1) trong modul p. 

//Nhap mot so nguy�n p tu b�n ph�m. H�y hien ra m�n h�nh tat ca c�c phan tu nguy�n thuy cu1a p
//ham tinh luy thua theo mod 
int dmod(int a, int m, int p) {
    int kq = 1;
    for (int i = 0; i < m; i++) {
        kq = (kq * a) % p;
    }
    return kq;
}

int main(){
	int p;
	int count,S2,S=0;
	cout<<"Nhap so nguyen P: ";cin>>p;
	
		for(int a=1 ;a<p;a++){
		cout<<"a = "<<a<<": ";
	  for(int i =1;i<p;i++ ){
	  	cout<<dmod(a,i,p)<<" ";
	  }
	  cout<<endl;
	}
	
	if(p%2==1){
		S=((p-1)/2)*p;
	}
	else{
			S=((p-2)/2)*p+p/2;
	}
	
	cout<<"Cac phan tu nguyen thuy cua p = "<<p<<" la:  "<<endl; 
		for (int a = 1; a < p; a++) {
			S2=0;
			count=0;
			for(int i=1;i<p;i++){
				S2=S2+dmod(a,i,p);
				if(i>1 && dmod(a,i,p)==a){
				count++;
				}
			}
        
    } cout<<endl;
	
	return 0;
}
