/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 static auto unsyncStdio = []() {
     std::ios_base::sync_with_stdio(false);
     return 0;
 }();
class Codec {
    void serializeNode(TreeNode* node, std::ostringstream& out) noexcept {
        if (node != nullptr) {
            out << node->val << ' ';
            serializeNode(node->left, out);
            serializeNode(node->right, out);
        } else {
            out << "# ";
        }
    }

    TreeNode* deserializeStream(std::istringstream& in) noexcept {
        std::string val;
        in >> val;
        if (val == "#") {
            return nullptr;
        }
        TreeNode* node = new TreeNode(std::stoi(val));
        node->left = deserializeStream(in);
        node->right = deserializeStream(in);
        return node;
    }
public:
    std::string serialize(TreeNode* root) noexcept {
        std::ostringstream out;
        serializeNode(root, out);
        return out.str();
    }

    TreeNode* deserialize(std::string data) noexcept {
        std::istringstream in(data);
        return deserializeStream(in);
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));