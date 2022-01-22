class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> stones(n+1, false);
        stones[1] = true;
        
        for(int i=2;i*i<=n;i++)
        {
            stones[i*i] = true;
        }
        for(int i=2;i<=n;i++)
        {
            if(stones[i]==true)
                continue;
            
            int idx = 1;
            while(idx*idx<=n and i>=idx*idx)
            {
                if(stones[i-idx*idx]==false)
                {
                    stones[i] = true;
                    break;
                }
                idx++;
            }
        }
        return stones[n];
    }
};