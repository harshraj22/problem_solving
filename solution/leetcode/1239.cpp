// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
// another bitmask based solution
// mask each alphabet

class Solution {
	bool isSet(int bit, long long int num) {
		return num & (1LL << bit);
	}

	int countBit(long long int num) {
		int ans = 0;
		for (int i = 0; i < 64; i += 1) 
			ans += isSet(i, num);
		return ans;
	}

	long long int setBit(int bit, long long int num) {
		return num | (1LL << bit);
	}

	vector<long long int> v;
	long long int ans;

	void recur(int index, long long int encode) {
		if (countBit(ans) < countBit(encode))
			ans = encode;
		if (index < 0) return;
		recur(index-1, encode);
		if ((encode & v[index]) == 0) 
			recur(index-1, encode | v[index]);
	}

public:
    int maxLength(vector<string>& arr) {
		int n = arr.size();
		v = vector<long long int> (n, 0);

		for (int i = 0; i < n; i += 1) {
			string s = arr[i];
			for (auto ch: s) {
				if (isSet(ch-'a', v[i])) {
					v[i] = 0; break;
				}
				v[i] = setBit(ch-'a', v[i]);
			}
		}

		recur(n-1, 0);

		return countBit(ans);
    }
};