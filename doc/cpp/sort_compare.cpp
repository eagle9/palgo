#include <algorithm>
#include <functional>
#include <array>
#include <iostream>
 
int main() {
    std::array<int, 10> s = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3}; 
 
    // sort using the default operator<
    std::sort(s.begin(), s.end());
    for (auto a : s) {
        std::cout << a << " ";
    }   
    std::cout << '\n';
 
    // sort using a standard library compare function object
    std::sort(s.begin(), s.end(), std::greater<int>());
    for (auto a : s) {
        std::cout << a << " ";
    }   
    std::cout << '\n';
 
    // sort using a custom function object
    struct {
        bool operator()(int a, int b) const {   
            return a < b;
        }   
    } CompareLess;
    std::sort(s.begin(), s.end(), CompareLess);
    for (auto a : s) {
        std::cout << a << " ";
    }   
    std::cout << '\n';
 
    // sort using a lambda expression 
	auto lmd = [](int a, int b) {return a > b ;}; //greater in front, ; before } is key
	std::sort(s.begin(), s.end(),lmd);
	std::cout << "sort using lambda object, greater in front:" << std::endl;
    for (auto a : s) {
        std::cout << a << " ";
    } 
    std::cout << '\n';

    std::sort(s.begin(), s.end(), [](int a, int b) {
        return a > b;   
    });
	std::cout << "sort using inline lambda object, greater in front:" << std::endl;
    for (auto a : s) {
        std::cout << a << " ";
    } 
    std::cout << '\n';
}
