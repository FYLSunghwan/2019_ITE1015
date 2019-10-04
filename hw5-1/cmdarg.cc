#include <iostream>
#include <string>

int main(int argc, char** argv) {
    std::string strs;
    int n=0;
    for(int i = 1; i<argc; i++) {
        int inp = atoi(argv[i]);
        if(inp) n+=inp;
        else strs += std::string(argv[i]);
    }
    std::cout << strs << std::endl << n << std::endl;
    return 0;
}