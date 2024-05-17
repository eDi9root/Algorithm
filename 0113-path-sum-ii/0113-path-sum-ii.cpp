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
    vector<vector<int>>stk;
public:
        
        void solve(TreeNode* root, int targetSum,int sum1,vector<int>trr){
                if (root->left==NULL && root->right==NULL){
                    if (sum1==targetSum){
                        stk.push_back(trr);
                    }
                    return;
                }
                if(root->left){
                    sum1+=root->left->val;
                    trr.push_back(root->left->val);
                    solve(root->left,targetSum,sum1,trr);
                    sum1-=root->left->val;
                    trr.pop_back();
                }
                if(root->right){
                    sum1+=root->right->val;
                    trr.push_back(root->right->val);
                    solve(root->right,targetSum,sum1,trr);
                    sum1-=root->right->val;
                    trr.pop_back();
                }

        }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root==NULL){
            return stk;
        }
        vector<int>trr;
        int sum1=root->val;
        trr.push_back(root->val);
       solve(root,targetSum,sum1,trr);
       return stk;
    }
};