/*
http://oj.leetcode.com/problems/binary-tree-inorder-traversal/
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        inorderTrav(root, res);
        return res;
    }
private:
    void copy_vector(const vector<int>& vec, vector<int>& res) 
    {
        int num = (int)vec.size();
        for(int i=0;i<num;i++)
            res.push_back(vec[i]);
    }
    
    int inorderTrav(TreeNode *root, vector<int>& res)
    {
        if(root == NULL)
            return -1;
     
        vector<int> left;
        vector<int> right;
        inorderTrav(root->left, left);
        inorderTrav(root->right, right);
        
        int num = (int)left.size() + (int)right.size() + 1;
        res.clear();
        res.reserve(num);
        copy_vector(left, res);
        res.push_back(root->val);
        copy_vector(right, res);
        
        return 0;  
    }    
};