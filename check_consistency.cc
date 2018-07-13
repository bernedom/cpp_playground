#include <iostream>
#include <type_traits>

template <int I>
struct A
{
  typedef std::integral_constant<int, I> id;
  constexpr A() = default;
};

// could use std::enable if to create a type failure if Ts are not instances of
// A

template <typename T>
constexpr bool check(T a) { return true; }

template <typename... Ts>
constexpr bool check(Ts... list_of_a)
{
  return check(list_of_a...);
}

template <typename T, typename... Ts>
constexpr bool check(T a, Ts... list_of_a)
{
  // check<T, Ts...>(a, list_of_a...) && check<Ts...>(list_of_a...);
  // static_assert(T::id::value == 1, "oops");
  return check(list_of_a...);
}

template <typename T, typename T1, typename... Ts>
constexpr bool check(T t, T1 t1, Ts... list_of_a)
{
  // static_assert(T::id::value != T1::id::value, "No duplicates");
  // check<T1, Ts...>(t1, list_of_a...);
  static_assert(T::id::value != T1::id::value, "No duplicates");
  return check(t, list_of_a...) && check(t1, list_of_a...);
}

int main(int, char **)
{
  check(A<1>(), A<2>(), A<3>()); // OK
  // check(A<1>(), A<1>(), A<2>()); // static assert triggered
  // check(A<1>(), A<2>(), A<2>()); // static assert triggered
  // check(A<1>(), A<2>(), A<1>()); // static assert triggered
}
