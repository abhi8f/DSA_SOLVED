string transform(string s)
{
    int n = s.size();
    if (n == 0) return 0;
    s[0]= toupper(s[0]);
    bool se = false;

    for(int i = 1; i < n; i++) {
        if (s[i] == ' ') se = true;
        else {
            if (se) {
                s[i] = toupper(s[i]);
                se = false;
            }
        }
    }
    return s;
}
