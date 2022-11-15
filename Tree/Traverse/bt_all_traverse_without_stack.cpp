
#include<iostream>
using namespace std;

typedef struct node Node;

struct node{
    int data;
    Node *left;
    Node *right;
};

Node *create_node(int ITEM){
    Node *new_node = (Node *)malloc(sizeof(Node));

    new_node->data = ITEM;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

//let's create this tree
//       2
//     /   \
//    7     9
//   / \     \
//  1   6     8
//     / \   / \
//    5  10 3   4

Node *create_tree(){
    Node *two = create_node(2);
    Node *seven = create_node(7);
    Node *nine = create_node(9);
    Node *one = create_node(1);
    Node *six = create_node(6);
    Node *eight = create_node(8);
    Node *five = create_node(5);
    Node *ten = create_node(10);
    Node *three = create_node(3);
    Node *four = create_node(4);

    two->left = seven;
    two->right = nine;

    seven->left = one;
    seven->right = six;

    six->left = five;
    six->right = ten;

    nine->right = eight;

    eight->left = three;
    eight->right = four;

    return two; //returning the root of the tree
                //i can return random node and print child and data of that node
}


//preorder traversal of the above tree
void pre_order(Node *node){
    printf("%d ", node->data);

    if(node->left != NULL){
        pre_order(node->left);
    }
    if(node->right != NULL){
        pre_order(node->right);
    }
}

//postorder traversal of the above tree
void post_order(Node *node){

    if(node->left != NULL){
        post_order(node->left);
    }
    if(node->right != NULL){
        post_order(node->right);
    }
    printf("%d ", node->data);
}

//inorder traversal of the above tree
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

    cout<<"preorder travese: "<<endl;
    pre_order(root);

    cout<<"\n\npostrder travese: \n";
    post_order(root);

    cout<<"\n\ninorder travese: \n";
    in_order(root);

    return 0;
}
