#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef struct _student{
    char name[MAX];
    int id;
    int point;
    char email[MAX];
    struct _student *pNext;
} student;

typedef struct _list{
    student *sHead;
    student *sTail;
} list;

void initList(list *clas){
    clas->sHead = clas->sTail = NULL;
}

void Menu()
{
    printf("=====================================\n");
    printf("__________Viet Nhat C - K62__________\n");
	printf("_________________Menu________________\n");
	printf("|[1].In thong tin lop sinh vien.    |\n");
	printf("|[2].Them sinh vien vao lop.        |\n" );
	printf("|[3].Sap xep sinh vien theo ten.    |\n");	
	printf("|[4].Sap xep sinh vien theo diem.   |\n");
    printf("|[5].Tim kiem sinh vien theo diem   |\n");
    printf("|[6].Xoa sinh vien theo diem.       |\n");
    printf("|[7].Thoat chuong trinh.            |\n");
	printf("=====================================\n");
    printf("*************************************\n");
}

student *getStudent(student temp){
    student *hocsinh = (student *)malloc(sizeof(student));
    strcpy(hocsinh->name, temp.name);
    hocsinh->id = temp.id;
    hocsinh->point = temp.point;
    strcpy(hocsinh->email, temp.email);
    hocsinh->pNext = NULL;
    return hocsinh;
}

void addTail(list *clas, student *hocsinh){
    if(clas->sHead == NULL){
        clas->sHead = clas->sTail = hocsinh;
        return;
    }else{
        clas->sTail->pNext = hocsinh;
        clas->sTail = hocsinh;
        return;
    }
}

void readFile(list *clas){
    student temp;
    char tmp[256];
    FILE *fin = fopen("StudentTest.txt", "r");
    while(!feof(fin)){
        fscanf(fin, "%d", &temp.id);
        fscanf(fin, "%d", &temp.point);
        fgets(tmp, 256, fin);
        fgets(tmp, 256, fin);
        sscanf(tmp, "%s %s", &temp.name, &temp.email);
        addTail(clas, getStudent(temp));
    }
}

void outputStudent(list clas){
    printf("MSSV\t\t\tHo Ten\t\t\tDiem\t\tEmail\n");
    for(student *p = clas.sHead; p; p = p->pNext){
        printf("%-23d %-24s %-14d %s\n", p->id, p->name, p->point, p->email);
    }
}

void sortStudent(list *clas){
    list stu1, stu2;
    if(clas->sHead == clas->sTail) return;
    initList(&stu1);  initList(&stu2);
    student *p;
    student *tag;
    tag = clas->sHead;
    clas->sHead = clas->sHead->pNext;
    tag->pNext = NULL;
    while(clas->sHead != NULL){
        p = clas->sHead;
        clas->sHead = clas->sHead->pNext;
        p->pNext = NULL;
        if(p->point >= tag->point) {
            addTail(&stu1, p);
        }
        else addTail(&stu2, p);
    }
    sortStudent(&stu1);
    sortStudent(&stu2);
    if(stu1.sHead != NULL){
        clas->sHead = stu1.sHead;
        stu1.sTail->pNext = tag;
    }
    else{
        clas->sHead = tag;
    }
    tag->pNext = stu2.sHead;
    if(stu2.sHead != NULL){
        clas->sTail = stu2.sTail;
    }
    else{
        clas->sTail = tag;
    }
}

void insertStudent(list *clas){
    int sizeadd;
    student temp;
    printf("Nhap so luong sinh vien can them: ");
    scanf("%d", &sizeadd);
    for(int i = 0; i < sizeadd; i++){
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        printf("Nhap MSSV: ");
        fflush(stdin);
        scanf("%d", &temp.id);
        printf("Nhap ten sinh vien: ");
        fflush(stdin);
        gets(temp.name);
        printf("Nhap diem: ");
        fflush(stdin);
        scanf("%d", &temp.point);
        printf("Nhap email: ");
        fflush(stdin);
        gets(temp.email);
        addTail(clas, getStudent(temp));
        printf("\n");
    }
}

void findStudent(list *clas){
    int check;
    student temp;
    list findclas;
    initList(&findclas);
    printf("Nhap diem can tim: ");
    scanf("%d", &check);
    for(student *p = clas->sHead; p; p = p->pNext){
        if(p->point == check){
            strcpy(temp.name, p->name);
            temp.id = p->id;
            temp.point = p->point;
            strcpy(temp.email, p->email);
            addTail(&findclas, getStudent(temp));
        }           
    }
    if(findclas.sHead == NULL) printf("Khong tim thay sinh vien co diem %d !", check);
    else{
        printf("Danh sach sinh vien dat diem %d:\n", check);
        outputStudent(findclas);
    }
}

void delStudent(list *clas){
    int check;
    student *j;
    printf("Nhap diem sinh vien muon xoa: ");
    scanf("%d", &check);
    cont:
    j = clas->sHead;
    while(j->pNext){
        if(clas->sHead->point == check){
            student *p = clas->sHead;
            clas->sHead = clas->sHead->pNext;
            p->pNext = NULL;
            free(p);
            goto cont;
        }
        if(j->pNext->point == check){
            student *p = j->pNext;
            j->pNext = j->pNext->pNext;
            free(p);
            goto cont;
        }
        j = j->pNext;
    }
}

void sortName(list *clas){
    list stu1, stu2;
    if(clas->sHead == clas->sTail) return;
    initList(&stu1);  initList(&stu2);
    student *p;
    student *tag;
    tag = clas->sHead;
    clas->sHead = clas->sHead->pNext;
    tag->pNext = NULL;
    while(clas->sHead != NULL){
        p = clas->sHead;
        clas->sHead = clas->sHead->pNext;
        p->pNext = NULL;
        if(strcmp(p->name, tag->name) < 0) {
            addTail(&stu1, p);
        }
        else addTail(&stu2, p);
    }
    sortStudent(&stu1);
    sortStudent(&stu2);
    if(stu1.sHead != NULL){
        clas->sHead = stu1.sHead;
        stu1.sTail->pNext = tag;
    }
    else{
        clas->sHead = tag;
    }
    tag->pNext = stu2.sHead;
    if(stu2.sHead != NULL){
        clas->sTail = stu2.sTail;
    }
    else{
        clas->sTail = tag;
    }
}

int main(){
    int chucnang;
    list clas;
    initList(&clas);
    readFile(&clas);
    do{
	    system("cls");
	    Menu();
        do{
            printf("Nhap chuc nang ban muon: ");
	        scanf("%d", &chucnang);
        }while(chucnang < 0 || chucnang > 8);
	    switch(chucnang)
	    {
		    case 1:
                outputStudent(clas);
		        break;
		    case 2:
                insertStudent(&clas);
		        break;
		    case 3:
                sortName(&clas);
                printf("Sau khi sap xep: \n");
                outputStudent(clas);
		        break;
		    case 4:
                sortStudent(&clas);
                printf("Sau khi sap xep: \n");
                outputStudent(clas);
		        break;
            case 5:
                findStudent(&clas);
                break;
            case 6:
                delStudent(&clas);
                break;
            case 7:
                return 0;
        }
        system("pause");
    }while(1);
}