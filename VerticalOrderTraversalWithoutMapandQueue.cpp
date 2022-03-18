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
public:
    void findMM(TreeNode *root,int &mini,int &maxi,int cur){
        if(root==NULL)return;
        if(cur<mini)mini=cur;
        if(cur>maxi)maxi=cur;
        
        findMM(root->left,mini,maxi,cur-1);
        findMM(root->right,mini,maxi,cur+1);
    }
    void solution(TreeNode *root,int line_no,int no,vector<int>&v1){
        if(root==NULL)return;
        if(no==line_no){
             //sort(v1.begin(),v1.end());
            v1.push_back(root->val);
           
        }
        solution(root->left,line_no,no-1,v1);
        solution(root->right,line_no,no+1,v1);
    }
    void mainsolution(TreeNode *root,vector<vector<int>>&ans,int &mini,int &maxi){
        
        int cur=0;
        findMM(root,mini,maxi,0);
        for(int line_no=mini;line_no<=maxi;++line_no){
            vector<int>v1;
            solution(root,line_no,0,v1);
           //sort(v1.begin(),v1.end());
            ans.push_back(v1);
        }
        
    }
    
    
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>>ans;
        int mini=0,maxi=0;
        mainsolution(root,ans,mini,maxi);
        //cout<<mini<<maxi<<endl;
        return ans;
        
    }
    
};