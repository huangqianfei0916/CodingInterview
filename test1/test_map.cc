#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<int, string> m0 = {
    {1000, "M"},
    {900,  "CM"},
    {500,  "D"},
    {400,  "CD"},
    {100,  "C"},
    {90,   "XC"},
    {50,   "L"},
    {40,   "XL"},
    {10,   "X"},
    {9,    "IX"},
    {5,    "V"},
    {4,    "IV"},
    {1,    "I"},
};


int main() {

    // c++17
    // for (auto& [key, value] : m) {
    //     cout << key << value << endl;
    // }

    // auto cmp = [](const pair<int, string>& a, const pair<int, string>& b){ return a.first > b.first;};

    // vector<pair<int, string>> vec_sort(m.begin(), m.end());

    // sort(vec_sort.begin(), vec_sort.end(), cmp);

    // for (auto [key, value] : vec_sort) {
    //     cout << key << "333" << value << endl;
    // }


    auto cmp = [](int a, int b){return a > b;};
    // vector<int> d = {2, 3, 4, 0, 1};
    // sort(d.begin(), d.end(), cmp);
    // for (auto item : d) {
    //     cout << item;
    // }

    vector<int> vec;
    vec.push_back(2);
    vec.push_back(1);   
    vec.push_back(3);   

    for (auto item : vec) {
        cout << item;
    }



    // typedef struct Student
	// {
	// 	std::string name;
	// 	int grade;
	// } Student;
 
	// //Lambda设置map排序规则,同样适合于vector,list
	// auto func = [](const Student* left, const Student* right)
	// {
	// 	return left->grade < right->grade;
	// };
 
	// //定义map
	// std::map<const Student*, std::string,decltype(func)> stuMap(func);
    
 
	// //测试代码
	// Student* s1 = new Student{ "s1",12 };
	// Student* s2 = new Student{ "s2",84 };
	// Student* s3 = new Student{ "s3",99 };
	// Student* s4 = new Student{ "s4",33 };
 
	// //map
	// stuMap.emplace(s1,"otherVals1");
	// stuMap.emplace(s2, "otherVals2");
	// stuMap.emplace(s3, "otherVals3");
	// stuMap.emplace(s4, "otherVals4");
	// std::cout << "map:" << '\n';
	// for (auto stu : stuMap)
	// {
	// 	std::cout << stu.first->grade << ":" << stu.first->name <<":"<<stu.second<< '\n';
	// }
	// std::cout << "-------------------------------------------" << '\n';


}
    
    
