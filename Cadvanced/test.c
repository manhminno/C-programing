// Chay chuong trinh thi chay gcc tenfile.c libfdr.a
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libfdr/jrb.h"
#include "libfdr/dllist.h"


#define INF_VALUE 1000000
typedef struct {
	JRB edges;
	JRB vertices;
} Graph;

Graph createGraph();
void addVertex(Graph graph, int id, char* name);			// Them ten cho cac dinh graph
char* getVertex(Graph graph, int id);						// Lay ten cua dinh theo id
void addEdge(Graph graph, int v1, int v2, double weight);	// Them canh vao graph tu v1->v2, them trong so  *****
double getEdgeValue(Graph graph, int v1, int v2); 			// Lay gia tri cua canh
int hasEdge(Graph graph, int v1, int v2);                   // Co canh tu v1->v2 ko
int indegree(Graph graph, int v, int* output);		        // cac dinh di vao dinh v
int outdegree(Graph graph, int v, int* output);		       // Cac dinh di ra dinh v
int DAG(Graph graph); 			                           // Kiem tra do thi co chu trinh hay ko
void dropGraph(Graph graph);	                           // Xoa graph
double shortestPath(Graph graph , int start ,int stop ,int* path , int * length);			// Tim duong di theo djtra




int main(int argc, char const *argv[])
{
    int path[1000];
    int length;
    Graph graph = createGraph();
    double weight;
    addVertex(graph, 0, "test");
    addVertex(graph, 1, "test");
    addVertex(graph, 2, "test");
    addVertex(graph, 3, "test");
    addVertex(graph, 4, "test");
    addVertex(graph, 5, "test");
    addVertex(graph, 6, "test");
    addEdge(graph, 0, 1, 2.1);
    addEdge(graph, 1, 2, 4.6);
    addEdge(graph, 2, 4, 3.1);
    addEdge(graph, 4, 6, 2.9);
    addEdge(graph, 6, 8, 3.1);
    addEdge(graph, 8, 1, 3.1);
    weight = shortestPath(graph, 0, 4, path, &length);
    printf("Do thi co chu trinh 1/0 ? %d\n", DAG(graph));
    printf("Tu 1 -> 2 co trong so la : %.2f\n", getEdgeValue(graph, 1, 2));
    printf("Total: %.2f\nLength: %d\n", weight, length);
    dropGraph(graph);

    return 0;
}


Graph createGraph(){
	Graph g;
	g.edges = make_jrb();
	g.vertices = make_jrb();
	return g;
}
void addVertex(Graph graph, int id, char *name)
{
    JRB node;
    node = jrb_find_int(graph.vertices, id);
    if(node == NULL)
        jrb_insert_int(graph.vertices, id, new_jval_s(name));
}

char *getVertex(Graph graph, int id)
{
    JRB node;
    node = jrb_find_int(graph.vertices, id);
    if(node != NULL)
        return jval_s(node->val);
    else return NULL;
}

int hasEdge(Graph graph, int v1, int v2)
{
    JRB node, tree;
    node = jrb_find_int(graph.edges, v1);
    if(node == NULL)
        return 0;
    tree = (JRB) jval_v(node->val);
    if(jrb_find_int(tree, v2) == NULL)
        return 0;
    else
        return 1;
}

void addEdge(Graph graph, int v1, int v2, double weight)
{
    JRB node, tree;
    if(!hasEdge(graph, v1, v2))
    {
        node = jrb_find_int(graph.edges, v1);
        if(node == NULL)
        {
            tree = make_jrb();
            jrb_insert_int(graph.edges, v1, new_jval_v(tree));
        }
        else
            tree = (JRB)jval_v(node->val);
        jrb_insert_int(tree, v2, new_jval_d(weight));
    }
}

double getEdgeValue(Graph graph, int v1, int v2)
{
	if(!hasEdge(graph, v1 ,v2))
        return -1;
    JRB node, tree, destination;
    node = jrb_find_int(graph.edges, v1);
    tree = (JRB) jval_v(node->val);
    destination = jrb_find_int(tree, v2);
    return jval_d(destination->val);
}
int indegree(Graph graph, int v, int* output){
	JRB node, tree;
	int total = 0;
	jrb_traverse(node, graph.edges){
		tree = (JRB) jval_v(node->val);
		if( jrb_find_int(tree, v)){
			output[total] = jval_i(node->key);
			total++;
		}
	}
	return total;
}

int outdegree(Graph graph, int v, int* output){
	JRB node, tree;
	int total = 0;
	node = jrb_find_int(graph.edges, v);
	if(node == NULL ) return 0;
	tree = (JRB) jval_v(node->val);
	jrb_traverse(node, tree) {
		output[total] = jval_i(node->key);
		total++;
	}
	return total;
}
int DAG(Graph graph){
	int visited[1000];
	int n, output[100], u, v, start;
	Dllist node, stack;
	JRB vertex;
	jrb_traverse(vertex, graph.vertices){
		memset(visited, 0, sizeof(visited));

		start = jval_i(vertex->key);
		stack = new_dllist();
		dll_append(stack, new_jval_i(start));
		while(!dll_empty(stack)){
			node = dll_last(stack);
			u = jval_i(node->val);
			dll_delete_node(node);
			if(!visited[u]){
				visited[u] = 1;
				n = outdegree(graph, u, output);
				for(int i = 0; i < n; i++){
					v = output[i];
					if(v == start) return 0;
					if(!visited[v]) dll_append(stack, new_jval_i(v));
				}
			}
		}
		free_dllist(stack);
	}
	return 1;
}

void dropGraph(Graph graph) {	
	JRB node;
	jrb_traverse(node,graph.edges)
		jrb_free_tree((JRB)jval_v(node->val));
	jrb_free_tree(graph.edges);
	jrb_free_tree(graph.vertices);
}

double shortestPath(Graph graph, int start, int stop, int *path, int *length)
{
    double total, distance[1000];
    int min,id,i,n,neighbor,position, previous[1000],output[1000],temp[1000];
    Dllist queue, shortest, node;

    //memset(distance, INF_VALUE, sizeof(distance));
    for(i = 0; i < 1000; i ++)
        distance[i] = INF_VALUE;

    distance[start] = 0;
    previous[start] = start;

    queue = new_dllist();
    dll_append(queue, new_jval_i(start));

    while(!dll_empty(queue))
    {
        min = INF_VALUE;
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
    if(total != INF_VALUE)
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