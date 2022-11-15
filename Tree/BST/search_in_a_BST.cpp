
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


bool searchInBST_with_recursion(Node *root, int ITEM){
    if( ITEM==root->data ){
        return 1;
    }
    else if( ITEM>(root->data) ){
        if(root->right==NULL) return 0;
        root = root->right;
        searchInBST(root, ITEM);
    }
    else{
        if(root->left==NULL) return 0;
        root = root->left;
        searchInBST(root, ITEM);
    }
}

bool searchInBST_with_iteration(Node *root, int ITEM){

    while(root){
        if( ITEM==root->data ){
            return 1;
        }
        else if( ITEM>(root->data) ){
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return 0;
}


int main()
{
    Node *root = create_tree();

    int ITEM;
    cout<<"Enter a value: ";
    cin>>ITEM;

    int ans  = searchInBST_2(root, ITEM);

    if(ans)
        cout<<"Found"<<endl;
    else
        cout<<"Not found"<<endl;





    return 0;
}
