class Codec {
public:

    void serializeDFS(TreeNode* root, string& s) {
        if (!root) {
            s += "#,";
            return;
        }
        s += to_string(root->val) + ",";
        serializeDFS(root->left, s);
        serializeDFS(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        serializeDFS(root, s);
        return s;
    }

    TreeNode* build(vector<string>& nodes, int& idx) {
        if (nodes[idx] == "#") {
            idx++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[idx++]));

        root->left = build(nodes, idx);
        root->right = build(nodes, idx);

        return root;
    }

    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string temp;

        for (char c : data) {
            if (c == ',') {
                nodes.push_back(temp);
                temp.clear();
            } else {
                temp += c;
            }
        }

        int idx = 0;
        return build(nodes, idx);
    }
};