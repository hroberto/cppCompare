// Source = https://www.geeksforgeeks.org/multithreading-c-2/

#include <iostream>


int main(int __argc, char** __argv)
{
    struct st{
        int i{};
        int x{};
    };
    auto myLambda = []() -> st { return {1, 2}; };

    st A = myLambda();
    std::cout << " st.i = " << A.i << std::endl;

    return EXIT_SUCCESS;
}
