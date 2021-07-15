
#include <iostream>


void example_lambda()
{
    // functions with similar prototypes
    std::string (*lambda_1)() = []() -> std::string { return "function lambda_1"; };
    auto lambda_2 = []() -> std::string { return { "function lambda_2" }; };

    // >> Pointer to function
    std::string (*p_old)();         // Declaration formal
    auto (*p_new)() -> std::string; // New sintaxe

    auto (*p2)() = lambda_1;

    p_old = lambda_1;
    std::cout << "Call pointer to lambda function [" << (*p_old)() << "]\n";

        p_new = lambda_2;
        std::cout << "Call pointer to lambda function [" << (*p_new)() << "]\n";

            std::cout << "Call pointer to lambda function [" << (*p_new)() << "]\n";
}

int main(int __argc, char** __argv)
{
    example_lambda();

    return EXIT_SUCCESS;
}
