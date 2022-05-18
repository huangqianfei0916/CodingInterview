
## DFS
* 面试题12:矩阵中的路径

* 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

  [["a","b","c","e"],
  ["s","f","c","s"],
  ["a","d","e","e"]]

  但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。

```java
class Solution {
 public boolean [][]vis;
    int rows;
    int cols;
    int index=0;
    public boolean exist(char[][] board, String word) {
        rows=board.length;
        cols=board[0].length;
        vis=new boolean[rows][cols];
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                vis[i][j]=false;
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(check(i,j,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
    public boolean check(int row,int col,char [][]board,String word){
        boolean flag=false;
        if(index==word.length()){
            return true;
        }

        if(row<0||row>=rows||col<0||col>=cols||vis[row][col]==true||word.charAt(index)!=board[row][col]){
            return fals e;
        }
        index++;
        vis[row][col]=true;
        flag=check(row+1,col,board,word)||check(row-1,col,board,word)||
        check(row,col+1,board,word)||check(row,col-1,board,word);
        if(flag==false){
            index--;
            vis[row][col]=false;
        }
        return flag;
    }
}
```
* 面试题13:机器人运动范围
* 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

```java
class Solution {
    int count=0;
    boolean [][]vis;
    int rows;
    int cols;
    public int movingCount(int m, int n, int k) {
        rows=m;
        cols=n;
        vis=new boolean[m][n];
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                vis[i][j]=false;
            }
        }
        count=check(0,0,k);
        return count;
    }
    public int check(int row,int col,int target){
        if(row<0||row>=rows||col<0||col>=cols||vis[row][col]==true||(dig(row)+dig(col))>target){
            return 0;
        }
        vis[row][col]=true;
        count++;
        check(row+1,col,target);
        check(row-1,col,target);
        check(row,col-1,target);
        check(row,col+1,target);
        return count;
    }
    
    public int dig(int num){
        int sum=0;
        while(num!=0){
            sum+=num%10;
            num=num/10;
        }
        return sum;
    }
}
```
* 200 岛屿数量 

* 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

  岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。

  此外，你可以假设该网格的四条边均被水包围。

  输入:
  [
  ['1','1','0','0','0'],
  ['1','1','0','0','0'],
  ['0','0','1','0','0'],
  ['0','0','0','1','1']
  ]
  输出: 3

```java
class Solution {
    boolean [][]vis;
    int rows;
    int cols;
    public int numIslands(char[][] grid) {
        if(grid.length==0){
            return 0;
        }

        rows=grid.length;
        cols=grid[0].length;
        vis=new boolean[rows][cols];
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                vis[i][j]=false;
            }
        }
        int count=0;
        for (int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(vis[i][j]==false&&grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;

    }
    public void dfs(int i,int j,char [][] grid){
        
        if(i<0||i>=rows||j<0||j>=cols||grid[i][j]=='0'||vis[i][j]==true){
            return;
        }
        vis[i][j]=true;
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i+1,j,grid);
        dfs(i,j-1,grid);

    }
}
```
* 463 岛屿的周长 

* 给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。

  网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。

  岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。

  输入:
  [[0,1,0,0],
   [1,1,1,0],
   [0,1,0,0],
   [1,1,0,0]]
  
  输出: 16


```java
class Solution {
  int rows;
    int cols;
    boolean [][]vis;
    int count=0;
    public int islandPerimeter(int[][] grid) {

        if(grid.length==0){
            return count;
        }
        rows=grid.length;
        cols=grid[0].length;
        vis=new boolean[rows][cols];
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                vis[i][j]=false;
            }
        }
        int row=0;
        int col=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    row=i;
                    col=j;
                    break;
                }
            }
        }
        check(row,col,grid);

        return count;
    }
    public void check(int row,int col,int [][] grid){
        if(row<0||row>=rows||col<0||col>=cols||vis[row][col]==true||grid[row][col]==0){
            return;
        }
        vis[row][col]=true;
        testCount(row,col,grid);
        check(row+1,col,grid);
        check(row-1,col,grid);
        check(row,col+1,grid);
        check(row,col-1,grid);

    }
    public void testCount(int row,int col,int [][]grid){
        if((col-1)<0||grid[row][col-1]==0){
            count++;
        }
        if((col+1)>=cols||grid[row][col+1]==0){
            count++;
        }
        if((row-1)<0||grid[row-1][col]==0){
            count++;
        }
        if((row+1)>=rows||grid[row+1][col]==0){
            count++;
        }
    }
}
```
* 695 岛屿的最大面积 

* 给定一个包含了一些 0 和 1 的非空二维数组 grid 。

  一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

  找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)

  示例 1:

  [[0,0,1,0,0,0,0,1,0,0,0,0,0],
   [0,0,0,0,0,0,0,1,1,1,0,0,0],
   [0,1,1,0,1,0,0,0,0,0,0,0,0],
   [0,1,0,0,1,1,0,0,1,0,1,0,0],
   [0,1,0,0,1,1,0,0,1,1,1,0,0],
   [0,0,0,0,0,0,0,0,0,0,1,0,0],
   [0,0,0,0,0,0,0,1,1,1,0,0,0],
   [0,0,0,0,0,0,0,1,1,0,0,0,0]]
  对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。

