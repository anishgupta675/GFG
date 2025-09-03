#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};


class Solution {
public:
    Node *temp = nullptr;

    void swap(Node *p) {
        temp = p->prev;
        p->prev = p->next;
        p->next = temp;
    }
    
    Node* reverse(Node * head)
    {
        //Your code here
        if(head == nullptr || head->next == nullptr) return head;
        Node *p = head;
        while(p) {
            swap(p);
            p = p->prev;
        }
        return temp->prev;
    }
};

int main() {}