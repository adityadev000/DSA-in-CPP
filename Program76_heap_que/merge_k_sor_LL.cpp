

#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
class compare {
    public :
    bool operator () (Node * a , Node * b) {
        return a-> data > b-> data ;
    }
};

Node* mergeKLists(vector<Node*> &listArray)
    // Write your code here.
{
    priority_queue<Node* , vector<Node * > , compare > mh ;

    for(int i =0 ;i < listArray.size() ; i++ ){
        if(listArray[i] != NULL )
        mh.push(listArray[i]);
    }

    Node * head = NULL ;
    Node * tail = NULL ;

    while(! mh.empty()) {
        Node * top = mh.top() ;
        mh.pop() ;

        if(head == NULL ){
            head = tail = top ;
            
        }
        else{
            tail -> next = top ;
            tail= tail -> next ;
        }

        
        if(tail -> next )
                mh.push(tail -> next );
    }
    return head ;
}


int main(){

    cout << "Alright !!!!!!!!!" << endl;


}