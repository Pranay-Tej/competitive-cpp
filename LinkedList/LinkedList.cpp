#include <bits/stdc++.h>

using namespace std;

class Node
{
public:

    int data;
    Node* next;

    Node();
    Node(int data);
    ~Node();
};

Node::Node(){
    data = 0;
    next = NULL;
}

Node::Node(int data)
{
    this->data = data;
    next = NULL;
}

Node::~Node()
{
    next = NULL;
}

class LinkedList
{
public:

    Node* head;

    LinkedList();
    ~LinkedList();

    bool add(int data, int index);
    void append(int data);
    Node* getLastNode();
    bool isEmpty();
    int length();
    void merge(LinkedList listTwo);
    void print();
    bool remove();
    bool remove(int index);
    void reverse();
};

LinkedList::LinkedList()
{
    head = NULL;
}

LinkedList::~LinkedList()
{
    head = NULL;
}

bool LinkedList::add(int data, int index)
{
    // case 1: index negative
    if (index < 0)
    {
        // index CANNOT be negative
        return false;
    }

    int counter = 0;

    // case 2: index is 0
    if (index == counter)
    {
        // if index is 0 insert at head
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
        return true;
    }

    Node *temp = head;

    // loop till end of list
    while (temp != NULL)
    {
        if (counter == index - 1 || counter == index)
        {
            // counter == index - 1
            // position just before the desired index

            // counter == index
            // append at end of list
            Node *new_node = new Node(data);
            // save next nodes address
            new_node->next = temp->next;
            // change prev nodes next address to new node
            temp->next = new_node;
            return true;
        }
        temp = temp->next;
        counter++;
    }

    return false;
}

void LinkedList::append(int data)
{

    Node *new_node = new Node(data);
    if (isEmpty())
    {
        head = new_node;
        return;
    }

    Node *temp = getLastNode();

    temp->next = new_node;
}

Node *LinkedList::getLastNode()
{
    if (isEmpty())
    {
        return NULL;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    return temp;
}

bool LinkedList::isEmpty()
{
    if (head == NULL)
    {
        return true;
    }

    return false;
}

int LinkedList::length()
{
    int counter = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        counter++;
    }
    return counter;
}

void LinkedList::merge(LinkedList listTwo){
    Node* temp = getLastNode();
    temp->next = listTwo.head;

    // making list 2 empty
    // NOT necessary
    // listTwo.head == NULL;
    // delete(&listTwo);
}

void LinkedList::print()
{
    cout << "[";

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data;

        if (temp->next != NULL)
        {
            // if condition to skip separation after the last element
            cout << ", ";
        }

        temp = temp->next;
    }
    cout << "]" << endl;
}

bool LinkedList::remove()
{

    // case 1: length 0
    if (isEmpty())
    {
        return false;
    }

    // case 2: length 1
    if (head->next == NULL)
    {
        delete (head);
        head = NULL;
        return true;
    }

    // case 3: length >1
    Node *temp = head;

    // loop till last but one node
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    // store the last node in a temporary value to free memory
    Node *to_be_deleted = temp->next;
    // change last but one - node's next value to NULL
    temp->next = temp->next->next;
    // free the memory of removed node
    delete (to_be_deleted);
    return true;
}

bool LinkedList::remove(int index)
{

    // case 1: length 0
    if (isEmpty())
    {
        return false;
    }

    int counter = 0;

    // case 2: index 0
    if (index == counter)
    {
        // if index is 0
        Node *prev_head = head;
        head = head->next;
        delete (prev_head);
        return true;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {

        if (counter == index - 1)
        {
            // position just before the desired index
            // store the last node in a temporary value to free memory
            Node *to_be_deleted = temp->next;
            // change last but one - node's next value to NULL
            temp->next = temp->next->next;
            // free the memory of removed node
            delete (to_be_deleted);
            return true;
        }
        temp = temp->next;
        counter++;
    }

    return false;
}

void LinkedList::reverse(){

    // case 1: list is empty. No need for reversing
    if(isEmpty()){
        return;
    }

    Node* currentNode = head;
    Node* prevNode = NULL;
    Node* nextNode = NULL;

    while(currentNode != NULL){
        // save the current node's next value in next node
        // use it to move after reversing the current element links
        nextNode = currentNode->next;

        // now that current node's next value is saved
        // change the link to point to prevNode
        currentNode->next = prevNode;

        // now that previous node value is used
        // save the current nodes value to use it in the next iteration
        prevNode = currentNode;

        // move on the next node
        currentNode = nextNode;
    }

    // currentNode is NULL
    // so prevNode is the end noe of the list
    // Since list is reversed this is the new head
    head = prevNode;
}

int main()
{

    LinkedList linkedList = *(new LinkedList());
    // LinkedList linkedList;

    linkedList.print();
    linkedList.append(1);
    linkedList.append(3);

    // outputs true adds 2 at index 1
    cout << linkedList.add(2, 0) << endl;
    linkedList.print();
    // cout << linkedList.length() << endl;
    // cout << linkedList.add(4, -1) << endl;
    // cout << linkedList.add(4, 4) << endl;

    // // outputs false
    // cout<<linkedList.add(2,-1)<<endl;

    // linkedList.print();

    // cout << linkedList.remove(1) << endl;

    // linkedList.print();
    // cout << linkedList.remove() << endl;

    // linkedList.print();
    // cout << linkedList.remove(0) << endl;

    // linkedList.print();

    // cout << linkedList.remove(0) << endl;

    // cout << linkedList.remove() << endl;

    LinkedList linkedListTwo = *(new LinkedList());
    // LinkedList linkedListTwo;

    linkedListTwo.print();
    linkedListTwo.append(200);
    linkedListTwo.print();

    linkedList.merge(linkedListTwo);
    linkedList.print();

    linkedList.reverse();
    linkedList.print();

    return 0;
}