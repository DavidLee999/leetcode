/*
 * 观察一下就可以发现该算法存在一些不足。因为很显然它存在大量重复运算：对跟节点的左右子树计算了深度后，
 * 递归时又在计算了一次。那么，首先想到的就是可以保存信息，或者抽取重复代码。对于一个节点，其最长路径
 * 为左右子树深度之和，那么我们可以直接在计算深度的时候计算其最长路径，即把 
 * daimeterOfBinaryTree 中的 int dia_root = depth_left + depth_right; 移动到 depth 里。再考虑到我们要
 * 的是最大值，可以创建一个变量，每次计算后保留最大值即可，而不必把每个节点的最长路径保留下来。就有了最后的代码。
*/
class Solution {
    public:
        int dia;
        int depth(TreeNode* root)
        {
            if (nullptr == root)
                return 0;
            int depth_left = depth(root->left);
            int depth_right = depth(root->right);

            dia = dia < (depth_left + depth_right) ? (depth_left + depth_right) : dia;

            return depth_left > depth_right ? depth_left + 1 : depth_right + 1;
        }
        int diameterOfBinaryTree(TreeNode* root) {
            dia = 0;
            depth(root);

            return dia;
        }
};

