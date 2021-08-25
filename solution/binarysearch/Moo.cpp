string solve(string cows) {
    int n = cows.size();
    // left[i] = nearest prev index where val = R
    // right[i] = nearest next index whrere val = L
    vector<int> left(n, -1), right(n, n);

    // find the nearest prev index where val = R
    for (int i = 1; i < n; i += 1) {
        if (cows[i-1] == 'R')
            left[i] = i-1;
        else if (cows[i-1] == 'L')
            left[i] = -1;
        else
            left[i] = left[i-1];
    }

    // find the nearest next index where val = L
    for (int i = n-2; i >= 0; i -= 1) {
        if (cows[i+1] == 'L')
            right[i] = i + 1;
        else if (cows[i+1] == 'R')
            right[i] = n;
        else
            right[i] = right[i+1];
    }

    // update each cell where val = @
    for (int i = 1; i < n-1; i += 1) {
        if (cows[i] != '@')
            continue;
        int il = left[i], ir = right[i];
        int distL = i - il, distR = ir - i;
        
        if (left[i] == -1 && right[i] == n)
            continue;
        else if (left[i] == -1) 
            cows[i] = 'L';
        else if (right[i] == n)
            cows[i] = 'R';
        else if (distL == distR)
            continue;
        else if (distL < distR)
            cows[i] = 'R';
        else 
            cows[i] = 'L';
    }

    // separately update index 0, n-1
    if (n > 1) {
        if (cows[1] == 'L' && cows[0] == '@')
            cows[0] = 'L';
        if (cows[n-2] == 'R' && cows[n-1] == '@')
            cows[n-1] = 'R';
    }

    return cows;
}
