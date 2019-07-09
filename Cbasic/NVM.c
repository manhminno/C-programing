#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30

int countx = 0;
int checkx = 0;

void Menu()
{
    printf("=====================================\n");
    printf("______Bach Khoa Champion League______\n");
	printf("_________________Menu________________\n");
	printf("|[1].In thong tin cac doi bong.     |\n");
	printf("|[2].In thong tin lich dau.         |\n" );
	printf("|[3].Cap nhat ket qua vong dau.     |\n");	
	printf("|[4].Thong ke.                      |\n");
    printf("|[5].Thoat chuong trinh.            |\n");
	printf("=====================================\n");
    printf("*************************************\n");
}

typedef struct _doibong{
    int id;
    char name[MAX];
    int diem, sobanthang, sobanthua;
    struct _doibong *next;
} doibong;

typedef struct _list{
    doibong *head;
    doibong *tail;
} list;

typedef struct _vongdau{
    doibong *doi1;
    doibong *doi2;
    struct _vongdau *rNext;
} vongdau;

typedef struct _round{
    vongdau *rHead;
    vongdau *rTail;
} round;

void initList(list *quanli){
    quanli->head = quanli->tail = NULL;
}

void initRound(round *gd){
    gd->rHead = gd->rTail = NULL;
}

doibong *makeNode(doibong temp){
    doibong *p = (doibong *)malloc(sizeof(doibong));
    p->diem = p->sobanthang = p->sobanthua = 0;
    p->next = NULL;
    p->id = temp.id;
    strcpy(p->name, temp.name);
    return p;
}

void addHead(list *quanli, doibong *p){
    if(quanli->head == NULL) quanli->head = quanli->tail = p;
    else{
        p->next = quanli->head;
        quanli->head = p;
    }
    return;
}

vongdau *makeVongDau(doibong *doi1, doibong *doi2){
    vongdau *p = (vongdau *)malloc(sizeof(vongdau));
    p->doi1 = doi1;
    p->doi2 = doi2;
    p->rNext = NULL;
    return p;
}

void addGd(round *gd, vongdau *p){
    if(gd->rHead == NULL){
        gd->rHead = gd->rTail = p;
        return;
    }
    else{
        gd->rTail->rNext = p;
        gd->rTail = p;
        return;
    }
}

doibong *findTeam(list quanli, int id){
    for(doibong *temp = quanli.head; temp; temp = temp->next){
        if(temp->id == id) return temp;
    }
}

int readFile(list *quanli, round *gd){
    FILE *fin = fopen("bongda.txt", "r");
    int size, id1, id2;
    char c;
    char tmp[MAX];
    doibong temp;
    doibong *doi1;
    doibong *doi2;
    fscanf(fin, "%d", &size);
    int count = size - 1;
    for(int i = 0; i < size; i++){
        fscanf(fin, "%d", &temp.id);
        fgets(tmp, 256, fin);
        tmp[strlen(tmp) - 1] = '\0';
        strcpy(temp.name, tmp + 3);
        addHead(quanli, makeNode(temp));
    }
    while(count != 0){
        fgets(tmp, 256, fin);
        for(int i = 0; i < size/2; i++){
            fgets(tmp, 256, fin);
            sscanf(tmp, "%d %d", &id1, &id2);
            doi1 = findTeam(*quanli, id1);
            doi2 = findTeam(*quanli, id2);
            addGd(gd, makeVongDau(doi1, doi2));
        }
        count--;
    }
    fclose(fin);
    return size;
}


void outPut(list quanli){
    printf("Id\t\tTendoibong\t\tDiem\t\tSobanthang\t\tSobanthua\n");
    for(doibong *p = quanli.head; p; p = p->next){
        printf("%-15d %-25s %-17d %-22d %d\n", p->id, p->name, p->diem, p->sobanthang, p->sobanthua);
    }
}

void printGd(round gd, int size){
    int count = 2;
    int check = 0;
    for(vongdau *p = gd.rHead; p; p = p->rNext){
        if(count == 0 || count == size/2){
            printf("Vong %d:\n", ++check);
            count = 2;
        }
        printf("%s - %s\n", p->doi1->name, p->doi2->name);
        count--;
    }
}

void editMatch(round *gd, int size){
    int a, b;
    printf("Cap nhat ket qua vong %d:\n", ++checkx);
    printf("Vong %d:\n", checkx);
    for(vongdau *p = gd->rHead; p; p = p->rNext){
        if(countx == size/2){
           gd->rHead = p;
           countx = 0;
           break;
        }
        printf("%s - %s: ", p->doi1->name, p->doi2->name);
        fflush(stdin);
        scanf("%d - %d", &a, &b);
        p->doi1->sobanthang +=a;
        p->doi2->sobanthua += a;
        p->doi1->sobanthua += b;
        p->doi2->sobanthang +=b;
        if(a > b) p->doi1->diem += 3;
        if(a == b){
            p->doi1->diem += 1;
            p->doi2->diem += 1;
        }
        if(b > a) p->doi2->diem += 3;
        countx++;
   }
}

void delTeam(list *quanli){
    int min = 9999;
    for(doibong *p = quanli->head; p; p = p->next){
        if(p->diem < min) min = p->diem;
    }
    if(quanli->head->diem == min){
        doibong *q = quanli->head;
        quanli->head = quanli->head->next;
        printf("Doi co diem thap nhat la:\n");
        printf("Id\t\tTendoibong\t\tDiem\t\tSobanthang\t\tSobanthua\n");
        printf("%-15d %-25s %-17d %-22d %d\n", q->id, q->name, q->diem, q->sobanthang, q->sobanthua);
        free(q);
        printf("Cac doi con lai:\n");
        outPut(*quanli);
    }
    else{
        for(doibong *p = quanli->head; p; p = p->next){
            if(p->next->diem == min){
                doibong *q = p->next;
                p->next = p->next->next;
                printf("Doi co diem thap nhat la:\n");
                printf("Id\t\tTendoibong\t\tDiem\t\tSobanthang\t\tSobanthua\n");
                printf("%-15d %-25s %-17d %-22d %d\n", q->id, q->name, q->diem, q->sobanthang, q->sobanthua);
                free(q);
                printf("Cac doi con lai:\n");
                outPut(*quanli);
                break;
            }
        }
    }
}

int main(){
    list quanli;    initList(&quanli);
    round gd;   initRound(&gd);
    int nteam; //so doi
    int chucnang;
    nteam = readFile(&quanli, &gd);
    do{
	    system("cls");
	    Menu();
        do{
            printf("Nhap chuc nang ban muon:");
	        scanf("%d", &chucnang);
        }while(chucnang < 0 || chucnang > 6);
	    switch(chucnang)
	    {
		    case 1:
            outPut(quanli);
		    break;
		    case 2:
            printGd(gd, nteam);
		    break;
		    case 3:
            editMatch(&gd, nteam);
            printf("Sau khi cap nhat:\n");
            outPut(quanli);
		    break;
		    case 4:
            delTeam(&quanli);
		    break;
            case 5:
            return 0;
	    }
        system("pause");
    }while(1);
}
