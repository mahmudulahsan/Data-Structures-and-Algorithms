#include <iostream>
#include<stack>
using namespace std;

typedef struct node Node;

struct node{
    int data;

    Node *left;
    Node *right;
};

Node *create_node(int ITEM){
    Node *node = new Node();

    node->data = ITEM;

    node->left = NULL;
    node->right = NULL;

    return node;
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

// Iterative function to do Preorder traversal of the tree
void preorder_stack(Node* root)
{
    if (root == NULL)
        return;

    stack<Node*> st;

    // start from root node (set current node to root node)
    Node* curr = root;

    // run till stack is not empty or current is
    // not NULL
    while (!st.empty() || curr != NULL) {
        // Print left children while exist
        // and keep pushing right into the
        // stack.
        while (curr != NULL) {
            cout << curr->data << " ";

            if (curr->right){
                st.push(curr->right);
            }

            curr = curr->left;
        }

        // We reach when curr is NULL, so We
        // take out a right child from stack
        if (st.empty() == false) {
            curr = st.top();
            st.pop();
        }
    }
}

int main()
{
    Node *root = create_tree();

    preorder_stack(root);
    //output
    //2 7 1 6 5 10 9 8 3 4

    return 0;
}
