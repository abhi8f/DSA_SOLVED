class Solution {
public:
    string longestPalindrome(string s) {
        int max=0, sz=s.size();
        string ss;
        for(int i=0;i<sz;i++){
            int pre=i-1, pos=i+1;
            while((0<=pre) && (pos<sz) && (s[pre]==s[pos])){
                pre--;
                pos++;
            }
            int l=pos-pre-1;
            if (max<l){
                max=l;
                ss=s.substr(pre+1, l);
            }

            pre=i; pos=i+1;
            while((0<=pre) && (pos<sz) && (s[pre]==s[pos])){
                pre--;
                pos++;
            }
            l=pos-pre-1;
            if (max<l){
                max=l;
                ss=s.substr(pre+1, l);
            }
        }
        return ss;
    }
};
