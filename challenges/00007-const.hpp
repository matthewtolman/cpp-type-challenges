#pragma once

#if false

#include <string>
#include <type_traits>

/*
* Problem:
*
* We want to be able to create a new 'Const' type whose properties are determined from a reference type.
* This reference type will have the fields title, description, and completed, but the types of those fields
* will differ. The Const type should use those types with an additional const modifier (e.g. int -> const int).
*
* Note: Since C++20 doesn't have reflection, we can't do arbitrary field selection like we can in TypeScript.
* So, for this challenge, we will only be doing known fields.
*
* Test cases are provided at the end to make sure the type works.
*
*/

// Switch to #if true when you're ready to attempt

namespace const_challenge {
    /*************************************
     * Solution Type, CHANGE THIS (may need some helpers)
     *************************************/

    template<class RefType>
    struct Const;

    /*************************************
     *  ____  ____  ____  ____  ____
     * (_  _)(  __)/ ___)(_  _)/ ___)
     *   )(   ) _) \___ \  )(  \___ \
     *  (__) (____)(____/ (__) (____/
     *
     *  Do Not Modify Below This Line
     *  ------------------------------
     *************************************/

    struct Todo {
        std::string title;
        const std::string description;
        bool completed;
    };

    struct Assignment {
        std::string_view title;
        std::string_view description;
        int completed;
    };

    template<typename T, typename I>
    constexpr bool titleShouldBeConst =
        std::is_same_v<decltype(std::declval<T>().title), std::add_const_t<decltype(std::declval<I>().title)>>;

    template<typename T, typename I>
    constexpr bool descriptionShouldBeConst =
        std::is_same_v<decltype(std::declval<T>().description), std::add_const_t<decltype(std::declval<I>().description)>>;

    template<typename T, typename I>
    constexpr bool completedShouldBeConst =
        std::is_same_v<decltype(std::declval<T>().completed), std::add_const_t<decltype(std::declval<I>().completed)>>;

    using TestType1 = Const<Todo>;
    static_assert(titleShouldBeConst<TestType1, Todo>);
    static_assert(descriptionShouldBeConst<TestType1, Todo>);
    static_assert(completedShouldBeConst<TestType1, Todo>);

    using TestType2 = Const<Assignment>;
    static_assert(titleShouldBeConst<TestType2, Assignment>);
    static_assert(descriptionShouldBeConst<TestType2, Assignment>);
    static_assert(completedShouldBeConst<TestType2, Assignment>);
}

#endif
