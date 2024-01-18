class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       vector<int> count(26, 0);

       for(char& c: S) {
           count[c-'a']++;
       }
       for(char& c: S) {
           if (count[c-'a'] == 1) return c;
       }
       return '$';
    }

};
