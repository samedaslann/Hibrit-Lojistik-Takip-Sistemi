#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void initGraph(Graph* g) {
	int i;
    for ( i = 0; i < MAX_CITIES; i++) {
        g->head[i] = NULL;
    }
}

void addEdge(Graph* g, int src, int dest) {
    EdgeNode* newNode = (EdgeNode*)malloc(sizeof(EdgeNode));
    newNode->dest = dest;
    newNode->next = g->head[src];
    g->head[src] = newNode;
    
    // Bellek izleme raporu için çıktılar
    printf("Baglanti eklendi: %d -> %d, Yeni Dugum Adresi: %p, Next Pointer: %p\n", 
           src, dest, (void*)newNode, (void*)newNode->next);
}

// Genişlik Öncelikli Arama (BFS)
void BFS(Graph* g, int start_vertex) {
    int visited[MAX_CITIES] = {0};
    int queue[MAX_CITIES];
    int front = 0, rear = 0;

    visited[start_vertex] = 1;
    queue[rear++] = start_vertex;

    printf("\nBFS Rota Gezinimi (Baslangic %d): ", start_vertex);

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        EdgeNode* temp = g->head[current];
        while (temp != NULL) {
            int adj_vertex = temp->dest;
            if (visited[adj_vertex] == 0) {
                visited[adj_vertex] = 1;
                queue[rear++] = adj_vertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}
