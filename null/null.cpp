class Solution {
public:
    vector<int> dailyTemperatures(const vector<int>& temperatures) {
        std::stack<int> myIndexStack;
        std::vector<int> result(temperatures.size(), 0);
        for (auto currentTempIdx = 0; currentTempIdx < temperatures.size(); ++currentTempIdx) {
            auto currentTemp = temperatures[currentTempIdx];
            while (!myIndexStack.empty() && temperatures[myIndexStack.top()] < currentTemp) {
                auto prevDayIdx = myIndexStack.top();
                myIndexStack.pop();
                result[prevDayIdx] = currentTempIdx-prevDayIdx;
            }
            myIndexStack.push(currentTempIdx);
        }
        return result;
    }
};