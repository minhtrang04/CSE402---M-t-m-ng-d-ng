#include<iostream>
#include<math.h>

using namespace std;

int main(){
	//Lap trinh tinh so diem c� tr�n duong cong Ep(a,b), voi a, b, p nhap tu b�n ph�m.
	// Liet k� c�c diem cua duong cong d� ra m�n h�nh
	int a,b,p,x,y,y2,yy,d=0;
	cout<<"Nhap modul P: ";cin>>p;
	cout<<"Nhap so a: ";cin>>a;
	cout<<"Nhap so b: ";cin>>b;
	
	for(x=0;x<p;x++){  
	   y2=(x*x*x + a*x + b)%p;
	     for(y=0;y<p;y++){
	        yy=(y*y)%p;
			if(y2==yy){
				cout<<d<<":("<<x <<","<<y <<")"<<endl;
				d++;
			}	
		 }
	}
	 cout<<"Tong so diem tren duong cong = "<<d;
	
	return 0;
}
