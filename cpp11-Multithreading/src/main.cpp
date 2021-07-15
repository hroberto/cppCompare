// CPP program to demonstrate multithreading
// using three different callables.
//
// Source = https://www.geeksforgeeks.org/multithreading-c-2/

#include <iostream>
#include <thread>

// A dummy function
void foo(int Z)
{
    for (int i = 0; i < Z; i++) {
        std::cout << "(1) Thread using function pointer as callable\n";
    }
}


// A callable object
class thread_obj {
public:
    void operator()(int x)
    {
        for (int i = 0; i < x; i++)
            std::cout << "(2) Thread using function object as  callable\n";
    }
};


int main(int __argc, char** __argv)
{
    std::cout << "Threads 1 and 2 and 3 operating independently" << std::endl;

    // This thread is launched by using
    // function pointer as callable
    std::thread th1(foo, 30);

    // This thread is launched by using
    // function object as callable
    std::thread th2(thread_obj(), 30);

    // Define a Lambda Expression
    auto f = [](int x) {
        for (int i = 0; i < x; i++)
            std::cout << "(3) Thread using lambda expression as callable\n";
    };

    // This thread is launched by using
    // lamda expression as callable
    std::thread th3(f, 3);
    // Permits the thread execute independently from then thread handle ( Lambda Expression )
    th3.detach();

    // Wait for the threads to finish
    // Wait for thread t1 to finish
    th1.join();

    // Wait for thread t2 to finish
    th2.join();

    // Wait for thread t3 to finish
    if ( th3.joinable() ) {
        th3.join();
    }

    return EXIT_SUCCESS;
}
