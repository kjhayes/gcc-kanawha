// { dg-do run }
// { dg-additional-options "-pthread" { target pthread } }
// { dg-require-effective-target c++11 }
// { dg-require-gthreads "" }

// Copyright (C) 2013-2025 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

#include <mutex>
#include <chrono>
#include <thread>
#include <testsuite_hooks.h>

// PR libstdc++/57641

namespace C = std::chrono;

// custom clock with epoch 10s before system_clock's
struct clock
{
  typedef C::system_clock::rep rep;
  typedef C::system_clock::period period;
  typedef C::system_clock::duration duration;
  typedef C::time_point<clock> time_point;
  static constexpr bool is_steady = C::system_clock::is_steady;

  static time_point
  now()
  {
    auto sys_time = C::system_clock::now().time_since_epoch();
    return time_point(sys_time + C::seconds(10));
  }
};

std::timed_mutex mx;
bool locked = false;

template <typename ClockType>
void f()
{
  locked = mx.try_lock_until(ClockType::now() + C::milliseconds(1));
}

template <typename ClockType>
void test()
{
  std::lock_guard<std::timed_mutex> l(mx);
  auto start = ClockType::now();
  std::thread t(f<ClockType>);
  t.join();
  auto stop = ClockType::now();
  VERIFY( (stop - start) < C::seconds(9) );
  VERIFY( !locked );
}

int main()
{
  test<C::system_clock>();
  test<C::steady_clock>();
}
