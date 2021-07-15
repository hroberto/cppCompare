// Source = https://www.geeksforgeeks.org/smart-pointers-cpp/


#include <iostream>
#include <chrono>


long int fib(int n)
{
    return (n <= 1)? n : fib(n-1) + fib(n-2);
}


constexpr long int fib_perform(int n)
{
    return (n <= 1)? n : fib_perform(n-1) + fib_perform(n-2);
}

int main(int __argc, char** __argv)
{
    auto lambda_now = []() -> auto { return std::chrono::high_resolution_clock::now(); };
    auto lambda_nanosecond = [](const auto & t1, const auto & t2) -> auto { return std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count(); };
    auto lambda_milisecond = [](const auto & t1, const auto & t2) -> auto { return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count(); };

    auto t1 = lambda_now();
    auto t2 = lambda_now();


    t1 = lambda_now();
    auto v2 = fib_perform( 50 );
    t2 = lambda_now();
    std::cout << __LINE__ << " -> result perform = " << v2 << std::endl;
    std::cout << ">> " << lambda_milisecond( t1, t2 ) << " milisenconds == " << lambda_nanosecond( t1, t2 ) << " nanoseconds " << std::endl;

    t1 = lambda_now();
    auto v = fib( 50 );
    t2 = lambda_now();
    std::cout << __LINE__ << " -> result = " << v << std::endl;
    std::cout << ">> " << lambda_milisecond( t1, t2 ) << " milisenconds == " << lambda_nanosecond( t1, t2 ) << " nanoseconds " << std::endl;

    return EXIT_SUCCESS;
}
