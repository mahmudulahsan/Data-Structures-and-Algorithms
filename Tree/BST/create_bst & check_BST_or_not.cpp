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

//check a tree binary search tree or not
int isBST(Node *root){
    static Node *prev = NULL;
    if(root){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        isBST(root->right);
    }
    else{
        return 1;
    }
}


//inorder traversal of a BST gives an ascending sorted array
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

    in_order(root);

    cout<<endl;

    if(isBST(root)){
        cout<<"it's a BST"<<endl;
    }
    else{
        cout<<"not an BST"<<endl;
    }

    return 0;
}
