class Solution
{
public:
	bool isPalindrome(string str)
	{
		int begin = 0, end = str.size() - 1;
		while (begin <= end)
		{
			if (str[begin] != str[end])
			{
				return false;
			}
			begin++;
			end--;
		}
		return true;
	}
	bool validPalindrome(string s)
	{
		if (isPalindrome(s))
		{
			return true;
		}
		int i = 0, j = s.size() - 1;
		while (i <= j)
		{
			if (s[i] != s[j])
			{
				break;
			}
			i++;
			j--;
		}
		string s1 = s.substr(0, i) + s.substr(i + 1, s.size());
		string s2 = s.substr(0, j) + s.substr(j + 1, s.size());
		if (isPalindrome(s1) or isPalindrome(s2))
		{
			return true;
		}
		return false;
	}
};