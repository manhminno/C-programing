//Code chay tren ubuntu
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
typedef struct quanly
{
	char ten[50];
	int id;
	int x,y;
	int r;

}station;


int nhapid();
void nhap();
void menu();
int them();
void xem();
int tinhd();
void sapxep();


int nhapid(int i,station quanly[50]){
	int j;
	int s=1;
	do{

		do{
			printf("nhap id\n");
			__fpurge(stdin);
			scanf("%d",&quanly[i].id);
		}while(quanly[i].id<=0);

		s=1;
		    for(j=0;j<i;j++){
			    if(quanly[i].id==quanly[j].id){
				    s=0;
				    break;
			    }


	        }
	}while(s==0);
}
// ________________________________
void nhap(int n,station quanly[50]){
	int i;
	for(i=0; i<=n-1; i++){
		printf("Tram thu %d\n",i+1);
		printf("Nhap id tram \n");
		nhapid(i,quanly);
		printf("Nhap ten truong tram\n");
		__fpurge(stdin);
		gets(quanly[i].ten);
		printf("Nhap toan do x,y cua tram\n" );
		__fpurge(stdin);
		scanf("%d%d",&quanly[i].x,&quanly[i].y);
		do{
			printf("Nhap ban kinh cua tram\n");
		    __fpurge(stdin);
		    scanf("%d",&quanly[i].r);
        }while(quanly[i].r<1||quanly[i].r>100);
	}
}
//_____________________________________________________
void menu(){
	printf("___________________________________________\n");
	printf("|1.Bo sung tram thu phat                  |\n");
	printf("|2.Xem danh sach tram phat                |\n" );
	printf("|3.Tinh khoang canh cua tram den trung tam|\n");
	printf("|4.Sap xep theo khoang cach               |\n");
	printf("|_________________________________________| \n");
}
//_____________________________________________________
int them(int *n, station quanly[50]){
	int n1,s;
	do{
		printf("Nhap vao so tram can bo sung\n");
		__fpurge(stdin);
		scanf("%d",&n1);
	}while((n1+*n)>50);
	s=*n;
	*n=*n+n1;
	for(int i=s; i<=*n-1; i++){
				printf("Tram thu %d\n",i+1);
				printf("Nhap id tram \n");
				nhapid(i,quanly);
				printf("Nhap ten truong tram\n");
				__fpurge(stdin);
				gets(quanly[i].ten);
				printf("Nhap toan do x,y cua tram\n" );
				__fpurge(stdin);
				scanf("%d%d",&quanly[i].x,&quanly[i].y);
				do{
					printf("Nhap ban kinh cua tram\n");
				    __fpurge(stdin);
				    scanf("%d",&quanly[i].r);
		        }while(quanly[i].r<1||quanly[i].r>100);

	}
	return *n;
}
//_______________________________________________
void xem(int n,station quanly[50]){
	int i;
	printf("%-10s%-20s%-10s%-10s\n","ID","Truong Tram","Toa Do","Ban kinh" );
	for (int i = 0; i < n; i++)
	{
		printf("%-10d%-20s(%3d,%-3d) %-10d\n",quanly[i].id,quanly[i].ten,quanly[i].x,quanly[i].y,quanly[i].r);
	}
}

int tinhd(int n,station quanly[50],double d[50]){


	for (int i = 0; i < n; i++)
		d[i]=sqrt(((quanly[i].x*quanly[i].x)+(quanly[i].y*quanly[i].y)));

	printf("%-10s%-20s%-10s%-10s%-15s\n","ID","Truong Tram","Toa Do","Ban kinh","khoang cach" );
	for (int i = 0; i < n; i++)

	    printf("%-10d%-20s(%3d,%-3d) %-10d%-15.2lf\n",quanly[i].id,quanly[i].ten,quanly[i].x,quanly[i].y,quanly[i].r,d[i]);
	return 0;

}
void sapxep(int n, double d[50], station quanly[50]){
	int i,j,doi;
	station doi1;
	for(i=0; i<n; i++){
		for(j=0 ; j<i; j++)
			if(d[j]<d[i]){
				doi=d[j];
				d[j]=d[i];
				d[i]=doi;
				doi1=quanly[j];
				quanly[j]=quanly[i];
				quanly[i]=doi1;
			}
	}

}
int main(int argc, char const *argv[])
{
	int n;
	double d[50];
	char yn;
	station quanly[50];
	int chon;
	do{
		printf("nhap so tram can quan ly\n");
		__fpurge(stdin);
		scanf("%d",&n);
	}while(n<=0||n>50);
	nhap(n,quanly);
	while(1){
		system("clear");

		menu();
		do{
			printf("Moi ban chon\n");
			__fpurge(stdin);
			scanf("%d",&chon);
		}while(chon<=0||chon>4);
		switch(chon){
			case 1: them(&n,quanly); break;
			case 2: xem(n,quanly); break;
			case 3: tinhd(n,quanly,d);break;
			case 4:sapxep(n,d,quanly); break;
		}
		printf("Bam mot phim bat ki de tiep tuc bam 'n' de ket thuc\n");
		__fpurge(stdin);
		scanf("%c",&yn);
		if(yn=='n'||yn=='N')
			break;


	}

	return 0;
}


