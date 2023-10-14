int countStudents(vector<int> &arr, int pages){
    int curPages=pages, student=1;
    for(int x: arr){
        if (curPages>=x) curPages -= x;
        else student++, curPages = pages - x;
    }
    return student;
}

int findPages(vector<int>& arr, int n, int m) {
    if (m>n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int mid, student;
    while(low <= high) {
        mid= low + (high - low)/2;
        
        student = countStudents(arr, mid);
        
        if (student <= m) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}