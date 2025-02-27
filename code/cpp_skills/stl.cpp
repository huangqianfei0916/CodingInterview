#include <iostream>

#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>

#include <math.h>

using namespace std;

/*
序列容器：vector，string，deque（双端队列），list（双向链表）
关联容器：set，map，multiset，multimap
适配容器：stack，queue，priirity_queue（优先队列）

可以访问下表的容器：vector,deque,map,
但是，vector和deque在初始化大小时候，不能使用下标插入元素，

priority_queue：模版参数一共三个，数据类型，容器，比较方式；
后两个参数默认情况下，就是大顶堆了
选择指定的比较方式时，第二个参数容器不可缺省
*/

void vector_demo() {
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(0);
    

    // 遍历
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << endl;
    }
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << endl;
    }

    // 查找
    vector<int>::iterator it = find(vec.begin(), vec.end(), 2);
    if (it != vec.end()) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    
    // 排序，降序只需要将起末颠倒即可
    // sort(vec.rbegin(), vec.rend());
    sort(vec.begin(), vec.end());
    // 反转
    reverse(vec.begin(), vec.end());
    // 大小
    cout << vec.size() << vec.empty() << endl;

    for (auto& item : vec) {
        cout << item << endl;
    }
    
    // 清空
    vec.clear();
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << endl;
    }
}


void split(const string s, vector<string>& tokens, const string& delimiters = " ") {
    int lastPos = s.find_first_not_of(delimiters);
    int pos = s.find_first_of(delimiters);
    while (string::npos != pos || string::npos != lastPos) {
        tokens.push_back(s.substr(lastPos, pos - lastPos));
        lastPos = s.find_first_not_of(delimiters, pos);
        pos = s.find_first_of(delimiters, lastPos);
    }
}
// string 不是引用传递
// int compare(int pos, int n, const string &s)const;
// string substr(int pos = 0,int n = npos) const;
// int find(const string &s, int pos = 0) 
void stringDemo() {
    string demo = "sponsorfly hqf baidu";
    // 遍历
    for(int i = 0; i < demo.size(); ++i) {
        cout << demo[i] << endl;
    }
    // 反转
    reverse(demo.begin(), demo.end());
    cout << demo << endl;
    // 子字符串，第一个数字代表从哪个index开始，第二个代表从index1开始截取的长度，不写则index1到结尾
    string temp = demo.substr(2, 3);
    cout << temp << endl;
    // 查找
    string demo1 = "sponsorfly hqf baidu";
    size_t idx = demo1.find(" ");
 
    if (idx != string::npos) {
        cout << idx << endl;
    } else {
        cout << "no find !";
    }
    cout << demo1.compare(0, 3, "spo") << endl;
    cout << demo1.find("hqf", 2) << endl;
    if (demo1.find_first_of("hqf", 5) == string::npos) {
        cout << "no first" << endl;
    } else {
        cout << "first success" << endl;
    }

    vector<string> res;
    string demo2 = "黄乾飞 spon fly 哈哈哈";
    split(demo2, res, " ");
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
    string test;
    for (int i = 0; i < demo2.size(); i+=3) {
        test += demo[i];
        test += demo[i+1];
        test += demo[i+2];
        if (test == "哈") {
            cout << "yes" << endl;
        }
    }
    
}

void arrDemo(int demo[]) {
    demo[0] = 100;
    
}

void listDemo() {
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_front(0);
    l.pop_back();
    
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it << endl;
    }
    for (auto& item : l) {
        cout << item << endl;
    }

}

void setDemo() {
    set<int> s;
    s.insert(1);
    s.insert(2);
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << endl;
    }
    set<int>::iterator f = s.find(2);
    if (f != s.end()) {
        cout << "yes" << *f << endl;
    } else {
        cout << "no" << *f << endl;
    }
    cout << s.size();

}

void mapDemo() {
    map<int, string> m;
    m.insert(pair<int, string>(1, "111"));
    m.insert(pair<int, string>(2, "222"));
    cout << m.size() << endl << m.max_size() << endl;

    for (map<int, string>::iterator it = m.begin(); it != m.end(); ++it) {
        cout << it->first << it->second << endl;
    }
    if (m.find(1) != m.end()) {
        cout << m.find(1)->first << m.find(1)->second << endl;
    }
}

void queueDemo() {
    queue<int> q;
    q.push(1);
    q.push(2);
    cout << q.back() << endl;
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
}

void stackDemo() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.top() << endl;
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

}

void dequeDemo() {
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(0);

    cout << dq.front() << endl;
    while (!dq.empty()) {
        cout << dq.front() << endl;
        dq.pop_front();
    }

}


long quickPow(int x, long n) {
    long res = 1;
    long tt = x;
    while (n != 0) {
        if ((n & 1) == 1) {
            res *= tt;
            res %= 1000000007;
        }
        tt *= tt;
        tt %= 1000000007;
        n /= 2;
    }
    return res;
}

// #include <queue>
void priority_queue_demo() {
    vector<int> vec = { 1,2,4,3,8,6,1,4 };
	priority_queue<int> pq;
	for (auto& item : vec) {
		pq.push(item);
	}
	while (pq.size()) {
		cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    // 指定第三个参数时候，第二个参数必须指定
    priority_queue<int, vector<int>, greater<int>> pq2;
    for (auto& item : vec) {
        pq2.push(item);
    }
    while (pq2.size()) {
        cout << pq2.top() << " ";
        pq2.pop();
    }
}

void split_test() {
    string demo = "123 456 789";
    int pre = 0;
    int pos = demo.find(" ");

    while (string::npos != pos || string::npos != pre) {
        demo = demo.substr(pre, pos - pre);
        cout << demo << endl;
        pre = pos;
        pos = demo.find(" ");
        pos = pos + pre;
        cout << pre << "-" << pos << endl;
    }

}

int main() {
    // vector_demo();
    // stringDemo();
    listDemo();
    // setDemo();
    // mapDemo();
    // queueDemo();
    // stackDemo();
    // dequeDemo();


    // int a[200];
    // a[0] = 200;
    // arrDemo(a);
    // cout << a[0];

    // cout << quickPow(2, 4) << endl;
    // int a = 0; 

    // priority_queue_demo();


    return 0;
}