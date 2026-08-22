#pragma once

// Switch to #if true when you're ready to attempt
#if false
#include <cstdint>

/*
* Problem:
*
* Calculate the Nth Fibonacci number at compile time. You may use templates or constexpr.
*/

namespace fibonacci_challenge {

/*************************************
 * Solution Type, CHANGE THIS (may need some helpers)
 *************************************/

template<uint32_t N>
static constexpr auto fibonnaci_v = 0;

/*************************************
 *  ____  ____  ____  ____  ____
 * (_  _)(  __)/ ___)(_  _)/ ___)
 *   )(   ) _) \___ \  )(  \___ \
 *  (__) (____)(____/ (__) (____/
 *
 *  Do Not Modify Below This Line
 *  ------------------------------
 *************************************/

static_assert(fibonnaci_v<0> == 0);
static_assert(fibonnaci_v<1> == 1);
static_assert(fibonnaci_v<2> == 1);
static_assert(fibonnaci_v<3> == 2);
static_assert(fibonnaci_v<4> == 3);
static_assert(fibonnaci_v<5> == 5);
static_assert(fibonnaci_v<6> == 8);
static_assert(fibonnaci_v<7> == 13);
static_assert(fibonnaci_v<8> == 21);
static_assert(fibonnaci_v<9> == 34);
static_assert(fibonnaci_v<10> == 55);
static_assert(fibonnaci_v<11> == 89);
static_assert(fibonnaci_v<12> == 144);
static_assert(fibonnaci_v<13> == 233);
static_assert(fibonnaci_v<14> == 377);
static_assert(fibonnaci_v<15> == 610);
static_assert(fibonnaci_v<16> == 987);
}

#endif
