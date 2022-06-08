#include<iostream>
using namespace std;

class A{
    public:
    int a;
    void funcA(){
        cout << "Function A is called.\n";
    }

    private:
    int b;
    void funcB(){
        cout << "Function B is called.\n";
    }

    protected:
    int c;
    void funcC(){
        cout << "Function C is called.\n";
    }
};   

int main(){
    A obj;
    obj.funcA();
    return 0;
}