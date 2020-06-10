// https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1
// Idea Used: Store two numbers at one index, 
// Alternate approach is to push num followed by min_fo_far into stack and handle queries likewise

/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

#define mod 102

/*returns min element from stack*/
int _stack :: getMin() {
    if (s.empty()) return -1;
    int var = s.top();
    return var/mod;
}

/*returns poped element from stack*/
int _stack ::pop() {
    if (s.empty()) return -1;
    int var = s.top();
    s.pop();
    return var % mod;
}

/*push element x into the stack*/
void _stack::push(int x) {
    int last_min = x;
    if (!s.empty()) {
        int num = s.top(), mn = num/mod;
        last_min = min(last_min, mn);
    } 

    s.push(x + mod*last_min);
}