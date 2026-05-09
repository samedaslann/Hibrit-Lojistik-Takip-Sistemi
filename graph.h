#ifndef GRAPH_H
#define GRAPH_H

#define MAX_CITIES 5

typedef struct EdgeNode {
    int dest;
    struct EdgeNode* next;
} EdgeNode;

typedef struct {
    EdgeNode* head[MAX_CITIES];
} Graph;

void initGraph(Graph* g);
void addEdge(Graph* g, int src, int dest);
void BFS(Graph* g, int start_vertex);

#endif
