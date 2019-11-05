// https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring/0

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test;
	cin >> test;
	while(test--){
		
		string s;
		int k, i=0, j=0, ans = -1;
		// the sliding window extends from 'i' to 'j' (including both)
		cin >> s >> k;
		map<char, int> mp;
		// map to store all characters and their counts of occurence in 'i' to 'j' (both included)
	
		for( ;j<s.size();j++){
			// we expect size of mp <= k for each step
			// increase count of each newly found character in the current window
			mp[s[j]] += 1;

			// if number of distinct characters in the current window exceeds the max allowed, shrink the window size form left
			while(mp.size() > k){
				mp[s[i]] -= 1;

				// if the current removed character was the last in the current window, remove it
				if(mp[s[i]] == 0){
					mp.erase(s[i]);
				}

				// shrink the window size
				i +=1 ;
			}

			// if current window has exactly k distinct elements, update out possible answer
			if(mp.size() == k)
				ans = max(ans, j-i+1);
		}

		cout << ans << '\n';
	}
	return 0;
}