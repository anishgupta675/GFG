#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
    
    int length(Node* head){
        Node* temp=head;
        int ans=0;
        while(temp){
            ans++;
            temp=temp->next;
        }
        return ans;
    }
    
    Node* addTwoLists(Node* first, Node* second)
    {
        // code here
        int N=length(first);
        int M=length(second);
        int diff,sum=0;
        Node*ptr1,*ptr2,*ansHead,*rem,*prev,*curr;
        ptr1=ptr2=ansHead=rem=prev=curr=NULL;
        
        if(N>=M){
            ptr1=first; 
            ptr2=second;
            diff=N-M;
        }
        else{
            ptr1=second; 
            ptr2=first;
            diff=M-N;
        }
        
        while(ptr1 && diff--){
            curr=new Node(ptr1->data);
            if(!ansHead){
                ansHead=curr;
                prev=curr;
            }
            else{
                prev->next=curr;
                prev=curr;
            }
            
            if(curr->data!=9){
                rem=curr;
            }
            ptr1=ptr1->next;
            
        }
        
        while(ptr1 && ptr2){
            sum=ptr1->data + ptr2->data;
            if(sum<=9){
                curr=new Node(sum);
                if(!ansHead) {
                    ansHead=curr;
                    prev=curr;
                }
                else{
                    prev->next=curr;
                    prev=curr;
                }
                
                if(curr->data!=9){
                    rem=curr;
                }
            }
            else{
                curr=new Node(sum%10);
                if(!ansHead){
                    ansHead=new Node(1);
                    ansHead->next=curr;
                    prev=curr;
                    rem=curr;
                }
                else{
                    prev->next=curr;
                    prev=curr;
    
                    if(rem){
                        rem->data++;
                    }
                    else{
                        Node* oneHead=new Node(1);
                        oneHead->next=ansHead;
                        ansHead=oneHead;
                        rem=ansHead;
                    }
                    rem=rem->next;
                    while(rem!=curr){
                        rem->data=0;
                        rem=rem->next;
                    }
                }
            }
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return ansHead;
    }
};

int main() {}