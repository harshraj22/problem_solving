// Problem: https://www.interviewbit.com/problems/longest-palindromic-substring/
// Video: (Code seems buggy there) https://www.youtube.com/watch?v=YVZttWzvyw8&feature=youtu.be

string LongestPalindrome(string A, bool preprocess) {
	int l = 0, r = -1, n;

	string s;
	// prepocess it, if you want to find even lenght palindrom 
	if (preprocess) {
		// even length palindromic substring
		s = "#";
		for (auto ch:A) {
			s += ch;
			s += '#';
		}
	}
	else {
		s = A;
	}

	n = s.size();

    // len[i] stores number of char to one side of s[i] 
    // (excluding char at s[i]) in the longest odd length
    //  palindrome centered at 'i'
	vector<int> len(n, 0);

    // [l, r] gives the range of palindrome(odd length)
    //  encountered till now with largest 'r'
	for (int i = 1; i < n - 1; i += 1) {
        // k is supposed to be len[i] for current 'i'
		int k = 0, j = 0;
		if (r < i) {
			k = 0;
		}
		else {
            // j+l is mirror image of 'i' with respect
            // to the center element of the palindrome
            // represented by [l, r]
			j = (r-i);
			k = min(len[j+l], r-i);
		}

        // extending boundaries of current palindrome
        // remember, this loop runs atleast once
		while(i+k<n && i-k>=0 && s[i+k] == s[i-k])
			k += 1;

        // remove 1 due to extra running of while loop
		len[i] = k - 1;

		if (r < i + k) {
			l = i - k;
			r = i + k;
		}
	}

	int index = max_element(len.begin(), len.end()) - len.begin();

	string ab = s.substr(index-len[index], 1+2*len[index]);

	string ans;
	for (auto ch:ab) {
		if (ch == '#')
			continue;
		ans += ch;
	}

	return ans;
}

string Solution::longestPalindrome(string A) {
    string evenLenPal = LongestPalindrome(A, true), oddLenPal = LongestPalindrome(A, false);
    if (evenLenPal.size() > oddLenPal.size())
        return evenLenPal;
    else 
        return oddLenPal;
}
