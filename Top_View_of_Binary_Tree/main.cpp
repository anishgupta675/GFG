#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        queue<pair<Node*,int>>q; //node,level
        map<int,int>m;  //level,verticle
        q.push({root,0});
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            auto node=f.first;
            int x=f.second;
            
            if(m.find(x)==m.end())
            m[x]=node->data; // only insert if its first vertical i.e only diff from bottom view
            
            if(node->left)  q.push({node->left,x-1});
            if(node->right)
                q.push({node->right,x+1});
        }
        vector<int>v;
        for(auto i:m){
            v.push_back(i.second); // insert value
        }
        return v;
    }

};

int main() {}