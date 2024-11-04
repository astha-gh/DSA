#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
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

int length(Node* head){
    Node* current = head;
    int count = 0;
    while(current != nullptr){
        current = current->next;
        count++;
    }
    return count;
}

bool search(Node* head , int val){
    Node* current = head;
    while(current != nullptr){
        if(current->data == val){
            return true;
        }
        current = current->next;
    }
    return false;
}

Node* arrToLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* current = head;
    for(int i = 1 ; i<arr.size() ; i++){
        Node* temp = new Node(arr[i]);
        current->next = temp;
        current = temp;
    }
    return head;
}

int main(){
    vector<int> arr = {1, 2, 3, 4};
    Node *head = new Node(arr[0]);
    Node *second = new Node(arr[1]);
    head->next = second;
    Node* third = new Node(arr[2]);
    second->next = third;
    Node* fourth = new Node(arr[3]);
    third->next = fourth;

    traverse(head);
    cout<<endl;
    cout<<length(head)<<endl;
    cout<<search(head , 2)<<endl;


    return 0;
}