#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
public:
    
    priority_queue<int> Left_PQ;
    priority_queue<int, vector<int>, greater<int>> Right_PQ;
    int total_num = 0;
    
    MedianFinder() {
        total_num = 0;
    }
    
    void addNum(int num) {
        if(Left_PQ.empty())
        {
            Left_PQ.emplace(num);
            ++total_num;
            return;
        }
        
        if(num <= Left_PQ.top())
        {
            Left_PQ.emplace(num);
        }
        else
        {
            Right_PQ.emplace(num);
        }
        
        if(Left_PQ.size() > Right_PQ.size()+1)
        {
            Right_PQ.emplace(Left_PQ.top());
            Left_PQ.pop();
        }
        
        if(Right_PQ.size() > Left_PQ.size()+1)
        {
            Left_PQ.emplace(Right_PQ.top());
            Right_PQ.pop();
        }
        ++total_num;
    }
    
    double findMedian() {
        if(total_num % 2 == 0)
        {
            return (long long)(Left_PQ.top() + Right_PQ.top())*0.5;
        }
        else
        {
            return Left_PQ.size() > Right_PQ.size()? Left_PQ.top():Right_PQ.top();
        }
    }
};