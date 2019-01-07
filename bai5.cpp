#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
int n;
float p,q;
struct phanso{
	int tu;
	int mau;
};
vector <phanso> PS;
fstream fi("FRACTIONS.INP");
fstream fo("FRACTIONS.OUT");
void DocFile(){
	fi>>n;
	fi>>p;
	fi>>q;
}
void XuatFile(){
	for(int i=0;i<PS.size();i++){
		fo<<PS[i].tu<<"/"<<PS[i].mau<<endl;
	}
}
// tim UCLN giua 2 so
int UCLN(int a,int b){
	if (a == 0 || b == 0){
        return a + b;
    }
    while (a != b)
        if (a > b)
            a -= b;
        else
            b -= a;
    return a;
}
// tim phan so
void TimPS(){
	phanso ps;
	float a;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			a=1.0*i/j;
			if((1/p<a)&&(1/q>a)&&(UCLN(i,j)==1)) //neu phan so thoa man yeu cau va toi gian
			{
				ps.tu=i;
				ps.mau=j;
				PS.push_back(ps);
			}	
		}
}
// sap xep
void SapXep(){
	float a,b;
	for( int i=0; i < PS.size() ; i++ )    
        for( int j = i+1 ; j < PS.size() ; j++ ) 
			{   
				a=1.0*PS[i].tu/PS[i].mau;
				b=1.0*PS[j].tu/PS[j].mau;
	            if( a>b )
	                swap(PS[i],PS[j]);// doi cho 2 phan so
            }
}
int main(){
	DocFile();
	int i;
	cout<<"Cac so trong file cua ban:"<<endl;
	cout<<"n= "<<n<<"	p= "<<p<<"	q= "<<q<<endl;
//	cout<<"-------------------------------"<<endl;
//	cout<<"Ban co muon nhap lai khong?"<<endl<<"1: Co"<<endl<<"0: Khong"<<endl;
//	cin>>i;
//	switch (i){
//		case 1:
//			cout<<"-------------------------------"<<endl;
//			cout<<"Nhap cac gia tri moi: "<<endl;
//			cout<<"n : ";
//			cin>>n;
//			cout<<"p : ";
//			cin>>p;
//			cout<<"q : ";
//			cin>>q;
//			break;
//		default:
//			break;
//	}
	do{
		cout<<"-------------------------------"<<endl;
		cout<<"Ban co muon nhap lai khong?"<<endl<<"1: Co"<<endl<<"0: Khong"<<endl;
		cin>>i;
		if(i==1){
			cout<<"Nhap cac gia tri moi: "<<endl;
			cout<<"n : ";
			cin>>n;
			cout<<"p : ";
			cin>>p;
			cout<<"q : ";
			cin>>q;
		}		
	} while(i!=0);
	cout<<"-------------------------------"<<endl;
	TimPS();
	SapXep();
	cout<<"Nhan 1 phim bat ky de tiep tuc:"<<endl;
	getch();
	cout<<"-------------------------------"<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<"Ket qua: "<<endl;
	for(int i=0;i<PS.size();i++){
		cout<<PS[i].tu<<"/"<<PS[i].mau<<endl;
	}
	XuatFile();
	
}
