#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}



void addEdge(Node *graph[], int U, int V) {
    Node *newNodeU = createNode(U);
    newNodeU->next = graph[V];
    graph[V] = newNodeU;

    Node* newNodeV = createNode(V);
    newNodeV->next = graph[U];
    graph[U] = newNodeV;
}

void printMatrix(Node *graph[]) {
    printf("[\n");
    for (int i = 0; i < SIZE; i++) {
        Node *p = graph[i];
        while (p) {
            printf(" %d ->", p->data);
            p = p->next;
        }
        printf(" NULL,");
        printf("\n");
    }
    printf("]\n");
}

int main() {
    Node *graph[SIZE] = {NULL};
    int startNode, endNode;
    printMatrix(graph);

   for (int i = 0; i < 2; i++) {
       printf("Enter startNode: ");
       scanf("%d", &startNode);
       printf("Enter endNode: ");
       scanf("%d", &endNode);

       addEdge(graph, startNode, endNode);
       printMatrix(graph);
   }

    return 0;

}