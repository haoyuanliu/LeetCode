//Solution I
class MedianFinder
{
    priority_queue<int> small, large;
public:
    void addNum(int num)
    {
        if(!large.empty() && -large.top() < num)
            large.push(-num);
        else
            small.push(num);
        if(small.size() - large.size() == 2)
        {
            large.push(-small.top());
            small.pop();
        }
        else if(large.size() -  small.size() == 2)
        {
            small.push(-large.top());
            large.pop();
        }
    }

    double findMedian()
    {
        if(small.size() > large.size()) return small.top();
        else if(small.size() < large.size()) return -large.top();
        else return (small.top() - large.top()) / 2.0;
    }
};

//Solution II
class MedianFinder
{
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
public:

    // Adds a number into the data structure.
    void addNum(int num)
    {
        if(left.empty())
        {
            left.push(num);
            return;
        }
        if(num <= left.top())
        {
            left.push(num);
            if(left.size() - right.size() > 1)
            {
                right.push(left.top());
                left.pop();
            }
        }
        else
        {
            right.push(num);
            if(right.size() - left.size() > 1)
            {
                left.push(right.top());
                right.pop();
            }
        }
    }

    // Returns the median of current data stream
    double findMedian()
    {
        if(left.size() == right.size())
            return (left.top() + right.top()) / 2.0;
        else if(left.size() > right.size()) return left.top();
        else return right.top();
    }
};
