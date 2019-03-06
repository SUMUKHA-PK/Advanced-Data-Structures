#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1 << (n))
using namespace std;
 
// Node Declaration
 
struct avl_node
{
    int data;
    struct avl_node *left;
    struct avl_node *right;
    struct avl_node *parent;
    int height;
};
 
typedef struct avl_node Node;




/****************************************************
 * Function Declarations: 
 ****************************************************/

Node* populateTree(Node *root, int treeNumber);
Node *case1(Node *root1, Node* root2);
Node *case2(Node *root1, Node* root2);
Node* mergeTrees(Node* root1, Node* root2);
int findSmallestKey(Node* root);
void displayTree(Node *ptr);
Node * createNode(int key);

 

////////////////////////////////////////////////////////////////

int height(avl_node *temp);
int diff(avl_node *temp);
avl_node *rr_rotation(avl_node *parent);
avl_node *ll_rotation(avl_node *parent);
avl_node *lr_rotation(avl_node *parent);
avl_node *rl_rotation(avl_node *parent);
avl_node *balance(avl_node *temp);
avl_node *insert(avl_node *root, int value);
void display(avl_node *ptr, int level);
void inorder(avl_node *tree);
void preorder(avl_node *tree);
void postorder(avl_node *tree);


Node* deleteNode(Node* root, int key);
Node * minValueNode(Node* node);


// Class Declaration
 

int main()
{
    
    // Node* root1 = new Node;
    // Node* root2 = new Node;

    Node *root1 = populateTree(NULL, 1);
    Node *root2 = populateTree(NULL, 2);

    std::cout<<"\n\n"<<std::endl;

    std::cout<<"Tree-1: "<<std::endl;
    displayTree(root1);
    std::cout<<"\n\n"<<std::endl;


    std::cout<<"Tree-2: "<<std::endl;
    displayTree(root2);
    std::cout<<"\n\n"<<std::endl;

    std::cout<<"\nMerging trees."<<std::endl;

    Node *root = mergeTrees(root1, root2);

    std::cout<<"New merged tree: "<<std::endl;
    displayTree(root);

    std::cout<<"\n\n"<<std::endl;

    return 0;
}
 
/******************************************************
 * 
 * The below functions are problem1 functions. 
 * 
 ******************************************************/

int findSmallestKey(Node* root) {

    if(root->left == NULL)
        return root->data;

    else 
        return findSmallestKey(root->left);
}

Node* populateTree(Node *root, int treeNumber) {

    std::cout<<"Populate Tree-"<<treeNumber<<": "<<std::endl;

    int key, choice, flag = 0;

    Node *newroot;

    if(treeNumber == 2) {
        std::cout<<"Smallest key of this tree should be larger than largest key of the other tree."<<std::endl;
    }

    while(1) {

        std::cout<<"1. Insert a node"<<std::endl;
        std::cout<<"2. I am done with tree-"<<treeNumber<<std::endl;

        std::cin>>choice;

        if(choice == 1) {
            std::cout<<"Enter a key: "<<std::endl;
            std::cin>>key;
            
            if(flag == 0) {
                newroot = insert(NULL, key);
                flag = 1;
            }
            else
                newroot = insert(newroot, key);

        }
        else if(choice == 2) {
            return newroot;
        }
    }

    return newroot;
}



Node *case1(Node *root1, Node* root2) {

    int x = findSmallestKey(root2);
    
    std::cout<<height(root2)<<std::endl;
    
    deleteNode(root2, x);

    displayTree(root2);

    std::cout<<height(root2)<<std::endl;

    int h = height(root2);



    int h1 = height(root1);

    Node* v = root1;
    Node *v_parent;

    // In the internet, h1 > h+1 is given which I think is not correct. h1 >= h is correct. 
    while(h1 >= h) {

        if(diff(v) == -1)
            h1 = h - 2;
        else
            h1 = h - 1;

        v_parent = v;    
        v = v->right;
    }

    // Root of the new tree. 
    Node* root3 = createNode(x);

    // Left Subtree is rooted at v. 
    root3->left = v;

    // Right Subtree is t2 itself. 
    root3->right = root2;

    std::cout<<"\n\n\n"<<std::endl;
    displayTree(root3);

    v_parent->right = root3;

    std::cout<<"\n\n\nfinal tree without balancing: "<<std::endl;

    // This display is exactly what I wanted. 
    displayTree(root1);

    std::cout<<"\n\n\n"<<std::endl;

    // Then this fucked up everything!
    balance(root1);

    // That fuckup is demonstrated by this display.
    displayTree(root1);

    return root1;
}

Node* case2(Node *root1, Node *root2) {
    std::cout<<"Under construction!"<<std::endl;
}


// t2 - an AVL Tree
// t1 - an AVL Tree whose largest key is lessthan smallest key of t2. 

// root1 - root of t1
// root2 - root of t2
Node* mergeTrees(Node* root1, Node* root2) {

    if(height(root1) >= height(root2))
        return case1(root1, root2);
    
    else
        return case2(root1, root2);
}


