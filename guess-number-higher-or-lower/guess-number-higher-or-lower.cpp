/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        int l = 1, r = n;
        while (l <= r)
        {
            int t = l + (r - l) / 2;
            if (guess(t) == 0)
                return t;
            if (guess(t) < 0)
                r = t - 1;
            else
                l = t + 1;
        }
        return 0;
    }
};