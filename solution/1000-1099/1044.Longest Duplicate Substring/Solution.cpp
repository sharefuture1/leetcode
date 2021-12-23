typedef unsigned long long ULL;

class Solution {
public:
    ULL p[30010];
    ULL h[30010];
    string longestDupSubstring(string s) {
        int base = 131, n = s.size();
        p[0] = 1;
        for (int i = 0; i < n; ++i)
        {
            p[i + 1] = p[i] * base;
            h[i + 1] = h[i] * base + s[i];
        }
        int left = 0, right = n;
        string ans = "";
        while (left < right)
        {
            int mid = (left + right + 1) >> 1;
            string t = check(s, mid);
            if (t.size() > ans.size()) ans = t;
            if (t.size() > 0) left = mid;
            else right = mid - 1;
        }
        return ans;
    }

    string check(string s, int len) {
        int n = s.size();
        unordered_set<ULL> seen;
        for (int i = 1; i + len - 1 <= n; ++i)
        {
            int j = i + len - 1;
            ULL t = h[j] - h[i - 1] * p[j - i + 1];
            if (seen.count(t)) return s.substr(i - 1, len);
            seen.insert(t);
        }
        return "";
    }
};