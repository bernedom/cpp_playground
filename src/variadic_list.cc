

#include <initializer_list>
#include <iostream>
#include <type_traits>

template <char... Cs> struct list {
  typedef std::integral_constant<char, '\0'> v;

  static constexpr bool has_duplicate(const char c) { return false; }
};

template <char C, char... Cs> struct list<C, Cs...> : list<Cs...> {
  typedef std::integral_constant<char, C> v;

  static_assert(!list<Cs...>::has_duplicate(C), "No duplicates allowed");

  static constexpr bool has_duplicate(const char c) {
    if
      constexpr(C == list<Cs...>::v::value) { return true; }
    if (c == C) {
      return true;
    }
    return list<Cs...>::has_duplicate(c);
  }
};

template <typename... Ts> struct unpack {

  static constexpr void print() { std::cout << "DEAD\n"; }
};

template <typename T, typename... Ts> struct unpack<T, Ts...> : unpack<Ts...> {

  static constexpr void print() {
    // std::cout << "VARIADIC PACK " << std::declval(T) << "\n ";
    unpack<Ts...>::print();
  }
};

template <typename... Cs> void add_step(Cs...) { unpack<Cs...>::print(); }

int main(int, char **) {
  list<'a', 'b', 'c'> ok;
  // these do not compile on purpose because of the static_assert
  // list<'x', 'y', 'y'> not_ok_next_to_each_others;
  // list<'x', 'y', 'z', 'x'> not_ok_with_space;

  add_step('g', 'h', 'i');
  return 0;
}