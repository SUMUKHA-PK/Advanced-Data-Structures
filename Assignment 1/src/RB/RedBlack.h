
using namespace std;

namespace rbtree {
    
    typedef struct node {
        struct node * left = NULL;
        struct node * right = NULL;
        struct node * parent = NULL;
        string color;
        int key;
    } Node;
    
    void inorder(Node * head) {
        
        if(head==NULL) {
            cout<<endl;
            return;
        }
        
        inorder(head->left);
        cout<<"Node-> Value: "<<head->key<<" Color: "<<head->color;
        inorder(head->right);
    }
    
    int height(Node * head) {

        if(head == NULL) {
            return 0;
        }
        int lh = height(head->left);
        int rh = height(head->right);

        return 1 + max(lh,rh);
    }

    void printOneLevel(Node * node, int level) {

        if(node == NULL) {
            return;
        }

        if(level==1) {
            cout<<node->key<<" ";
        }
        else if(level>1) {
            printOneLevel(node->left,level-1);
            printOneLevel(node->right,level-1);
        }
    }

    void levelOrder(Node * node) {
        
        int h = height(node);
        for(int i=1;i<=h;i++) 
            printOneLevel(node,i);
        cout<<endl;
    }

/*
    Left rotate at node x. 
    Usage : leftRotate(&root,nodeToBeRotated);
*/

    void leftRotate(Node ** root, Node * x) {
        Node * y = x->right;
        Node * T2 = y->left;

        y->left = x;
        x->right = T2;
        if(x->right!=NULL) x->right->parent = x;

        if(x->parent!=NULL){
            if(x->parent->right==x){
                x->parent->right =y;
                y->parent = x->parent;
            }
            else if (x->parent->left==x){
                x->parent->left =y;
                y->parent = x->parent;
            }
        }
        else {
            y->parent = NULL;
            *root = y;
        }
        x->parent = y;
    }

/*
    Right rotate at node x. 
    Usage : rightRotate(&root,nodeToBeRotated); root is Node*
*/

    void rightRotate(Node ** root, Node * y) {
        Node * x = y->left;
        Node * T2 = x->right;

        x->right = y;
        y->left = T2;
        if(y->left!=NULL) y->left->parent=y;

        if(y->parent!=NULL){
            if(y->parent->right==y){
                y->parent->right =x;
                x->parent = y->parent;
            }
            else if (y->parent->left==y){
                y->parent->left =x;
                x->parent = y->parent;
            }
        }
        else{
            x->parent=NULL;
            *root = x;
        }
        y->parent = x;
    }

    Node * createNode(int val) {
        Node * node = new Node;
        node ->key = val;
        return node;
    }

/*
    Balance the RB Tree.
    Usage: insertFixup(&root,nodeToBeFixed); (root is Node *)
*/

    void insertFixup(Node ** head, Node * z) {
        // If the fixup has reached head node or the one below end the fixup process
        if(z->parent!=NULL){
            if(z->parent->parent!=NULL){
                // Continue only if the current and parents colour is RED
                while(z->parent->color == "RED") {
                    // If uncle is to the left of grandpa
                    if(z->parent == z->parent->parent->left) {
                        Node * y = z->parent->parent->right;
                        // Operate only if uncle of node exists
                        // The case where nodes parent and uncle are red.
                        if(y!=NULL&&y->color=="RED"){
                            z->parent->color = "BLACK" ;
                            y->color = "BLACK";
                            z->parent->parent->color = "RED";
                            z = z->parent->parent;
                        }
                        //Since there is no uncle, move parent and balance colours
                        else{
                            if(z==z->parent->right){
                                leftRotate(head,z->parent);
                                rightRotate(head,z->parent);
                                z->left->color = "RED";
                                z->right->color = "RED";
                                z->color = "BLACK";
                            }
                            else{
                                rightRotate(head,z->parent->parent);
                                z->parent->color = "BLACK";
                                z->parent->right->color = "RED";
                            }
                        }
                    }
                    // If uncle is to the right of grandpa
                    else if(z->parent == z->parent->parent->right) {
                        Node * y = z->parent->parent->left;
                        if(y!=NULL&&y->color=="RED"){
                            z->parent->color = "BLACK" ;
                            y->color = "BLACK";
                            z->parent->parent->color = "RED";
                            z = z->parent->parent;
                        }
                        else{
                            if(z==z->parent->right){
                                leftRotate(head,z->parent->parent);
                                z->parent->color = "BLACK";
                                z->parent->left->color = "RED";
                            }
                            else{                        
                                rightRotate(head,z->parent);
                                leftRotate(head,z->parent);
                                z->left->color = "RED";
                                z->right->color = "RED";
                                z->color = "BLACK";
                            }    
                        }
                    }
                    //Corner case check: If the traversal reaches head node, colour it black and exit
                    if(z->parent==NULL){
                        z->color = "BLACK";
                        break;
                        if(z->parent->parent==NULL){
                            z->color = "BLACK";
                            break;
                        }
                    }
                }
            }
        }
    }

/*
    Insert node at location.
    Usage : insertNode(&root,root,node,NULL,-1);
    d -> decider, starts at -1, used to attach parent to the node
    parent -> parent of node, decided later, pass NULL in beginning
*/
    void insertNode(Node** root,Node * head,Node * node, Node * parent, int d){
        if(head == NULL) {
            if(d==0) {
                parent->left = node;
                node->parent = parent;
                node->color = "RED";
            }
            else if(d==1) {
                parent->right = node;
                node->parent = parent;
                node->color = "RED";
            }
            else {
                head = node;
                head->color = "BLACK";
                head->parent = NULL;
            }
            return;
        }

        if(node->key<head->key){
            insertNode(root,head->left,node,head,0);
        }
        else{
            insertNode(root,head->right,node,head,1);
        }
        insertFixup(root, node);
    } 

    Node * inorderSuccessor(Node* node){

        Node * temp = node;
        temp=temp->right;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }

    Node * BSTReplace(Node * node,int n){
        if(node->left!=NULL && node->right!=NULL){
            return inorderSuccessor(node);
        }
        else if(node->left==NULL&&node->right==NULL){
            return NULL;
        }
        else if(node->left!=NULL){
            return node->left;
        }
        else{
            return node->right;
        }
    }

/*
    Delete node with val 'n'
*/
    void deleteNode(Node* root,int n){
        if(root==NULL)
            return;
        Node * temp = root, * temp1;
        while(temp!=NULL){
            temp1=temp;
            if(n<temp->key){
                temp=temp->left;
            }
            else if(n>temp->key){
                temp=temp->right;
            }
            else{
                break;
            }
        }
        if(temp1->key!=n){
            cout<<"No value found"<<endl;
            return;
        }

        Node * node = BSTReplace(temp,n);
        // The node to be deleted is a leaf node
        if(node==NULL){
            if(node->parent->color=="RED"){
                cout<<"Ws";
                delete node;
            }
            cout<<"W1s";
        }
        //Non leaf node
        else{
            cout<<"WTF"<<endl;
        }
    }
}

