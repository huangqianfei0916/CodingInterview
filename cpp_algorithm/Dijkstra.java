/*
 * @Author: huangqianfei
 * @Date: 2022-10-04 14:46:17
 * @Description: Dijkstra算法首先通过广度优先遍历的方式计算出各个顶点的（父节点，距离首节点的最短路径）
 * 然后通过最后节点的父节点进行回朔，得到最终的路径
 */
import java.util.ArrayList;
import java.util.List;

class Vertex {
    public int id;
    public Vertex father;
    public int minLenth = 10000;
}

public class Dijkstra {
 
    static int[][] matrix = new int[6][6];
    final static int N = 10000;
 
    public static void main(String[] args) {
 
        //邻接矩阵
        matrix[0] = new int[]{0, 6, 3, N, N, N};/*1*/
        matrix[1] = new int[]{6, 0, 2, 5, N, N};/*2*/
        matrix[2] = new int[]{3, 2, 0, 3, 4, N};/*3*/
        matrix[3] = new int[]{N, 5, 3, 0, 2, 3};/*4*/
        matrix[4] = new int[]{N, N, 4, 2, 0, 5};/*5*/
        matrix[5] = new int[]{N, N, N, 3, 5, 0};/*6*/
 
        //已标记点集合
        List<Vertex> Marked = new ArrayList<>();
        Vertex vt0 = new Vertex();
        vt0.id = 0;
        vt0.minLenth = 0;
        Marked.add(vt0);
 
        //未标记点集合
        List<Vertex> UnMarked = new ArrayList<>();
        for (int i = 0; i < 5; i++) {
            Vertex vtx = new Vertex();
            vtx.id = i+1;
            UnMarked.add(vtx);
        }
 
        //将未标记点集合中的点转移到已标记点集合
        int order = 1;
        while(!UnMarked.isEmpty()){
            Vertex vtx = FindVer(Marked, UnMarked);
            UnMarked.remove(vtx);
            Marked.add(vtx);
            System.out.println("第"+order+"次标号，顶点"+vtx.id+"的标号为：（" + vtx.father.id + "，" +vtx.minLenth + "）");
            order++;
        }
 
        //输出路径
        for(Vertex v :Marked){
            if(v.id == 5){
                System.out.println("0-5的最短路径长度为：" + v.minLenth);
                System.out.print("逆推得最优路径为：" + "5");
                while(v.id != 0){
                    v = v.father;
                    System.out.print( " -> " + v.id);
                }
            }
        } 
    }

    static Vertex FindVer(List<Vertex> Marked, List<Vertex> UnMarked){
        int M = 10000;
        Vertex v = null;
        for (Vertex ve : UnMarked) {
            for (Vertex vr : Marked) {
                int all_p = vr.minLenth + matrix[vr.id][ve.id];
                System.out.println(vr.id + "-" + ve.id + "=" + all_p);
        
                if (all_p <= ve.minLenth) {
                    ve.minLenth = all_p;
                    ve.father = vr;
                }
                System.out.println(ve.minLenth);
            }
            if (ve.minLenth < M) {
                M = ve.minLenth;
                v = ve;
            }
        }
        System.out.println("-------------");
        return v;
    }
 
}
