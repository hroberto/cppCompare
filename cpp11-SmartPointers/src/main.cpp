// Source = https://www.geeksforgeeks.org/smart-pointers-cpp/


#include <iostream>
#include <memory>



void  smartPointer_unique()
{
    std::cout << "=====  SmartPointer - unique_ptr =======" << std::endl;

    std::unique_ptr< std::string > us1( new std::string( "Test Smart Pointer") );

    std::cout << "Address pointer us1 [" << us1.get() << "]" << std::endl;
    std::cout << "  - Content [" << *us1 << "]" << std::endl;

    std::cout << "Moving SmartPointer for other variable." << std::endl;
    std::unique_ptr< std::string > us2 = std::move( us1 );

    std::cout << "Address pointer us1 [" << us1.get() << "]" << std::endl;
    std::cout << " - Pointer was moved for other SmartPointer." << std::endl;

    std::cout << "Address pointer us2 [" << us2.get() << "]" << std::endl;
    std::cout << "  - Content US2[" << *us2 << "]" << std::endl;
}

void  smartPointer_shared()
{
    std::cout << "\n=====  SmartPointer Shared =======" << std::endl;

    std::shared_ptr< std::string > us1( new std::string( "Test Smart Pointer") );

    std::cout << "Address pointer us1 [" << us1.get() << "] - use_count [" << us1.use_count() << "]" << std::endl;
    std::cout << "  - Content US1 [" << *us1 << "]" << std::endl;

    std::cout << "Copying  SmartPointer for other variable." << std::endl;
    std::shared_ptr< std::string > us2 = us1;

    std::cout << "Address pointer us1 [" << us1.get() << "] - use_count [" << us1.use_count() << "]" << std::endl;
    std::cout << "  - Content US1 [" << *us1 << "]" << std::endl;

    std::cout << "Address pointer us2 [" << us2.get() << "] - use_count [" << us2.use_count() << "]" << std::endl;
    std::cout << "  - Content US2[" << *us2 << "]" << std::endl;
}

void  smartPointer_weak()
{
    std::cout << "\n=====  SmartPointer Weak =======" << std::endl;

    std::weak_ptr< std::string > us_weak;
    {
        std::shared_ptr< std::string > us1( new std::string( "Test Smart Pointer") );

        std::cout << "Address pointer us1 [" << us1.get() << "] - use_count [" << us1.use_count() << "]" << std::endl;
        std::cout << "  - Content US1 [" << *us1 << "]" << std::endl;

        us_weak = us1;
        std::cout << "Address pointer us1 [" << us1.get() << "] - use_count [" << us1.use_count() << "]" << std::endl;

        std::cout << "Address pointer us_weak.expired() [" << std::boolalpha << us_weak.expired() << "] - use_count [" << us_weak.use_count() << "]" << std::endl;

        if (auto mySharedTemp = us_weak.lock()) { // Has to be copied into a shared_ptr before usage
            std::cout << *mySharedTemp << "\n";
            std::cout << "  - Content us_weak [" << *mySharedTemp << "]" << std::endl;
        }
        else {
            std::cout << "us_weak is expired\n";
        }
    }
    std::cout << "Address pointer us_weak.expired() [" << std::boolalpha << us_weak.expired() << "] - use_count [" << us_weak.use_count() << "]" << std::endl;

}


int main(int __argc, char** __argv)
{
    smartPointer_unique();
    smartPointer_shared();
    smartPointer_weak();

    return EXIT_SUCCESS;
}
