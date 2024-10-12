#include "fmt/format.h"
#include "mylib.hh"

int main() {
    int result = add(5, 3);

    fmt::print("5 + 3 = {}\n", result);

    return 0;
}
