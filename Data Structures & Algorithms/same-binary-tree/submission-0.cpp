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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({p,q});

        while(!st.empty()){
            pair<TreeNode*, TreeNode*> top = st.top();
            st.pop();

            if(top.first == NULL && top.second == NULL) continue;

            else if((top.first == NULL && top.second != NULL) || (top.first != NULL && top.second == NULL) || (top.first -> val != top.second -> val)) return false;

            st.push({top.first->right, top.second->right});
            st.push({top.first -> left, top.second -> left});
        }
        return true;
    }
};