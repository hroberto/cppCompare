// Source = https://www.geeksforgeeks.org/multithreading-c-2/

#include <iostream>
#include <array>

typedef int X;


void uninitializedVariables() {
    // uninitialized built-in type
    int i;

    // initialized built-in type
    int j=10;

    // initialized built-in type
    int k(10);

    // Aggregate initialization
    int a[]={1, 2, 3, 4};

    // default constructor
    X x1;

    // Parameterized constructor
    X x2(1);

    // Parameterized constructor with single argument
    X x3=3;

    // copy-constructor
    X x4=x3;


    std::cout << i << ", " << j << ", " << k << ", " << a[0] << ", " << x1<< ", " << x2<< ", " << x3 << ", " << x4 << std::endl;
}


void  unifiedInitialization() {
    int i{};     // initialized built-in type, equals to int i{0};

    int j{10}; // initialized built-in type

    int a[]{1, 2, 3, 4}; // Aggregate initialization

    X x1{}; // default constructor

    X x2{1}; // Parameterized constructor;

    X x3=3;

    X x4{x3}; // copy-constructor


    std::cout << i << ", " << j << ", " << a[0] << ", " << x1<< ", " << x2<< ", " << x3 << ", " << x4 << std::endl;
}

int main(int __argc, char** __argv)
{
    uninitializedVariables();
    unifiedInitialization();


    std::array<int, 3> std_ar1 = {1, 2, 3}; // brace-elision okay
    std::cout << " std_ar1[0] = " << std_ar1[0] << std::endl;

    /**  The GNU not disponibilization the initialization deduction for Struct in version C++11 **/
    
    // struct st{
    //     int i{};
    //     int x{};
    // };
    // auto myLambda = []() -> st { st a{1, 2}; return a; };
    //
    // st A = myLambda();
    // std::cout << " st.i = " << A.i << std::endl;

    return EXIT_SUCCESS;
}
