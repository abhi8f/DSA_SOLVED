int getWorkers(vector<int> &boards, int maxPaint) {
    int workers = 1, curPaint = maxPaint;
    
    for(int x: boards) {
        if (curPaint>=x) curPaint -= x;
        else workers++, curPaint = maxPaint - x;
    }
    return workers;
}

int findLargestMinDistance(vector<int> &boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    int mid, workers;

    while (low <= high) {
        
        mid = low + (high - low)/2;
        
        workers = getWorkers(boards, mid);

        if (workers <= k) high = mid - 1;
        else low = mid + 1;

    }
    return low;
}