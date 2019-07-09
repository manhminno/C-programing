#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZENAME 50

typedef struct _Student{
    char Name[SIZENAME];
    int ID;
    float Score;
    struct _Student *next;
} Student;

typedef struct ListStudent{
    Student *first;
    Student *last;
} List;

void InitList(List *l){
    l->first = l->last = NULL;
}

Student *GetStudent(char *Name, int ID, float Score){
    Student *p = (Student *)malloc(sizeof(Student));
    strcpy(p->Name, Name);
    p->ID = ID;
    p->Score = Score;
    p->next = NULL;
    return p;
}

void AddStudent(List *l, Student *p){
    if(l->first == NULL){
        l->first = l->last = p;
        return;
    }
    else{
        l->last->next = p;
        l->last = p;
        return;
    }
}

int CheckID(List l, int ID){
    for(Student *p = l.first; p != NULL; p = p->next){
        if(p->ID == ID) return 1;
    }
    return 0;
}

void Input(List *l){
    char Name[SIZENAME];
    int ID;
    float Score;
    while(ID != 0){
        printf("Nhap ID:");
        fflush(stdin);
        scanf("%d", &ID);
        while(CheckID(*l, ID)){
            printf("ID bi trung, vui long nhap lai\n");
            printf("Nhap ID:");
            fflush(stdin);
            scanf("%d", &ID);
        }
        if(ID == 0) return;
        printf("Nhap ten:");
        fflush(stdin);
        gets(Name);
        do{
            printf("Nhap diem:");
            fflush(stdin);
            scanf("%f", &Score);
        }while(Score < 0 || Score >10);
        printf("\n");
        Student *p = GetStudent(Name, ID, Score);
        AddStudent(l, p);
    }
}

void Output(List l){
    printf("\nDanh sach hoc sinh:\n");
    for(Student *p = l.first; p != NULL; p = p->next){
        printf("Name: %s\n", p->Name);
        printf("ID: %d\n", p->ID);
        printf("Score: %.2f\n", p->Score);
        printf("\n");
    }
}

void SortStudent(List *l){
    List l1, l2;
    if(l->first == l->last) return;
    InitList(&l1);  InitList(&l2);
    Student *p;
    Student *tag;
    tag = l->first;
    l->first = l->first->next;
    tag->next = NULL;
    while(l->first != NULL){
        p = l->first;
        l->first = l->first->next;
        p->next = NULL;
        if(p->Score >= tag->Score) {
            AddStudent(&l1, p);
        }
        else AddStudent(&l2, p);
    }
    SortStudent(&l1);
    SortStudent(&l2);
    if(l1.first != NULL){
        l->first = l1.first;
        l1.last->next = tag;
    }
    else{
        l->first = tag;
    }
    tag->next = l2.first;
    if(l2.first != NULL){
        l->last = l2.last;
    }
    else{
        l->last = tag;
    }
}

void DelStudent(List *l){
    Student *temp;
    for(Student *p = l->first; p != NULL; p = p->next){
        if(p->Score < 5){
            temp->next = NULL;
            l->last = temp;
            free(p);
            return;
        }
        temp = p;
    }
}

int main(){
    //Nhap thong tin sinh vien, va sap xep list, loai bo sinh vien diem duoi 5 ra khoi list
    //Stop nhap bang cach go 0 vao ID
    List l;
    InitList(&l);
    Input(&l);
    SortStudent(&l);
    DelStudent(&l);
    Output(l);
}



