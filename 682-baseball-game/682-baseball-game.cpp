class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for (string op : ops) {
            if (op == "C") {
                s.pop();
            } else if (op == "D") {
                int temp = s.top();
                s.push(temp * 2);
            } else if (op == "+") {
                int temp1 = s.top();
                s.pop();
                int temp2 = s.top();
                s.push(temp1);
                s.push(temp1 + temp2);
            } else {
                s.push(stoi(op));
            }
        }
        
        int sum = 0;
        while (!s.empty()) {
            sum += s.top();
            s.pop();
        }
        
        return sum;
    }
};