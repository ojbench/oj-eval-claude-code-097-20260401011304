#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    ~TreeNode() {
        delete left;
        delete right;
    }
};

class Solution {
private:
    int count;
    int result;

    void reverseInorder(TreeNode* node, int k) {
        if (node == nullptr || count >= k) {
            return;
        }

        // Visit right subtree first (larger values)
        reverseInorder(node->right, k);

        // Visit current node
        count++;
        if (count == k) {
            result = node->val;
            return;
        }

        // Visit left subtree (smaller values)
        reverseInorder(node->left, k);
    }

public:
    int kthLargest(TreeNode* root, int k) {
        count = 0;
        result = -1;
        reverseInorder(root, k);
        return result;
    }
};

// Build tree from level-order array representation
TreeNode* buildTree(const vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    size_t i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (i < arr.size()) {
            if (arr[i] != -1) {
                curr->left = new TreeNode(arr[i]);
                q.push(curr->left);
            }
            i++;
        }

        // Right child
        if (i < arr.size()) {
            if (arr[i] != -1) {
                curr->right = new TreeNode(arr[i]);
                q.push(curr->right);
            }
            i++;
        }
    }

    return root;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int cnt;
        cin >> cnt;

        // Build tree and find kth largest
        TreeNode* root = buildTree(arr);
        Solution solution;
        int result = solution.kthLargest(root, cnt);

        cout << result << endl;

        // Clean up - destructor handles this recursively
        delete root;
    }

    return 0;
}
