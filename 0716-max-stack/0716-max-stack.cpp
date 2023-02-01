class MaxStack {
    using CountT = unsigned;
    using ValueT = int;
    std::set<pair<CountT, ValueT>> theStack;
    std::set<pair<ValueT, CountT>> theMaxEntrySet;
    CountT theNextId{0};

public:
    void push(ValueT x) {
        theStack.emplace(theNextId, x);
        theMaxEntrySet.emplace(x, theNextId);
        ++theNextId;
    }
    
    ValueT pop() {
        const auto [myId, myValue] = *theStack.rbegin();
        theStack.erase(std::make_pair(myId, myValue));
        theMaxEntrySet.erase(std::make_pair(myValue, myId));
        return myValue;
    }
    
    ValueT top() {
        return (*theStack.rbegin()).second;
    }
    
    ValueT peekMax() {
        return (*theMaxEntrySet.rbegin()).first;
    }
    
    int popMax() {
        const auto [myValue, myId] = *theMaxEntrySet.rbegin();
        theMaxEntrySet.erase(std::make_pair(myValue, myId));
        theStack.erase(std::make_pair(myId, myValue));
        return myValue;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */