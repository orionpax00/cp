    bool canPartition(vector<int>& nums) {
        bitset<100*200 + 1> bits(1); // 100*200 + 1 max sum possible
        int sum = 0; for(int x : nums) sum += x;
        
        if(sum&1) return 0;
        for(int num: nums){
            bits |= bits << num;
        }
        
        return bits[sum/2];
    }
