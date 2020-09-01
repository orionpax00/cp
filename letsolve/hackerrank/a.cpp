#include<bits/stdc++.h>
using namespace std;

string countLuck(vector<string> matrix, int k) {
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    pair<int,int> S;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]=='X'){
                visited[i][j]=true;
            }
        

            if(matrix[i][j]=='M'){
                S=make_pair(i,j);
            }
        }
    }
    vector<vector<bool>> direction(n,vector<bool>(m,false));
    queue<pair<int,int>> q;
    q.push(S);
    visited[S.first][S.second]=true;
    
    
    
    int count=0;
    while(!q.empty()){
        pair<int,int> p=q.front();
        q.pop();
        
        if(matrix[p.first][p.second]=='*'){
            
            break;
        }
        int temp=0;
        if(p.first-1>=0&&visited[p.first-1][p.second]==false){
            q.push(make_pair(p.first-1,p.second));
            visited[p.first-1][p.second]=true;
            temp++;
        }

        if(p.first+1<n&&visited[p.first+1][p.second]==false){
            q.push(make_pair(p.first+1,p.second));
            visited[p.first+1][p.second]=true;
                temp++;
        }
        

        if(p.second+1<m&&visited[p.first][p.second+1]==false){
            q.push(make_pair(p.first,p.second+1));
            visited[p.first][p.second+1]=true;
                temp++;
        }

        if(p.second-1>=0&&visited[p.first][p.second-1]==false){
            q.push(make_pair(p.first,p.second-1));
            visited[p.first][p.second-1]=true;
                temp++;
        }

        if(temp>1){
            direction[p.first][p.second]=true;
            count++;
        }
    // direction[p.first][p.second]=true;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<direction[i][j]<<" ";
        }
        cout<<endl;
    }



    if(count==k){
        return "Impressed";    
    }

    return "Oops!";
}


int main(){
	
	int n, m; cin >> n >> m;
  vector<string> input(n);
	for(int i = 0 ; i < n ; i++) cin >> input[i];
	
	string ans = countLuck(input, m);
	cout << ans;
		

	return 0;
}
