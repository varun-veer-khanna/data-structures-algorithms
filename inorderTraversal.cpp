#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};

class Solution {
    vector<int> ans;
public:
    void inorder(TreeNode* &root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
};

int main(){
    Solution obj;

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector <int> ans=obj.inorderTraversal(root);
    for (int i=0; i<ans.size(); i++){
        cout<<ans[i];
    }

    delete root->right->left;
    delete root->right;
    delete root;
    return 0;
}