#include <iostream>

int main()
{
    // в цикле от 1 до 100
    for (int i = 1; i <= 100; i++)
    {
        //  - если число кратно и 3, и 5, вывести FizzBuzz
        if ((i % 3) == 0 && ((i % 5) == 0))
        {
            std::cout << "FizzBuzz" << std::endl;
        }
        //  - иначе если число кратно 3, вывести Fizz
        else if (i % 3 == 0)
        {
            std::cout << "Fizz" << std::endl;
        }
        //  - иначе если число кратно 5, вывести Buzz
        else if (i % 5 == 0)
        {
            std::cout << "Buzz" << std::endl;
        }
        //  - иначе вывести число
        else
        {
            std::cout << i << std::endl;
        }
    }
}
