class Solution {
public:
    bool isPossible(vector<int>& v, int m, int total) {
        int splits = 1, sum = 0;

        for (auto it : v) {
            if (sum + it > total) {
                splits++;
                sum = it;
            } else {
                sum += it;
            }
        }

        return splits <= m;
    }

    int splitArray(vector<int>& v, int m) {

        int low = 0, high = 0, ans = 0;

        for (int it : v) {
            low = max(low, it);
            high += it;
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(v, m, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};