#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100
#define INFINITY INT_MAX

int minDistance(int dist[], bool sptSet[], int numVertices) {
    int min = INFINITY, minIndex;
    for (int v = 0; v < numVertices; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}
void dijkstra(int graph[MAX][MAX], int numVertices, int startVertex) {
    int dist[numVertices];  
    bool sptSet[numVertices];  

    for (int i = 0; i < numVertices; i++) {
        dist[i] = INFINITY;
        sptSet[i] = 0;
    }
    dist[startVertex] = 0;

    for (int count = 0; count < numVertices - 1; count++) {
        int u = minDistance(dist, sptSet, numVertices);
        sptSet[u] = 1;
        for (int v = 0; v < numVertices; v++) {
            if (!sptSet[v] && graph[u][v] != INFINITY && dist[u] != INFINITY && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printf("Khoang cach ngan nhat tu dinh %d:\n", startVertex);
    for (int i = 0; i < numVertices; i++) {
        if (dist[i] == INFINITY) {
            printf("Dinh %d: Khong co duong di\n", i);
        } else {
            printf("Dinh %d: %d\n", i, dist[i]);
        }
    }
}

int main() {
    int numVertices, numEdges, u, v, weight;
    int graph[MAX][MAX];
    printf("Nhap so luong dinh: ");
    scanf("%d", &numVertices);
    printf("Nhap so luong canh: ");
    scanf("%d", &numEdges);
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (i == j) {
                graph[i][j] = 0;  
            } else {
                graph[i][j] = INFINITY;  
            }
        }
    }
    printf("Nhap cac canh va trong so (u v weight):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &u, &v, &weight);
        graph[u][v] = weight; 
        graph[v][u] = weight; 
    }

    int startVertex;
    printf("Nhap dinh bat dau de thuc hien Dijkstra: ");
    scanf("%d", &startVertex);
    dijkstra(graph, numVertices, startVertex);

    return 0;
}

