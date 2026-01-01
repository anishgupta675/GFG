#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        if(head1 == nullptr || head2 == nullptr) return nullptr;
        Node *ptr1 = head1, *ptr2 = head2;
        while(ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if(ptr1 == ptr2) return ptr1;
            if(ptr1 == nullptr) ptr1 = head2;
            if(ptr2 == nullptr) ptr2 = head1;
        }
        return nullptr;
    }
};

int main() {}