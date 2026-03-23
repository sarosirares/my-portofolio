#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef int ElementType;

typedef struct node_type
{
    KeyType key;
    ElementType info ;
    struct node_type *left , *right ;
}NodeT;

NodeT *root;

void nInsert(KeyType givenKey)
{
    NodeT *p, *q;

    p = (NodeT*)malloc(sizeof(NodeT));
    p->key = givenKey;
    p->left = p->right = NULL;
    if(root == NULL)
    {
        root = p;
        return;
    }
    q = root;
    for( ; ; )
    {
        if(givenKey < q->key)
        {
            if(q->left == NULL)
            {
                q->left = p;
                return;
            }
            q = q->left;
        }
        else
        if(givenKey > q->key)
        {
            if(q->right = NULL)
            {
                q->right = p;
                return;
            }
            q = q->right;
        }
        else
        {
            free(p);
        }
    }
}

NodeT* find(NodeT* root, KeyType givenKey)
{
    NodeT *p;

    if(root == NULL) return NULL;
    for(p = root; p != NULL; )
    {
        if(givenKey == p->key) return p;
        else
        if(givenKey < p->key) p = p->left;
        else                  p = p->right;
    }
    return NULL;
}

void delTree(NodeT* root)
{
    if(root != NULL)
    {
        delTree(root->left);
        delTree(root->right);
        free(root);
    }
}

NodeT* buildOptTree(int i, int j)
{
    NodeT* p;

    if(i == j) p = NULL;
    else
    {
        p = (NodeT*)malloc(sizeof(NodeT));
        p->left = buildOptTree(i, r[i][j] - 1);
        p->key = keys[roots[i][j]]
    }
}

void preorder(NodeT *p)
{
    if(p != NULL)
    {
        preorder(p->left);
        preorder(p->right);
    }
}
void inorder(NodeT* p)
{
    if(p != NULL)
    {
        inorder(p->left);
        inorder(p->right);
    }
}
void postorder(NodeT* p)
{
    if(p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
