### 一维度DP

* [打家劫舍](#1)
* [最长上升子序列](#2)
* [连续子数组的最大和](#3)
* [单词拆分](#4)
* 乘积最大子数组
******
<h4 id="1">打家劫舍</h4>

你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。

 * base: dp[0]=0;dp[1]=nums[0];
* 递推公式：dp[i]=Math.max(dp[i-1],dp[i-2]+nums[i-1]);
```java
class Solution {
    public int rob(int[] nums) {
        if(nums.length==0){
            return 0;
        }
       int dp[]=new int [nums.length+1];
       dp[0]=0;
       dp[1]=nums[0];
       for(int i=2;i<nums.length;i++){
           dp[i]=Math.max(dp[i-1],dp[i-2]+nums[i-1]);
       }
        return dp[dp.length-1];
    }
}
```
* 若是房屋是环形的；
* 考虑打劫方式为打劫除去最后一个的全部，打劫除去第一个的全部；取最大。
```java
public int rob(int[] nums) {
        if(nums.length==0){
            return 0;
        }
        if(nums.length==1){
            return nums[0];
        }
        
     int []a=new int[nums.length-1];
     int []b=new int[nums.length-1];
     System.arraycopy(nums,1,a,0,nums.length-1);
     System.arraycopy(nums,0,b,0,nums.length-1);
     return  Math.max( myRob(a),myRob(b) );

    }

    public int myRob(int [] nums){
           if(nums.length==0){
            return 0;
        }
        int []dp=new int [nums.length];
        
        if(nums.length==1){
            return nums[0];
        }
        if(nums.length==2){
            return nums[0]>nums[1]?nums[0]:nums[1];
        }
        dp[0]=nums[0];
        dp[1]=Math.max(nums[0],nums[1]);
        for(int i=2;i<dp.length;i++){
            dp[i]=Math.max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[dp.length-1];
    }
```

******
<h4 id="2">最长上升子序列</h4>

给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。

dp[i]=max(dp[j])+1,其中0≤j<i且num[j]<num[i]

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        if(nums.length==0){
            return 0;
        }
        int dp[]=new int [nums.length];

        for(int i=0;i<nums.length;i++){
            dp[i]=1;
        }
        int res=1;
        for(int i=1;i<nums.length;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=Math.max(dp[i],dp[j]+1);
                }
            }
            res=Math.max(res,dp[i]);
        }
        return res;
    }
}
```

******
<h4 id="3">连续子数组的最大和</h4>

**题目描述**
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)

* 解法1
* cur代表当前累加和；若这个值小于0则舍去；
* sum为记录最大值；
```java
public class Solution {
    public int FindGreatestSumOfSubArray(int[] array) {
        if(array.length==0){
            return 0;
        }
        int cur=array[0];
        int sum=array[0];
        
        for(int i=1;i<array.length;i++){
            if(cur<0){
                cur=array[i];
            }else{
                cur+=array[i];
            } 
            if(cur>sum){
                sum=cur;
            } 
        }
        return sum;
    }
}
```

* 解法2
* 动态规划
* base： dp[0]=array[0]
* 递推：dp[i]=Math.max(array[i],array[i]+dp[i-1]);

```java
   public int FindGreatestSumOfSubArray(int[] array) {
        if(array.length==0){
            return 0;
        }
        int sum=array[0];
        int dp[]=new int[array.length];
        dp[0]=array[0];
        for(int i=1;i<array.length;i++){
            dp[i]=Math.max(array[i],array[i]+dp[i-1]);
            sum=Math.max(sum,dp[i]);
        }
        return sum;     
    }
```

<h4 id="4">139 单词拆分</h4>
* 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

  说明：

  拆分时可以重复使用字典中的单词。
  你可以假设字典中没有重复的单词。
  示例 1：

  输入: s = "leetcode", wordDict = ["leet", "code"]
  输出: true
  解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。


```java
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        boolean[]dp=new boolean[s.length()+1];
        dp[0]=true;
        HashSet <String>set=new HashSet(wordDict);
        for(int i=1;i<=s.length();i++){
            for(int j=0;j<i;j++){
                if(dp[j]&&set.contains(s.substring(j,i))){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.length()];

    }
}
```

* 乘积最大子数组-152
  给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

  示例 1:

  输入: [2,3,-2,4]
  输出: 6
  解释: 子数组 [2,3] 有最大乘积 6。
  示例 2:

  输入: [-2,0,-1]
  输出: 0
  解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

```java
class Solution {
   public int maxProduct(int[] nums) {
    int n = nums.length;
    if (n == 0) {
        return 0;
    }

    int[] dpMax = new int[n];
    dpMax[0] = nums[0];
    int[] dpMin = new int[n];
    dpMin[0] = nums[0];
    int max = nums[0];
    for (int i = 1; i < n; i++) {
        dpMax[i] = Math.max(dpMin[i - 1] * nums[i], Math.max(dpMax[i - 1] * nums[i], nums[i]));
        dpMin[i] = Math.min(dpMin[i - 1] * nums[i], Math.min(dpMax[i - 1] * nums[i], nums[i]));
        max = Math.max(max, dpMax[i]);
    }
    return max;
   }
}
```

