# include <iostream>
# include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};

class Solution {    
public:
    bool isMirror(TreeNode * left, TreeNode *right){
        if (left==NULL && right==NULL){
            return true;
        }
        if (left == NULL || right == NULL){
            return false;
        }
        return (left->val==right->val) && isMirror(left->right, right->left) && isMirror(left->left, right->right);
    }
    bool isSymmetric(TreeNode *root) {    
        if (root==NULL){
            return true;
        }
        return isMirror(root->left, root->right);        
    }
};

int main(){
    TreeNode * root = new  TreeNode(1);
    root->left = new TreeNode(2);
    root->right= new TreeNode(2);
    root->left->left= new TreeNode(3);
    root->right->right= new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->right->left=new TreeNode(4);

    Solution obj;

    bool symmetry=obj.isSymmetric(root);

    if (symmetry){
        cout<<"Tree is symmetric"<<endl;
    }
    else{
        cout<<"Tree is asymmetric";
    }

    delete root->right->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;
    return 0;
}