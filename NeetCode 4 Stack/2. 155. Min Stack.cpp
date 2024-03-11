class MinStack {
    class ValMin {
        public int val;
        public int mn;

        public ValMin(int val, int mn) {
            this.val = val;
            this.mn = mn;
        }
    }

    Stack<ValMin> stk;

    public MinStack() {
        stk = new Stack<>();
    }

    public void push(int val) {
        if (stk.empty()) {
            stk.push(new ValMin(val, val));
        } else {
            int mn = Math.min(val, stk.peek().mn);
            stk.push(new ValMin(val, mn));
        }
    }

    public void pop() {
        if (!stk.empty()) {
            stk.pop();
        }
    }

    public int top() {
        return stk.peek().val;
    }

    public int getMin() {
        return stk.peek().mn;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
