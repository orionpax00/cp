long long kadanes(vector<int>& v){
  long long ans = INT_MIN, temp=0;
  for(int x: v){
    temp += x;
    ans = max(ans, temp);
    temp = max(temp, 0);
  }
  return ans;
}
