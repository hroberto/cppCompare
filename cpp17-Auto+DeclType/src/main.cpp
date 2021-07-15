// Source = https://www.geeksforgeeks.org/smart-pointers-cpp/


#include <iostream>
#include <memory>
#include <utility>


// Example of use the function typeid
void example_typeid_1()
{
    std::cout << "====== example_typeid_1 ========\n";

    const int x = 1;
    auto y = 3.37;
    auto ptr = &x;

    std::cout << typeid(x).name() << std::endl
         << typeid(y).name() << std::endl
         << typeid(ptr).name() << std::endl;

         // OUTPUT
         // i
         // d
         // PKi
}


// template<class T, class U>
// auto add(T t, U u) { return t + u; } // the return type is the type of operator+(T, U)
//
// // perfect forwarding of a function call must use decltype(auto)
// // in case the function it calls returns by reference
// template<class F, class... Args>
// decltype(auto) PerfectForward(F fun, Args&&... args)
// {
//     return fun(std::forward<Args>(args)...);
// }
//
// template<auto n> // C++17 auto parameter declaration
// auto f() -> std::pair<decltype(n), decltype(n)> // auto can't deduce from brace-init-list
// {
//     return {n, n};
// }
//
// void example_auto()
// {
//     auto a = 1 + 2;          // type of a is int
//     auto b = add(1, 1.2);    // type of b is double
//     static_assert(std::is_same_v<decltype(a), int>);
//     static_assert(std::is_same_v<decltype(b), double>);
//
//
//     auto c0 = a;             // type of c0 is int, holding a copy of a
//     decltype(auto) c1 = a;   // type of c1 is int, holding a copy of a
//     decltype(auto) c2 = (a); // type of c2 is int&, an alias of a
//     std::cout << "a, before modification through c2 = " << a << '\n';
//     ++c2;
//     std::cout << "a,  after modification through c2 = " << a << '\n';
//
//     auto [v, w] = f<0>(); //structured binding declaration
//
//
//     auto d = {1, 2}; // OK: type of d is std::initializer_list<int>
//     auto n = {5};    // OK: type of n is std::initializer_list<int>
// //  auto e{1, 2};    // Error as of DR n3922, std::initializer_list<int> before
//     auto m{5};       // OK: type of m is int as of DR n3922, initializer_list<int> before
// //  decltype(auto) z = { 1, 2 } // Error: {1, 2} is not an expression
//
//     // auto is commonly used for unnamed types such as the types of lambda expressions
//     auto lambda = [](int x) { return x + 3; };
//
// //  auto int x; // valid C++98, error as of C++11
// //  auto x;     // valid C, error in C++
// }

void example_lambda()
{
    std::string (*lambda_1)() = []() -> std::string { return "function lambda_1"; };
    auto lambda_2 = []() -> std::string { return { "function lambda_2" }; };

    // >> Pointer to function with return std::string and no parameters
    // std::string (*p)();      // Declaration formal
    auto (*p)() -> std::string;// New sintaxe

    p = lambda_1;
    std::cout << "Call pointer to lambda function [" << (*p)() << "]\n";

    p = lambda_2;
    std::cout << "Call pointer to lambda function [" << (*p)() << "]\n";
}

int main(int __argc, char** __argv)
{
    example_typeid_1();
    example_auto();

    example_lambda();

    return EXIT_SUCCESS;
}
