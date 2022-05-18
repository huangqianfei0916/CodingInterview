* 进制转化
* 使用java带的包。
```java
		// 十进制转化为其他进制
		int a = 17;
		System.out.println(Integer.toBinaryString(a));
		System.out.println(Integer.toOctalString(a));
		System.out.println(Integer.toHexString(a));
		System.out.println(Integer.toString(a, 2));
		// 其它进制转化为10进制
		System.out.println(Integer.parseInt("1111", 2));
```


* 使用StringBuffer的10进制转化为其他进制。
```java
   public String solve(int M, int N) {
        if (M == 0) return "0";
        boolean flag = true;
        if (M < 0) {
            M = -M;
            flag = false;
        }
        StringBuffer res = new StringBuffer();
        String hex = "0123456789ABCDEF";
        while (M != 0) {
            res.append(hex.charAt(M % N));
            M = M / N;
        }
        return flag == true ? res.reverse().toString() : "-" + res.reverse().toString();
    }
```

* 其他进制转化为十进制；（10进制以内，超过十进制可以单独处理）
```java
	public static void tr(String s, int radix) {
		int len = s.length() - 1;
		int sum = 0;
		int k = 0;

		for (int i = len; i >= 0; i--) {
			int d = Integer.valueOf(s.charAt(i));

			sum = (int) (sum + (s.charAt(i) - '0') * Math.pow(radix, k));
			k++;
		}
		System.out.println(sum);
	}
```

