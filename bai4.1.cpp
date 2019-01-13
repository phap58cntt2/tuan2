#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
void TaoFile(FILE *f);
void NgauNhien(FILE *f);
void XuatFileFi(FILE *f);
void XuatFileFa(FILE *f);
void XuatFileFb(FILE *f);
void Chia(FILE *fi, FILE *fa, FILE *fb, int m);
void Tron(FILE *fa, FILE *fb, FILE *fi, int m);
int	m, n=5;
int	main(){
	FILE *fi, *fa, *fb; 	
	//TaoFile(fi);
	NgauNhien(fi);
	printf("File nguon:"); 
	XuatFileFi(fi); 
	m = 1;
	while(m<n){
		Chia(fi, fa, fb, m);	
		printf("\nFile 1:"); 	
		XuatFileFa(fa);  
		printf("\nFile 2:");
		XuatFileFb(fb); 
		Tron(fa, fb, fi, m);
		printf("\nFile nguon sau khi tron:");
		XuatFileFi(fi); 	
		m = m*2;		
	}
	printf("\nFile dich:"); 
	XuatFileFi(fi);		
}
// tao file gom  n phan tu
void TaoFile(FILE *f){
	int	i, x;	
	f = fopen("input.txt","wt"); 				
	printf("So phan tu: "); 	
	scanf("%d", &n);	
	for (int i=0; i<n; i++){
		printf("Phan tu thu %d: ",i+1);	
		scanf("%d", &x);
		fprintf(f, "%3d", x);
	}
	fclose(f);
}
// tao file ngau nhien gom  n phan tu
void NgauNhien(FILE *f){
	int	i, x;
	srand(time(NULL));	
	f = fopen("input.txt","wt");					
	printf("Tao file ngau nhien - Nhap so phan tu: "); 	
	scanf("%d", &n);
	for (int i=0; i<n; i++){	
		x = rand()%99;
		fprintf(f, "%3d", x);
	}
	fclose(f);
}
void  XuatFileFi(FILE *f){
	int	 x;
	f= fopen("input.txt","rt");
	while (!feof(f)){
		fscanf(f, "%d", &x); 
		printf("%3d", x);
	}
	fclose(f);	
}
void  XuatFileFa(FILE *f){
	int	 x;
	f= fopen("input1.txt","rt");
	while (!feof(f)){
		fscanf(f, "%d", &x); 
		printf("%3d", x);
	}
	fclose(f);	
}
void  XuatFileFb(FILE *f){
	int	 x;
	f= fopen("input2.txt","rt");
	while (!feof(f)){
		fscanf(f, "%d", &x); 
		printf("%3d", x);
	}
	fclose(f);	
}
// chia xoay vong file fi cho fa va fb moi lan m phan tu cho den khi het file fi
void Chia(FILE *fi, FILE *fa, FILE *fb, int m){
	int	dem, x;
	fi = fopen("input.txt","rt"); 	
	fa = fopen("input1.txt","wt"); 	
	fb = fopen("input2.txt","wt"); 
	while (!feof(fi))
	{
		//--------chia m phan tu cho fa
		dem	= 0;
		while ((dem<m)and (!feof(fi))){
			fscanf(fi,"%3d", &x);
			fprintf(fa,"%3d", x);
			dem++;			
		}
		//--------chia m phan tu cho fb
		dem	= 0;
		while ((dem<m)and (!feof(fi))){
			fscanf(fi,"%3d", &x);
			fprintf(fb,"%3d", x);
			dem++;			
		}
	}	
	fclose(fi);	 
	fclose(fa);
	fclose(fb);	
}

//===========tron m phan tu tren fa voi m phan tu tren fb thanh 2p phan tu tren fi den khi fa hay fb ket thuc
void Tron(FILE *fa, FILE *fb, FILE *fi, int m){
	int	kt, x, y, a, b;	
	fi = fopen("input.txt","wt"); 	
	fa = fopen("input1.txt","rt"); 	
	fb = fopen("input2.txt","rt"); 
	while ((!feof(fa))&& (!feof(fb))){
		a = 0;	//so phan tu cua fa da ghi len fi
		b = 0;	//so phan tu cua fb da ghi len fi	
		fscanf(fa, "%3d", &x);
		fscanf(fb, "%3d", &y);
		kt = 0;
		while ((a!=m)&& (b!=m)&& (!kt))
		{
			if (x<y){
				fprintf(fi,"%3d", x);//ghi x ra file fi
				a++;
				if ((a<m)&& (!feof(fa)))			//chua du m phan tu va chua het file fa
					fscanf(fa, "%3d", &x);		//doc tiep 1 phan tu tu fa vao bien x, de lan sau lap sau ghi vao fi		
				else 						//da xong fa(du m phan tu hoac ket thuc), ==> ghi fb vao fi
				{
					fprintf(fi,"%3d", y);			//ghi y ra file	fi
					b++;
					if (feof(fa))			//neu fa da ket thuc thi dung viec phan phoi
						kt =1;
				}
			}		
			else{	
				fprintf(fi,"%3d", y);			//ghi y ra file	fi
				b++;
				if ((b<m)&& (!feof(fb)))			//chua du m phan tu va chua het file fa
					fscanf(fb, "%3d", &y);		//doc tiep 1 phan tu tu fa vao bien x, de lan sau lap sau ghi vao fi
				else 						//da xong fb (du m phan tu hoac ket thuc), ==> ghi  fa vao fi
				{
					fprintf(fi,"%3d", x);			//ghi x ra file	fi
					a++;
					if (feof(fb))			//neu fa da ket thuc thi dung viec phan phoi
						kt =1;
				}							
			}	
		}
		//ghi tiep phan con lai cua m phan tu tren fa vao fi
		while ((a<m)&& (!feof(fa)))	{
			fscanf(fa, "%3d", &x);
			fprintf(fi,"%3d", x);	
			a++;
		}	
		//ghi tiep phan con lai cua m phan tu tren fb vao fi
		while ((b<m)&& (!feof(fb)))	{
			fscanf(fb, "%3d", &y);
			fprintf(fi,"%3d", y);	
			b++;
		}				
	}	
	if(!feof(fa))// fa con phan tu
	{
		//chep phan con lai cua fa len fi
		while (!feof(fa)){	
			fscanf(fa, "%3d", &x);
			fprintf(fi,"%3d", x);	
		}
	}	
	if(!feof(fb))// fb con phan tu
	{
		//chep phan con lai cua fb len fi
		while (!feof(fb))		{	
			fscanf(fb, "%3d", &y);
			fprintf(fi,"%3d", y);	
		}
	}	
	fclose(fi);
	fclose(fa);
	fclose(fb);	
}





