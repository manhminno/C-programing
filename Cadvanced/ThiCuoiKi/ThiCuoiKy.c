#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libfdr/graph.h"

#define MAX 100
#define INFINITY 1000000

Graph g;
int nthanhtri;
int nketnoi;
int map[MAX][MAX];

void initMap(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; i++){
            map[i][j] = 0;
        }
    }
}

void readFile(const char *name){
    int v1, v2;
    double w;
    int count = 0;
    FILE *fin = fopen("dothi.txt", "r");
    fscanf(fin, "%d %d", &nthanhtri, &nketnoi);
    for(int i = 0; i < nketnoi; i++){
        fscanf(fin, "%d %d %lf", &v1, &v2, &w);
        map[v1][v2] = map[v2][v1]= (int)w;
        char c[1];
        c[1] = '\0';
        c[0] = v1 + 48;
        addVertex(g, v1,"0");
        c[0] = v2 + 48;
        addVertex(g, v2, "0");
        addEdge_notD(g, v1, v2, w);
    }
    fclose(fin);
}

void printMap(){
    for(int i = 1; i <= nthanhtri; i++){
        for(int j = 1; j <= nthanhtri; j++){
            printf("%d\t", map[i][j]);
        }
        printf("\n");
    }
}

void printListConnect(){
    int output[100];
    for(int i = 1; i <= nthanhtri; i++){
        int check = outdegree(g, i, output);
        if(check != 0){
            printf("Castle %d:", i);
            for(int j = 0; j < check; j++){
                printf("%d\t", output[j]);
            }
        }
        printf("\n");
    }
}

void checkLand(){
    int max = -1;
    int output[100];
    int check;
    for(int i = 1; i < nthanhtri; i++){
        check = indegree(g, i, output);
        if(check > max) max = check;
    }
    printf("Danh sach thanh tri co nhieu duong di den nhat:\n");
    for(int i = 1; i < nthanhtri; i++){
        check = indegree(g, i, output);
        if(check == max) printf("%d\t", i);
    }
}

int checkWalk(int i){
    int output[100];
    int tmp = 1;
    int check = outdegree(g, i, output);
    for(int j = 0; j < check; j++){
        if(getEdgeValue(g, i, output[j]) < 50) tmp = 0;
    }
    if(tmp == 1) return 1;
    return 0;
}

void shortLand(){
    int path[100];
    int length;
    int v1, v2;
    printf("Nhap dinh bat dau: ");
    scanf("%d", &v1);
    printf("Nhap dinh den:");
    scanf("%d", &v2);
    double time = shortestPath(g, v1, v2, path, &length);
    if(time){
        printf("Do dai duong di: %.0lf\n", time);
        for(int i = 0; i < length; i++){
            printf("%d ", path[i]);
        }
        printf("\n");
    }else printf("ROUTE NOT FOUND\n");
}

double shortestPath2(Graph graph, int start, int stop, int *path, int *length)  // tim duong ngan nhat Djkstra
{
    double total, distance[1000];
    int min,id,i,n,neighbor,position, previous[1000],output[1000],temp[1000];
    Dllist queue, shortest, node;

    //memset(distance, INFINITY, sizeof(distance));
    for(i = 0; i < 1000; i ++)
        distance[i] = INFINITY;

    distance[start] = 0;
    previous[start] = start;

    queue = new_dllist();
    dll_append(queue, new_jval_i(start));

    while(!dll_empty(queue))
    {
        min = INFINITY;
        dll_traverse(node, queue)
        {
            id = jval_i(node->val);
            if(min > distance[id])
            {
                min = distance[id];
                shortest = node;
            }
        }
        id = jval_i(shortest->val);
        dll_delete_node(shortest);

        if(id == stop) break;

        n = outdegree(graph, id, output);
        for(i = 0; i < n; i ++)
        {
            if(getEdgeValue(graph, id, neighbor) < 50) i++;
            neighbor = output[i];
            if(distance[neighbor] > distance[id] + getEdgeValue(graph, id, neighbor))
            {
                distance[neighbor] = distance[id] + getEdgeValue(graph, id, neighbor);
                previous[neighbor] = id;
                dll_append(queue, new_jval_i(neighbor));
            }
        }
    }

    total = distance[stop];
    if(total != INFINITY)
    {
        temp[0] = stop;
        position = 1;
        while(stop != start)
        {
            stop = previous[stop];
            temp[position ++] = stop;
        }
        for(i = position - 1; i >= 0; i --)
            path[position - i - 1] = temp[i];
        *length = position;
    }
    return total;
}

void checkMinWalk(){
    int path[100];
    int length;
    int v1, v2;
    printf("Nhap dinh bat dau: ");
    scanf("%d", &v1);
    printf("Nhap dinh den:");
    scanf("%d", &v2);
    double time = shortestPath2(g, v1, v2, path, &length);
    if(time != -1){
        printf("Do dai duong di: %.0lf\n", time);
        for(int i = 0; i < length; i++){
            printf("%d ", path[i]);
        }
        printf("\n");
    }else printf("ROUTE NOT FOUND\n");
}

void Menu()
{
    printf("=====================================\n");
    printf("_____________________________________\n");
	printf("_________________Menu________________\n");
	printf("|[1].Doc ban do.                    |\n");
	printf("|[2].Danh sach ke.                  |\n" );
	printf("|[3].Kiem tra duong di.             |\n");	
	printf("|[4].Tim duong di ngan nhat.        |\n");
    printf("|[5].Tim duong di bo ngan nhat      |\n");
    printf("|[6].Thoat chuong trinh.            |\n");
	printf("=====================================\n");
    printf("*************************************\n");
}

int main(int argc, char const *argv[]){
    g = createGraph();
    int chucnang;
    readFile("dothi.txt");
    do{
	    Menu();
        do{
            printf("Nhap chuc nang ban muon: ");
	        scanf("%d", &chucnang);
        }while(chucnang < 1 || chucnang > 6);
	    switch(chucnang)
	    {
		    case 1:
                printMap();
		        break;
		    case 2:
                printListConnect();
		        break;
		    case 3:
                printf("Danh sach cac thanh tri chi cos the den no bang cach di bo:\n");
                for(int i = 1; i <= nthanhtri; i++){
                    if(checkWalk(i)) printf("%d\t", i);
                }
                printf("\n");
                checkLand();
                printf("\n");
		        break;
		    case 4:
                shortLand();
		        break;
            case 5:
                checkMinWalk();
                break;
            case 6:
                return 0;
        }
    }while(1);
    dropGraph(g);
    return 0;
}