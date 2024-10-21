#include <iostream>
#include <string>
#include <cassert>
#include <catch2/catch_test_macros.hpp>
using namespace std;

string fizzbuzz(int n) {
        if(n % 3== 0 && n % 5 == 0) {
                return "FizzBuzz";
        }
        else if(n % 3 == 0) {
                return "Fizz";
        }
        else if(n % 5 == 0) {
                return "Buzz";
        }
        else {
                return to_string(n);
        }
}

int main() {
        cout << "Running tests with cassert first: ";
        assert(fizzbuzz(15) == "FizzBuzz");
        assert(fizzbuzz(3) == "Fizz");
        assert(fizzbuzz(5) == "Buzz");
        assert(fizzbuzz(7) == "7");
        assert(fizzbuzz(6) == "Fizz");
        assert(fizzbuzz(10) == "Buzz");
        assert(fizzbuzz(30) == "FizzBuzz");
        cout << "All cassert tests passed succesfully!" << endl;
        cout << "Now running tests with Catch2: ";
        TEST_CASE("Word printed is the integer when not divisible by 3 or 5", "[FizzBuzz1]") {
                REQUIRE(fizzbuzz(7) == "7");
        }
        TEST_CASE("Word printed is Fizz when divisible by 3", "[FizzBuzz2]") {
                REQUIRE(fizzbuzz(3) == "Fizz");
                REQUIRE(fizzbuzz(6) == "Fizz");
        }
        TEST_CASE("Word printed is Buzz when divisible by 5", "[FizzBuzz3]") {
                REQUIRE(fizzbuzz(5) == "Buzz");
                REQUIRE(fizzbuzz(10) == "Buzz");
        }
        TEST_CASE("Word printed is FizzBuzz when divisible by both 3 and 5", "[FizzBuzz4]") {
                REQUIRE(fizzbuzz(15) == "FizzBuzz");
                REQUIRE(fizzbuzz(30) == "FizzBuzz");
        }

        cout << "All catch 2 tests passed succesfully!" << endl;
        return 0;
}

