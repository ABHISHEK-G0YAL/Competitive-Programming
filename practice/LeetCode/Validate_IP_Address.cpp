// https://leetcode.com/problems/validate-ip-address/
// Accepted    0 ms

class Solution {
public:
    vector<string> split(string &s, char delim) {
        vector<string> v;
        string temp = "";
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != delim)
                temp += s[i];
            else {
                v.push_back(temp);
                temp = "";
            }
        }
        v.push_back(temp);
        return v;
    }
    bool isPartIPv4(string &s) {
        int n = s.size();
        if(n > 3 or n == 0)
            return false;
        for(int i = 0; i < n; i++)
            if(s[i] < '0' or s[i] > '9')
                return false;
        if(s.find('0') == 0 and n > 1)
            return false;
        int x = stoi(s);
        return x >= 0 and x <= 255;
    }
    bool isPartIPv6(string &s) {
        int n = s.size();
        if(n > 4 or n == 0)
            return false;
        for(int i = 0; i < n; i++)
            if((s[i] < '0' or s[i] > '9')
           and (s[i] < 'a' or s[i] > 'f')
           and (s[i] < 'A' or s[i] > 'F'))
                return false;
        return true;
    }
    bool isIPv4(string &ip) {
        vector<string> ipv = split(ip, '.');
        if(ipv.size() != 4)
            return false;
        for(int i = 0; i < 4; i++)
            if(isPartIPv4(ipv[i]) == false)
                return false;
        return true;
    }
    bool isIPv6(string &ip) {
        vector<string> ipv = split(ip, ':');
        if(ipv.size() != 8)
            return false;
        for(int i = 0; i < 8; i++)
            if(isPartIPv6(ipv[i]) == false)
                return false;
        return true;
    }
    string validIPAddress(string &IP) {
        if(isIPv4(IP))
            return "IPv4";
        else if(isIPv6(IP))
            return "IPv6";
        else
            return "Neither";
    }
};