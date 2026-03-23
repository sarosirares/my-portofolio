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

NodeT *createBinTree(int branch, NodeT *parent)
{
    NodeT *p;
    int key;

    if(branch == 0)
        printf("Root identifier [0 to end] = ");
    else if(branch == 1)
            printf("Left child of %d [0 to end] = ", parent->key);
    else
        printf("Right child of %d [0 to end] = ", parent->key);
    scanf("%d", &key);
    if(key == 0)
        return NULL;
    else
    {
        p = (NodeT*)malloc(sizeof(NodeT));
        if(p == NULL)
            fatalError("Out of space in createBinTree");
        p->key = key;
        p->left = createBinTree(1, p);
        p->right = createBinTree(2, p);
    }
    return p;
}


int main()
{
    NodeT *root;

    root = createBinTree(0, NULL);
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

/*

NodeT *createBinTree()
{
    NodeT *p;
    char c;

    printf("\nIntroduce the node id: ");
    scanf("%c", &c);

    if(c == "*")
        return NULL;
    else
    {
        p = (NodeT*)malloc(sizeof(NodeT));
        if(p == NULL)
            fatalError("Out of space in createBinTree");
        p->id = c;
        p->left = createBinTree();
        p->right = createBinTree();
    }
    return p;
}

*/
