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

    Node * inorderSuccessor(Node* node,int &n) {
        Node * nodeTemp = node;
        while(nodeTemp!=NULL){
            node = nodeTemp;
            nodeTemp=nodeTemp->left;
            n=0;
        }
        return node;
    }
    Node * BSTReplace(Node * node,int n){
        if(node->left!=NULL && node->right!=NULL){
            return inorderSuccessor(node,n);
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
    If d=0, returns the right child of parent;
    else returns the left child of the parent.
*/

    Node* sibling(int d,Node * node){
        if(d==0){
            return node->parent->right;
        }
        return node->parent->left;
    }


/*
    Fixing double black nodes. 

*/    
    void fixDblack(Node **root,Node* node){
        //  If it is the root node, reduce it to BLACK.
        if(node->parent==NULL){
            node->color = "BLACK";
            return;
        }
        // Check whether it is a left child or a right child
        int d;
        if(node->parent->left==node){
            d=0;
        }
        else{
            d=1;
        }
        // If there are no siblings move the operation to parent
        if(sibling(d,node)==NULL){
            fixDblack(root,node->parent);
        }
        else{
            // If there is a sibling to the right
            if(d==0){
                Node* sibling = node->parent->right;
                //If the sibling is RED
                if(sibling->color=="RED"){
                    leftRotate(root,node->parent);
                    node->parent->parent->color = "BLACK";
                    node->color="BLACK";
                    if(node->parent->right!=NULL){
                        node->parent->right->color = "RED";
                    }
                }
                // Black sibling
                else{
                    // If there are no children to the siblings or if they arent RED, move the operation to parent.
                    if(sibling->right!=NULL&&sibling->right->color=="RED"){
                        leftRotate(root,node->parent);
                        sibling->right->color="BLACK";
                        node->color="BLACK"; // FROM DBLACK
                    }
                    else if(sibling->left!=NULL&&sibling->left->color=="RED"){
                        rightRotate(root,sibling);
                        leftRotate(root,sibling->parent);
                        sibling->left->color = "BLACK";
                        node->color="BLACK"; // FROM DBLACK
                    }
                    else{
                        node->color="BLACK";
                        node->parent->color = "DBLACK";
                        sibling->color = "RED";
                        fixDblack(root,node->parent);
                    }
                }
            }
            // If there is a sibling to the left
            else{
                Node *sibling = node->parent->left;
                //If the sibling is RED
                if(sibling->color=="RED"){
                    rightRotate(root,node->parent);
                    node->parent->parent->color = "BLACK";
                    node->color="BLACK";
                    if(node->parent->left!=NULL){
                        node->parent->left->color = "RED";
                    }
                }
                // Black sibling
                else{
                    // If there are no children to the siblings or if they arent RED, move the operation to parent.
                    if(sibling->right!=NULL&&sibling->right->color=="RED"){
                        leftRotate(root,node->parent);
                        sibling->right->color="BLACK";
                        node->color="BLACK"; // FROM DBLACK
                    }
                    else if(sibling->left!=NULL&&sibling->left->color=="RED"){
                        rightRotate(root,sibling);
                        leftRotate(root,sibling->parent);
                        sibling->left->color = "BLACK";
                        node->color="BLACK"; // FROM DBLACK
                    }
                    else{
                        node->color="BLACK";
                        node->parent->color = "DBLACK";
                        sibling->color = "RED";
                        fixDblack(root,node->parent);
                    }
                }
            }
        }
    }
    

/*
    deleteFixup is the balancer after a delete operation

    Subsequent arguments are on a need to give basis
*/
    void deleteFixup(Node **root,Node* node1){
        if(node1->color=="RED"){
            node1->color="BLACK";
        }
        else{
            node1->color = "DBLACK";
            fixDblack(root,node1);
        }
    }

/*
    Delete node with val 'n'

    **root -> to alter root on needed
    *head -> the iterator
    key -> the key to be found
    *parent -> the parent of the node
    d -> the decider to move left or right

*/
    void deleteNode(Node ** root,Node * head,int key, Node * parent, int d){
        if(head==NULL)
            return;
        if(key<head->key) {
            deleteNode(root,head->left,key,head,0);
        }
        else if(key>head->key){
            deleteNode(root,head->right,key,head,1);
        }
        else{
            //Leaf node deletion
            if(head->left==NULL&&head->right==NULL){
                if(head->parent!=NULL){
                    if(head->parent->right==head){
                        head->parent->right=NULL;
                    }
                    else {
                        head->parent->left=NULL;
                    }
                    Node* par = head->parent;
                    int col = 0;
                    if(head->color=="RED")
                        col=1;
                    delete head;
                    // Only black nodes deleted must be checked
                    if(col==0){
                        deleteFixup(root,par);
                    }
                }
                else{
                    * root = NULL;
                    delete head;
                    return;
                }
            }
            // One child in the right deletion
            else if(head->left==NULL){
                if(head->parent!=NULL){
                    Node *u = head;
                    Node *v = head->right;
                    int col = 0;
                    if(u->color=="RED"){
                        col=1;
                    }
                    if(head->parent->right==head){
                        head->parent->right = head->right;
                        head->right->parent = head->parent;
                        Node * temp = head;
                        head=head->right;
                        delete temp;
                    }
                    else if(head->parent->left==head){
                        head->parent->left = head->right;
                        head->right->parent = head->parent;
                        Node * temp = head;
                        head=head->right;
                        delete temp;
                    }
                    // If the deleted node is RED, it is already balanced
                    if(col==0){
                        deleteFixup(root,head);
                    }
                }
                else{
                    head->right->parent = NULL;
                    * root = head->right;
                    delete head;
                    return;
                }
            }
            // One child in the left deletion
            else if(head->right==NULL){
                if(head->parent!=NULL){
                    Node *u= head;
                    Node *v= head->left;
                    int col = 0;
                    if(u->color=="RED"){
                        col=1;
                    }
                    if(head->parent->right==head){
                        head->parent->right = head->left;
                        head->left->parent = head->parent;
                        Node * temp = head;
                        head=head->left;
                        delete temp;
                    }
                    else if(head->parent->left==head){
                        head->parent->left = head->left;
                        head->left->parent = head->parent;
                        Node * temp = head;
                        head=head->left;
                        delete temp;
                    }
                    if(col==0){
                        deleteFixup(root,head);
                    }
                }
                else{
                    head->right->parent = NULL;
                    * root = head->left;
                    delete head;
                    return;
                }
            }
            else {
                int n = 1;
                Node * nodeTemp = new Node;
                nodeTemp = inorderSuccessor(head->right,n);
                head->key = nodeTemp->key;
                deleteNode(root,head->right,nodeTemp->key,head->parent,n); 
            }
        }

        if(head==NULL)
            return;
    }

}  // namespace rbtree

