#include <type_traits>

template <typename T, bool Move = true, bool Stop = true, bool Pause = true>
struct Chain
{
    Chain(T &inner) : _inner(inner) {}
    typedef std::integral_constant<bool, Move> CanMove;
    typedef std::integral_constant<bool, Stop> CanStop;
    typedef std::integral_constant<bool, Pause> CanPause;

    auto move()
    {
        static_assert(CanMove::value, "Able to move");
        return _inner.move();
    }
    auto stop()
    {
        static_assert(CanStop::value, "Able to stop");
        return _inner.stop();
    }
    auto pause()
    {
        static_assert(CanPause::value, "Able to pause");
        return _inner.pause();
    }

    T &_inner;
};

struct A
{

    auto move() { return Chain<A, false, true, true>(*this); }
    auto stop() { return Chain<A, true, false, true>(*this); }
    auto pause() { return Chain<A, true, false, false>(*this); }
};

int main(int, char **)
{
    A a;
    a.move().stop().pause().move();
    // a.move().move(); // fails with static assert
}