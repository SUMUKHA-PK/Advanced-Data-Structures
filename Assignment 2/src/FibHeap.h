#include<bits/stdc++.h>
using namespace std;

namespace fibheap {

struct node {
    int n;
    int id;
    int degree;
    node *parent;
    node *child;
    node *left;
    node *right;
    char mark;
    char C;
};

int nH;
node *H;

node* InitializeHeap()
{
    node* np;
    np = NULL;
    return np;
}

/*
 * Create Node
 */

node* Create_node(int value, int id)
{
    node* x = new node;
    x->n = value;
    x->id = id;
    return x;
}

int Fibonnaci_link(node* H1, node* y, node* z)
{
    (y->left)->right = y->right;
    (y->right)->left = y->left;
    if (z->right == z)
        H1 = z;
    y->left = y;
    y->right = y;
    y->parent = z;
    if (z->child == NULL)
        z->child = y;
    y->right = z->child;
    y->left = (z->child)->left;
    ((z->child)->left)->right = y;
    (z->child)->left = y;
    if (y->n < (z->child)->n)
        z->child = y;
    z->degree++;
}

/*
 * Union Nodes in Fibonnaci Heap
 */

node* Union(node* H1, node* H2)
{
    node* np;
    node* H = InitializeHeap();
    H = H1;
    (H->left)->right = H2;
    (H2->left)->right = H;
    np = H->left;
    H->left = H2->left;
    H2->left = np;
    return H;
}

/*
 * Display Fibonnaci Heap
 */

int Display(node* H)
{
    node* p = H;
    if (p == NULL)
    {
        cout<<"The Heap is Empty"<<endl;
        return 0;
    }
    cout<<"The root nodes of Heap are: "<<endl;
    do
    {
        cout<<p->n;
        p = p->right;
        if (p != H)
        {
            cout<<"-->";
        }
    }
    while (p != H && p->right != NULL);
    cout<<endl;
}

/*

 * Consolidate Node in Fibonnaci Heap

 */

int Consolidate(node* H1)

{

    int d, i;

    float f = (log(nH)) / (log(2));

    int D = f;

    node* A[D];

    for (i = 0; i <= D; i++)

        A[i] = NULL;

    node* x = H1;

    node* y;

    node* np;

    node* pt = x;

    do

    {

        pt = pt->right;

        d = x->degree;

        while (A[d] != NULL)

        {

            y = A[d];

            if (x->n > y->n)

            {

                np = x;

                x = y;

                y = np;

            }

            if (y == H1)

                H1 = x;

            Fibonnaci_link(H1, y, x);

            if (x->right == x)

                H1 = x;

                A[d] = NULL;

            d = d + 1;

        }

        A[d] = x;

        x = x->right;

    }

    while (x != H1);

    H = NULL;

    for (int j = 0; j <= D; j++)

    {

        if (A[j] != NULL)

        {

            A[j]->left = A[j];

            A[j]->right =A[j];

            if (H != NULL)

            {

                (H->left)->right = A[j];

                A[j]->right = H;

                A[j]->left = H->left;

                H->left = A[j];

                if (A[j]->n < H->n)

                H = A[j];

            }

            else

            {

                H = A[j];

            }

            if(H == NULL)

                H = A[j];

            else if (A[j]->n < H->n)

                H = A[j];

        }

    }

}

/*
 * Extract Min Node in Fibonnaci Heap
 */
node* Extract_Min(node* H1)
{
    node* p;
    node* ptr;
    node* z = H1;
    p = z;
    ptr = z;
    if (z == NULL)
        return z;
    node* x;
    node* np;
    x = NULL;
    if (z->child != NULL)
        x = z->child;
    if (x != NULL)
    {
        ptr = x;
        do
        {
            np = x->right;
            (H1->left)->right = x;
            x->right = H1;
            x->left = H1->left;
            H1->left = x;
            if (x->n < H1->n)
                H1 = x;
            x->parent = NULL;
            x = np;
        }
        while (np != ptr);
    }
    (z->left)->right = z->right;
    (z->right)->left = z->left;
    H1 = z->right;
    if (z == z->right && z->child == NULL)
        H = NULL;
    else
    {
        H1 = z->right;
        Consolidate(H1);
    }

    nH = nH - 1;

    return p;

}




/*
 * Initialize Heap
 */



/*
 * Insert Node
 */

node* Insert(node* H, node* x)
{
    x->degree = 0;
    x->parent = NULL;
    x->child = NULL;
    x->left = x;
    x->right = x;
    x->mark = 'F';
    x->C = 'N';
    if (H != NULL)
    {
        (H->left)->right = x;
        x->right = H;
        x->left = H->left;
        H->left = x;
        if (x->n < H->n)
            H = x;
    }
    else
    {
        H = x;
    }
    nH = nH + 1;
    return H;
}

/*
 * Link Nodes in Fibonnaci Heap
 */


/*

 * Find Nodes in Fibonnaci Heap

 */

node* Find(node* H, int k)

{

    node* x = H;

    x->C = 'Y';

    node* p = NULL;

    if (x->n == k)

    {

        p = x;

        x->C = 'N';

        return p;

    }

    if (p == NULL)

    {

        if (x->child != NULL )

            p = Find(x->child, k);

        if ((x->right)->C != 'Y' )

            p = Find(x->right, k);

    }

    x->C = 'N';

    return p;

}


 /*

 * Cut Nodes in Fibonnaci Heap

 */

int Cut(node* H1, node* x, node* y)

{

    if (x == x->right)

        y->child = NULL;

    (x->left)->right = x->right;

    (x->right)->left = x->left;

    if (x == y->child)

        y->child = x->right;

    y->degree = y->degree - 1;

    x->right = x;

    x->left = x;

    (H1->left)->right = x;

    x->right = H1;

    x->left = H1->left;

    H1->left = x;

    x->parent = NULL;

    x->mark = 'F';

}

 

/*

 * Cascade Cutting in Fibonnaci Heap

 */

int Cascase_cut(node* H1, node* y)

{

    node* z = y->parent;

    if (z != NULL)

    {

        if (y->mark == 'F')

        {

            y->mark = 'T';

	}

        else

        {

            Cut(H1, y, z);

            Cascase_cut(H1, z);

        }

    }

}

/*

 * Decrease key of Nodes in Fibonnaci Heap

 */

int Decrease_key(node*H1, int x, int k)

{

    node* y;

    if (H1 == NULL)

    {

        cout<<"The Heap is Empty"<<endl;

        return 0;

    }

    node* ptr = Find(H1, x);

    if (ptr == NULL)

    {

        cout<<"Node not found in the Heap"<<endl;

        return 1;

    }

    if (ptr->n < k)

    {

        cout<<"Entered key greater than current key"<<endl;

        return 0;

    }

    ptr->n = k;

    y = ptr->parent;

    if (y != NULL && ptr->n < y->n)

    {

        Cut(H1, ptr, y);

        Cascase_cut(H1, y);

    }

    if (ptr->n < H->n)

        H = ptr;

    return 0;

}



 


/*

 * Delete Nodes in Fibonnaci Heap

 */

int Delete_key(node* H1, int k)

{

    node* np = NULL;

    int t;

    t = Decrease_key(H1, k, -5000);

    if (!t)

        np = Extract_Min(H);

    if (np != NULL)

        cout<<"Key Deleted"<<endl;

    else

        cout<<"Key not Deleted"<<endl;

    return 0;

}



}   // namespace fibheap end.