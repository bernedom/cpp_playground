/*
 An example to illustrate how a compile time check of a fixed size collection
 could be
 facilitated using variadic templates and static asserts
*/

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
constexpr void check(T a) {}

template <typename... Ts>
constexpr void check(Ts... list_of_a)
{
  check(list_of_a...);
}

template <typename T, typename T1, typename... Ts>
constexpr void check(T t, T1 t1, Ts... list_of_a)
{
  static_assert(T::id::value != T1::id::value, "No duplicates");
  check(t, list_of_a...);
  check(t1, list_of_a...);
}

int main(int, char **)
{
  check(A<1>(), A<2>(), A<3>()); // OK
  // check(A<1>(), A<1>(), A<2>()); // static assert triggered
  // check(A<1>(), A<2>(), A<2>()); // static assert triggered
  // check(A<1>(), A<2>(), A<1>()); // static assert triggered
  // check(A<1>(), A<2>(), A<1>(), A<2>());
}
