// https://www.geeksforgeeks.org/print-nodes-top-view-binary-tree/

class Solution {
    public:
      
      void oragnizeAnsFromMap(map<int, int>& hdToNodemap, vector<int>& ans){
          for(auto i: hdToNodemap){
              ans.push_back(i.second);
          }
      }
      
      vector<int> topView(Node *root) {
          // code here
              
          map<int, int> hdToNodemap;  // node andhorizontal distance 
          queue< pair<Node*, int> >q;
          
          q.push(make_pair(root,0));
          
          while(!q.empty()){
              pair<Node*, int> top = q.front();
              q.pop();
              
              Node* frontNode = top.first;
              int hd = top.second;
              
              // if there is no entry in map then create a new entry
              if(hdToNodemap.find(hd)==hdToNodemap.end()){
                  hdToNodemap[hd] = frontNode->data;
              }
              
              // child ko dekhna he
              if(frontNode->left != NULL){
                  q.push(make_pair(frontNode->left, hd-1));
              }
              if(frontNode->right != NULL){
                  q.push(make_pair(frontNode->right, hd+1));
              }
          }
          
          vector<int> ans;
          oragnizeAnsFromMap(hdToNodemap, ans);
          return ans;
      }
  };
  