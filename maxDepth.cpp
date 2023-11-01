

#include<iostream>
#include<bits/stdc++.h>

using namespace std;


 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int depthCounter(TreeNode *root, int depth){

        if (root!=NULL){
            return depth;
        }
        else if (root->left){
            depth++;
            depthCounter(root->left, depth);
        }
        else{
            depth++;
            depthCounter(root->right, depth);
        }
        return depth;
    }
    int maxDepth(TreeNode* root) {
        int depth=0;
        if (root==NULL){
            return depth;
        }
        depth=depthCounter(root, depth);
        return depth+1;        
    }
};

int main(){
    TreeNode *root=new TreeNode(1);



    Solution obj;
    int actDepth=obj.maxDepth(root);
    cout<<actDepth;
    return 0;
}