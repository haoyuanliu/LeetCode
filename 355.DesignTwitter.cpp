class Twitter
{
    struct tweet
    {
        int userId;
        int tweetId;
        int tweetTime;
        tweet(int userId_, int tweetId_) : userId(userId_), tweetId(tweetId_) {}
    };

    int userId;
    int time = 0;
    unordered_map<int, vector<tweet>> userToTweet;
    unordered_map<int, unordered_set<int>> userToFollowee;

public:
    /** Initialize your data structure here. */
    Twitter()
    {
        userId = 0;
        time++;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        tweet temp = tweet(userId, tweetId);
        temp.tweetTime = time++;
        userToTweet[userId].push_back(temp);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        vector<int> res;
        priority_queue<pair<int, int>> que;
        int count = 0;
        for(auto const tweet : userToTweet[userId])
        {
            que.push(make_pair(tweet.tweetTime, tweet.tweetId));
        }
        for(auto const followee : userToFollowee[userId])
        {
            for(auto const tweet : userToTweet[followee])
            {
                que.push(make_pair(tweet.tweetTime, tweet.tweetId));
            }
        }
        while(!que.empty())
        {
            res.push_back(que.top().second);
            que.pop();
            if(++count >= 10)
                break;
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        if(followerId != followeeId)
            userToFollowee[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        userToFollowee[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
