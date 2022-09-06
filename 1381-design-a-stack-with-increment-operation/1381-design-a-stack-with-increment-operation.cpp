class CustomStack {
public:
    int cap;
    vector<int> nums;
    vector<int> inc;
    CustomStack(int maxSize) {
        cap = maxSize;
        nums.clear();
        inc.clear();
    }
    
    void push(int x) {
        if(nums.size() == cap) return;
        nums.push_back(x);
        inc.push_back(0);
    }
    int pop() {
        if(nums.size() == 0) return -1;
        int ans = nums.back()+inc.back();
        if(inc.size() != 1) {
            inc[inc.size()-2] += inc.back();
        }
        inc.pop_back();
        nums.pop_back();
        return ans;
    }
    void increment(int k, int val) {
        int n = inc.size();
        if(n == 0) return;
        inc[min(k, n)-1] += val;
    }
};