#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node* adj[MAX];  
    int numVertices;  
} Graph;

void initGraph(Graph* graph, int numVertices) {
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        graph->adj[i] = NULL;
    }
}

void addEdge(Graph* graph, int start, int end) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = end;
    newNode->next = graph->adj[start];
    graph->adj[start] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = start;
    newNode->next = graph->adj[end];
    graph->adj[end] = newNode;
}

void BFS(Graph* graph, int startVertex) {
    bool visited[MAX] = {false}; 
    int queue[MAX];
    int front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("Duyet BFS: ");

    while (front < rear) {
        int currentVertex = queue[front++];  
        printf("%d ", currentVertex);

        Node* temp = graph->adj[currentVertex];
        while (temp != NULL) {
            int neighbor = temp->vertex;

            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    int numVertices, numEdges, startVertex, u, v;

    Graph graph;

    printf("Nhap so luong dinh: ");
    scanf("%d", &numVertices);
    printf("Nhap so luong canh: ");
    scanf("%d", &numEdges);

    initGraph(&graph, numVertices);

    printf("Nhap danh sach cac canh (u v):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(&graph, u, v);
    }

    printf("Nhap dinh bat dau de duyet BFS: ");
    scanf("%d", &startVertex);
    BFS(&graph, startVertex);

    return 0;
}

