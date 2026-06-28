#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <functional>
using namespace std;
int until(int x,function<int(int)> f, function<bool(int)> g){
    while(!g(x)){
        x=f(x);
    }
    return x;

};

int main(){
    auto double_number = [](int n) {return 2*n;};
    auto triple_number = [](int n) {return 3*n;};
    auto square_number = [](int n) {return n*n;};
    auto increment = [](int n) {return n+1;};
    auto decrement = [](int n) {return n-1;};

    

    auto greater_than_100 = [](int n){return n > 100;};
    auto is_positive = [](int n){return n>0;};
    auto is_negative = [](int n){return n<0;};
    

    assert(until(1,double_number,greater_than_100)==128);
    assert(until(10,triple_number,greater_than_100)==270);
    assert(until(2,square_number,greater_than_100)==256);
    assert(until(-10,increment,is_positive)==1);
    assert(until(10,decrement,is_negative)==-1);

    cout << "All tests passed" << endl;
    return 0;

};
