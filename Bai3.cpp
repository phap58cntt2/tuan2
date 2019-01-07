#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<vector>
#include<string.h>
using namespace std;
struct AVL{
	int goc;
	int cb;
	AVL *trai,*phai;
};
AVL *Cay;
void TaoCay(AVL *&Cay){
	Cay=NULL;
	
}
void TaoNut(AVL *&Cay,int data){
	Cay = new AVL;	
	Cay->goc = data;
	Cay->phai = NULL;
	Cay->trai= NULL;
	Cay->cb = 0;
}
void XoayTrai(AVL *&Cay){
	AVL *Q;
	Q = Cay->phai;
	Cay->phai=Q->trai;
	Q->trai=Cay;
	Cay=Q;
}
void XoayPhai(AVL *&Cay){
	AVL *Q;
	Q=Cay->trai;
	Cay->trai=Q->phai;
	Q->phai=Cay;
	Cay=Q;
}
void XuLyTrai(AVL *&Cay){
	switch(Cay->trai->cb){
	case 1:
		XoayPhai(Cay);	
		Cay->cb = 0;
		Cay->phai->cb = 0;
		break;
	case 2:		
		XoayTrai(Cay->trai);
		XoayPhai(Cay);
		switch(Cay->cb){
		case 0:
			Cay->trai->cb = 0;
			Cay->phai->cb = 0;
			break;
		case 1:
			Cay->trai->cb = 0;
			Cay->phai->cb = 2;
			break;
		case 2:
			Cay->trai->cb = 1;
			Cay->phai->cb = 0;
			break;
		}
		Cay->cb = 0;
		break;
	}
}
void XuLyPhai(AVL *&Cay){
	switch(Cay->phai->cb){
	case 2:
		XoayTrai(Cay);	
		Cay->cb = 0;
		Cay->trai->cb = 0;
		break;
	case 1:		
		XoayPhai(Cay->phai);
		XoayPhai(Cay);
		switch(Cay->cb){
		case 0:
			Cay->trai->cb = 0;
			Cay->phai->cb = 0;
			break;
		case 1:
			Cay->trai->cb = 1;
			Cay->phai->cb = 0;
			break;
		case 2:
			Cay->trai->cb = 0;
			Cay->phai->cb = 2;
			break;
		}
		Cay->cb = 0;
		break;
	}
}

void MocNut(AVL *&Cay, int data){
	if(Cay==NULL){
		TaoNut(Cay,data);
	}
	else {
		if(Cay->goc==data)
			cout<<"So nay da ton tai trong cay!"<<endl;
		else if(Cay->goc > data){
			MocNut(Cay->trai,data);
			switch(Cay->cb){
				case 0:
				Cay->cb = 1;
				case 1:
				XuLyTrai(Cay);
				case 2:
				Cay->cb = 0;
			}	
		}
		else{
			MocNut(Cay->phai,data);
			switch(Cay->cb){
				case 0:
				Cay->cb=2;
				case 1:
				Cay->cb = 0;
				case 2:
				XuLyPhai(Cay);
			}
}
}
}
void ThemNut(AVL *&Cay){
	int gt;
	int i=1;
	cout<<"Nhap gia tri. 0:Dung"<<endl;
	do{
		cout<<"Nhap gia tri "<<i<<":";
		i++;
		cin>>gt;
		if(gt!=0)
			MocNut(Cay,gt);	
	} while(gt!=0);
}
void DuyetCay(AVL *Cay){
	if(Cay!=NULL){
		DuyetCay(Cay->trai);
		cout<<Cay->goc<<" ";
		DuyetCay(Cay->phai);
	}
}
int main(){
	AVL *Cay;
	TaoCay(Cay);
	ThemNut(Cay);
	DuyetCay(Cay);
}
