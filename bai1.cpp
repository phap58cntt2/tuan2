#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<vector>
#include<string.h>
using namespace std;
vector <int> D;
int n;
/// mang co san
//int A[5][5]={0,1,0,1,0,
//			 0,0,1,1,1,
//			 0,0,0,0,1,
//			 0,0,0,0,0,
//			 0,0,0,0,0};
int A[10][10];
fstream fi;
// nhap mang bang tay
void Nhapmang(int A[10][10]){
	cout<<"Nhap so luong cong viec: ";
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cout<<"A["<<i<<"]["<<j<<"]= ";
			cin>>A[i][j];
		}		
}
// doc mang tu file DAT
int Nhapmangfile(){
	fi.open("input.dat",ios::in | ios::binary);
	char a[1];
	fi.read(a,1);
	n=atoi(a);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			fi.read(a,1);
			A[i][j]=atoi(a);
		}
}
// chon dinh khong co cung toi
int chondinh(int A[10][10]){
	int cot=0;
	while(cot<n){
		int kt=0;
		for(int i=0;i<n;i++)
			if(A[i][cot]!=0)
				kt=1;
		if(kt==0)
			return cot;
		else cot++;
	}
	return -1;
}
// xuat mang
void xuatmang(int A[10][10]) {
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<A[i][j]<<" ";
		cout<<endl;
	}		
}
// xoa cot
void xoacung(int A[10][10],int t){
	// xoa cung xuat phat tu t
	for(int i=0;i<n;i++)
		A[t][i]=0;
	// dieu kien de khong chon lai dinh t
	for(int i=0;i<n;i++)
		A[i][t]=1;
}
int main(){
	//Nhapmang(A);
	Nhapmangfile();
	xuatmang(A);
	while(chondinh(A)!=-1)
	{
		cout<<"Chon dinh: "<<chondinh(A)<<endl;
		D.push_back(chondinh(A));
		xuatmang(A);
		xoacung(A,chondinh(A));		
	}
	if(D.size()==n){
		for(int i=0;i<n-1;i++)
			cout<<D[i]<<"->";
		cout<<D[n-1];
	}	
	else 
		cout<<"Khong sap xep Topo";
}
