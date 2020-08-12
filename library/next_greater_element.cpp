template < typename T > 
map< int, int > nge(vector< T > arr) { //next greater element
	map< int, int> ans;
  stack < T > s;
	int n = arr.size(); 
  s.push(0); 
 
	for (int i = 1; i < n; i++) { 
    if (s.empty()) { 
      s.push(i); 
      continue; 
    }

		while (s.empty() == false && arr[s.top()] < arr[i]) {          
        ans[s.top()] = i; 
        s.pop(); 
    } 
  
    s.push(i); 
  }
	
	while (s.empty() == false) { 
		ans[s.top()] = -1;
    s.pop(); 
  }

	return ans; 
} 
