#include "Executor.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc == 2)
            Executor exe(argv[1]);
        else
        {
            Executor();
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
//    system("leaks avm");
    return 0;
}