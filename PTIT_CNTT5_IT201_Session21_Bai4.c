#include <stdio.h>

int MATRIX[3][3];

// Hàm khởi tạo ma trận hai chiều với các giá trị ô là 0
void maTrix() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            MATRIX[i][j] = 0;
        }
    }
}
// Khởi tạo hàm tạo liên kết
void adjacencyMatrix(int U, int V) {
    MATRIX[U][V] = 1;
}
// Tạo hàm hiển thị ma trận
void printMatrix() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", MATRIX[i][j]);
        }
        printf("\n");
    }
}

int main() {
    maTrix();

    adjacencyMatrix(1, 0);
    adjacencyMatrix(1, 2);
    adjacencyMatrix(2, 0);

    printMatrix();

    return 0;
}