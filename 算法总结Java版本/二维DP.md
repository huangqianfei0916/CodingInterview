* 二维DP

* [杨辉三角](#1)

* [最小路径和](#2)

* [最长公共子序列](#3)

* [最长公共子串](#4)

* [编辑距离](#5)

* [最长回文子串](#6)

* 从矩阵左上角到右下角有多少种走法

  ******

<h4 id="1">杨辉三角</h4>

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200427161151248.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1NvX3RoYXQ=,size_16,color_FFFFFF,t_70)

* 动态规划
* base：所有为1的地方
* 递推：dp[i] [j]=dp[i-1] [j-1]+dp[i-1] [j];
```java
class Solution {
    public List<List<Integer>> generate(int numRows) {

        int [][]dp=new int[numRows][numRows];

        for(int i=0;i<numRows;i++){
            dp[i][0]=1;
        }
        for(int i=0;i<numRows;i++){
            dp[i][i]=1;
        }
        for(int i=2;i<numRows;i++){
            for(int j=1;j<i;j++){
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
        }
        List<List<Integer>> listall=new ArrayList();
        for(int i=0;i<numRows;i++){
            ArrayList<Integer>list=new ArrayList();
            for(int j=0;j<=i;j++){
                list.add(dp[i][j]);
            }
            listall.add(list);
        }
        return listall;

    }
}
```
***************
<h4 id="2">最小路径和</h4>
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。

* base：dp[0] [0]=grid[0] [0];
* 递推
* i==0 时，dp[i] [j]=grid[i] [j]+dp[i] [j-1];
* j==0时，dp[i] [j]=grid[i] [j]+dp[i-1] [j];
* 其余，dp[i] [j]=grid[i] [j]+Math.min(dp[i-1] [j],dp[i] [j-1]);
```java
class Solution {
    public int minPathSum(int[][] grid) {

        int [][]dp=new int [grid.length][grid[0].length];

        dp[0][0]=grid[0][0];
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                if(i==0){
                    if(j==0){
                        dp[i][j]=grid[0][0];
                    }else{
                        dp[i][j]=grid[i][j]+dp[i][j-1];
                    }
                }else if(j==0){
                    dp[i][j]=grid[i][j]+dp[i-1][j];
                }else{
                    dp[i][j]=grid[i][j]+Math.min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[dp.length-1][dp[0].length-1];
    }
}
```
<h4 id="3">最长公共子序列</h4>

**********
给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。

若这两个字符串没有公共子序列，则返回 0。

**base和递推公式：**
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200403203609642.png)

```java
class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        char[] s1 = text1.toCharArray();
		char[] s2 = text2.toCharArray();

		int dp[][] = new int[s1.length + 1][s2.length + 1];
		for (int i = 0; i < s2.length; i++) {
			dp[0][i] = 0;
		}
		for (int i = 0; i < s1.length; i++) {
			dp[i][0] = 0;
		}

		for (int i = 0; i < s1.length; i++) {
			for (int j = 0; j < s2.length; j++) {
				if (s1[i] == s2[j]) {
					dp[i + 1][j + 1] = dp[i][j] + 1;
				} else {
					dp[i + 1][j + 1] = Math.max(dp[i][j + 1], dp[i + 1][j]);
				}
			}
		}
		return dp[s1.length][s2.length];
    }
}

```
* 测试样例："abcde", "ace"
* dp输出：

**0 0 0 0 
0 1 1 1 
0 1 1 1 
0 1 2 2 
0 1 2 2 
0 1 2 3** 
*************

<h4 id="4">最长公共子串</h4>

********

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200418175358269.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1NvX3RoYXQ=,size_16,color_FFFFFF,t_70)
```java
	public int lcs(String text1, String text2) {

		char[] s1 = text1.toCharArray();
		char[] s2 = text2.toCharArray();

		int dp[][] = new int[s1.length + 1][s2.length + 1];
		for (int i = 0; i < s2.length; i++) {
			dp[0][i] = 0;
		}
		for (int i = 0; i < s1.length; i++) {
			dp[i][0] = 0;
		}
		int result = 0;

		for (int i = 0; i < s1.length; i++) {
			for (int j = 0; j < s2.length; j++) {
				if (s1[i] == s2[j]) {
					dp[i + 1][j + 1] = dp[i][j] + 1;
				} else {
					dp[i + 1][j + 1] = 0;
				}
				result = Math.max(result, dp[i + 1][j + 1]);
			}
		}
		return result;
	}
```
样例："loop", "helloword"
2
0 0 0 0 0 0 0 0 0 0 
0 0 0 1 1 0 0 0 0 0 
0 0 0 0 0 2 0 1 0 0 
0 0 0 0 0 1 0 1 0 0 
0 0 0 0 0 0 0 0 0 0 

*************************
<h4 id="5">编辑距离</h4>

*********

给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
示例 1:

输入: word1 = "horse", word2 = "ros"
输出: 3
解释: 
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')

**base:**
一个字符串的长度为0，编辑距离自然是另一个字符串的长度;
**递推：**
若当前比对的字符相等；则当前的编辑距离等于 去掉这两字符的编辑距离；也就是dp[i] [j]=dp[i-1] [j-1];
若是不相等；则取dp[i] [j]为dp[i-1] [j-1]+1,dp[i-1] [j]+1,dp[i] [j-1]+1;中的最小值。

```java
class Solution {
    public int minDistance(String word1, String word2) {
      int[][] dp = new int[word1.length() + 1][word2.length() + 1];

		for (int i = 0; i < word2.length() + 1; i++) {
			dp[0][i] = i;

		}
		for (int i = 0; i < word1.length() + 1; i++) {
			dp[i][0] = i;

		}
		for (int i = 0; i < word1.length(); i++) {
			for (int j = 0; j < word2.length(); j++) {
				if (word1.charAt(i) == word2.charAt(j)) {
					dp[i + 1][j + 1] = dp[i][j];
				} else {
					dp[i + 1][j + 1] = Math.min(dp[i][j + 1] + 1, Math.min(dp[i][j] + 1, dp[i + 1][j] + 1));
				}
			}
		}

		return dp[word1.length()][word2.length()];
    }
}
```
*******

<h4 id="6">最长回文子串</h4>

**题目描述**

给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

* 中心扩散法
```java
class Solution {
    public String longestPalindrome(String s) {
     if (s.isEmpty()) {
			return "";
		}
		char[] d = s.toCharArray();
		int start = 0;
		int end = d.length - 1;
		int len = 1;
		int maxlen = 0;
		int maxstart = 0;
		int left = 0;
		int right = 0;
		for (int i = start; i <= end; i++) {
			left = i - 1;
			right = i + 1;
			while (left >= 0 && d[left] == d[i]) {
				len++;
				left--;
			}
			while (right <= end && d[i] == d[right]) {
				len++;
				right++;
			}
	
			while (left >= 0 && right <= end && d[left] == d[right]) {
				left--;
				right++;
				len+=2;
			}
			if (len > maxlen) {
				maxlen = len;
				maxstart = left;
			}
			len = 1;
		}
		return s.substring(maxstart + 1, maxstart + maxlen + 1);
    }
}
```
* 动态规划
* j-i<3  表示左右之间的距离【i+1,j-1】-->  j-1-i-1+1 = j-i-i<2  -->  j-i<3
```java
public String longestPalindrome(String text1) {
        if(text1.length()<2){
            return text1;
        }

		char[] s1 = text1.toCharArray();

		int maxlen = 1;
		int start = 0;
        int end=0;
		int dp[][] = new int[s1.length][s1.length];
		for (int j = 1; j < s1.length; j++) {
			for (int i = 0; i < j; i++) {
				if (s1[i] == s1[j]) {
					if (j - i < 3) {
						dp[i][j] = 1;
					} else {
						dp[i][j] = dp[i + 1][j - 1];
					}
				} else {
					dp[i][j] = 0;
				}
				if (dp[i][j] == 1) {
					int cur = (j - i + 1);
					if (cur > maxlen) {
						maxlen = cur;
						start = i;
                        end=j;
					}
				}
			}
		}
		return text1.substring(start, maxlen+start);

	}
```

* 从矩阵左上角到右下角有多少种走法
```java
class Solution {
    public int uniquePaths(int m, int n) {
        int [][]dp=new int [m][n];
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];

    }
}
```

* 参考
*********
* https://blog.csdn.net/ggdhs/article/details/90713154