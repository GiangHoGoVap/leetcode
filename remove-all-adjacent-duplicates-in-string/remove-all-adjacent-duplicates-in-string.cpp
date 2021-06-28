class Solution {
public:
    string removeDuplicates(string S) {
    	stack<char> s;
	    for (unsigned i=0; i<S.length(); ++i){
		    if (s.empty() || s.top() != S[i]) s.push(S[i]);
		    else s.pop();
	    }
	    string res = "";
	    while (!s.empty()){
		    res = s.top() + res;
		    s.pop();
	    }
	    return res;
    }
};