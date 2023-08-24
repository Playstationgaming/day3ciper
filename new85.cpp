#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x) : data(x),next(NULL){}

};
void insert(Node* &head,Node* &tail,int data){
    Node* newNode = new Node(data);
    if(!head){
        head =newNode;
        tail=newNode;
    }
    else{
        tail->next =newNode;
        tail = newNode;

    }
}
void Printfun(Node* head){
    Node* curr=head;
    while(curr){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}
Node* Merge(Node* l, Node* r){
    if(!l)
    return r;
    if(!r){
        return l;
    }
    Node* answer=NULL;
    if(l->data <= r->data){
        answer=l;
        answer->next=Merge(l->next, r);

    }
    else{
        answer=r;
        answer->next=Merge(l,r->next);

    }
    return answer;
}
void split(Node* source,Node* &front,Node* &back){
    Node* slow=source;
    Node*fast=source->next;
    while(fast){
        fast=fast->next;
        if(fast){
            slow=slow->next;
            fast=fast->next;
        }
    }
    front=source;
    back=slow->next;
    slow->next=NULL;
}
void mergesort(Node* &head){
    if(!head||!head->next){
        return;
    }
    Node*front;
    Node* back;
    split(head,front,back);
    mergesort(front);
    mergesort(back);
    head=Merge(front,back);
}
int main(){
    int N;
    cin>>N;
    Node* head =NULL;
    Node* tail=NULL;
    for(int i=0;i<N;++i){
        int value;
        cin>>value;
        insert(head,tail,value);

    }
    mergesort(head);
    Printfun(head);
    return 0;
}