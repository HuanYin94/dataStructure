#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

#define NUM 100

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}tree;

node *root, *p, *q[NUM];

int sum = 0;
int m = sizeof(tree);

void insertData(int x)
{
    node *p, *q, *s;
    s = (tree*)malloc(m);
    s->data = x;
    s->lchild = NULL;
    s->rchild = NULL;

    if(!root)
        root = s;

    p = root;

    while(p)
    {
        q = p;
        if(p->data == x)
        {
            return;
        }
        else if(x < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }

    if(x < q->data)
        q->lchild = s;
    else
        q->rchild = s;
}

void printTree(node *root)
{
    if(root)
        cout<<root->data<<" ";
    if(root->lchild)
        printTree(root->lchild);
    if(root->rchild)
        printTree(root->rchild);
}

void deleteNode(node *&no)
{
    if(no->lchild)
        deleteNode(no->lchild);
    if(no->rchild)
        deleteNode(no->rchild);

    free(no);
    no = NULL;
}

void deleteSubTree(int input, node *&n)
{
    if(n)
    {
        if(n->data == input)
        {
            deleteNode(n);
            return;
        }

        if(n->lchild)
            deleteSubTree(input, n->lchild);

        if(n->rchild)
            deleteSubTree(input, n->rchild);
    }
}

int main()
{
    int i = 1;
    int input;
    root = NULL;

    cout<<"Enter '0' to exit:  "<<endl;

    do
    {
        cout<<"Input the "<<i<<" Number  ";
        i++;
        scanf("%d", &input);

        if(input ==  0)
        {
            cout<<"Setup the tree, The tree is: "<<endl;
        }
        else
            insertData(input);

    }while(input!=0);

    printTree(root);

    cout<<""<<endl;

    cout<<"Enter the node you delete:  ";
    scanf("%d", &input);

    deleteSubTree(input, root);

    cout<<"After deleted:  "<<endl;
    printTree(root);
    cout<<""<<endl;
}
