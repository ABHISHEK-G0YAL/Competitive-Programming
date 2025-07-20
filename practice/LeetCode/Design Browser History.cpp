// https://leetcode.com/problems/design-browser-history/

class BrowserHistoryUsingStacks {
    string currentUrl;
    stack<string> backHistory;
    stack<string> forwardHistory;
public:
    BrowserHistoryUsingStacks(string homepage) {
        this->currentUrl = homepage;
    }
    
    void visit(string url) {
        backHistory.push(currentUrl);
        stack<string>().swap(forwardHistory);
        currentUrl = url;
    }
    
    string back(int steps) {
        while (steps-- && !backHistory.empty()) {
            forwardHistory.push(currentUrl);
            currentUrl = backHistory.top();
            backHistory.pop();
        }
        return currentUrl;
    }
    
    string forward(int steps) {
        while (steps-- && !forwardHistory.empty()) {
            backHistory.push(currentUrl);
            currentUrl = forwardHistory.top();
            forwardHistory.pop();
        }
        return currentUrl;
    }
};

class BrowserHistory {
    vector<string> history;
    int idx = -1;
public:
    BrowserHistory(string homepage) {
        visit(homepage);
    }
    
    void visit(string url) {
        ++idx;
        // delete forward history
        if (idx < history.size()) {
            history.resize(idx);
        }
        history.push_back(url);
    }
    
    string back(int steps) {
        if (!history.empty()) {
            idx = max(idx - steps, 0);
        }
        return history[idx];
    }
    
    string forward(int steps) {
        if (!history.empty()) {
            idx = min(idx + steps, int(history.size() - 1));
        }
        return history[idx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */