class Logger {
    std::unordered_map<std::string, int> messagesLastUsed;

public:
    bool shouldPrintMessage(int timestamp, string message) noexcept {
        const bool shouldPrint = messagesLastUsed.find(message) == messagesLastUsed.cend() || timestamp - messagesLastUsed[message] >= 10;
        if (shouldPrint) {
            messagesLastUsed[message] = timestamp;
        }
        return shouldPrint;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */