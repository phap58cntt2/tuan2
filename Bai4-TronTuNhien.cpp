#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
# define in	"input.txt"
# define out1 "input1.txt"
# define out2 "input2.txt"
void TaoFile();
void NgauNhien();
void XuatFile(FILE *f, char link[]);
void Chia(FILE *fi, FILE *fa, FILE *fb, int p);
void Tron(FILE *fa, FILE	*fb, FILE *fi, int p);
void Copy(FILE *a, FILE *b);
void CopyRun(FILE *a, FILE *b);
void ChiaTuNhien(FILE *fi, FILE *fa, FILE *fb);
void TronRun();
void TronTuNhien();
FILE *fi, *fa, *fb; 
int	 p, n, M, x, y, x1, x2;
int	Eor;
int	main(){
	int i=1;
	//TaoFile();
	NgauNhien();
	printf("-------------------------------\n");
	printf("File nguon:");
	XuatFile(fi, in); 
	printf("\n-------------------------------");	
	do{	
		printf("\n-------------------------------");
		printf("\nLan %d",i);
		//doc file fi va xuat ra file fa,fb
		fi = fopen("input.txt","rt"); 	
		fa = fopen("input1.txt","wt"); 	
		fb = fopen("input2.txt","wt");
		ChiaTuNhien(fi, fa, fb);
		//xuat ket qua sau moi lan chia ra man hinh
		printf("\nKet qua sau khi chia: ");
		printf("\nFile 1:"); 
		XuatFile(fa, out1);
		printf("\nFile 2:"); 
		XuatFile(fb, out2);
		// doc file fa,fb va ghi ra file fi
		fi = fopen("input.txt","wt"); 	
		fa = fopen("input1.txt","rt"); 	
		fb = fopen("input2.txt","rt"); 	
		M = 0; 
		TronTuNhien();
		//=xuat ket qua sau moi lan tron ra man hinh
		printf("\nFile nguon sau khi tron :"); 
		XuatFile(fi, in);
		i++;
	} while (M !=1);
	//Xuat ket qua chinh ra man hinh
	printf("\n-------------------------------");
	printf("\n-------------------------------");
	printf("\nFile dich:"); 
	XuatFile(fi, in);	
}
//doc 1 phan tu tu file a ghi vao file b
void Copy(FILE *a, FILE *b){	
	fscanf(a, "%3d", &x);
	fprintf(b, "%3d", x);
	if  (!feof(a)){		
		fscanf(a, "%d", &y);
		long	vt = ftell(a)-2;
		fseek(a, vt, SEEK_SET); //lui vi tri doc file
	}
	if (feof(a))
		Eor =1;  //Eor ==1 neu het run tren a hoac het a
	else 
		if(x>y) //gap 1 so y nho hon x thi het run
			Eor =1;	
		else
			Eor=0;		
}
//chep 1 run tu a vao b
void CopyRun(FILE *a, FILE *b){
	do
		Copy(a, b);
	while  (!Eor);
}
//tron 1 run cua fa va fb vao fi
void TronRun(){
	do{
		long int vt;
		fscanf(fa, "%d", &x1);
		vt = ftell(fa)-2;
		fseek(fa, vt, SEEK_SET);//lui vi tri doc file
		fscanf(fb, "%d", &x2);
		vt = ftell(fb)-2;
		fseek(fb, vt, SEEK_SET);//lui vi tri doc file
		if(x1<=x2){
			Copy(fa, fi);
			if (Eor) CopyRun(fb, fi);
		}
		else{
			Copy(fb,fi);
			if (Eor) CopyRun(fa,fi);
		}		
	}while(!Eor);
}
//tron cac run cua  fa, fb vao fi
void TronTuNhien(){
	while ((!feof(fa)) && (!feof(fb))){
		TronRun();
		M++;		
	}	
	while (!feof(fa)){
		CopyRun(fa,fi);	
		M++;	
	}
	while (!feof(fb)) {
		CopyRun(fb,fi);
		M++;	
	}
	fclose(fi);
	fclose(fa);
	fclose(fb);		
}
//phan bo luan phien cac Run tu nhien tu fi vao fa, fb
void ChiaTuNhien(FILE *fi, FILE *fa, FILE *fb){
	do{
		CopyRun(fi, fa);
		if (!feof(fi))
			CopyRun(fi, fb);
	}while (!feof(fi));
	fclose(fi);	
	fclose(fa);
	fclose(fb);	
}
//tao file fi gom  n phan tu
void	TaoFile(){
	int	i, x;
	FILE *fi;	
	fi = fopen("input.txt","wt");						
	printf("Cho biet so phan tu:"); 	
	scanf("%d", &n);
	for (int i=0; i<n; i++)
	{
		printf("Phan tu thu %d :",i+1);
		scanf("%d", &x); 
		fprintf(fi, "%3d", x); 
	}
	fclose(fi);
}
//tao file fi gom  n phan tu ngau nhien
void NgauNhien(){
	srand(time(NULL));
	int	i, x;
	FILE *fi;	
	fi = fopen("input.txt","wt"); 							
	printf("Tao file ngau nhien - Hay nhap so phan tu:"); 	
	scanf("%d", &n);
	for (int i=0; i<n; i++){	
		x = rand()%99+1;
		fprintf(fi, "%3d", x);
	}
	fclose(fi);
}	
//Xuat file ra man hinh
void XuatFile(FILE *fi, char link[]){	
	int	i,x;
	fi = fopen(link,"rt"); 	
	while  (!feof(fi)){
		fscanf(fi, "%d", &x);
		printf("%3d", x);
	}
	fclose(fi);	
}







