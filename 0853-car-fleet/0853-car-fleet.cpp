class Solution {
 public:
  int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
    std::vector<std::pair<int, int>> cars;
    for (int i = 0; i < position.size(); ++i) {
      cars.push_back(std::make_pair(position[i], speed[i]));
    }
    std::sort(cars.begin(), cars.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
      return a.first > b.first;
    });
    int fleet = 0;
    double time = 0;
    for (const auto& car : cars) {
      if (car.first + car.second * time < target) {
        ++fleet;
        time = static_cast<double>(target - car.first) / car.second;
      }
    }
    return fleet;      
  }
};