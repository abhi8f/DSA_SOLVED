bool isValidBST(vector<int> &order){
   int n = order.size();
   if (n<2) return true;
   for(int i=1; i<n; i++) {
       if (order[i-1]>=order[i]) return false;
   }
   return true;
}
