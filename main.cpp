//code from http://en.cppreference.com/w/cpp/language/constraints

#include <string>
#include <locale>
using namespace std::literals;

// Declaration of the concept "EqualityComparable", which is satisfied by
// any type T such that for values a and b of type T,
// the expression a==b compiles and its result is convertible to bool
template<typename T>
concept bool EqualityComparable = requires(T a, T b) {
	{ a == b } -> bool;
};

void f(EqualityComparable&&); // declaration of a constrained function template
							  // template<typename T>
							  // void f(T&&) requires EqualityComparable<T>; // long form of the same

int main() {
	f("abc"s); // OK, std::string is EqualityComparable
	f(std::use_facet<std::ctype<char>>(std::locale{})); // Error: not EqualityComparable 
}

/*
A concept is a named set of requirements. The definition of a concept appears at namespace scope
and has the form of a function template definition (in which case it is called function concept) 
or variable template definition (in which case it is called variable concept). The only difference 
is that the keyword concept appears in the decl-specifier-seq:
*/