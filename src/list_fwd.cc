// #include <initializer_list>
// #include <type_traits>
// #include <memory>

// template<typename ...T>
// class VTemp : public std::initializer_list<T...>{
// public:
//     constexpr VTemp(T... t) : std::initializer_list<decltype(t)...>(t...){
//         static_assert(sizeof...(T) > 1, "At least two");
//     }
// };

// template<typename ...T>
// class VV {
//     public:
//     static_assert(sizeof...(T) > 1 "at least two");
//     constexpr VV(T... t) {

//     }
// };

// class IniL
// {
//     public:
//     IniL(std::initializer_list<int> l)
//     {
//         constexpr VV<decltype(l)::value_type> v(l);
//      //static_assert(l.size() > 0, "At least two");
//         //VTemp(l);
//       //  VTemp t({1, 2, 3});
//     }
// };

int main(int, char **)
{
    //    IniL i{1,2,3};
    //  VV<int, int> v(1, 2);

    //  VV{1,2};
    //VTemp<int>(1);
}