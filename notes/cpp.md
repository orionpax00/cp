---
title: "CPP"
author: Durgesh

html:
  offline: false

export_on_save:
  html: true

print_background: true
---

* Static data memeber doesn't contribute to size of object.
```cpp
class Test{
    static int i;
    int j;
}

Test t;
cout << sizeof(t);
------------------
output: 4 //size of integer j
```
* Both static and Non static functions does not contribute of size

* In Multiple inheritence constructors are called in derivation order from left to right while destructors are called in reverse order.
```cpp
class B1{
    public:
    B1(){
        cout <<"B1\n";
    }
}

class B2{
    public:
    B2(){
        cout <<"B2\n";
    }
}

class D: public B1, public B2{ //Multiple Inheritance
    D(){
        cout <<"D\n";
    }
}
----------
output: 
B1
B2
D
```
* Conversion constructor and Conversion Operator
```cpp
class A{
    public:
    A(int _n){ // can be extended to multiple argument
        n = _n;
    }

    void print(){
        cout << n ;
    }

    private:
    int n;
}

A a(10);
a.print()

a = 20;  // same can be extended to multiple argument as {a,b,c,d,...}
a.print()
```

* virtual inheritence : save memory by not causing unnessary copies of base class.
```cpp
class Base{
    int b;
}

class D : virtual public Base {}
```
* If there are multiple levels of inheritence then the function is searched lineary from bottom to top until the matching function is found.
```cpp
class A{
    public:
    print(){
        cout << "A";
    }
}
class B{
    public:
    print(){
        cout << "B";
    }
}

class D: public A, public B{}

D d;
d.print();
---------
output: B
```

* Scope Resolution Operator
```cpp
int x = 10;
void func(){
    int x = 1;
    {
        int x = 2;
        cout << ::x; // global scope
    }
}
func()
-------
output: 10
```



