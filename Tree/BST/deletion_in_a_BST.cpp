
#include<iostream>

using namespace std;

typedef struct node Node;

struct node{
    int data;
    Node *left;
    Node *right;
};

Node *create_node(int ITEM){
    //Node *new_node = (Node *)malloc(sizeof(Node)); // for c
    Node *new_node = new Node();

    new_node->data = ITEM;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

//let's create this tree
//        10
//      /    \
//     5      17
//    / \     / \
//   3   7   12  19
//  / \
// 1   4

Node *create_tree(){
    Node *ten = create_node(10);
    Node *five = create_node(5);
    Node *seventeen = create_node(17);
    Node *three = create_node(3);
    Node *seven = create_node(7);
    Node *twelve = create_node(12);
    Node *nineteen = create_node(19);
    Node *one = create_node(1);
    Node *four = create_node(4);

    ten->left = five;
    ten->right = seventeen;

    five->left = three;
    five->right = seven;

    seventeen->left = twelve;
    seventeen->right = nineteen;

    three->left = one;
    three->right = four;

    return ten;// Returning the root of the tree
                //i can return random node and print child and data of that node
}

//find inorder predecessor
Node *findInOrderPredecessor(Node *root){
    root = root->left;
    while(root->right!=NULL){
        root = root->right;
    }
    return root;
}

//delete a node from BST
Node *deleteInBST(Node *root, int ITEM){

    Node *in_pre;
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        delete root;
        return NULL;
    }

    //searching for the node to be deleted
    if(ITEM < root->data){
        root->left = deleteInBST(root->left, ITEM);
    }
    else if(ITEM > root->data){
        root->right = deleteInBST(root->right, ITEM);
    }
    //deletion when the node is found
    else{
        in_pre = findInOrderPredecessor(root);
        root->data = in_pre->data;
        root->left = deleteInBST(root->left, in_pre->data);
    }
    return root;
}

void in_order(Node *node){

    if(node->left != NULL){
        in_order(node->left);
    }
    printf("%d ", node->data);
    if(node->right != NULL){
        in_order(node->right);
    }
}


int main()
{
    Node *root = create_tree();

    cout<<"Inorder Traversal: ";
    in_order(root); //ensuring insertion is right or wrong

    cout<<endl;

    while(1){
        int ITEM;
        cout<<"Enter a value: ";
        cin>>ITEM;

        deleteInBST(root, ITEM);

        cout<<"Inorder Traversal(After deletion): ";
        in_order(root);
        cout<<endl;
    }




    return 0;
}


