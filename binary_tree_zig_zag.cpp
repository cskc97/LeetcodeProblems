#include<iostream>
#include<queue>
#include<unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {

        if (root == nullptr) {
            return vector<vector<int>>();
        }
        vector<vector<int>> result;

        queue<TreeNode *> bfsQ;

        int level = 0;
        bfsQ.push(root);


        while (!bfsQ.empty()) {

            int numElems = 1 << level;level++;
            vector<int> sub;
            for (int count = 0; count < numElems; count++) {
                TreeNode *front;
                front= bfsQ.front();
                bfsQ.pop();
                if (front != NULL) {
                    sub.push_back(front->val);
                    if (level % 2 == 0) {
                        bfsQ.push(front->left);
                        bfsQ.push(front->right);
                    } else {
                        bfsQ.push(front->right);
                        bfsQ.push(front->left);
                    }


                }




            }
            result.push_back(sub);




        }
        return result;

    }


};

int main(){
    TreeNode*left = new TreeNode(1);
    TreeNode* right = new TreeNode(2);
    TreeNode* root = new TreeNode(0);
    root->left = left;
    root->right = right;

    TreeNode * a = new TreeNode(3);
    TreeNode* b = new TreeNode(4);
    TreeNode* c = new TreeNode(5);
    TreeNode* d = new TreeNode(6);

    left->left = a;
    left->right = b;

    right->left = c;
    right->right = d;


    Solution s = Solution();
    vector<vector<int>> res = s.zigzagLevelOrder(root);
    for(auto vals: res){
        for(auto val:vals){
            cout<<val<<" ";
        }
        cout<<endl;
    }

}