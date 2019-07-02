// usage : https://www.codechef.com/viewsolution/25026640

vector<string> split (string s, string delimiter){
/*
	Beware of mixing '>>' with getline(cin,str) as '>>' leaves '\n' in buffer 
	which is taken by getline(cin,str); use cin.ignore() or std::fflush(stdin)
	when getline() is followed by '>>'
*/
	if(s.back()=='\n')s=s.substr(0,(int)s.size()-1);
	//removing newline char (if exists)
    
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;	vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}