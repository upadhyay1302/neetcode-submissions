/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL) return ans;

        vector<int> x;


        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();
            if(top == NULL){
                ans.push_back(x);
                x.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                x.push_back(top->val);
                if(top -> left != NULL) q.push(top->left);
                if(top -> right != NULL) q.push(top -> right);
            }
        }

        return ans;
    }
};