#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void initMatrix(int matrix[MAX][MAX], int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            matrix[i][j] = 0;
        }
    }
}

void addEdge(int matrix[MAX][MAX], int start, int end) {
    matrix[start][end] = 1;
    matrix[end][start] = 1;
}

void printMatrix(int matrix[MAX][MAX], int numVertices) {
    printf("Ma tran ke cua do thi:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int checkSymmetry(int matrix[MAX][MAX], int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0; 
            }
        }
    }
    return 1;  
}

int main() {
    int numVertices, numEdges, start, end;
    int matrix[MAX][MAX];
    printf("Nhap so luong dinh cua do thi: ");
    scanf("%d", &numVertices);
    printf("Nhap so luong canh cua do thi: ");
    scanf("%d", &numEdges);
    initMatrix(matrix, numVertices);
    printf("Nhap danh sach cac canh cua do thi:\n");
    for (int i = 0; i < numEdges; i++) {
        printf("Nhap canh %d (dinh dau, dinh cuoi): ", i + 1);
        scanf("%d %d", &start, &end);
        addEdge(matrix, start, end);
    }
    printMatrix(matrix, numVertices);

    if (checkSymmetry(matrix, numVertices)) {
        printf("Ma tran ke la doi xung.\n");
    } else {
        printf("Ma tran ke khong doi xung.\n");
    }

    return 0;
}