```java
class Solution {
   int []count=new int[50*50];
    int res=0;
    boolean [][]vis;
    int rows;
    int cols;
    public int maxAreaOfIsland(int[][] grid) {

        if(grid.length==0){
            return 0;
        }
        rows=grid.length;
        cols=grid[0].length;
        vis=new boolean[rows][cols];
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                vis[i][j]=false;
            }
        }
        int k=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1&&vis[i][j]==false){
                    check(i,j,grid,k);
                    k++;
                }
            }
        }

        for(int i=0;i<count.length;i++){
            if(count[i]>res){
                res=count[i];
            }
        }
        return res;
    }
    public void check(int row,int col,int [][]grid,int k){
        if(row<0||row>=rows||col<0||col>=cols||vis[row][col]==true||grid[row][col]==0){
            return;
        }
        vis[row][col]=true;
        count[k]++;

        check(row+1,col,grid,k);
        check(row-1,col,grid,k);
        check(row,col+1,grid,k);
        check(row,col-1,grid,k);
    }

}
```
* 827 最大人工岛 

* 在二维地图上， 0代表海洋， 1代表陆地，我们最多只能将一格 0 海洋变成 1变成陆地。

  进行填海之后，地图上最大的岛屿面积是多少？（上、下、左、右四个方向相连的 1 可形成岛屿）

  示例 1:

  输入: [[1, 0], [0, 1]]
  输出: 3
  解释: 将一格0变成1，最终连通两个小岛得到面积为 3 的岛屿。

```java
class Solution {
   int[][] count;
    int res = 0;
    boolean[][] vis;
    int rows;
    int cols;

    public int largestIsland(int[][] grid) {

        if (grid.length == 0) {
            return 0;
        }
        boolean flag = false;

        rows = grid.length;
        cols = grid[0].length;
        count = new int[rows][cols];
        vis = new boolean[rows][cols];
        init();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    flag = true;
                    grid[i][j] = 1;
                    check(i, j, grid, i, j);
                    grid[i][j] = 0;
                    init();
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (count[i][j] > res) {
                    res = count[i][j];
                }
            }
        }
        if (flag == false) {
            res = rows * cols;
        }
        System.out.println(res);
        return res;
    }

    public void init() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                vis[i][j] = false;
            }
        }

    }

    public void check(int row, int col, int[][] grid, int i, int j) {
        if (row < 0 || row >= rows || col < 0 || col >= cols || vis[row][col] == true || grid[row][col] == 0) {
            return;
        }
        vis[row][col] = true;
        count[i][j]++;

        check(row + 1, col, grid, i, j);
        check(row - 1, col, grid, i, j);
        check(row, col + 1, grid, i, j);
        check(row, col - 1, grid, i, j);
    }
}
```
* 221 最大矩阵

* 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

  示例:

  输入: 

  1 0 1 0 0
  1 0 1 1 1
  1 1 1 1 1
  1 0 0 1 0

  输出: 4

```java
class Solution {
    int res=0;
    int rows;
    int cols;
    public int maximalSquare(char[][] matrix) {

        if (matrix.length==0){
            return 0;
        }
        rows=matrix.length;
        cols=matrix[0].length;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if (matrix[i][j]=='1'){
                    dfs(matrix,i,j,1);
                }
            }
        }
        return res;
    }
    public void dfs(char [][] matrix,int i,int j,int len){
        if(!check(matrix,i,j,len)){
            return;
        }
        res=Math.max(res,len*len);
        dfs(matrix,i,j,len+1);

    }
    public boolean check(char [][] matrix,int x,int y,int len){
        if((x+len)>rows||(y+len)>cols){
            return false;
        }
        for(int i=x;i<x+len;i++){
            for(int j=y;j<y+len;j++){
                if(matrix[i][j]=='0'){
                    return false;
                }
            }
        }
        return true;
    }
}
```

* dfs模拟

```java
static class Node {
        int left = -1;
        int right = -1;
        boolean haveSon = false;
    }

    static int ans = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        Set<Integer> set = new HashSet<>();
        Node[] root = new Node[m + 1];
        for (int i = 1; i <= m; i++) {
            root[i] = new Node();
        }
        for (int i = 0; i < n; i++) {
            int index = sc.nextInt();
            String str = sc.next();
            int next = sc.nextInt();
            if (str.equals("left")) {
                root[index].left = next;
                root[index].haveSon = true;
            } else {
                root[index].right = next;
                root[index].haveSon = true;
            }
            set.add(next);
        }
        int rootIndex = -1;
        for (int i = 1; i <= m; i++) {
            if (set.contains(i) == false) {
                rootIndex = i;
                break;
            }
        }
        dfs(rootIndex, root);
        System.out.println(ans);
    }

    public static void dfs(int root, Node[] nodes) {
        if (nodes[root].haveSon == false) {
            return;
        }

        int left = nodes[root].left;
        int right = nodes[root].right;

        if (left != -1 && nodes[left].haveSon == false && right != -1 && nodes[right].haveSon == false) {
            ans++;
            return;
        }
        if (left != -1)
            dfs(left, nodes);
        if (right != -1)
            dfs(right, nodes);
    }
```

