
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


// Iterative function for inorder tree traversal
void inorder_stack(Node *root)
{
    stack<Node*> s;

    Node *curr = root;

    while (curr != NULL || !s.empty())
    {
        // Reach the left most Node of the curr Node
        while (curr !=  NULL)
        {
            /* place pointer to a tree node on
               the stack before traversing
              the node's left subtree */
            s.push(curr);
            curr = curr->left;
        }

        /* Current must be NULL at this point */
        curr = s.top();
        s.pop();

        cout << curr->data << " ";

        /* we have visited the node and its
           left subtree.  Now, it's right
           subtree's turn */
        curr = curr->right;

    } /* end of while */
}

int main()
{
    Node *root = create_tree();

    inorder_stack(root);
    //output
    //1 7 5 6 10 2 9 3 8 4

    return 0;
}
