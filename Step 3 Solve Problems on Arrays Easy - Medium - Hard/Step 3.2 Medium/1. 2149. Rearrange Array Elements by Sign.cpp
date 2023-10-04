vector<int> alternateNumbers(vector<int>& nums) {
    queue<int> p, n;
    for(int x: nums) if (x<0) n.push(x); else p.push(x);
    vector<int> v;
    while(!p.empty() && !n.empty()) {
        v.push_back(p.front());
        p.pop();
        v.push_back(n.front());
        n.pop();
    }
    while(!p.empty()) v.push_back(p.front()), p.pop();

    while(!n.empty()) v.push_back(n.front()), n.pop();

    return v;
}