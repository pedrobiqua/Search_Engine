#include "hello.h"

Hello::Hello() {}

std::string Hello::greet(const std::string& name) {
    return "Hello, " + name + "!";
}
