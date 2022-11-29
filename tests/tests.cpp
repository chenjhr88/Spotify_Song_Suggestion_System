#include <iostream>
#include <fstream>
#include <ctype.h>
#include <time.h>
#include <utility>

TEST_CASE("test1", "[valgrind][weight=1]")
{
    REQUIRE("HELLO" == "HELLO");
}