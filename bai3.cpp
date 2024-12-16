#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int adjMatrix[MAX][MAX];
    int numVertices;
} GraphMatrix;

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node* adj[MAX];
    int numVertices;
} GraphList;

void initGraphMatrix(GraphMatrix* graph, int numVertices) {
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

void initGraphList(GraphList* graph, int numVertices) {
    graph->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        graph->adj[i] = NULL;
    }
}

void addEdgeMatrix(GraphMatrix* graph, int start, int end, int isDirected) {
    graph->adjMatrix[start][end] = 1;
    if (!isDirected) {
        graph->adjMatrix[end][start] = 1;
    }
}

void addEdgeList(GraphList* graph, int start, int end, int isDirected) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = end;
    newNode->next = graph->adj[start];
    graph->adj[start] = newNode;

    if (!isDirected) {
        newNode = (Node*)malloc(sizeof(Node));
        newNode->vertex = start;
        newNode->next = graph->adj[end];
        graph->adj[end] = newNode;
    }
}

int DFS_Matrix(int vertex, int visited[], int recursionStack[], GraphMatrix* graph) {
    visited[vertex] = 1;
    recursionStack[vertex] = 1;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1) {
            if (!visited[i] && DFS_Matrix(i, visited, recursionStack, graph)) {
                return 1;
            } else if (recursionStack[i]) {
                return 1;
            }
        }
    }

    recursionStack[vertex] = 0;
    return 0;
}

int DFS_List(int vertex, int visited[], int recursionStack[], GraphList* graph) {
    visited[vertex] = 1;
    recursionStack[vertex] = 1;

    Node* temp = graph->adj[vertex];
    while (temp != NULL) {
        int neighbor = temp->vertex;
        if (!visited[neighbor] && DFS_List(neighbor, visited, recursionStack, graph)) {
            return 1;
        } else if (recursionStack[neighbor]) {
            return 1;
        }
        temp = temp->next;
    }

    recursionStack[vertex] = 0;
    return 0;
}
int detectCycleMatrix(GraphMatrix* graph) {
    int visited[MAX] = {0};
    int recursionStack[MAX] = {0};

    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i] && DFS_Matrix(i, visited, recursionStack, graph)) {
            return 1;
        }
    }
    return 0;
}
int detectCycleList(GraphList* graph) {
    int visited[MAX] = {0};
    int recursionStack[MAX] = {0};

    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i] && DFS_List(i, visited, recursionStack, graph)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int numVertices, numEdges, start, end, isDirected, choice;
    GraphMatrix graphMatrix;
    GraphList graphList;

    printf("Nhap so luong dinh: ");
    scanf("%d", &numVertices);
    printf("Nhap so luong canh: ");
    scanf("%d", &numEdges);

    printf("Chon loai do thi (1: Ma tran ke, 2: Danh sach ke): ");
    scanf("%d", &choice);
    if (choice == 1) {
        initGraphMatrix(&graphMatrix, numVertices);
    } else if (choice == 2) {
        initGraphList(&graphList, numVertices);
    }
    printf("Nhap danh sach cac canh:\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d", &start, &end);
        printf("La do thi co huong? (1: Co huong, 0: Vo huong): ");
        scanf("%d", &isDirected);
        if (choice == 1) {
            addEdgeMatrix(&graphMatrix, start, end, isDirected);
        } else {
            addEdgeList(&graphList, start, end, isDirected);
        }
    }
    int hasCycle = 0;
    if (choice == 1) {
        hasCycle = detectCycleMatrix(&graphMatrix);
    } else {
        hasCycle = detectCycleList(&graphList);
    }

    if (hasCycle) {
        printf("Do thi co chu ky.\n");
    } else {
        printf("Do thi khong co chu ky.\n");
    }

    return 0;
}

