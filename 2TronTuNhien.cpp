#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctime>


# define	inp		"F:\\bang.int"
# define	out1	"F:\\bang1.int"
# define	out2	"F:\\bang2.int"


void 	TaoFile(void);
void	TaoFileNgauNhien(void);
void 	XuatFile(FILE  *f, char	duongdan[]);
void	Chia(FILE	*a, FILE	*b, FILE	*c, int		p);
void	Tron(FILE	*b, FILE	*c, FILE	*a, int		p);

//========================================doc 1 phan tu tu file a ghi vao file b
void	Copy(FILE	*a, FILE	*b);
//============chep 1 run tu a vao b
void	CopyRun(FILE	*a, FILE	*b);

void	ChiaTuNhien(FILE	*a, FILE	*b, FILE	*c);
//phan bo luan phien cac Run tu nhien tu a vao b, c

//======tron 1 run cua c va c vao a
void	TronRun();

//==========tron b, c vao a
void	TronTuNhien();


FILE	*a, *b, *c; 
int		p, n, M, x, y, x1, x2;
int	Eor;

//============
int		main()
{
	srand(time(NULL));  
	//	TaoFile();
	TaoFileNgauNhien();
	
	printf("File nguon:");
//	XuatFile();  
	XuatFile(a, inp); 
	
	do	
	{	
		a = fopen("f:\\bang.int","rt"); 	
		b = fopen("f:\\bang1.int","wt"); 	
		c = fopen("f:\\bang2.int","wt"); 
			

		ChiaTuNhien(a, b, c);
		
		//==xuat ket qua sau khi chia
		printf("\n File 1:"); 
		XuatFile(b, out1);
		printf("\n File 2:"); 
		XuatFile(b, out2);
		
		
		
		
		a = fopen("f:\\bang.int","wt"); 	
		b = fopen("f:\\bang1.int","rt"); 	
		c = fopen("f:\\bang2.int","rt"); 
		
		M = 0; 
		TronTuNhien();
		
		
		//=======xuat ket qua sau khi tron
		printf("\n Kq tron :"); 
		XuatFile(a, inp);

	} while (M !=1);
	
	
	printf("\n File dich:"); 
	XuatFile(a, inp);

	getch();	
}

//========================================doc 1 phan tu tu file a ghi vao file b
void	Copy(FILE	*a, FILE	*b)
{
	//	a = fopen("f:\\bang.int","rt"); 	
//		b = fopen("f:\\bang1.int","wt"); 	

	
	fscanf(a, "%3d", &x);
	fprintf(b, "%3d", x);

	if  (!feof(a)) 
	{
			
		fscanf(a, "%d", &y);		//doc tu fle vao bien 
		long	curpos = ftell(a)-2;
		fseek(a, curpos, SEEK_SET);
	}
	
	if (feof(a)) Eor =1;  //Eor ==1 neu het run tren a hoac het a
	else  Eor = (x>y)?1:0;			//gap 1 so y nho hon x thi het run
}



//============chep 1 run tu a vao b
void	CopyRun(FILE	*a, FILE	*b)
{
	do
		Copy(a, b);
	while  (!Eor);
}


//======tron 1 run cua c va c vao a
void	TronRun()
{
	do
	{
		fscanf(b, "%d", &x1);		//doc tu fle vao bien 
		int 	curpos = ftell(b)-2;
		fseek(b, curpos, SEEK_SET);
		
		fscanf(c, "%d", &x2);		//doc tu fle vao bien 
		 	curpos = ftell(c)-2;
		fseek(c, curpos, SEEK_SET);
		
		
		if(x1<=x2)
		{
			Copy(b, a);
			if (Eor) CopyRun(c, a);
		}
		else
		{
			Copy(c,a);
			if (Eor) CopyRun(b,a);
		}
			
			
		
	}while(!Eor);
}

//==========tron cac run cua  b, c vao a
void	TronTuNhien()
{
	while ((!feof(b)) && (!feof(c)))
	{
		TronRun();
		M++;
			
	}
	
	while (!feof(b)) 
	{
		CopyRun(b,a);
		
		M++;
		
	}
	
	while (!feof(c)) 
	{
		CopyRun(c,a);
		
		M++;
		
	}
		fclose(a);	 fclose(b);		fclose(c);	
	
	
	
}




//========================================================
void	ChiaTuNhien(FILE	*a, FILE	*b, FILE	*c)
{
		do
		{
			CopyRun(a, b);
			if (!feof(a))  CopyRun(a, c);
		
		}while (!feof(a));
		
		fclose(a);	 fclose(b);		fclose(c);	
}








//----tao file fp gom  n phan tu
void	TaoFile(void)
{
	
	int	i, x;
	FILE	*fp;
	
//	fp = fopen("F:\\TTCSK58\BoDe3\bang.data","wt"); 	
	fp = fopen("F:\\bang.int","wt"); 	
				
		
	if(fp==NULL)
	{
		printf("\nKhong tao duoc file.");
		getch();
		exit(0);
	}
					
					
	printf("Cho biet so phan tu:"); 	
	scanf("%d", &n);
	
	for (int i=0; i<n; i++)
	{
		
		scanf("%d", &x);       //nhap x tu ban phim
		fprintf(fp, "%3d", x); 	//ghi x vao file 
	}
	fclose(fp);
}


//===================================tao file fp gom  n phan tu
void	TaoFileNgauNhien(void)
{
	//randomize();
	int	i, x;
	FILE	*fp;
	
//	fp = fopen("F:\\TTCSK58\BoDe3\bang.data","wt"); 	
	fp = fopen("F:\\bang.int","wt"); 	
				
		
	if(fp==NULL)
	{
		printf("\nKhong tao duoc file.");
		getch();
		exit(0);
	}
					
					
	printf("Tao file ngau nhien - Hay nhap so phan tu:"); 	
	scanf("%d", &n);
	
	for (int i=0; i<n; i++)
	{
		
		x = rand()%51;
		fprintf(fp, "%3d", x); 	//ghi x vao file 
	}
	fclose(fp);
}


	
//==========Xuat file ra man hinh
void 	XuatFile(FILE  *fp, char	duongdan[])
{
	
	int		i,x;
	fp = fopen(duongdan,"rt"); 
	
//	fp = fopen("F:\\TTCSK58\BoDe3\bang.data","rt"); 	
		

	if(fp==NULL)
	{
		printf("\nKhong doc duoc file.");
		getch();
		exit(0);
	}
	

	i=0;
	
//	while	(i<n)

	n =0;
	while  (!feof(fp)) 
	{
		fscanf(fp, "%d", &x);		//doc tu fle vao bien 
		printf("%3d", x);			//xuat ra man hinh
		//i++;
		n++;
	}
	
	fclose(fp);	
}







