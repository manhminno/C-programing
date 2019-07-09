#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libfdr/graph.h"

#define MAX 100

int nkhohang;
int nsanpham;
Graph g;

typedef struct{
    char name[MAX];
    int idsp;
    int soluong;
} mathang;

typedef struct{
    int id;
    char name[MAX];
    mathang sanpham[MAX];
} khohang;

void readFileSP(const char *name, mathang *sanpham){
    FILE *fin = fopen(name, "r");
    char namesp[MAX];
    int idsp;
    fscanf(fin, "%d", &nsanpham);
    for (int i = 0; i < nsanpham; i++)
    {
        fscanf(fin, "%s %d", &namesp, &idsp);
        sanpham[i].idsp = idsp;
        strcpy(sanpham[i].name, namesp);
    }
    fclose(fin);
}

void readFileKho(const char *name, khohang *list, mathang *sanpham){
    FILE *fkhohang = fopen(name, "r");
    int idsp, nsp, v1, v2, nedges;
    double w;
    int idkho;
    char namekho[MAX], namesp[MAX];
    fscanf(fkhohang, "%d", &nkhohang);
    for (int i = 0; i < nkhohang; i++){
        fscanf(fkhohang, "%s %d", &namekho, &idkho);
        addVertex(g, idkho, strdup(namekho));
        list[i].id = idkho;
        strcpy(list[i].name, namekho);
        for (int j = 0; j < nsanpham; j++){
            fscanf(fkhohang, "%d %d", &idsp, &nsp);
            list[i].sanpham[j].soluong = nsp;
            list[i].sanpham[j].idsp = idsp;
            int k;
            for(k = 0; k < nsanpham; k++){
                if(sanpham[k].idsp == idsp) break;
            }
            strcpy(list[i].sanpham[j].name, sanpham[k].name);
        }
    }
    fscanf(fkhohang, "%d", &nedges);
    for (int i = 0; i < nedges; i++){
        fscanf(fkhohang, "%d %d %lf", &v1, &v2, &w);
        addEdge_notD(g, v1, v2, w);
    }
    fclose(fkhohang);
}

int findKho(khohang *list, int idfind){
    for(int i = 0; i < nkhohang; i++){
        if(list[i].id == idfind) return i;
    }
}

int findSP(khohang list, int idsp){
    for(int i = 0; i < nsanpham; i++){
        if(list.sanpham[i].idsp == idsp) return i;
    }
}

void printSp(mathang *sanpham){
    for (int i = 0; i < nsanpham; i++)
    {
        printf("%s %d\n", sanpham[i].name, sanpham[i].idsp);
    }
}

void printKhoKe(khohang *list, mathang *sanpham, int v1, int idsp){
    int i = 0;
    int find = findKho(list, v1);
    int findsp = findSP(list[find], idsp);
    printf("%s\n", list[find].name);
    printf("%s %d\n", list[find].sanpham[findsp].name, list[find].sanpham[findsp].soluong);
    printf("---Cac kho ke la:\n");
    while (i < nkhohang){
        if (hasEdge(g, v1, list[i].id)){
            find = findKho(list, list[i].id);
            findsp = findSP(list[find], idsp);
            printf("%s\n", list[find].name);
            printf("%s %d\n", list[find].sanpham[findsp].name, list[find].sanpham[findsp].soluong);
        }
        i++;
    }
}

void printKho(khohang *list){
    printf("%s\n", list[4].sanpham[0].name);
    for(int i = 0; i < nkhohang; i++){
        printf("%s\n", list[i].name);
        for (int j = 0; j < nsanpham; j++){
           printf("%s %d\n", list[i].sanpham[j].name, list[i].sanpham[j].soluong);
        }
        printf("---\n");
    }
}

double orderHang(Graph g, khohang *list, int idsp, int nsp, int idkho1, int idkho2){
    int find = findKho(list, idkho1);
    int find2 = findKho(list, idkho2);
    if(list[find].sanpham[findSP(list[find], idsp)].soluong >= nsp) return 30;
    else{
        if (list[find2].sanpham[findSP(list[find2], idsp)].soluong >= nsp){
            int path[100];
            int length;
            double s = shortestPath(g, idkho1, idkho2, path, &length);
            double time = (s / 30) * 60 + 30;
            return time;
        }
    }
    return -1;
}

int main(int argc, char const *argv[]){
    g = createGraph();
    khohang *list = (khohang *)malloc(MAX * sizeof(khohang));
    mathang *sanpham = (mathang *)malloc(MAX * sizeof(mathang));
    
    if (strcmp(argv[1], "-t") == 0) printf("C-Advanced, HK20182\n");
    
    else if (strcmp(argv[1], "-s") == 0){
        readFileSP(argv[2], sanpham);
        printSp(sanpham);
    }

    else if (strcmp(argv[1], "-w") == 0){
        readFileSP(argv[3], sanpham);
        readFileKho(argv[2], list, sanpham);
        printf("%.0lf\n", getEdgeValue(g, atoi(argv[4]), atoi(argv[5])));
    }

    else if (strcmp(argv[1], "-a") == 0){
        readFileSP(argv[3], sanpham);
        readFileKho(argv[2], list, sanpham);
        printKho(list);
    }
    
    else if (strcmp(argv[1], "-h") == 0){
        readFileSP(argv[3], sanpham);
        readFileKho(argv[2], list, sanpham);
        printKhoKe(list, sanpham, atoi(argv[5]), atoi(argv[4]));
    }

    else if (strcmp(argv[1], "-g") == 0){
        readFileSP(argv[3], sanpham);
        readFileKho(argv[2], list, sanpham);
        double check = orderHang(g, list, atoi(argv[4]), atoi(argv[5]), atoi(argv[6]), atoi(argv[7]));
        if(check != -1){
            int hour = (int)check;
            int min = hour%60;
            hour /= 60;
            printf("Dat hang thanh cong, thoi gian giao hang la: %d gio %d phut.\n", hour, min);
        }
        else printf("Dat hang khong thanh cong!");
    }

    return 0;
}