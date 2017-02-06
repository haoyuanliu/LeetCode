//Solution I
class Solution
{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int res;
        priority_queue<int> que;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix.size(); ++j)
            {
                que.push(-matrix[i][j]);
            }
        }
        for(int i = 0; i < k && !que.empty(); ++i)
        {
            res = -que.top();
            que.pop();
        }
        return res;
    }
};

//Solution II
class Solution
{
    struct Node
    {
        int idx;
        int idy;
        int val;
        Node(int x, int y, int v) : idx(x), idy(y), val(v) {}
        bool operator < (const Node &ref) const { return val > ref.val; }
    };
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int res;
        int len = matrix.size();
        priority_queue<Node> que;
        int left = 0;
        int right = 0;
        que.push(Node(left, right, matrix[left][right]));
        for(int i = 1; i < k; ++i)
        {
            left = que.top().idx;
            right = que.top().idy;
            que.pop();
            if(left == 0 && right+1 < len) que.push(Node(left, right+1, matrix[left][right+1]));
            if(left+1 < len) que.push(Node(left+1, right, matrix[left+1][right]));
        }
        return que.top().val;
    }
};
