#include <stdio.h>
#include <stdlib.h>

typedef struct node_type
{
    char id;
    int key;
    struct node_type *left, *right;
}NodeT;

void fatalError(const char *msg)
{
    printf(msg);
    printf("\n");
    exit(1);
}

void preorder(NodeT *p, int level)
{
    int i;

    if(p != NULL)
    {
        for(i = 0; i <= level; i++)
            printf(" ");
        printf("%2.2d\n", p->key);
        preorder(p->left, level + 1);
        preorder(p->right, level + 1);
    }
}

void inorder(NodeT *p, int level)
{
    int i;

    if(p != NULL)
    {
        inorder(p->left, level + 1);
        for(i = 0; i <= level; i++)
            printf(" ");
        printf("%2.2d\n", p->key);
        inorder(p->right, level + 1);
    }
}

void postorder(NodeT *p, int level)
{
    int i;

    if(p != NULL)
    {
        postorder(p->left, level + 1);
        postorder(p->right, level + 1);
        for(i = 0; i <= level; i++)
            printf(" ");
        printf("%2.2d\n", p->key);
    }
}

NodeT *creBalBinTree(int nbOfNodes)
{
    NodeT *p;
    int nLeft, nRight;

    if(nbOfNodes == 0) return NULL;
    else
    {
        nLeft = nbOfNodes / 2;
        nRight = nLeft - 1;
        p = (NodeT*)malloc(sizeof(NodeT));
        printf("]nNode identifier= ");
        scanf("%d", &(p->key));
        p->left = creBalBinTree(nLeft);
        p->right - creBalBinTree(nRight);
    }
    return p;
}


int main()
{
    NodeT *root;
    int nbOfNodes = 0;

    printf("\nNumber of nodes in the tree= ");
    scanf("%d", &nbOfNodes);
    creBalBinTree(nbOfNodes);
    while('\n' != getc(stdin));
    printf("\nPreorder listing\n");
    preorder(root, 0);
    printf("Press Enter to continue.");
    while('\n' != getc(stdin));
    printf("\nInorder listing\n");
    inorder(root, 0);
    printf("Press Enter to continue.");
    while('\n' != getc(stdin));
    printf("\nPostorder listing\n");
    postorder(root, 0);
    printf("Press Enter to continue.");
    while('\n' != getc(stdin));
    return 0;
}
