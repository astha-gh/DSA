#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

void traverse(Node* head){
    Node* current = head;
    while(current != nullptr){
        cout<<current->data<<" ";
        current = current->next;
    }
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
    
    
    

    return 0;
}