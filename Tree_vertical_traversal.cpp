#include<iostream> 
#include<map> 
#include<queue> 
#include<vector> 

using namespace std; 
struct TreeNode{
     int val; 
     TreeNode* left; 
     TreeNode* right; 
     TreeNode(): val(0), left(nullptr), right(nullptr){}
     TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
     TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right){}
}; 

class Solution{
public: 
      vector<vector<int>> verticalOrder(TreeNode* root){
        vector<vector<int>> res; 
        if(!root) return res; 
        map<int, vector<int>> mp; 
        queue<pair<TreeNode*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()){
          auto [node, hd] = q.front(); 
          q.pop(); 
          mp[hd].push_back(node->val); 
          if(node->left) q.push({node->left, hd-1}); 
          if(node->right) q.push({node->right, hd+1}); 
        }
        for(auto [key, vec]: mp){
          res.push_back(vec); 
        }
        return res; 
        
      }
}; 
int main(){
  TreeNode* root = new TreeNode(3); 
  root->left = new TreeNode(9); 
  root->right = new TreeNode(20); 
  root->right->left = new TreeNode(15); 
  root->right->right = new TreeNode(7); 
  Solution sol; 
  vector<vector<int>> res= sol.verticalOrder(root); 
  for(auto vec:res){
    cout<< "[" ; 
    for(int num:vec) {
      cout << num << " " ; 
    }
    cout << "]" << endl; 
      
  }
  return 0; 
}
