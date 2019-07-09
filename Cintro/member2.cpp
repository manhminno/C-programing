#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
//<<<<<<< HEAD
//=======
//
//>>>>>>> a099be550d75c82852e38eb2d4b0b69a44afdecc

#define SIZE_NAME 20
#define SIZE_MEMBER 200

/* NV: viết hàm ShowInfoMember, ShowChangeInfoMember */

typedef struct InfoMember{
    int id;
    char name[SIZE_NAME];
    int age;
    int group_id;
} InfoMember;

//số lượng member
int nmember = 0;
//hàm
InfoMember *InitInfoMember();
InfoMember **InitListInfoMember(int length);
void ShowInfoMember(InfoMember **member,int length);
void ShowChangeInfoMember(InfoMember **members);
void InputInfoMember(InfoMember *member, FILE *file);
void AddInfoMember(InfoMember **members);
void FreeInfoMember(InfoMember *member);
void DeleteInfoMember(InfoMember **members);
void SearchInfoMember(InfoMember **members, InfoMember **listSearchMember);
int SearchMember(InfoMember **members, InfoMember **listSearchMember, char temp);
void ghi(FILE *file, InfoMember *members);

void menu(){
    printf("***************************************\n");
    printf("|=====================================|\n");
    printf("|[1].Xem thanh vien                   |\n" );
    printf("|[2].Them thanh vien                  |\n");
    printf("|[3].Sua thong tin thanh vien         |\n");
    printf("|[4].Xoa thanh vien                   |\n" );
    printf("|[5].Tim kiem thong tin thanh vien    |\n" );
    printf("|[6].Them thanh vien tu file          |\n" );
    printf("|[7].Thoat chuong trinh               |\n" );
    printf("|=====================================|\n");
}

int main(){
    InfoMember **members;
    members = InitListInfoMember(SIZE_MEMBER);
    InfoMember **listSearchMember;
    listSearchMember = InitListInfoMember(SIZE_MEMBER);
    FILE *file = NULL;
    file =fopen("Demo.txt", "w");
    //do something
    int choose;
    char cont;
    FILE *p;
    do{
        system("cls");
        menu();
        printf("Nhap chuc nang:");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                ShowInfoMember(members, nmember);
                break;
            case 2:
                AddInfoMember(members);
                break;
            case 3:
                ShowChangeInfoMember(members);
                break;
            case 4:
                DeleteInfoMember(members);
                break;
            case 5:
                SearchInfoMember(members, listSearchMember);
                break;
//            case 6:
//                char s[] = "members.txt";
//                AddFromFile(members, s);
//                break;
        }
        printf("Ban co muon tiep tuc khong? (Y/N):");
        fflush(stdin);
        scanf("%c", &cont);
    }while(cont == 'y' || cont == 'Y');

    //kết thúc
    //getch();
    return 0;
}

//Khởi tạo member
//không cần viết hàm này thêm :)) nhưng thử check xem hàm này đúng ko :v
InfoMember *InitInfoMember(){
    //khởi tạo
    InfoMember *member = (InfoMember*) malloc (sizeof(InfoMember));

    //set 1 số trường
    member->id = 0;
    strcpy(member->name, "None");
    member->age = 0;
    member->group_id = 0;

    return member;
}

//Khởi tạo mảng member
InfoMember **InitListInfoMember(int length){
    InfoMember **listMember = (InfoMember**) malloc (length * sizeof(InfoMember*));

    //nếu không thể khởi tạo
    if (listMember == NULL) return listMember;
    //cho các phần tử NULL
    for (int i = 0 ; i < length ; i++){
        listMember[i] = NULL;
    }

    return listMember;
}

//hiển thị thông tin member
void ShowInfoMember(InfoMember **member,int length){
    //in ra màn hình
    printf("Have %d member:\n", length);
    printf("%-10s %-20s %-10s %-10s\n", "ID", "Name", "Age", "Group_ID" );
    for (int i = 0; i < length; i++)
    {
        printf("%-10d %-20s %-10d %-10d\n", member[i]->id ,member[i]->name, member[i]->age, member[i]->group_id );
    }
}

//In màn hình và nhập thay đổi giá trị member vị trí index
void ShowChangeInfoMember(InfoMember **members, FILE *file){
    int index;
    // nhập vị trí index. nếu index sai quay lại việc nhập.
    do {
        printf("Nhap index: ");
        scanf("%d", &index);
        if (index >= nmember || index < 0)
            printf("Nhap qua index cho phep, moi ban nhap lai.\n");
    } while(index >= nmember || index < 0);

    //in màn hình và nhập dữ liệu sửa


    printf("Nhap du lieu sua\n");
    InputInfoMember(members[index], file);

}

//nhập bàn phím
void InputInfoMember(InfoMember *member, FILE *file){
    //in màn hình
    printf( "ID: " );
    fflush(stdin);
    scanf( "%d",&member->id );
    fflush(stdin);
    printf( "Name: " );
    gets(member->name);
    printf( "Age: " );
    fflush(stdin);
    scanf( "%d",&member->age );
    printf( "Group_ID: " );
    fflush(stdin);
    scanf( "%d",&member->group_id);
    ghi(file, member);
    //gán vào member

}

// thêm người vào mảng
void AddInfoMember(InfoMember **members, FILE *file){
    //nếu vượt quá giới hạn thì ko thêm
    if (nmember >= SIZE_MEMBER) return;

    //khởi tạo phần tử cuối
    members[nmember] = InitInfoMember();
    //nhập giá trị
    InputInfoMember(members[nmember], file);
    //cộng số phần tử thêm 1
    nmember++;
}

//free bộ nhớ member
void FreeInfoMember(InfoMember *member){
    free(member->name);
    free(member);
}

//Xóa member tại vị trí index
void DeleteInfoMember(InfoMember **members){
    int index;
    // nhập vị trí index. nếu index sai quay lại việc nhập.
    do {
        printf("Nhap index: ");
        scanf("%d", &index);
        if (index >= nmember || index < 0)
            printf("Nhap qua index cho phep, moi ban nhap lai.\n");
    } while(index >= nmember || index < 0);

    FreeInfoMember(members[index]);
    //số chuyển phần tử cuối cùng thành phần tử index
    //có thể dich từng phần tử để bảo toàn số thứ tự
    members[index] = members[nmember - 1];
    members[nmember - 1] = NULL;
    //số lượng người - 1
    nmember--;
}

int SearchMember(InfoMember **members,InfoMember **listSeachMember, char temp[]){
    int sizeoflist=0;
    for (int i = 0; i < nmember; i++)
    {
        if (members[i]->id==atoi(temp)||strstr(members[i]->name,temp)!=NULL||members[i]->age==atoi(temp)||members[i]->group_id==atoi(temp))
        {
            listSeachMember[sizeoflist]=members[i];
            sizeoflist++;
        }
    }
    return sizeoflist;
}

void SearchInfoMember(InfoMember **members, InfoMember **listSeachMember){
    char temp[30];
    printf("Nhap thong tin ban muon tim kiem:");
    fflush(stdin);
    gets(temp);
    int check=SearchMember(members,listSeachMember,temp);
    if(check==0) printf("Khong co thong tin nao lien quan den '%s'\n", temp);
    else ShowInfoMember(listSeachMember,check);
}

void ghi(FILE *file, InfoMember *members){
    fprintf(file,"%d\n %s\n %d\n %d\n", members->id, members->name, members->age, members->group_id);
    fclose(file);
}

