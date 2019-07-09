#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libfdr/graph.h"

#define MAX 100

typedef struct{
    int id;
    char ip[MAX];
} internet;

Graph g;
int ninternet;
int nconnect;

void readFile(const char *name, internet *list){
    FILE *fin = fopen(name, "r");
    char ip[MAX];
    int id;
    int v1, v2;
    double w;
    fscanf(fin, "%d", &ninternet);
    for(int i = 0; i < ninternet; i++){
        fscanf(fin, "%d %s", &id, ip);
        list[i].id = id;
        strcpy(list[i].ip, ip);
        addVertex(g, id, strdup(ip));
    }
    fscanf(fin, "%d", &nconnect);
    for(int i = 0; i < nconnect; i++){
        fscanf(fin, "%d %d %lf", &v1, &v2, &w);
        addEdge_notD(g, v1, v2, w);
    }
    fclose(fin);
}

void printList(internet *list){
    for(int i = 0; i < ninternet; i++){
        printf("%d %s\n", list[i].id, list[i].ip);
    }
}

void hasConnect(int v1){
    int output[MAX];
    int conn = outdegree(g, v1, output);
    printf("%d\n", conn);
    for(int i = 0; i < conn; i++){
        printf("%d %s %.0lf\n", output[0], getVertex(g, output[i]), getEdgeValue(g, v1, output[i]));
    }
}

void findConnect(int v1, int v2){
    int path[MAX];
    int length;
    double check = shortestPath(g, v1, v2, path, &length);
    printf("%.0lf\n", check);
    for(int i = 0; i < length; i++){
        printf("%s\n", getVertex(g, path[i]));
    }
}

int main(int argc, char const *argv[]){
    g = createGraph();
    internet *list = (internet *)malloc(MAX*sizeof(internet));
    
    if (strcmp(argv[1], "-h") == 0) printf("C-Advanced, HK20152\n");
    
    else if (strcmp(argv[1], "-v") == 0){
        readFile(argv[2], list);
        printList(list);
    }

    else if (strcmp(argv[1], "-w") == 0){
        readFile(argv[2], list);
        double check = getEdgeValue(g, atoi(argv[3]), atoi(argv[4]));
        printf("%.0lf\n", check);
    }

    else if (strcmp(argv[1], "-p") == 0){
        readFile(argv[2], list);
        findConnect(atoi(argv[3]), atoi(argv[4]));
    }
    
    else if (strcmp(argv[1], "-n") == 0){
        readFile(argv[2], list);
        hasConnect(atoi(argv[3]));
    }


    return 0;
}