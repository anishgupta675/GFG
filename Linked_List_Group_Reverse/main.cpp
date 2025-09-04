#include<bits/stdc++.h>
using namespace std;

/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
*/
struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

}*head;

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(head == nullptr || k == 1) return head;
        struct node *prev = nullptr, *curr = head, *after = nullptr;
        int i = 1;
        while(curr != nullptr && i <= k) {
            after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
            i++;
        }
        struct node *prev_start = head, *start = curr;
        head = prev;
        prev = nullptr;
        i = 1;
        while(curr != nullptr) {
            if(i == k || curr->next == nullptr) {
                prev_start->next = curr;
                after = curr->next;
                curr->next = prev;
                prev = nullptr;
                curr = after;
                i = 1;
                prev_start = start;
                start = curr;
            } else {
                after = curr->next;
                curr->next = prev;
                prev = curr;
                curr = after;
                i++;
            }
        }
        return head;
    }
};

int main() {}