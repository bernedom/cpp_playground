/**
 *
 * Example illustrating how a user o fa class can be forced to call init()
 * before a call to another function
 */

#include <cassert>
#include <type_traits>

// A defined type that is only copy-constructible from the outside
template <typename T, int I> struct Enforcer {

  typedef std::integral_constant<int, I> Id;
  friend T;

public:
  Enforcer(const Enforcer &rhs) = default;
  Enforcer(Enforcer &&rhs) = default;

  Enforcer &operator=(const Enforcer &rhs) = default;
  Enforcer &operator=(Enforcer &&rhs) = default;

  const T *owner() const { return _owner; }

private:
  Enforcer(T *owner) : _owner(owner){};
  T *_owner;
};

struct Dummy {
  int _i{99};
};

template <int I> struct ForceCallToInit {

  const Enforcer<ForceCallToInit, I> init() {
    // do stuff
    return Enforcer<ForceCallToInit, I>{this};
  }

  void doSomething(const Enforcer<ForceCallToInit, I> &e) {
    assert(e._owner == this);
  }
};

int main(int, char **)

{
  ForceCallToInit<1> fc;
  auto token = fc.init();
  fc.doSomething(token);

  ForceCallToInit<2> fc2;

  // below fails with an assert
  // fc2.doSomething(token);
  // fc2.doSomething(token);

  return 0;
}
