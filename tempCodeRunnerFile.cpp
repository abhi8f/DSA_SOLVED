    if (i==0) return 0;
    return max(r(i-1, l, price), l>=i?price[i-1]+r(i, l-i, price):0);
}

int cutRod(vector<int> &price, int n) {
    return r(n, n, price);
}