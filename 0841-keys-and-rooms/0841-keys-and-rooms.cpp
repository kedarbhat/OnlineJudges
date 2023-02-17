class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        std::bitset<1024> visited{};
        std::deque<int> keys{0};
        while (!keys.empty()) {
            auto currentRoom = keys.front();
            keys.pop_front();
            visited[currentRoom] = true;
            for (auto neighborRoom : rooms[currentRoom]) {
                if (!visited[neighborRoom]) {
                    keys.push_back(neighborRoom);
                }
            }
        }
        return visited.count() == rooms.size();
    }
};