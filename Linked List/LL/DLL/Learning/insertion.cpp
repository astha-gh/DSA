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

Node* insertHead(Node* head , int x){
    Node* newNode = new Node(x , head , nullptr);
    head->back = newNode;
    return newNode;
}

Node* insertAfterTail(Node* head , int x){
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    Node* newNode = new Node(x , nullptr , temp);
    temp->next = newNode;
    return head;
}

Node* insertBeforeTail(Node* head , int val){
    Node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    Node* front = temp->next;
    Node* newNode = new Node(val , front , temp);
    temp->next = newNode;
    front->back = newNode;
    return head;
}

Node* insertBeforeK(Node* head , int ele , int pos){
    if(pos == 1){
        return insertHead(head , ele);
    }
    Node* temp = head;
    int count = 0;
    while(temp != nullptr){
        count++;
        if(count == pos - 1){
            break;
        }
        temp = temp->next;
    }
    Node* front = temp->next;
    Node* newNode = new Node(ele ,front , temp);
    temp->next = newNode;
    front->back = newNode;
    return head;
}

void insertBeforeTheGivenNode(Node* node , int val){
    Node* prev = node->back;
    Node* newNode = new Node(val , node , prev);
    prev->next = newNode;
    node->back = newNode;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5 };
    Node* head = arrtoDLL(arr);
    traverse(head);
    cout<<endl;

    head = insertHead(head , 0);
    traverse(head);
    cout<<endl;

    head = insertAfterTail(head , 6);
    traverse(head);
    cout<<endl;

    head = insertBeforeTail(head , 5);
    traverse(head);
    cout<<endl;

    head = insertBeforeK(head , 77 , 7);
    traverse(head);
    cout<<endl;

    insertBeforeTheGivenNode(head->next , 100);
    traverse(head);
    cout<<endl;


    return 0;
}