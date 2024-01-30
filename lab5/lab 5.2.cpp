//Josephus problem - circular linked list based approach
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        this->data = val;
        this->next = nullptr;
    }
};

class circularLL {
public:
    Node* head;

    circularLL() : head(nullptr) {}

    void append(Node*& head, int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void deleteNode(Node*& head, int val) {
    if (head == nullptr) {
        return;
    }

    Node* last = head;
    Node* d;

    if (head->data == val) {
        while (last->next != head) {
            last = last->next;
        }

        last->next = head->next;
        delete head; 
        head = last->next;
        return;
    }

    while (last->next != head && last->next->data != val) {
        last = last->next;
    }

    if (last->next->data == val) {
        d = last->next;
        last->next = d->next;
        delete d;  
    }
}


    void display(Node* head) {
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter the no of people - ";
    cin >> n;
    Node* head = nullptr;
    circularLL cll;
    for (int i = 1; i <= n; i++) {
        cll.append(head, i);
    }
    
    int noOfDead = 0;
    bool kill = false;
    Node* temp = head;
    while (noOfDead < n - 1) {
        if (kill) {
            Node* t2=temp;
            temp=temp->next;
            cll.deleteNode(head,t2->data);
            noOfDead++;
     }else{
     	 temp=temp->next;
     }
       
        kill = !kill;
    }
    cout << "Survivor is - ";
    cll.display(head);
    return 0;
}

