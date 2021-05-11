#include<bits/stdc++.h>
using namespace std;
class TreeNode  {
public:
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int key)   {
        val=key;
        left = nullptr;
        right = nullptr;
    }
};

vector<int> ans;

TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder, int &idx, int start, int end)  {
    if(start>end)   return nullptr;
    TreeNode *root = new TreeNode(preorder[idx]);
    int pos=-1;
    for(int i=start;i<=end;++i) {
        if(inorder[i]==preorder[idx])   {
            pos=i;
            break;
        }
    }
    idx++;
    root->left = buildTree(preorder, inorder, idx, start, pos-1);
    root->right = buildTree(preorder, inorder, idx, pos+1, end);
    return root;
}

void nodesAtLevelK(TreeNode* root, int k)   {
    if(!root)   return;
    if(k==0)    ans.push_back(root->val);
    nodesAtLevelK(root->left, k-1);
    nodesAtLevelK(root->right, k-1);
    return;
}

int kDistNode(TreeNode* root, int target, int k)    {
    if(!root)   return -1;
    if(root->val==target)   {
        nodesAtLevelK(root, k);
        return 1;
    }
    int dl = kDistNode(root->left, target, k);
    if(dl!=-1)  {
        if(dl==k)   ans.push_back(root->val);
        else    nodesAtLevelK(root->right, k-dl-1);
        return 1 + dl;
    }

    int dr = kDistNode(root->right, target, k);
    if(dr!=-1) {
        if(dr==k)   ans.push_back(root->val);
        else    nodesAtLevelK(root->left, k-dr-1);
        return 1+dr;
    }
    return -1;
}

void Inorder(TreeNode* root)    {
    if(!root)   return;
    Inorder(root->left);
    cout<<root->val<<" ";
    Inorder(root->right);
    return;
}
int main() {

    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);

    int n;
    cin>>n;
    vector<int> preorder(n);
    vector<int> inorder(n);
    for(int i=0;i<n;++i)    cin>>preorder[i];
    for(int i=0;i<n;++i)    cin>>inorder[i];
    int idx=0;
    TreeNode* root = buildTree(preorder, inorder, idx, 0, n-1);
    // Inorder(root);
    // cout<<endl;
    int t;
    cin>>t;
    while(t--)  {
        ans.clear();
        int target, k;
        cin>>target>>k;
        kDistNode(root, target, k);
        if(ans.empty()) {
            cout<<0<<endl;
            continue;
        }
        sort(begin(ans), end(ans));
        for(auto &x : ans)  cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}