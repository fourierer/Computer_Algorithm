//未完成
class Solution {
public:
    void serializeHelper(TreeNode *node, string& s)
    {
        if (node == NULL)
        {
            s.push_back('N');
            s.push_back(',');
            return;
        }
        s += to_string(node->val);
        s.push_back(',');
        serializeHelper(node->left, s);
        serializeHelper(node->right, s);
    }
    char* Serialize(TreeNode *root)
    {
        if (root == NULL)
            return NULL;
        string s = "";
        serializeHelper(root, s);
 
        char *ret = new char[s.length() + 1];
        strcpy(ret, s.c_str());
        return ret;
    }
     
    TreeNode *deserializeHelper(string &s)
    {
        if (s.empty())
            return NULL;
        if (s[0] == 'N')
        {
            s = s.substr(2);
            return NULL;
        }
        TreeNode *ret = new TreeNode(stoi(s));
        s = s.substr(s.find_first_of(',') + 1);
        ret->left = deserializeHelper(s);
        ret->right = deserializeHelper(s);
        return ret;
    }
     
    TreeNode* Deserialize(char *str)
    {
        if (str == NULL)
            return NULL;
        string s(str);
        return deserializeHelper(s);
    }
};