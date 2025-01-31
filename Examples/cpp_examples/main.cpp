#include <hello.h>

int main(int argc, char const* argv[]) {
    auto hello = Hello();
    std::cout << hello.greet("Pedro") << std::endl;
    return 0;
}
