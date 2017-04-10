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

node *root, *p, *q[NUM], *head, *first;

int sum = 0;
int m = sizeof(tree);

void PreOderTrvs(node *root)
{
    node *n;
    n= root;

    if(!n)
        return;

    if(n->lchild == NULL &&n->rchild == NULL)
    {
        head->rchild = n;
        head = n;
        return;
    }

    if(n->lchild)
        PreOderTrvs(n->lchild);

    if(n->rchild)
        PreOderTrvs(n->rchild);

    return;
}

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

node findTheLeft(node *root)
{
    node *n;
    n = root;

    if(n->lchild == NULL && n->rchild == NULL)
    {
        first = n;
    }

    if(n->lchild)
    {
        n = n->lchild;
        findTheLeft(n);
    }
    else if(n->rchild)
    {
        n = n->rchild;
        findTheLeft(n);
    }
    return *first;
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

void printList(node *left)
{
    node *n;
    n = left;
    while(n)
    {
        cout<<n->data<<" ";
        n = n->rchild;
    }
    cout<<""<<endl;
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

    findTheLeft(root);

    head = (node*)malloc(sizeof(node));

    PreOderTrvs(root);

    cout<<""<<endl;
    cout<<"The linked list is: "<<endl;

    printList(first);

}
