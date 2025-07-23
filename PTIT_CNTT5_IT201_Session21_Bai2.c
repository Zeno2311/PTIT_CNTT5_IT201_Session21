#include <stdio.h>

int MATRIX[4][4];

// Hàm khởi tạo ma trận hai chiều với các giá trị ô là 0
void maTrix() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            MATRIX[i][j] = 0;
        }
    }
}
// Khởi tạo hàm tạo liên kết
void adjacencyMatrix(int U, int V) {
    MATRIX[U][V] = 1;
    MATRIX[V][U] = 1;
}
// Tạo hàm hiển thị ma trận
void printMatrix() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", MATRIX[i][j]);
        }
        printf("\n");
    }
}

int main() {
    maTrix();

    adjacencyMatrix(0, 1);
    adjacencyMatrix(0, 2);
    adjacencyMatrix(1, 2);
    adjacencyMatrix(2, 3);

    printMatrix();

    return 0;
}