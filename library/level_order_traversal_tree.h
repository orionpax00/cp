vector<int> leftView(Node *root){
   vector<int> ans;
   queue<Node*> q;
   q.push(root); q.push(NULL);
   ans.push_back(-1);
   while(!q.empty()){
       Node* p = q.front();
       
       if(p != NULL){
           while(q.front() != NULL){
               ans.push_back(p->data);
               if(p->left != NULL) q.push(p->left);
               if(p->right != NULL) q.push(p->right);
               q.pop();
               p = q.front();
           }
           q.push(NULL); //to mark the starting of new level
           ans.push_back(-1);
       }
       q.pop();
   }
   return ans;
}
