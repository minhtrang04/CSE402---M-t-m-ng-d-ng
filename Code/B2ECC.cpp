#include<iostream>
#include<math.h>
using namespace std;
int main(){
	//P(xP, yP) và  Q(xQ, yQ) là  2 diem khác nhau thuoc Ep(a,b). 
	//Lap trinh nhap toa do 2 diem roi tinh tong 2 diem do, voi p nhap tu ban phim
	while(true){
	
	int Xp,Yp,Xq,Yq,Xr,Yr,p;
	cout<<"Nhap Xp: ";cin>>Xp;
	cout<<"Nhap Yp: ";cin>>Yp;
	cout<<"Nhap Xq: ";cin>>Xq;
	cout<<"Nhap Yq: ";cin>>Yq;
	cout<<"Nhap p: ";cin>>p;
	if(Xp!=Xq){
		int TS=(Yq-Yp+p)%p;
		int MS=(Xq-Xp+p)%p,MS2;
		for(int i=0;i<p;i++){
			if(i*MS%p==1){
				MS2=i;break;
			}
		}
			int L=TS*MS2%p;
			Xr=(L*L%p-Xp+p-Xq+p)%p;
			Yr=(L*(Xp-Xr+p)%p-Yp+p)%p;
			cout<<"(Xr,Yr)=("<<Xr<<" , "<<Yr<<")";
	}
		
		else if(Yp==Yq){
			cout<<"Hai diem trung nhau ";
		}
		else{
				cout<<"Hai diem doi nhau ";
		}
}
	return 0;
}
