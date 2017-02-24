class Solution
{
public:
    int trapRainWater(vector<vector<int>>& heightMap)
    {
        int res = 0;
        if(heightMap.size() <= 2)
            return res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        int row = heightMap.size();
        int col = heightMap[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));

        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(!(i==0 || i==row-1 || j==0 || j==col-1))
                    continue;
                que.push(make_pair(heightMap[i][j], i*col+j));
                visited[i][j] = 1;
            }
        }

        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int minHeight = 1<<31;

        while(!que.empty())
        {
            int height = que.top().first;
            int x = que.top().second / col;
            int y = que.top().second % col;
            que.pop();
            minHeight = max(minHeight, height);

            for(const auto d : dir)
            {
                int x2 = x + d[0];
                int y2 = y + d[1];
                if(x2 < 0 || x2 >= row || y2 < 0 || y2 >= col || visited[x2][y2])
                    continue;
                if(heightMap[x2][y2] < minHeight)
                    res += minHeight - heightMap[x2][y2];
                que.push(make_pair(heightMap[x2][y2], x2 * col + y2));
                visited[x2][y2] =  1;
            }
        }
        return res;
    }
};
