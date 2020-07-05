// https://www.interviewbit.com/problems/hotel-reviews/

vector<string> split(string s) {
    vector<string> words;
    string word;    s += '_';
    for (auto ch: s) {
        if (ch != '_')
            word += ch;
        else if (word.size()) {
            words.push_back(word);
            word = "";
        }
    }
    
    return words;
}

vector<int> Solution::solve(string A, vector<string> &B) {
    vector<string> ordered_words = split(A);
    unordered_set<string> good_words = {ordered_words.begin(), ordered_words.end()};
    unordered_map<int, int> freq;
    vector<vector<string>> samples;
    vector<int> answer(B.size());

    for (auto word: B)
    	samples.push_back(split(word));

    for (int i = 0; i < B.size(); i += 1) {
    	for (auto word: samples[i])
    		freq[i] += (good_words.find(word) != good_words.end());
    }
    
    for (int i = 0; i < answer.size(); i += 1)
    	answer[i] = i;

    stable_sort(answer.begin(), answer.end(), [&](int i, int j) {
    	// return i < j, actually i > j
    	if (freq[i] != freq[j])
    		return (freq[j] != 0 && freq[i] > freq[j]) || (freq[j] == 0);
    	return false;
    });
    
    return answer;
}
