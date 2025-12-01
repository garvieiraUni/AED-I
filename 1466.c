#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

Node* insert(Node *root, int val){
    if(root == NULL){
        Node *n = (Node*) malloc(sizeof(Node));
        n->val = val;
        n->left = n->right = NULL;
        return n;
    }
    if(val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

int main(){
    int C;
    scanf("%d", &C);

    for(int caso = 1; caso <= C; caso++){
        int N;
        scanf("%d", &N);

        Node *root = NULL;
        for(int i = 0; i < N; i++){
            int x;
            scanf("%d", &x);
            root = insert(root, x);
        }

        // BFS usando fila
        Node *queue[600];
        int ini = 0, fim = 0;

        queue[fim++] = root;

        printf("Case %d:\n", caso);

        int printed = 0;

        while(ini < fim){
            Node *u = queue[ini++];

            if(printed) printf(" ");
            printf("%d", u->val);
            printed = 1;

            if(u->left)  queue[fim++] = u->left;
            if(u->right) queue[fim++] = u->right;
        }

        printf("\n\n");
    }

    return 0;
}
