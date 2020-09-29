class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int a[], int n, int x) {
	    int low;
	    int l = 0, r = n - 1;
	   // 1 1 2 2 2 2 3
	    
	    while(l < r){
	        int mid = (l+r)/2;
	        if(a[mid] >= x){
	            r = mid;
	        }else l = mid + 1;
	    }
	    low = l;
	    l = 0; r = n - 1;
	    while(l < r){
	        int mid = (l+r)/2;
	        if(a[mid] <= x){
	            l = mid;
	        }else r = mid - 1;
	    }
	    
	    return r - low + 1;
	}
};
