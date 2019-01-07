#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
struct nut{
	char nd[50];
	nut *sau,*truoc;
	
};
nut *dau,*dsc;
void khoitao(nut *&dau){
	dau = NULL;
}
void nhap(nut *&dau){
	nut *p,*q;
	int i = 1;
	char ndc[80];
	do{
		cout<<"Nhap dong "<<i<<" : ";
		fflush(stdin);
		gets(ndc);
			if(strcmp(ndc,"\0" )){
					//Tao nut moi
				p = new nut;
				strcpy(p->nd,ndc);
				p->sau = NULL;
				p->truoc = NULL;
				//Moc vao van ban
				if(dau == NULL)
					dau = p;
				else {
					q->sau = p;
					p->truoc = q;
				}
					q = p;
					i++;
				
			}
	}
	while(strcmp(ndc,"\0")!=0);
}

void duyet(nut *dau){
	if(dau != NULL){
		cout<<endl<<dau->nd;
		duyet(dau->sau);
	}
	cout<<endl;
}

void xoadong(nut *&dau,int i){
	nut *p,*t,*s;
	int k = 1;
	p = dau;
	while((p != NULL) && (k != i)){
		p = p->sau;
		k++;
	}
	if(p != NULL){
		//1. p == dau -> xoa nut dau;
		if(p == dau){
			dau = dau->sau;
			dau->truoc = NULL;
		}
			
		//2. p la nut cuoi
		if(p->sau == NULL){
			t = p->truoc;
			t->sau = NULL;
		}
		//3.p la nut giua
		if(p != dau && p->sau != NULL){	
			t = p->truoc;
			s = p->sau;
			t->sau = s;
			s->truoc = t;	
		}
		delete p;
	}
}
//
void chenik(nut *&dau,int i,int k){
	nut *p,*q,*t;
    int j;
    // Tim nut thu i
    	p=dau;
		j=1;
    	while (j<i && p!=NULL){ 
			p=p->sau;
        	j=j+1;
        }
    	if (p==NULL)
			printf("\n Khong chen duoc !");
		else{ 
		// Tim nut thu k
			q=dau;j=1;
        	while (j<k && q!=NULL){
				q=q->sau;
        		j=j+1;
        	}
	    	if (q==NULL)
				printf("\n Khong chen duoc !");		
			else{
				t= new nut;
		    	strcpy(t->nd,p->nd);
		    	t->sau=q->sau;
		    	q->sau=t;
		    	t->sau->truoc=t;
		    	t->truoc=q;
			}
		}    		 
       
}
void xoadongij(nut *&dau,int i ,int j){
	int k;
	for(k = i; k <= j; k++)
		xoadong(dau,i);
}
 void taods(nut *dau,nut *&dsc,int i, int j)
 { int k;
   nut *p,*q,*t;
     // Tim nut i
     p=dau;k=1;
        while (k<i && p!=NULL)
         { p=p->sau;
           k=k+1; }
    if (p!=NULL)
	  {  dsc=NULL;
	     for(k=i;k<=j;k++)
	       { if (p==NULL) break;
	          else
	          {  t=new nut;
	             strcpy(t->nd,p->nd);
	             t->sau=NULL;
	             t->truoc=NULL;
	             if (dsc==NULL)
	               dsc=t;
	             else
				   q->sau=t;
				   t->truoc=q;
				   q=t;
				   p=p->sau;  
			  }
		   }
					  }       		 
 }
 void Chendong(nut *&dau,int i, int j, int k)
 {      nut *pk,*cdsc,*sk;
        int v;
        taods(dau,dsc,i,j);
        // cdsc tro den nut cuoi dsc
        cdsc=dsc;
          while (cdsc->sau!=NULL)
            cdsc=cdsc->sau;
       // Tim nut k
       pk=dau;v=1;
        while (v<k && pk!=NULL)
         { pk=pk->sau;
           v=v+1;
           		 }
       // moc dsc vao sau dong k
	      sk=pk->sau;
		  pk->sau=dsc;
		  dsc->truoc=pk;
		  cdsc->sau=sk;
		  sk->truoc=cdsc;    		 
 }
int main(){
	nut *dau;
	int n,i,j,k;
	khoitao(dau);
	nhap(dau);
	duyet(dau);
	cout<<"Chon dong can xoa:";
	cin>>n;
	cout<<"Xoa dong "<<n<<endl;
	xoadong(dau,n);
	duyet(dau);
	cout<<"Xoa dong 3 den dong 5"<<endl;
	xoadongij(dau,3,5);
	duyet(dau);
	cout<<"Chon dong can chen:";
	cin>>i;
	cout<<"Chon vi tri chen:";
	cin>>k;
	cout<<"Chen dong "<<i<<" sau dong "<<k<<" :"<<endl;
	chenik(dau,i,k);
	duyet(dau);
	cout<<"Chen tu 3 den 5 sau vi tri 2"<<endl;
	Chendong(dau,3,5,2);
    duyet(dau);
	
	
}
