
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            this->next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };


#include<bits/stdc++.h>
using namespace std;

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int>* l1=first;
    Node<int>* l2=second;
    Node<int>* res=NULL;
    Node<int>* temp=NULL;

    if(l1->data<l2->data)
        temp=l1;
    else
        temp=l2;

    res=temp;

    

}
