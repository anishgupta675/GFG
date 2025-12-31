#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node *slow_ptr = head, *fast_ptr = head;
        while(fast_ptr->next != nullptr && fast_ptr->next->next != nullptr) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        bool end_flag = 0;
        if(fast_ptr->next == nullptr) end_flag = 1;
        Node *prev = nullptr, *curr = slow_ptr->next, *after = nullptr;
        while(curr != nullptr) {
            after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }
        slow_ptr->next = prev;
        Node *head2 = slow_ptr->next;
        Node *end1 = (end_flag) ? slow_ptr : slow_ptr->next;
        while(head != end1) {
            if(head->data != head2->data) return 0;
            head = head->next;
            head2 = head2->next;
        }
        return 1;
    }
};

int main() {}