#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    Node* sortedInsert(Node* head, int data) {
        Node* newnode = new Node(data);
        
        // Case 1: Empty list
        if (head == nullptr) {
            newnode->next = newnode; // Point to itself
            return newnode;
        }
        
        // Case 2: Insert at head position (new smallest element)
        if (data <= head->data) {
            Node* last = head;
            // Find last node (which points back to head)
            while (last->next != head) {
                last = last->next;
            }
            // Insert between last and head
            last->next = newnode;
            newnode->next = head;
            return newnode; // Return new head
        }
        
        // Case 3: Insert somewhere after head
        Node* prev = head;
        Node* current = head->next;
        
        // Find first node with data >= new data
        while (current != head && current->data < data) {
            prev = current;
            current = current->next;
        }
        
        // Insert between prev and current
        prev->next = newnode;
        newnode->next = current;
        
        return head; // Head remains same
    }
};

int main() {}