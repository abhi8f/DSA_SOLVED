/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define d(x) cout<<#x<<": "<<x<<endl;

class Codec {
private: 
    int getIntFromString(int &i, string &data) {
        string cur = "";
        while(data[i]!=',') {
            cur+=data[i];
            i++;
        }
        i++;
        return stoi(cur);
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            TreeNode *node = nodeQueue.front();
            nodeQueue.pop();
            if (!node) {
                ans.push_back(',');
                continue;
            }
            ans += to_string(node->val) + ',';
            nodeQueue.push(node->left);
            nodeQueue.push(node->right);
        }
        return ans;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream full(data);
        string cur;
        getline(full, cur, ',');

        if (cur=="") return NULL;
        queue<TreeNode *> nodeQueue;
        TreeNode *root = new TreeNode(stoi(cur));
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            TreeNode *node = nodeQueue.front();
            nodeQueue.pop();

            getline(full, cur, ',');
            if (cur==""){
                node->left=NULL;
            }
            else {
                node->left = new TreeNode(stoi(cur));
                nodeQueue.push(node->left);
            }
            getline(full, cur, ',');
            if (cur==""){
                node->right=NULL;
            }
            else {
                node->right = new TreeNode(stoi(cur));
                nodeQueue.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
