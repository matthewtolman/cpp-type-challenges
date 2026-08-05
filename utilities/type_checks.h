#pragma once

#include <type_traits>

template<bool v> struct HoldsTrueImpl { using type = std::false_type; };
template<> struct HoldsTrueImpl<true> { using type = std::true_type; };

/**
 * Useful inside a concept to assert that a type expression which evaluates to a boolean value holds true
 * Example Usage:
 *
 *  template<class T, class U>
 *  concept HasTitle = requires(T t, U u)
 *  {
 *      { HoldsTrue<std::is_same_v<
 *              decltype(std::declval<T>().title),
 *              decltype(std::declval<U>().title)
 *        >>{} } -> std::same_as<std::true_type>;
 *  };
 */
template<bool v> using HoldsTrue = HoldsTrueImpl<v>::type;
