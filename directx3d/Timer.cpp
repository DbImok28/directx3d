#include "Timer.hpp"

Timer::Timer()
{
	last = std::chrono::steady_clock::now();
}

float Timer::Mark()
{
	const auto old = last;
	last = std::chrono::steady_clock::now();
	return (last - old).count();
}

float Timer::Peek() const
{
	return std::chrono::duration<float>(std::chrono::steady_clock::now() - last).count();
}