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

// An iterative function to do postorder traversal of a given binary tree
void postorder_stack(Node* root)
{
    // Check for empty tree
    if (root == NULL)
        return;

    stack<Node*> st;

    do
    {
        // Move to leftmost node
        while (root)
        {
            // Push root's right child and then root to stack.
            if (root->right){
                st.push(root->right);
            }

            st.push(root);

            // Set root as root's left child
            root = root->left;
        }

        // Pop an item from stack and set it as root
        //st.pop(root);
        root = st.top();
        st.pop();


        // If the popped item has a right child and the right child is not
        // processed yet, then make sure right child is processed before root
        if (root->right && st.top() == root->right)
        {
            st.pop(); // remove right child from stack
            st.push(root); // push root back to stack
            root = root->right; // change root so that the right
                                // child is processed next
        }
        else // Else print root's data and set root as NULL
        {
            cout<<root->data<<" ";
            root = NULL;
        }
    } while (!st.empty());
}

int main()
{
    Node *root = create_tree();

    postorder_stack(root);
    //output
    //1 5 10 6 7 3 4 8 9 2

    return 0;
}
