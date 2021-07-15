# ESTUDO COMPARATIVO ENTRE VERSOES DA LINGUAGEM C++



##  1. Referencias externas

- [Comparative between versions- C++11 vs C++14 vs C++17](https://www.geeksforgeeks.org/c-11-vs-c-14-vs-c-17/)
- [Features of C++17 with Examples](https://www.geeksforgeeks.org/features-of-c17-with-examples/)


## 2. Versão C++11

- [Features C++11](https://en.cppreference.com/w/cpp/11)
- [The Biggest Changes in C++11](https://smartbear.com/blog/the-biggest-changes-in-c11-and-why-you-should-care/)



### Dedução automatica de tipos(auto) e decltype
- [references 1](https://en.cppreference.com/w/cpp/language/auto)
- [references 2](https://www.ibm.com/docs/en/i/7.3?topic=specifiers-decltypeexpression-type-specifier-c11)

```cpp

    auto i = 4;
    auto a[5];
    auto *p;    
    decltype(i) var1; 		// int
    decltype(1) var2; 		// int
    decltype(2+3) var3; 	// int(+ operator returns an rvalue)
    decltype(i=1) var4 = i; // int&, because assignment to int
                            // returns an lvalue
    decltype(*p) var11 = i; // int&(*operator returns an lvalue)                                


    // Pointer to function
    auto (*p_new)() -> std::string;

    // functions with similar prototypes
    auto lambda = []() -> std::string { return { "function lambda_2" }; };
    auto (*p2)() = lambda;
```

### Expressoes de função Lambda
- [references](https://en.cppreference.com/w/cpp/language/lambda)

```cpp
    // functions with similar prototypes
    std::string (*lambda_1)() = []() -> std::string { return "function lambda_1"; };
    auto lambda_2 = []() -> std::string { return { "function lambda_2" }; };

    // >> Pointer to function
    std::string (*p_old)();         // Declaration formal
    auto (*p_new)() -> std::string; // New sintaxe

    p_old = lambda_1;
    std::cout << "Call pointer to lambda function [" << (*p_old)() << "]\n";

    p_new = lambda_2;
    std::cout << "Call pointer to lambda function [" << (*p_new)() << "]\n";
```

### Sintaxe uniforme de Inicializacao
- [Uniform Initialization in C++](https://www.geeksforgeeks.org/uniform-initialization-in-c/)

```cpp
    // uninitialized built-in type
    int i;    

    // initialized built-in type
    int j=10;

    // initialized built-in type
    int k(10);

    // Aggregate initialization
    int a[]={1, 2, 3, 4}

    // default constructor
    X x1;

    // Parameterized constructor
    X x2(1);

    // Parameterized constructor with single argument
    X x3=3;

    // copy-constructor
    X x4=x3;
```

### Declaração de metodos default e delete
- [Defaulted functions](https://community.ibm.com/community/user/ibmz-and-linuxone/blogs/fang-lu2/2020/03/24/defaulted-functions-in-c11)
- [Explicitly defaulted functions (C++11)](https://www.ibm.com/docs/en/zos/2.3.0?topic=definitions-explicitly-defaulted-functions-c11)
- [Deleted functions (C++11}](https://www.ibm.com/docs/en/zos/2.3.0?topic=definitions-deleted-functions-c11)

### Declaração de metodos final e override
- [final specifier](https://en.cppreference.com/w/cpp/language/final)
- [override specifier](https://en.cppreference.com/w/cpp/language/override)
