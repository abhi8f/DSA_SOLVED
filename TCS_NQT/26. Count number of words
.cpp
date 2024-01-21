int countWords(string s)
{
    string ns = "";

    bool slash = false;
    for(char& c: s) {
        if (c=='\\') {
            slash = true;
        } else if (slash) {
            slash = false;
            if (c == 'n') {
                ns += '\n';
            } else {
                ns += '\t';
            }
        } else {
            slash = false;
            ns += c;
        }
    }

    stringstream ss(ns);
    string temp;
    int count = 0;
    while(ss>>temp) {
        count++;
    }
    return count;
}
