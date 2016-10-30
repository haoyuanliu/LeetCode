class Solution {
public:
    int thirdMax(vector<int>& nums)
    {
        bool status = true;//定义一个bool值，仅仅第一个(1<<31)才进行计数
        int count = 0;//定义一个count变量，记录不同数字出现的个数
        int one, two, three;//记录第一大、第二大、第三大数
        one = two = three = 1<<31;//初始化为最小值

        for(auto x : nums)
        {
            if(status && x == 1<<31)//第一次出现(1<<31)，计数加一
            {
                count++;
                status = false;
            }
            if(x > one)
            {
                three = two;
                two = one;
                one = x;
                count++;
            }
            else if(x > two && x < one)
            {
                three = two;
                two = x;
                count++;
            }
            else if(x > three && x < two)
            {
                three = x;
                count++;
            }
        }

        if(count < 3)
            return one;
        else
            return three;
    }
};
