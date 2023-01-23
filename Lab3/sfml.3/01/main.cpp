#include <iostream>

int main()
{
    for (int i = 0; i < 100; i++)
    {
        switch (i % 15)
        {
        case 0:
            std::cout << "FizzBuzz" << std::endl;
            break;
        case 5:
        case 10:
            std::cout << "Buzz" << std::endl;
            break;
        case 3:
        case 6:
        case 9:
        case 12:
            std::cout << "Fizz" << std::endl;
            break;
        default:
            std::cout << i << std::endl;
        }
    }
    return 0;
}