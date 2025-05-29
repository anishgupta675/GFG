#include<bits/stdc++.h>

using namespace std;

//User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        if(root==NULL){
            return 0;
        }
        //mapping node with sum upto that node
        map<Node*,pair<int,int>>m;
        queue<pair<pair<Node*,int>,int>>q;
        q.push(make_pair(make_pair(root,root->data),0));
        
        while(!q.empty()){
            pair<pair<Node*,int>,int>temp=q.front();
            q.pop();
            Node* frontnode=temp.first.first;
            int SumUptoNode=temp.first.second;
            int lv=temp.second;
            
            m[frontnode]=make_pair(SumUptoNode,lv);
            
            if(frontnode->left){
            q.push(make_pair(make_pair(frontnode->left,frontnode->left->data+m[frontnode].first),lv+1));
            }
            if(frontnode->right){
            q.push(make_pair(make_pair(frontnode->right,frontnode->right->data+m[frontnode].first),lv+1));
            }
            
        }
        int ans=INT_MIN;
        vector<int>possible;
        int myanslv=-1;
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second.second>=myanslv){
                myanslv=it->second.second;
            }
           
        }
        
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second.second==myanslv){
                possible.push_back(it->second.first);
            }
        }
        
        for(int i=0;i<possible.size();i++){
            if(possible[i]>ans){
                ans=possible[i];
            }
        }
        
        return ans;
    }
};

int main() {}