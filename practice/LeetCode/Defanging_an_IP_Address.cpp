// https://leetcode.com/problems/defanging-an-ip-address/
// Accepted    0 ms

class Solution {
public:
    string defangIPaddr(string address, string osf = "") {
        if(address.empty())
            return osf;
        else if(address.front() == '.')
            return defangIPaddr(address.substr(1), osf + "[.]");
        else
            return defangIPaddr(address.substr(1), osf + address.front());
    }
};