LeetCode207-BFS-课程表

你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]


```java
class Solution {
   public boolean canFinish(int numCourses, int[][] prerequisites) {
        int[] input = new int[numCourses];
        ArrayList<ArrayList<Integer>> listall = new ArrayList<>();
        for (int i = 0; i < numCourses; i++) {
            listall.add(new ArrayList<>());
        }
        for (int i = 0; i < prerequisites.length; i++) {
            input[prerequisites[i][0]]++;
            listall.get(prerequisites[i][1]).add(prerequisites[i][0]);
        }
        LinkedList <Integer>q=new LinkedList<>();
        for(int i=0;i<input.length;i++){
            if(input[i]==0){
                q.offer(i);
            }
        }
        while(!q.isEmpty()){
            int val=q.poll();
            numCourses--;
            ArrayList<Integer>temp=listall.get(val);
            for (Integer integer : temp) {
                input[integer]--;
                if(input[integer]==0){
                    q.offer(integer);
                }
            }

        }
        return numCourses==0;
    }
}
```
LeetCode-55 跳跃游戏

给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。
```java
class Solution {
    public boolean canJump(int[] nums) {
        int k=0;
        for(int i=0;i<nums.length;i++){
            if(i>k){
                return false;
            }
          
            k=Math.max(k,i+nums[i]);
        }
        return true;
    }
}
```

********
### 丑数
**题目描述**
把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

```java
public class Solution {
    public int GetUglyNumber_Solution(int index) {
        if(index<7){
            return index;
        }
        int t2=0;int t3=0;int t5=0;
        int [] res=new int [index];
        res[0]=1;
        for(int i=1;i<index;i++){
            res[i]=Math.min(res[t2]*2,Math.min(res[t3]*3,res[t5]*5));
                
            if(res[i]==res[t2]*2){
                t2++;
            }
            if(res[i]==res[t3]*3){
                t3++;
            }
            if(res[i]==res[t5]*5){
                t5++;
            }
        }
        return res[index-1];
    }
}
```

### 括号生成

**题目描述**
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

```java
import java.util.*;

class Solution {
    ArrayList<String>list=new ArrayList();
    public List<String> generateParenthesis(int n) {

        get(n,"",0,0);
        return list;
    }
    public void get(int n,String s,int left,int right){
        
        if(s.length()==2*n){
            list.add(s);
            return ;
        }
        if(left<n){     
            get(n,s+"(",left+1,right);
        }
        if(right<left){
            get(n,s+")",left,right+1);
        }
    }
}
```

### 剪绳子

给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1），每段绳子的长度记为k[0],k[1],...,k[m]。请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
* 牛客大佬分析：
 * 题目分析：
 * 先举几个例子，可以看出规律来。
 * 4 ： 2*2
 * 5 ： 2*3
 * 6 ： 3*3
 * 7 ： 2* 2* 3 或者4* 3
 * 8 ： 2* 3* 3
 * 9 ： 3* 3* 3
 * 10：2* 2* 3* 3 或者4* 3* 3
 * 11：2* 3* 3* 3
 * 12：3* 3* 3* 3
 * 13：2* 2* 3* 3* 3 或者4* 3* 3* 3
 * 下面是分析：
 * 首先判断k[0]到k[m]可能有哪些数字，实际上只可能是2或者3。
 * 当然也可能有4，但是4=2*2，我们就简单些不考虑了。
 * 5<2* 3,6<3* 3,比6更大的数字我们就更不用考虑了，肯定要继续分。
 * 其次看2和3的数量，2的数量肯定小于3个，为什么呢？因为2* 2* 2<3* 3，那么题目就简单了。
 * 直接用n除以3，根据得到的余数判断是一个2还是两个2还是没有2就行了。
 * 由于题目规定m>1，所以2只能是1* 1，3只能是2* 1，这两个特殊情况直接返回就行了。
 * 乘方运算的复杂度为：O(log n)，用动态规划来做会耗时比较多。

```java
public class Solution {
    public int cutRope(int target) {
        if(target==2){
            return 1;
        }
        if(target==3){
            return 2;
        }
        int x=target/3;
        int y=target%3;
        if(y==0){
            return (int)Math.pow(3,x);
        }else if(y==1){
            return (int)(2*2*Math.pow(3,x-1));
        }else{
            return (int)(2*Math.pow(3,x));
        }
    }
}
```
*********
### 约瑟夫环

* 用ArrayList存储数据；没去除一个数字都要index--；
```java
import java.util.*;
public class Solution {
    public int LastRemaining_Solution(int n, int m) {
        if(m==0){
            return -1;
        }
        ArrayList <Integer>list=new ArrayList();
        for(int i=0;i<n;i++){
            list.add(i);
            
        }
        int index=-1;
        while(list.size()>1){
            index=(index+m)%list.size();
            list.remove(index);
            index--;
        }
        return list.get(0);
        
    }
}
```

### 不用加减乘除做加法
**题目描述**
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

* 这里异或是不带进位的加法；
* & 是进位，需要左移一下；
* 然后重复上面操作，直到没有进位，无进位时结果为num1；
```java
public class Solution {
    public int Add(int num1,int num2) {
        while(num2!=0){
            int temp1=num1^num2;
            int temp2=(num1&num2)<<1;
            num1=temp1;
            num2=temp2;
        }
        return num1;
    }
}
```
***********
### 构建乘积数组
**题目描述**
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。（注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，B[n-1] = A[0] * A[1] * ... * A[n-2];）

* 根据图片先计算上三角再计算下三角；上三角和下三角对应行相乘。
![img](https://img-blog.csdnimg.cn/20200329102158493.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1NvX3RoYXQ=,size_16,color_FFFFFF,t_70)

```java
import java.util.ArrayList;
public class Solution {
    public int[] multiply(int[] A) {
        
        if(A.length==0){
            return null;
        }
        int B[]=new int[A.length];
        B[0]=1;
        for(int i=1;i<B.length;i++){
            B[i]=B[i-1]*A[i-1];
            
        }
        int temp=1;
        for(int j=A.length-2;j>=0;j--){
            temp*=A[j+1];
            B[j]*=temp;
        }
        return B;

    }
}
```