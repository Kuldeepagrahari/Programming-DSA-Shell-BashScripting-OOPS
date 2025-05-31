#include<bits/stdc++.h>
using namespace std;

int main(){
    int a = 4, b = 7;
    // [capture list](parameters) => Return_type{// funtion body}(// function calling);
    // capture list: [a, b] captures the variables a and b by value, if empty it captures nothing and a, b will not be implicitly available in the lambda function but can be passed as parameters, without passing parameters, lamda will have access of parent scope variables but explicitly.
    // implicitly passing parameters: [=] captures all variables by value, [&] captures all variables by reference.
    // implicit vs explicit in c++ in simple words: implicit means the compiler does it for you, explicit means you do it yourself.
    //arrow operator in c++: it is used to specify the return type of a lambda function, if not specified it will be deduced by the compiler. 
    // In short, these are the rules of lambda functions in C++, which needs to give mandatory and which are optional, answer is:the capture list is mandatory, the parameters are optional, the return type is optional, and the function body is mandatory.
    // these are the examples with different situations of mandatory and optional rules of lambda functions in C++. answer is:
    // auto f1 = [a, b]() { return a + b; }; // capture by value, no parameters, no return type specified
    // auto f2 = [&a, &b]() { return a + b; }; // capture by reference, no parameters, no return type specified
    // auto f3 = [=]() { return a + b; }; // capture all by value, no parameters, no return type specified
    // auto f4 = [&]() { return a + b; }; // capture all by reference, no parameters, no return type specified
    // auto f5 = [a, b](int x, int y) { return a + b + x + y; }; // capture by value with parameters, no return type specified
    // auto f6 = [&a, &b](int x, int y) { return a + b + x + y;}; // capture bu ref with parameters, no return type


    // Calling later with extra parameters
    auto f = [&](int i) -> int{return a+b+i;};
    for(int i = 0; i < 10; i++)
    cout << f(i) << endl;

    // Calling at the same time with existing vars only
    for(int i = 0; i < 10; i++)
    [&]() -> void{cout << a + b + i << endl;}();

    // If want to call the same lamda function inside body: then initialize with function<ReturnType(parameter1, parameter2..)>

    // function<void(int)> K = [&](int stInd) -> void {
    //     ans.push_back(subset);

    //     for(int i = stInd; i < n; i++){
    //         subset.push_back(nums[i]);
    //         K(i + 1);
    //         subset.pop_back();
    //     }
    // };
    // K(0);
    
    //when the parameters and return type mandatory and when optional: when no extra variables required to pass only those which already defined & return type is mandatory when return is not clear i.e complex and multiple and recursive
}