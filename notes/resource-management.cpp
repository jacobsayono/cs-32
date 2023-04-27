/*
RESOURCE MANAGEMENT

limited resources in
    memory
    processor
    disk space
    network
    number of open files
    ...

*/

/*
    Steps of construction:
    1) inheritance
    2) construct the data members, consulting the member initialization list
        if a data member is not listed in the member initialization list:
            if it's of a built-in type (like double), it's left uninitialized
            if it's of a class type, that class' default constructor is called
    3) execute the body code of the constructor inside {}

    Steps of destruction:
    1) execute the body of the destructor
    2) destory each data member:
        if it's of a built-in type, do nothing
        if it's of a class type, call class' default destructor for that member
    3) inheritance
*/

#include <cstring>

class String {
    public:
        String(const char* value = "");
        String(const String& other);  // copy constructor
        // String(String other);  / ILLEGAL!!!
        String& operator=(const String& rhs);  // assignment constructor
        ~String();
        void swap(String& other);
        // ...
    private:
        // char text_[100000];  (all strings will allocate 100000 memory long)
        // class invariant:
        // text_ is a pointer to a dynamically allocated array of len_ + 1 characters
        // len_ >= 0
        // len_ == strlen(text_)
        char* text_;
        int len_;
        // int number_of_copies_made_from_me_;  // this is OK
};

void String::swap(String& other) {
    // ... swap text_ and other.text_ ...
    // ... swap len_ and other.len_ ...
}

String& String::operator=(const String& rhs) {
    if (this != &rhs) {  // copy-and-swap
        String temp(rhs);
        swap(temp);
    }
    return *this;
}

// NOT MODERN WAY
// String& String::operator=(const String& rhs) {
//     if (this != &rhs) {
//         delete [] text_;
//         len_ = rhs.len_;
//         text_ = new char[len_ + 1];
//         strcpy(text_, rhs.text_);
//         return *this;
//         /*
//         v = (u = s);    v.operator(u.operator=(s));
//         u = s;  u.operator = (s);   'this' points to u, rhs is a reference to s
//         */
//     }
// }

/*
two pointers or references to the same type ===> aliasing might occur
"aliasing" two or more different ways of talking about the same object
*/

String::String(const char* value) {  // value: nullptr
    /*
    u:  text_: '\0'
        len_: 0
    */
    if (value == nullptr) {
        value = "";  // value: '\0'
    }
    len_ = strlen("");
    text_ = new char[len_ + 1];
    strcpy(text_, value);
}

// String::String(const char* value) {
//     len_ = strlen(value);
//     // text_ = value;
//     text_ = new char[len_ + 1];
//     strcpy(text_, value);
// }

// String::String() {
//     len_ = 0;
//     text_ = new char[1];
//     text_[0] = '\0';

//     len_ = strlen("");
//     text_ = new char[len_ + 1];
//     strcpy(text_, ___);
// }

String::~String() {
    // delete text_;  // WRONG!!!
    delete [] text_;
}

/*
Blah* bp = new Blah;
...
delete bp;

Foo* fp = new Foo[100];
...
delete [] fp;
*/

String::String(const String& other) {
    len_ = other.len_;
    text_ = new char[len_ + 1];
    strcpy(text_, other.text_);
}




void f(String t) {
    // ...
}

void h() {
    /*
    s:  text_: H e l l o '\0'
        len_: 5

    t:  text_: '\0'
        len_: 0
    */

    String s("Hello");
    String t;  // String t("");
    // ...
    char* p;
    // ... set p somehow ..
    String u(p);
    // ...

    f(s);
    String w("WOW");
    w = s;
}

// {0} {1} {2} {3} {4} {5}
// 'H' 'e' 'l' 'l' 'o' '\0'




/*
copy String example:

String x(s);
String x = s;
passing a String by value to a function
returning a value from a function (not a pointer or reference)


String blah(..., ..., ...) {
    String result;
    ...
    return result;
}

*/