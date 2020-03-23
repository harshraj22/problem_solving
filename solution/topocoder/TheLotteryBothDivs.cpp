// https://community.topcoder.com/stat?c=problem_statement&pm=11359

#include<bits/stdc++.h>
using namespace std;

class TheLotteryBothDivs {
	#define ll long long int 

	ll power(ll x=10, ll y=1, ll mod = 1e12+7){
		ll res = 1;
		while(y > 0){
			if(y & 1)
				res = (res * x) % mod;
			y = y >> 1;
			x = (x*x)% mod;
		}
		return res % mod;
	}

	public:

		bool belongs(string to, string self) {
			// check if string 'self' belongs to the string 'to' as a suffix
			if (to.size() < self.size())
				return false;

			// if it has to be a suffix, match the last characters
			string temp = to.substr((int)to.size()-self.size(), self.size());
			return temp == self;
		}

		double find(vector<string> goodSuffixes) {
			int N = goodSuffixes.size();

			// N is small enough to allow such complexity get accepted
			for (int i=0;i<N;i++) {
				for (int j=i+1; j<N;j++) {
					// if one of the strings is "", it must belong to other
					// we don't want that, as no original string is ""
					if (goodSuffixes[j].size() == 0)
						continue;
					else if (goodSuffixes[i].size() == 0)
						continue;
					// if goodSuffixes[i] belongs to goodSuffixes[j]
					else if (belongs(goodSuffixes[i], goodSuffixes[j]))
						goodSuffixes[i] = "";
					else if(belongs(goodSuffixes[j], goodSuffixes[i]))
						goodSuffixes[j] = "";
				}
			}

			double ans = 0;

			for (auto it:goodSuffixes) {
				int n = it.size();
				// if n==0, that means it was like "442" (see input array in main())
				// with some "42" already present
				if (n==0)
					continue;
				ans += 1.0/this->power(10,n);
			}
			return ans;
		}
};

/* 
int main() {
	auto obj = TheLotteryBothDivs();

	// for given pair of strings, answer should be calculated considering
	// only "42". Think why, this is the reason, we are removing some
	// strings.
	vector<string> v = {"442", "42"};
	cout << fixed << setprecision(8) << obj.find(v) << '\n';

	return 0;
}

 */