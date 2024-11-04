#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;
    Node(int data1 , Node* next1 , Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

void traverse(Node* head){
    Node* current = head;
    while(current != nullptr){
        cout<<current->data<<" ";
        current = current->next;
    }
}

Node* arrtoDLL(vector<int> &arr){
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1 ; i<n-1 ; i++){
        Node* temp = new Node(arr[i] , nullptr , prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* delHead(Node* head){
    if(head == nullptr || head->next == nullptr) return nullptr;
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

Node* delTail(Node* head){
    if(head == nullptr || head->next == nullptr) return nullptr;
    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    Node* prev = tail->back;
    tail->back = nullptr;
    prev->next = nullptr;
    delete tail;
    return head;
}

Node* delK(Node* head , int k){
    if(head == nullptr) return nullptr;
    Node* temp = head;
    int count = 0;
    while(temp != nullptr){
        count++;
        if(count == k){
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;
    //egde case
    if(prev == nullptr && front == nullptr){
        return nullptr;
    } 
    else if(prev == nullptr) {
        return delHead(head);
    }
    else if(front == nullptr) {
        return delTail(head);
    }
    //otherwise
    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
        return delTail(head);
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5 , 6, 7, 8, 9};
    Node* head = arrtoDLL(arr);
    traverse(head);
    cout<<endl;

    head = delHead(head);
    traverse(head);
    cout<<endl;

    head = delTail(head);
    traverse(head);
    cout<<endl;

    head = delK(head, 3);
    traverse(head);
    cout<<endl;

    return 0;
}