class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry{0};
        string res{""};
        while (i >= 0 || j >= 0 || carry)
        {
            int sum{0};
            sum += carry;
            if (i >= 0)
            {
                sum = sum + (num1[i] - '0');
            }
            if (j >= 0)
            {
                sum = sum + (num2[j] - '0');
            }
            carry = sum / 10;
            sum = sum % 10;
            res.push_back(sum + '0');
            --i;
            --j;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};