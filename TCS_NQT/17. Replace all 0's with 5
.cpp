int convertFive(int n) {
    string s = to_string(n);
    int l = s.size();
    for(int i = 0; i<l; i++) {
        if (s[i] == '0') s[i] = '5';
    }
    return stoi(s);
}

int convertFive(int n) {
    int ans = 0;
    int m = 1;
    while(n) {
        int r = n % 10;
        if (r==0) r = 5;
        ans = m*r + ans;
        m*=10;
        n/=10;
    }
    return ans;
}
