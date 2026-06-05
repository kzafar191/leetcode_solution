// Last updated: 5/6/2026, 5:10:20 pm
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }

private:
    int dfsHeight(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = dfsHeight(root->left);
        if (leftHeight == -1) return -1;

        int rightHeight = dfsHeight(root->right);
        if (rightHeight == -1) return -1;

        if (abs(leftHeight - rightHeight) > 1) return -1;

        return 1 + max(leftHeight, rightHeight);
    }
};