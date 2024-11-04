#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

void traverse(Node* head){
    Node* current = head;
    while (current != nullptr){
        cout<<current->data<<" ";
        current = current->next;
    }
}

Node* insertHead(Node* head , int x){
    Node* temp = new Node(x); 
    temp->next = head;
    return temp;
}

Node* insertTail(Node* head , int x){
    if(head == nullptr) return new Node(x);
    Node *newNode = new Node(x);
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

//k--->pos , x --->value
Node* insertK(Node* head , int k , int x){
    if(head == nullptr){
        if(k==1) return new Node(x);
        else return head;
    }
    if(k==1){
        Node* temp = new Node(x);
        temp->next = head;
        return temp;
    } 
    int count = 0;
    Node* temp = head;
    while(temp != nullptr){
        count++;
        if(count == k-1){
            Node* newNode = new Node(x);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

//insert the node before the value x
Node* insertVal(Node* head , int ele , int val){
    
}

int main(){
    Node* head = new Node(1);
    Node* sec = new Node(2);
    head->next = sec;
    Node* third = new Node(3);
    sec->next = third;
    Node* fourth = new Node(4);
    third->next = fourth;
    Node* fivth = new Node(5);
    fourth->next = fivth;

    traverse(head);
    cout<<endl;
    
    head = insertHead(head , 0);
    traverse(head);
    cout<<endl;

    Node* ans = insertTail(head , 6);
    traverse(head);
    cout<<endl;

    head = insertK(head , 5 , 77);
    traverse(head);
    cout<<endl;
    

    return 0;
}