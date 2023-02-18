class Twitter {
  int timestamp{0};
  std::unordered_map<int, std::vector<std::pair<int, int>>> tweets;
  std::unordered_map<int, std::unordered_set<int>> followees;
public:
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(timestamp, tweetId);
        timestamp++;
    }
    
    std::vector<int> getNewsFeed(int userId) {
        std::vector<int> res;
        std::priority_queue<std::pair<int, int>> pq;
        for (auto t : tweets[userId]) {
            pq.push(t);
        }
        for (const auto f : followees[userId]) {
            for (auto t : tweets[f]) {
                pq.push(t);
            }
        }
        for (int i = 0; i < 10 && !pq.empty(); ++i) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followees[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};