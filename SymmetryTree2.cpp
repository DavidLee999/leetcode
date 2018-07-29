/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (nullptr == root)
            return true;
        
        std::queue<std::pair<TreeNode *, TreeNode *> > check_queue;
        check_queue.push(std::make_pair(root->left, root->right));
        
        std::pair<TreeNode *, TreeNode *> check_pair;
        while(!check_queue.empty())
        {
            check_pair = check_queue.front();
            check_queue.pop();
            
            if ((nullptr == check_pair.first && nullptr != check_pair.second) ||
                (nullptr != check_pair.first && nullptr == check_pair.second))
                return false;
            
            if (nullptr == check_pair.first && nullptr == check_pair.second)
                continue;
            
            if (check_pair.first->val != check_pair.second->val)
                return false;
            
            check_queue.push(std::make_pair(check_pair.first->left, check_pair.second->right));
            check_queue.push(std::make_pair(check_pair.first->right, check_pair.second->left));
        }
        
        return true;
    }
};
