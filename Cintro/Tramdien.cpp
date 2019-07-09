#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

typedef struct {
	int id;
	char name[30];
	int x,y;
	int r;
} station;

station list[50];

int count = 0;

void Import(int index){
	char name[30];
	int id, x, y, r;
	
	printf("**********************************************\n");
	printf("id = ");		scanf("%d", &id);
	
	fflush(stdin);
	printf("Nhap ho ten truong tram: "); 	gets(name);
	
	printf("x = ");		scanf("%d", &x);
	printf("y = ");		scanf("%d", &y);
	printf("r = ");		scanf("%d", &r);
	printf("\n");
	
	list[index].id = id;
	strcpy(list[index].name, name);
	list[index].x = x;
	list[index].y = y;
	list[index].r = r;
}

void InitList(){
	int n;
	do {
	printf("So luong phan tu muon nhap: ");
	scanf("%d", &n);
	} while (n > 50 || n < 0);
	for (int i = 0 ; i < n ; i++)
		Import(i);
	count = n;
}

void AddStation(){
	int n;
	do {
	printf("So luong phan tu muon nhap them: ");
	scanf("%d", &n);
	} while (n + count > 50 || n < 0);
	for (int i = 0; i < n ; i++)
		Import(i + count);
	count += n;
}

void ShowStation(int index){
	printf("%10d%40s%10d%10d%10d\n", list[index].id, list[index].name, list[index].x, list[index].y, list[index].r);
}

void ShowListStation(){
	printf("%10s%40s%10s%10s%10s\n", "ID", "Ho ten", "Toa do", "Ban kinh");
	for(int i = 0 ; i < count ; i++)
		ShowStation(i);
}

int menu(){
	int key;
	do{
		system("cls");
		printf("1. Nhap moi cham phat\n");
		printf("2. Bo xung tram phat\n");
		printf("3. Xem danh sach tram\n");
		printf("4. Tinh toan khoang cach\n");
		printf("5. Thoat chuong trinh\n");
		scanf("%d", &key);
	} while (key <= 0 || key > 5);
	return key;
}

int main(){
	int key;
	do{
		key = menu();
		system("cls");
		switch (key){
			case 1:
				InitList();
				break;
			case 2:
				AddStation();
				break;
			case 3:
				ShowListStation();
				break;
			case 4:
				break;
		}
		printf("please touch any keyboard to continuse....");
		getch();
	}while(key != 5);
}
