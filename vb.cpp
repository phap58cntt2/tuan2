#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
struct nut {
	char nd[80];
	nut *sau,*truoc;
};
typedef nut Node;

Node *dau,*dsc;

void khoitao(Node *&dau)
{ dau= NULL;}

void nhapvb(Node *&dau)
{ Node *p,*q;
     char ndt[80];
     int i=1;
       do
       { printf("\n Nhap dong %d : ",i);
         fflush(stdin);
         gets(ndt);
            if (strcmp(ndt,"\0")!=0)
             { p=new Node;
               strcpy(p->nd,ndt);
               p->sau=NULL;
               p->truoc=NULL;
                 if (dau==NULL)
                      dau=p;
                 else
				    q->sau=p;
					p->truoc=q;
					q=p; 
					i=i+1; 
			 }
       	  
	   }
	   while (strcmp(ndt,"\0")!=0);
       
}
 //-------------------------------------------------
 void duyetvb(Node *dau)
 { Node *p;
     p=dau;
      while (p!=NULL)
        { printf ("\n %s",p->nd);
          p=p->sau;
		}
 }
 //-------------------------------------------------
 void Inij(Node *dau, int i, int j)
 { Node *p=dau;
     int k=1;
    // Tim dong i
	while (k<i && p!=NULL)
	{ p=p->sau;
	  k=k+1;
	 } 
   // Neu co dong i	 
	 if (p!=NULL)
	   { while (k<=j && p!=NULL)
	      { printf("\n %s",p->nd);
	        p=p->sau;
			k=k+1; 
		  }
	   }	                   
 }
 //-------------------------------------------------
 void Xoadong(Node *&dau, int i)
 { Node *p,*q,*t;
    int k;
   // Tim nut thu i
        p= dau;
        k=1;
     while (k<i && p!=NULL)
	   { p=p->sau;
	     k=k+1;
		  }   
    if (p!=NULL)
	  if (p==dau)
	  // nut bi xoa la nut dau
	  { dau=p->sau;
	    dau->truoc=NULL;
	    delete p;
				}
	  else
	    if (p->sau==NULL)
	   // nut bi xoa la nut cuoi 
	   {  t=p->truoc;
	      t->sau=NULL;
	      delete p;  }
		else
		//nut bi xoa la o giua
		{t=p->truoc;
		 q=p->sau;
		 t->sau=q;
		 q->truoc=t;
		 delete p; 
								}  					  
     }
 //-------------------------------------------------
 void Xoadongij(Node *&dau, int i,int j)
 { int k;
    for (k=i;k<=j;k++)
        Xoadong(dau,i);
 }
 //-------------------------------------------------
 void Chepdong(Node *&dau, int i,int k) 
 // Chep dong i vao sau dong k
 { Node *p,*q,*t;
    int j;
    // Tim nut thu i
       p=dau;j=1;
        while (j<i && p!=NULL)
         { p=p->sau;
           j=j+1;
           		 }
       if (p==NULL) printf("\n Khong chen duoc !");
	    else
		{ // Tim nut thu k
			q=dau;j=1;
        while (j<k && p!=NULL)
         { q=q->sau;
           j=j+1;
           		 }
       if (q==NULL) printf("\n Khong chen duoc !");		
	   else
	     // Tim duoc nut i, nut k
	      {
		  t= new Node;
	      strcpy(t->nd,p->nd);
	      t->sau=q->sau;
	      q->sau=t;
	      t->sau->truoc=t;
	      t->truoc=q;}
		  }    		 
       
 }
 //-------------------------------------------------
 void taods(Node *dau,Node *&dsc,int i, int j)
 { int k;
   Node *p,*q,*t;
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
	          {  t=new Node;
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
 //-------------------------------------------------
 void Chendong(Node *&dau,int i, int j, int k)
 {      Node *pk,*cdsc,*sk;
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
 //--------------------------------------------------
 int main()
 {    int d,h;
      khoitao(dau);
      nhapvb(dau);
      duyetvb(dau);
//      printf("\n Tu dong 3 den dong 5: \n");
//      Inij(dau,3,5);
      //printf("\n Nhap dong dau xoa: ");
      //scanf("%d",&d);
   
     /* Xoadong(dau,d);
      printf("\n Sau khi xoa dong \n"); */
      
     // Xoadongij(dau,3,5);
      //printf("\n Sau khi xoa tu dong 3 den dong 5 \n");
     // printf("\n Chep dong 5 vao sau dong 2 \n");
//    	Chepdong(dau,5,2);
	printf("\n Danh sach sau chen \n");
     taods(dau,dsc,4,6);
//     Inij(dau,4,6);
     duyetvb(dsc);
     cout<<endl<<"abc";
     Chendong(dau,4,6,7);
     duyetvb(dau);

 }
