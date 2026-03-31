#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// Free tree memory
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    string line;

    // Read input
    while (getline(cin, line)) {
        if (line.empty()) continue;

        // Parse input: "root = [12, 5, 18, 2, 9, 15, 20], cnt = 4"
        size_t rootPos = line.find("root = [");
        size_t cntPos = line.find("], cnt = ");

        if (rootPos == string::npos || cntPos == string::npos) {
            continue;
        }

        // Extract array part
        size_t arrayStart = rootPos + 8; // length of "root = ["
        string arrayStr = line.substr(arrayStart, cntPos - arrayStart);

        // Parse array
        vector<int> arr;
        stringstream ss(arrayStr);
        string token;
        while (getline(ss, token, ',')) {
            // Trim spaces
            size_t start = token.find_first_not_of(" \t");
            size_t end = token.find_last_not_of(" \t");
            if (start != string::npos) {
                token = token.substr(start, end - start + 1);
                if (token == "null" || token == "None") {
                    arr.push_back(-1);
                } else {
                    arr.push_back(stoi(token));
                }
            }
        }

        // Extract cnt
        size_t cntStart = cntPos + 9; // length of "], cnt = "
        string cntStr = line.substr(cntStart);
        // Remove any trailing characters
        size_t endPos = cntStr.find_first_not_of("0123456789");
        if (endPos != string::npos) {
            cntStr = cntStr.substr(0, endPos);
        }
        int cnt = stoi(cntStr);

        // Build tree and find kth largest
        TreeNode* root = buildTree(arr);
        Solution solution;
        int result = solution.kthLargest(root, cnt);

        cout << result << endl;

        // Clean up
        deleteTree(root);
    }

    return 0;
}
