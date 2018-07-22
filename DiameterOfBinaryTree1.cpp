/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
 * 树的直径即为两个最远节点间的距离。考虑该路径通过根节点的情况。如示例图所示，通过根节点的最长路径
 * 即为根节点的左子树的深度加上右子树的深度。如果该路径不通过根节点（一般是根结点的某一孩子为Null），
 * 根据树的递归定义，通过某节点的最长路径即为该节点孩子深度之和。如此，我们需要编写一个求树深度的函数，
 * 然后计算通过跟节点的最长路径，再计算其左右孩子的最长路径，三者最大即为该节点的最长路径。
*/
class Solution {
    public:

        int depth(TreeNode* root)
        {
            if (nullptr == root)
                return 0;
            int depth_left = depth(root->left);
            int depth_right = depth(root->right);


            return depth_left > depth_right ? depth_left + 1 : depth_right + 1;
        }
        int diameterOfBinaryTree(TreeNode* root) {
            if (nullptr == root)
                return 0;

            int depth_left = depth(root->left);
            int depth_right = depth(root->right);

            int dia_root = depth_left + depth_right;

            int dia_right = diameterOfBinaryTree(root->right);
            int dia_left = diameterOfBinaryTree(root->left);

            return max({dia_root, dia_right, dia_left});
        }
};

