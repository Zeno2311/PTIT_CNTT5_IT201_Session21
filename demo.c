#include <stdio.h>
#include <stdlib.h>

// int MATRIX[3][3];
//
// // Hàm khởi tạo ma trận hai chiều với các giá trị các ô là 0
// void maTrix() {
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             MATRIX[i][j] = 0;
//         }
//     }
// }
//
// // khởi tạo hàm tao liên kết
// void adjacemy(int U, int V) {
//     MATRIX[U][V] = 1;
//     MATRIX[V][U] = 1; // đồ thị vô hướng thì phải quan hệ 2 chiều
// }
//
// // Tạo hàm hiển thị ma trận
// void printMaTrix() {
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             printf("%d ", MATRIX[i][j]);
//         }
//         printf("\n");
//     }
// }


// Danh sách kề: ý tưởng mỗi đỉnh là 1 danh sách liên sách với các đỉnh khác
// Tạo cấu trúc 1 node
typedef struct Node {
    int data;
    struct Node *next;
} Node;
// Viết hàm tạo node
Node *createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Tạo mảng chứa danh sách các con trỏ mà trỏ tới từng đỉnh
Node *adjacency[4];
// Viết node tạo liên kết
Node *addAdjacency(int U, int V) {
    // Tạo 1 node mới, thêm vào đầu
    Node* newNode = createNode(U);
    // Đi liên kết với phần tử ban đầu
    newNode->next = adjacency[U];
    adjacency[U] = newNode; // newNode lúc này sẽ là phần tử đầu
    newNode = createNode(V);
    newNode->next = adjacency[V]; // Liên kết với phần tử ban đầu
    adjacency[V] = newNode;
}

// Hàm hiển thị liên kết các điểm
void printAdjacency() {
    for (int i = 0; i < 4; i++) {
        Node* current = adjacency[i];
        while (current) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    // maTrix();
    // adjacemy(0, 1);
    // printMaTrix();

    // Khởi tạo các giá trị trong mảng về NULL
    for (int i = 0; i < 4; i++) {
        adjacency[i] = NULL;
    }
    addAdjacency(1, 2);
    addAdjacency(2, 3);
    printAdjacency();

    return 0;
}
