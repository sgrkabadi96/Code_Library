class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int> > s;
    priority_queue<int> f;
    MedianFinder() {
       
    }
    
    void addNum(int num) {
        if(f.size() == 0 || num < f.top()) {
            f.push(num);
        } else  s.push(num);
        
        if(f.size() > s.size() + 1) {
            s.push(f.top());
            f.pop();
        }
        else if( s.size() > f.size() + 1 ) {
            f.push(s.top());
            s.pop();
        }
    }
    
    double findMedian() {
        if(s.size() == f.size()) {
            if(f.size() == 0) return 0;
            return double(s.top() + f.top()) / 2 ;
        } else if(f.size() > s.size()) return f.top();
        
        return s.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */