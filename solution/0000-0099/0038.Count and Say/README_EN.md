# [38. Count and Say](https://leetcode.com/problems/count-and-say)

[中文文档](/solution/0000-0099/0038.Count%20and%20Say/README.md)

## Description

<p>The <strong>count-and-say</strong> sequence is a sequence of digit strings defined by the recursive formula:</p>

<ul>
	<li><code>countAndSay(1) = &quot;1&quot;</code></li>
	<li><code>countAndSay(n)</code> is the way you would &quot;say&quot; the digit string from <code>countAndSay(n-1)</code>, which is then converted into a different digit string.</li>
</ul>

<p>To determine how you &quot;say&quot; a digit string, split it into the <strong>minimal</strong> number of groups so that each group is a contiguous section all of the <strong>same character.</strong> Then for each group, say the number of characters, then say the character. To convert the saying into a digit string, replace the counts with a number and concatenate every saying.</p>

<p>For example, the saying and conversion for digit string <code>&quot;3322251&quot;</code>:</p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0038.Count%20and%20Say/images/countandsay.jpg" style="width: 581px; height: 172px;" />
<p>Given a positive integer <code>n</code>, return <em>the </em><code>n<sup>th</sup></code><em> term of the <strong>count-and-say</strong> sequence</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> &quot;1&quot;
<strong>Explanation:</strong> This is the base case.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 4
<strong>Output:</strong> &quot;1211&quot;
<strong>Explanation:</strong>
countAndSay(1) = &quot;1&quot;
countAndSay(2) = say &quot;1&quot; = one 1 = &quot;11&quot;
countAndSay(3) = say &quot;11&quot; = two 1&#39;s = &quot;21&quot;
countAndSay(4) = say &quot;21&quot; = one 2 + one 1 = &quot;12&quot; + &quot;11&quot; = &quot;1211&quot;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 30</code></li>
</ul>

## Solutions

<!-- tabs:start -->

### **Python3**

```python
class Solution:
    def countAndSay(self, n: int) -> str:
        s = '1'
        for _ in range(n - 1):
            i = 0
            t = []
            while i < len(s):
                j = i
                while j < len(s) and s[j] == s[i]:
                    j += 1
                t.append(str(j - i))
                t.append(str(s[i]))
                i = j
            s = ''.join(t)
        return s
```

### **Java**

```java
class Solution {
    public String countAndSay(int n) {
        String s = "1";
        while (--n > 0) {
            StringBuilder t = new StringBuilder();
            for (int i = 0; i < s.length();) {
                int j = i;
                while (j < s.length() && s.charAt(j) == s.charAt(i)) {
                    ++j;
                }
                t.append((j - i) + "");
                t.append(s.charAt(i));
                i = j;
            }
            s = t.toString();
        }
        return s;
    }
}
```

### **C++**

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while (--n)
        {
            string t = "";
            for (int i = 0; i < s.size();)
            {
                int j = i;
                while (j < s.size() && s[j] == s[i]) ++j;
                t += to_string(j - i);
                t += s[i];
                i = j;
            }
            s = t;
        }
        return s;
    }
};
```

### **Go**

```go
func countAndSay(n int) string {
	s := "1"
	for k := 0; k < n-1; k++ {
		t := &strings.Builder{}
		i := 0
		for i < len(s) {
			j := i
			for j < len(s) && s[j] == s[i] {
				j++
			}
			t.WriteString(strconv.Itoa(j - i))
			t.WriteByte(s[i])
			i = j
		}
		s = t.String()
	}
	return s
}
```

### **...**

```

```

<!-- tabs:end -->
