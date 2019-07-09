//Ho va ten: Nguyen Viet Manh   MSSV: 20176816  Lop: Viet Nhat C - K62
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _monan{
    int stt;
    char name[255];
    int soluongton;
    double giatien;
    struct _monan *mnext;
} monan;

typedef struct _list2{
    monan *dau;
    monan *cuoi;
} list2;

typedef struct request{
    int ID;
    int order[7];
    long total;
    struct request *next;
} Request;

typedef struct _list{
    Request *head;
    Request *tail;
} list;

void initList(list *goimon){
    goimon->head = goimon->tail = NULL;
}

void initList2(list2 *mon){
    mon->dau = mon->cuoi = NULL;
}

monan *makeMon(monan temp){
    monan *p = (monan *)malloc(sizeof(monan));
    p->stt = temp.stt;
    strcpy(p->name, temp.name);
    p->soluongton = temp.soluongton;
    p->giatien = temp.giatien;
    p->mnext = NULL;
    return p;
}

void addMon(list2 *mon, monan *temp){
    if(mon->dau == NULL){
        mon->dau = mon->cuoi = temp;
        return;
    }else{
        mon->cuoi->mnext = temp;
        mon->cuoi = temp;
        return;
    }
}

Request *makeNode(Request temp){
    Request *p = (Request *)malloc(sizeof(Request));
    p->ID = temp.ID;
    for(int i = 0; i < 7; i++){
        p->order[i] = temp.order[i];
    }
    p->total = temp.total;
    p->next = NULL;
    return p;
}

void addHead(list *rq, Request *temp){
    if(rq->head == NULL){
        rq->head = rq->tail = temp;
        return;
    }else{
        temp->next = rq->head;
        rq->head = temp;
        return;
    }
}

void orderMon(list *rq){
    Request temp;
    printf("Nhap so luong cac mon muon order:\n");
    printf("Bun_bo_hue: ");
    scanf("%d", &temp.order[0]);
    printf("Com_suon_sot: ");
    scanf("%d", &temp.order[1]);
    printf("Com_ca_ran: ");
    scanf("%d", &temp.order[2]); 
    printf("My_xao: ");
    scanf("%d", &temp.order[3]);
    printf("Com_ca_kho_to: ");
    scanf("%d", &temp.order[4]); 
    printf("Pho_tai_lam: ");
    scanf("%d", &temp.order[5]);
    addHead(rq, makeNode(temp));
}

monan *findFood(list2 mon, int id){
    for(monan *q = mon.dau; q; q = q->mnext){
        if(q->stt == id) return q;
    }
}

void printOrder(list rq, list2 *mon){
    int count = 0;
    monan *q;
    for(Request *p = rq.head; p; p = p->next){
        printf("Don hang so %d\n", ++count);
        printf("Mon da chon\t\tSo luong\tThanh tien\n");
        for(int i = 0; i < 6; i++){
            if(p->order[i] > 0){
                q = findFood(*mon, i+1);
                int a = q->giatien;
                int b = p->order[i];
                a = a*b;
                printf("%-24s %-15d %d\n", q->name, p->order[i], a);
                q->soluongton -= p->order[i];
                
            }
        }
    }
}

void Menu()
{
    printf("=====================================\n");
    printf("__________Nha Hang Viet Nhat_________\n");
	printf("_________________Menu________________\n");
	printf("|[1].Danh sach mon hom nay.         |\n");
	printf("|[2].Nhan order.                    |\n" );
	printf("|[3].Thong tin tat ca order.        |\n");	
	printf("|[4].Mon ua chuong nhat.            |\n");
    printf("|[5].Thoat chuong trinh.            |\n");
	printf("=====================================\n");
    printf("*************************************\n");
}

int readFile(list2 *mon){
    FILE *fin = fopen("thucdontheongay.txt", "r");
    int size;
    monan temp;
    fscanf(fin, "%d", &size);
    for(int i = 0; i < size; i++){
        fscanf(fin, "%d", &temp.stt);
        fscanf(fin, "%s", &temp.name);
        fscanf(fin, "%d", &temp.soluongton);
        fscanf(fin, "%lf", &temp.giatien);
        addMon(mon, makeMon(temp));
    }
    return size;
}

void printMenu(list2 mon){
    printf("ID\tTen mon\t\tSo luong ton\tGia tien\n");
    for(monan *p = mon.dau; p; p = p->mnext){
        printf("%-7d %-20s %-11d %.0lf\n", p->stt, p->name, p->soluongton, p->giatien);
    }
}

int main(){
    list2 mon;  initList2(&mon);
    list rq;    initList(&rq);
    int nmon = readFile(&mon);
    int chucnang;
    do{
	    system("cls");
	    Menu();
        do{
            printf("Nhap chuc nang ban muon: ");
	        scanf("%d", &chucnang);
        }while(chucnang < 1 || chucnang > 5);
	    switch(chucnang)
	    {
		    case 1:
                printMenu(mon);
		        break;
		    case 2:
                orderMon(&rq);
		        break;
		    case 3:
                printOrder(rq, &mon);
		        break;
		    case 4:
		        break;
            case 5:
                return 0;
        }
        system("pause");
    }while(1);
}