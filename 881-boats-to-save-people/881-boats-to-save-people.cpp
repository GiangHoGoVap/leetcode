class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size(), count=0, right=n-1, left=0;
        sort(people.begin(), people.end());
        
        while(left<=right) {
            if(people[right]+people[left]>limit || right==left) {
                count++;
                right--;
            }
            else if(people[right]+people[left]<=limit) {
                count++;
                left++; right--;
            }
        }   
        return count;
    }
};