#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void calculateDegreeUndirected(int graph[MAX][MAX], int numVertices) {
    int degree[MAX] = {0}; 
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (graph[i][j] == 1) {
                degree[i]++;  
                degree[j]++; 
            }
        }
    }

    for (int i = 0; i < numVertices; i++) {
        printf("Bac cua dinh %d: %d\n", i, degree[i]);
    }
}

void calculateDegreeDirected(int graph[MAX][MAX], int numVertices) {
    int inDegree[MAX] = {0}; 
    int outDegree[MAX] = {0};

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (graph[i][j] == 1) { 
                outDegree[i]++; 
                inDegree[j]++;  
            }
        }
    }
    for (int i = 0; i < numVertices; i++) {
        printf("Bac vao cua dinh %d: %d\n", i, inDegree[i]);
        printf("Bac ra cua dinh %d: %d\n", i, outDegree[i]);
    }
}

void findMaxDegree(int graph[MAX][MAX], int numVertices, int isDirected) {
    int maxDegree = -1;
    int maxVertex = -1;

    if (isDirected) {
        int inDegree[MAX] = {0}; 
        int outDegree[MAX] = {0};
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (graph[i][j] == 1) {
                    outDegree[i]++;
                    inDegree[j]++;
                }
            }
        }
        for (int i = 0; i < numVertices; i++) {
            int totalDegree = inDegree[i] + outDegree[i];
            if (totalDegree > maxDegree) {
                maxDegree = totalDegree;
                maxVertex = i;
            }
        }
    } else {
        int degree[MAX] = {0}; 
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (graph[i][j] == 1) {
                    degree[i]++;
                    degree[j]++;
                }
            }
        }
        for (int i = 0; i < numVertices; i++) {
            if (degree[i] > maxDegree) {
                maxDegree = degree[i];
                maxVertex = i;
            }
        }
    }

    printf("Dinh co bac lon nhat la: %d voi bac = %d\n", maxVertex, maxDegree);
}

int main() {
    int numVertices, numEdges, u, v, isDirected;
    int graph[MAX][MAX];
    printf("Nhap so luong dinh: ");
    scanf("%d", &numVertices);
    printf("Nhap so luong canh: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph[i][j] = 0; 
        }
    }
    printf("Nhap 1 neu do thi co huong, 0 neu do thi vo huong: ");
    scanf("%d", &isDirected);

    printf("Nhap cac canh (u v) cua do thi:\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;  

        if (!isDirected) {
            graph[v][u] = 1; 
        }
    }
    if (isDirected) {
        calculateDegreeDirected(graph, numVertices);
    } else {
        calculateDegreeUndirected(graph, numVertices);
    }
    findMaxDegree(graph, numVertices, isDirected);

    return 0;
}

