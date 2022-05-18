* hash&合并区间&快速幂&素数

### 前 K 个高频元素&合并区间&快速幂&素数

给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]

* 主要应用了HashMap按照值进行排序
```java
import java.util.Map.Entry;
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {

		HashMap<Integer, Integer> map = new HashMap();
		for (int i = 0; i < nums.length; i++) {
			if (map.containsKey(nums[i])) {
				int temp = map.get(nums[i]);
				temp++;
				map.put(nums[i], temp);
			} else {
				map.put(nums[i], 1);
			}
		}
		List<Map.Entry<Integer, Integer>> list = new ArrayList<Map.Entry<Integer, Integer>>(map.entrySet());
		Collections.sort(list, new Comparator<Map.Entry<Integer, Integer>>() {
			// 降序排序
			@Override
			public int compare(Entry<Integer, Integer> o1, Entry<Integer, Integer> o2) {
				// return o1.getValue().compareTo(o2.getValue());
				return o2.getValue().compareTo(o1.getValue());
			}

		});
		ArrayList<Integer> l = new ArrayList<Integer>();
		int js = 0;
		for (Map.Entry<Integer, Integer> mapping : list) {
			l.add(mapping.getKey());
			js++;
			if (js == k) {
				break;
			}

		}
		return l;
    }
}
```
*************
### 合并区间
给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

```java
class Solution {
    public int[][] merge(int[][] intervals) {

      Arrays.sort(intervals, Comparator.comparingInt(x -> x[0]));
        ArrayList <int []>list=new ArrayList();
        for(int i=0;i<intervals.length;i++){
            if(list.size()==0||intervals[i][0]>list.get(list.size()-1)[1]){
                list.add(intervals[i]);
            }else{
                list.get(list.size()-1)[1]=Math.max(intervals[i][1],list.get(list.size()-1)[1]);
            }
        }

        int [][]a=new int[list.size()][2];

        for(int i=0;i<a.length;i++){
            a[i]=list.get(i);
        }
        return a;
    }
}
```

### Leetcode-快速幂

* 注意这里取值范围，取反时候会出现越界，所以采用long n=b；

```java
class Solution {
    public double myPow(double x, int b) {
        long n=b;
        if(n==0){
            return 1;
        }
        boolean flag=false;
        if(n<0){
            flag=true;
            n=-n;
        }
        double res=1;
        while(n>0){
            if(n%2==1){
                n=n-1;
                res=res*x;
                n=n/2;
                x=x*x;
            }else{
                n=n/2;
                x=x*x;
            }
        }
        if(flag){
            res=1/res;
        }
        return res;
    }
}
```



### 素数

统计所有小于非负整数 n 的质数的数量。

示例:

输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。

*************

首先从 2 开始，我们知道 2 是一个素数，那么 2 × 2 = 4, 3 × 2 = 6, 4 × 2 = 8... 都不可能是素数了。

然后我们发现 3 也是素数，那么 3 × 2 = 6, 3 × 3 = 9, 3 × 4 = 12... 也都不可能是素数了。

```java
public int countPrimes(int n) {
		int sum = 0;
		int flag = 0;
		int d[] = new int[n];
		for (int i = 0; i < d.length; i++) {
			d[i] = 1;
		}
		for (int i = 2; i < Math.sqrt(n); i++) {
			if (d[i] == 1)
				for (int j = 2 * i; j < n; j += i) {

					d[j] = 0;

				}
		}
		for (int i : d) {
			System.out.println(i);
		}
		for (int i = 2; i < d.length; i++) {
			if (d[i] == 1) {
				sum++;
			}
		}
		return sum;

	}

```
* 解法2
```java
public class Prime {
    public static void main(String[] args) {

        for (int i = 0; i < 20; i++) {
            System.out.println(i + " " + isPrime(i));
        }
    }
    public static boolean isPrime(int src) {
        double sqrt = Math.sqrt(src);
        if (src < 2) {
            return false;
        }
        if (src == 2 || src == 3) {
            return true;
        }
        if (src % 2 == 0) {
            return false;
        }
        for (int i = 3; i <= sqrt; i += 2) {
            if (src % i == 0) {
                return false;
            }
        }
        return true;
    }
}
```