void displayTree(Node *ptr) {

        std::cout<<ptr->data;
        // if(ptr->color == RED)
        //     std::cout<<"R";

        // else if(ptr->color == BLACK)
        //     std::cout<<"B";

        if(ptr->left == NULL && ptr->right == NULL)
            return;

        else if(ptr->left != NULL && ptr->right == NULL) {

            std::cout<<"(";
            displayTree(ptr->left);
            std::cout<<",X)";
        }

        else if(ptr->left == NULL && ptr->right != NULL) {

            std::cout<<"(X,";
            displayTree(ptr->right);
            std::cout<<")";
        }

        else {
            std::cout<<"(";
            displayTree(ptr->left);
            std::cout<<",";
            displayTree(ptr->right);
            std::cout<<")";
        }
    }


Node * createNode(int key){

        Node * node = new Node;
        node->data = key;
        node->left = NULL;
        node->right = NULL;
        return node;
    }




/*****************************************************
 * 
 * The below functions are AVL Tree related functions. 
 * 
 *****************************************************/


// Height of AVL Tree
 
int height(avl_node *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
 
 
// Height Difference
 
int diff(avl_node *temp)
{
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}
 
 
// Right- Right Rotation
 
avl_node *rr_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
 
// Left- Left Rotation
 
avl_node *ll_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
 
 
// Left - Right Rotation
 
avl_node *lr_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}
 
 
// Right- Left Rotation
 
avl_node *rl_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}
 
 
// Balancing AVL Tree
 
avl_node *balance(avl_node *temp)
{
    int bal_factor = diff (temp);
    if (bal_factor > 1)
    {
        if (diff (temp->left) > 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
    }
    else if (bal_factor < -1)
    {
        if (diff (temp->right) > 0)
            temp = rl_rotation (temp);
        else
            temp = rr_rotation (temp);
    }
    return temp;
}
 
 
// Insert Element into the tree
 
avl_node *insert(avl_node *root, int value)
{
    if (root == NULL)
    {
        root = new avl_node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
        root = balance (root);
    }
    else if (value >= root->data)
    {
        root->right = insert(root->right, value);
        root = balance (root);
    }
    return root;
}
 
 
// Display AVL Tree
 
    // void display(avl_node *ptr, int level)
    // {
    //     int i;
    //     if (ptr!=NULL)
    //     {
    //         display(ptr->right, level + 1);
    //         printf("n");
    //         if (ptr == root)
    //         cout<<"Root -> ";
    //         for (i = 0; i < level && ptr != root; i++)
    //             cout<<"        ";
    //         cout<<ptr->data;
    //         display(ptr->left, level + 1);
    //     }
    // }
 
 
// Inorder Traversal of AVL Tree
 
void inorder(avl_node *tree)
{
    if (tree == NULL)
        return;
    inorder (tree->left);
    cout<<tree->data<<"  ";
    inorder (tree->right);
}
 
// Preorder Traversal of AVL Tree
 
void preorder(avl_node *tree)
{
    if (tree == NULL)
        return;
    cout<<tree->data<<"  ";
    preorder (tree->left);
    preorder (tree->right);
 
}
 
 
//  Postorder Traversal of AVL Tree
 
void postorder(avl_node *tree)
{
    if (tree == NULL)
        return;
    postorder ( tree ->left );
    postorder ( tree ->right );
    cout<<tree->data<<"  ";
}

/*******************************************
 * 
 * These are PK's functions!
 * 
 *******************************************/
Node* deleteNode(Node* root, int key) 
{ 
    // STEP 1: PERFORM STANDARD BST DELETE 
  
    if (root == NULL) 
        return root; 
  
    // If the key to be deleted is smaller than the 
    // root's key, then it lies in left subtree 
    if ( key < root->data ) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the 
    // root's key, then it lies in right subtree 
    else if( key > root->data ) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is 
    // the node to be deleted 
    else
    { 
        // node with only one child or no child 
        if( (root->left == NULL) || (root->right == NULL) ) 
        { 
            Node *temp = root->left ? root->left : 
                                             root->right; 
  
            // No child case 
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else // One child case 
             *root = *temp; // Copy the contents of 
                            // the non-empty child 
            free(temp); 
        } 
        else
        { 
            // node with two children: Get the inorder 
            // successor (smallest in the right subtree) 
            Node* temp = minValueNode(root->right); 
  
            // Copy the inorder successor's data to this node 
            root->data = temp->data; 
  
            // Delete the inorder successor 
            root->right = deleteNode(root->right, temp->data); 
        } 
    } 
  
    // If the tree had only one node then return 
    if (root == NULL) 
      return root; 
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE 
    root->height = 1 + max(height(root->left), 
                           height(root->right)); 
  
    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to 
    // check whether this node became unbalanced) 
    int balance = diff(root); 
  
    // If this node becomes unbalanced, then there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && diff(root->left) >= 0) 
        return rr_rotation(root); 
  
    // Left Right Case 
    if (balance > 1 && diff(root->left) < 0) 
    { 
        root->left =  ll_rotation(root->left); 
        return rr_rotation(root); 
    } 
  
    // Right Right Case 
    if (balance < -1 && diff(root->right) <= 0) 
        return ll_rotation(root); 
  
    // Right Left Case 
    if (balance < -1 && diff(root->right) > 0) 
    { 
        root->right = rr_rotation(root->right); 
        return ll_rotation(root); 
    } 
  
    return root; 
} 

Node * minValueNode(Node* node) 
{ 
    Node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 
  
    return current; 
} 