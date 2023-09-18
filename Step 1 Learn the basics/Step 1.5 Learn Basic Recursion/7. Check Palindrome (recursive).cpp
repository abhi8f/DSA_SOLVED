bool rec(int i, string &str){
    if (i<0) return true;
    if (str[i]!=str[str.size()-1-i]) return false;
    return rec(i-1, str);
}

bool isPalindrome(string& str) {
    return rec(str.size()/2-1, str);
}
