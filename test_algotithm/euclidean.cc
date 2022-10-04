/*
 * @Author: huangqianfei
 * @Date: 2022-10-02 19:57:16
 * @Description: 
 */
#include <iostream>
#include <vector>
using namespace std;


int greater_common_divisor(int a, int b) {
    // 要求a>b
    int d = 1;
    while (d) {
        d = a % b;
        a = b;
        b = d;
    }
    return a;
} 

int least_common_multiple(int a, int b, int gcd) {
    return (a * b) / gcd;
} 

int main() {
    int a = 8;
    int b = 4;
    int gcd = greater_common_divisor(a, b);
    cout <<  "gcd:" << gcd << endl;
    cout << "lcm:" << least_common_multiple(a, b, gcd) << endl;
    return 0;
}