#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int adjMatrix[MAX][MAX];
    int num;
} matrix;

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node* adj[MAX];
    int num;
} list;

void initGraphMatrix(matrix* graph, int num) {
    graph->num = num;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

void initGraphList(list* graph, int num) {
    graph->num = num;
    for (int i = 0; i < num; i++) {
        graph->adj[i] = NULL;
    }
}

void addEdgeMatrix(matrix* graph, int start, int end, int isDirected) {
    graph->adjMatrix[start][end] = 1;
    if (!isDirected) {
        graph->adjMatrix[end][start] = 1;
    }
}

void addEdgeList(list* graph, int start, int end, int isDirected) {
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

void printGraphMatrix(matrix* graph) {
    printf("Do thi ma tran ke:\n");
    for (int i = 0; i < graph->num; i++) {
        for (int j = 0; j < graph->num; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void printGraphList(list* graph) {
    printf("Do thi danh sach ke:\n");
    for (int i = 0; i < graph->num; i++) {
        Node* temp = graph->adj[i];
        printf("Dinh %d: ", i);
        while (temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, numVertices, startVertex, endVertex, isDirected;
    matrix graphMatrix;
    list graphList;

    printf("Nhap so luong dinh: ");
    scanf("%d", &numVertices);

    initGraphMatrix(&graphMatrix, numVertices);
    initGraphList(&graphList, numVertices);

    do {
        printf("\nMenu:\n");
        printf("1. Them canh vao do thi ma tran ke\n");
        printf("2. Them canh vao do thi danh sach ke\n");
        printf("3. Hien thi do thi ma tran ke\n");
        printf("4. Hien thi do thi danh sach ke\n");
        printf("5. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap dinh dau (startVertex) va dinh cuoi (endVertex): ");
                scanf("%d %d", &startVertex, &endVertex);
                printf("La do thi co huong? (1: Co huong, 0: Vo huong): ");
                scanf("%d", &isDirected);
                addEdgeMatrix(&graphMatrix, startVertex, endVertex, isDirected);
                break;
            case 2:
                printf("Nhap dinh dau (startVertex) va dinh cuoi (endVertex): ");
                scanf("%d %d", &startVertex, &endVertex);
                printf("La do thi co huong? (1: Co huong, 0: Vo huong): ");
                scanf("%d", &isDirected);
                addEdgeList(&graphList, startVertex, endVertex, isDirected);
                break;
            case 3:
                printGraphMatrix(&graphMatrix);
                break;
            case 4:
                printGraphList(&graphList);
                break;
            case 5:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 5);

    return 0;
}
