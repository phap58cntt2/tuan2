#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<vector>
#include<string.h>
using namespace std;
struct nut{
	char nd[80];
	nut *sau, *truoc;
};
nut *dau;
void nhapvb(nut *dau){
	nut *p,*q;
	int i=1;
	char ndvb[80];
	do{
		cout<<"Nhap dong "<<i+1<<" :"<<endl;
		fflush(stdin);
		gets(ndvb);
		if(strcmp(ndvb,"\0")!=0)
		//tao nut moi
		{
			p=new nut;
			strcpy(p->nd,ndvb);
			p->sau=NULL;
			p->truoc=NULL;
			if(dau==NULL)
				dau=p;
			else{
				q->sau=p;
				p->truoc=q;
			}
			q=p;
			i++;
		}
			
	} while(strcmp(ndvb,"\0")!=0);		
}
void khoitao(nut *dau)
{
    dau->truoc = dau->sau = NULL;
}

int main(){
	
	nhapvb(dau);
}
