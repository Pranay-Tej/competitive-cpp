#include<bits/stdc++.h>
using namespace std;

#define COUNT 10  


class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node();
    Node(int data);
    ~Node();
};

Node::Node()
{
    data = 0;
    left = NULL;
    right = NULL;
}

Node::Node(int data)
{
    this->data = data;
    left = NULL;
    right = NULL;
}

Node::~Node()
{
    left = NULL;
    right = NULL;
}


class BST
{
private:
    void inOrder(Node* root);
    void postOrder(Node* root);
    void preOrder(Node* root);

public:
    Node* root;

    BST();
    ~BST();

    // Functionality
    void add(int data);
    Node* search(int data);
    bool remove();

    // Traversal
    void inOrder();
    void levelOrder();
    void postOrder();
    void preOrder();
};

BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    root = NULL;
}

// Functionality
void BST:: add(int data){

    Node* currentNode = root;

    while(currentNode != NULL){
        
        // Leaf node
        if(currentNode->left == NULL && currentNode->right == NULL){
            break;
        }

        if(currentNode->data < data){
            // If data should be inserted to the right
            // And the current node doesn't have a node to the right
            // Thats where the new node should be inserted
            if(currentNode->right == NULL){
                break;
            }
            currentNode = currentNode->right;
        }else{
            // If data should be inserted to the left
            // And the current node doesn't have a node to the left
            // Thats where the new node should be inserted
            if(currentNode->left == NULL){
                break;
            }
            currentNode = currentNode->left;
        }
    }

    Node* newNode = new Node(data);

    if(currentNode == NULL){
        // if root is NULL
        root = newNode;
    }else if(currentNode->data < data){
        // Attach the node to current node's right position
        currentNode->right = newNode;
    }else{
        // Attach the node to current node's left position
        currentNode->left = newNode;
    }


}

Node* BST:: search(int data){
    
    Node* currentNode = root;
    
    while(currentNode != NULL){
        if(currentNode->data == data){
            return currentNode;
        }else if(currentNode->data < data){
            currentNode = currentNode->right;
        }else{
            currentNode = currentNode->left;
        }
    }

    return NULL;
}

// Traversal

void BST:: inOrder(){
    cout<<"In Order: ";
    inOrder(root);
    cout<<endl;
}

void BST:: inOrder(Node* root){
    
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout<<(root->data)<<" ";
    inOrder(root->right);
}

void BST:: levelOrder(){
    
    queue<Node*> Q;
    Q.push(root);
    cout<<"Level Order: ";
    while(!Q.empty()){
        Node* currentNode = Q.front();
        Q.pop();
        if(currentNode->left != NULL){
            Q.push(currentNode->left);
        }
        if(currentNode->right != NULL){
            Q.push(currentNode->right);
        }
        cout<<currentNode->data<<" ";

    }
    cout<<endl;
}


void BST:: postOrder(){
    cout<<"Post Order: ";
    postOrder(root);
    cout<<endl;
}

void BST:: postOrder(Node* root){
    
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<(root->data)<<" ";
}

void BST:: preOrder(){
    cout<<"Pre Order: ";
    preOrder(root);
    cout<<endl;
}

void BST:: preOrder(Node* root){
    
    if(root == NULL){
        return;
    }

    cout<<(root->data)<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){

    BST bstOne = *(new BST());
    bstOne.add(5);
    bstOne.add(1);
    cout<<bstOne.search(5)<<" "<<bstOne.search(1)<<endl;
    bstOne.add(10);
    cout<<bstOne.search(5)<<" "<<bstOne.search(1)<<" "<<bstOne.search(10)<<endl;
    bstOne.add(3);
    cout<<bstOne.search(5)<<" "<<bstOne.search(1)<<" "<<bstOne.search(10)<<" "<<bstOne.search(3)<<endl;
    bstOne.add(2);
    cout<<bstOne.search(5)<<" "<<bstOne.search(1)<<" "<<bstOne.search(10)<<" "<<bstOne.search(3)<<" "<<bstOne.search(2)<<endl;
    bstOne.inOrder();
    bstOne.preOrder();
    bstOne.postOrder();
    bstOne.levelOrder();
    cout<<bstOne.search(5)->data<<endl;

    return 0;
}