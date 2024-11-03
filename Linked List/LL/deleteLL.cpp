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

Node* delHead(Node* head){
    if(head == nullptr) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* delTail(Node* head){
    if(head == nullptr || head->next == nullptr) return nullptr;
    Node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* removeK(Node* head , int k){
    if(head == nullptr) return head;
    if(k == 1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int count = 0;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
        count++;
        if(count == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
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
    
    // Node* ans = delHead(head);
    // cout<<ans->data<<endl;

    // delTail(head);
    // traverse(head);

    head = removeK(head , 3);
    traverse(head);

    

    return 0;
}