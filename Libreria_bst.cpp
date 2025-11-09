#include <iostream>
using namespace std;

struct Node
{

    int x;
    Node *right;
    Node *left;
    Node(int val)
    {
        x = val;
        right = nullptr;
        left = nullptr;
    }
};

void inserimento(Node *&root)
{

    cout << "Quanti valori vuoi inserire?" << endl;
    int n;
    cin >> n;
    int val;
    Node *curr = root;
    for (int i = 0; i < n; i++)
    {
        cout << "Inserisci il valore" << endl;
        cin >> val;
        while (curr->left != nullptr && curr->right != nullptr)
        {
            if (val > curr->x)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }
        if (val > curr->x)
        {
            curr->right = new Node(val);
        }
        else
        {
            curr->left = new Node(val);
        }
        curr = root;
    }
}
Node* ricerca(Node *root, int val) {
    if (root == nullptr)
        return nullptr;
    if (root->x == val)
        return root;
    else if (val < root->x)
        return ricerca(root->left, val);
    else
        return ricerca(root->right, val);
}

void preOrder(Node* node) {

if (node == nullptr) return;

cout << node->x << " ";

preOrder(node->left);

preOrder(node->right);

}



void inOrder(Node* node) {
    if (node == nullptr) return;
    inOrder(node->left);
    cout << node->x << " ";
    inOrder(node->right);
}



void postOrder(Node* node) {
    if (node == nullptr) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->x << " ";
}



Node* deletefoglia(Node* node) {
    delete node;
    return nullptr;
}





Node* deletefigliounico(Node* node) {
    Node* child = nullptr;

    if (node->left != nullptr) {
        child = node->left;
    } else if (node->right != nullptr) {
        child = node->right;
    }

       delete node;

    return child; //poi il parent si attacca al child
}



Node* deleteduefigli(Node* node) {
    if (node == nullptr) return nullptr;


    Node* succ = node->right;
    Node* succParent = node; 

    while (succ->left != nullptr) {
        succParent = succ;
        succ = succ->left;
    }


    if (succParent->left == succ) {
        succParent->left = succ->right; 
    } else {
       
        succParent->right = succ->right;
    }

 
    succ->left = node->left;
    if (succ != node->right) {
        succ->right = node->right;
    }


    delete node;

   
    return succ;
}

