#include <memory>

struct Next{

    Next(int _i ) : i{_i} {} 
    Next(const Next&) = delete;
    Next(Next&& n) = delete;
   
    Next& operator=(const Next&) = delete;
    Next&& operator=(Next&&) = delete;


    int i{0};
};


class C{
    public:
void func(Next&& n)
{ n.i = 55; }

};



int main(int, char**){

    C c;
    Next n(99);
    c.func(std::move(n));

    c.func(Next(123));
    return  0;
}