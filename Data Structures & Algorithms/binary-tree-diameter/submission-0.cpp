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
    int height(TreeNode* root){
        if(root == NULL) return 0;

        int leftheight = height(root->left);
        int rightheight = height(root->right); 

        int maxheight = max(leftheight, rightheight);

        int total = maxheight + 1;
        return total;

    }
    int diameterOfBinaryTree(TreeNode* root) {

        if(root == NULL) return 0;

        int option1 = diameterOfBinaryTree(root->left);
        int option2 = diameterOfBinaryTree(root->right);


        int leftH = height(root -> left);
        int rightH = height(root -> right);

        int option3 = leftH + rightH;
   
        int maxH = max(option1, max(option2, option3));
        return maxH;
        
    }
};