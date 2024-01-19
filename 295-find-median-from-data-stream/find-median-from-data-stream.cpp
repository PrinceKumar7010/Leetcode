class MedianFinder {
public:
   
  priority_queue<int,vector<int>,greater<int>> right;
   priority_queue<int> left;
    int mid;

    MedianFinder() {
     mid = INT_MAX;
    }
    
    void addNum(int num) {
     if(mid==INT_MAX){
         mid = num;
         return;
     }

     if(num>=mid){
         right.push(num);
     }

     else{
         left.push(num);
     }

     if(abs((int)left.size()-(int)right.size())>1){

      if(left.size()>right.size()){
          right.push(mid);
          mid  = left.top();
          left.pop();
      }

      else{
         left.push(mid);
          mid  = right.top();
          right.pop();
      }

     }


    }
    
    double findMedian() {
    
     int n = left.size()+right.size()+1;

     if(n%2) return mid;

     if(left.size()>right.size()){
         return (double)(mid+left.top())/2;
     }

     return (double)(mid+right.top())/2;

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */