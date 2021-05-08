#include <bits/stdc++.h>
using namespace std;

/*
    Type Casting and Casting Operators in C++ - I
    A cast operator takes an expression of source type (implicit from the expression) and convert it to an expression of target type
    (explicit in the operator) following the semantics of the operator.
    Example :
        i1 : T1   -> T2  (source type : T1 , target type = T2)
        cast<T2>(i)

    Types :
    1) const_cast<type>(expr)
        -Explicitly overrides const and/or volatile in a cast
        -Usually doesn't perform computation or change value
        -i.e. It can take away from a constant expression, or it can add constness to an expression

    2) static_cast<type>(expr)
        -Performs a non-polymorphic cast (Since, it's static, hence non-polymorphic)
        -Usually performs computation to change value - implicit or user defined

    3) reinterpret_cast<type>(expr)
        -Casts between unrelated pointer types or pointer & interger (should not be used much)

    4) dynamic_cast<type>(expr)  (IMPORANT)
        -Perform a run-time case that verifies the validity of the cast
        -Performs pre-defined computation, sets null or throws exception
*/

/////////////////////////////////const_cast Operator/////////////////////////////////////
class A {
    int i_;
public:
    A(int i) : i_(i) {}

    int get() const { return i_; }

    void set(int j) { i_ = j ; }
};

void print(char* str) {
    cout << str << endl;
}

int main() {
    const char *c = "sample text";

//    print(c); //ERROR : Cannot convert const char* to char*

    print(const_cast<char *>(c)); //You removed constness from c

    //Please note that 'this' is a constant pointer
    const A a(1); //'this' pointer points to a constant object a

    cout << a.get() << endl; //I am able to call const member function get() only because a is const

//    a.set(5); ERROR : a is of type 'const A' and when you call a.set(), you send 'this' pointer which is of type 'A&'
                        //So, converting from const A to A& gives error.

    const_cast<A&>(a).set(5); //Resultant is an object which has a 'this' pointer which points to a non-const object

    //Please note that 'this' is a constant pointer
    //const_cast<A>(a).set(5); So, this is not allowed. You cannot remove constness of 'this' pointer

return 0;
}