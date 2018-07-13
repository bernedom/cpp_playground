#include <type_traits>

// {
//     std::integral_constant<bool, b> init_called;
//     static constexpr int Oid = I;
// };
// template <int I, bool b>
// struct enforcerImpl
// {
//     std::integral_constant<bool, b> isHere;
// };

// template <int I>
// struct enforcer : public enforcerImpl<I, true>
// {
// };

// class C
// {

//   private:
//   public:
//     constexpr C()
//     {
//     }

//     template <int I>
//     constexpr enforcer<I> init(const int i)
//     {
//         typedef enforcer<I> e;
//     }

//     constexpr void execute()
//     {
//         //static_assert(std::is_constructible<enforcer<2>>(), "type is
//         defined");
//         //static_assert(enforcerImpl<1, true>::isHere::value, "is here");
//         static_assert(std::is)
//     }

//     void inc()
//     {
//         _i++;
//     }

//     int _i{99};
// };

int main(int, char **) {
  // C c;
  // c.inc();
  // c.init<1>(99);
  // return 0;
}