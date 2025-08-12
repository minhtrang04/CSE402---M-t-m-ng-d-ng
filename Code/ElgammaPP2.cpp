#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

//Nhap mot so nguy�n p tu b�n ph�m. H�y hien ra m�n h�nh tat ca c�c gi� tri cua 
//a thuoc [1,p-1] v� c�c luy thua tuong ung cua a (gom a, a^2, a^3,�a^p-1) trong modul p. 

//Nhap mot so nguy�n p tu b�n ph�m. H�y hien ra m�n h�nh tat ca c�c phan tu nguy�n thuy cua p

//ham tinh luy thua theo mod 
int dmod(int a, int m, int p) {
    int kq = 1;
    for (int i = 0; i < m; i++) {
        kq = (kq * a) % p;
    }
    return kq;
}
int main(){
	int p,count;
	cout<<"Nhap p: ";cin>>p;
		cout<<"Cac phan tu nguyen thuy cua p = "<<p<<" la:  "<<endl; 
		for(int a=1;a<p;a++)
		{
			count=0;
			vector<int> b(p,0); //Mang de danh dau cac phan tu da xuat hien
			for(int i=1;i<p;i++){
				int j=dmod(a,i,p);//tinh a^i % p
				if(b[j]==0){
					b[j]=1;//danh dau la phan tu da xuat hien
				}
				else{
					count++;//neu trung lap,tang dan va thoat vong lap
					break;
				}
			}
			if(count==0){
				cout << a << " ";
			}
		}
	
	return 0;
}
