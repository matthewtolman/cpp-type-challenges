#pragma once

// Switch to #if true when you're ready to attempt
#if false
#include <type_traits>

#include <string>
#include <type_traits>
#include <tuple>
#include <variant>

/*
* Problem:
*
* We have a tuple type and we want to make a variant that could hold every type present in the tuple.
* Basically, given `std::tuple<int, std::string, double>` we want to get out `std::variant<int, std::string, double>`.
*
* Test cases are provided at the end to make sure the type works.
*
*/

namespace tuple_variant_challenge {

    /*************************************
     * Solution Type, CHANGE THIS (may need some helpers)
     *************************************/

    template<typename T>
    using to_variant = void;

    /*************************************
     *  ____  ____  ____  ____  ____
     * (_  _)(  __)/ ___)(_  _)/ ___)
     *   )(   ) _) \___ \  )(  \___ \
     *  (__) (____)(____/ (__) (____/
     *
     *  Do Not Modify Below This Line
     *  ------------------------------
     *************************************/

    static_assert(
        std::is_same_v<to_variant<std::tuple<int, double, std::string> >, std::variant<int, double, std::string> >);
    static_assert(
        std::is_same_v<to_variant<std::tuple<std::tuple<int, double>, double, std::string> >, std::variant<std::tuple<
            int, double>, double, std::string> >);
}

#endif
