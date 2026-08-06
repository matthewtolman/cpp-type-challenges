#pragma once

#if false

#include <string>
#include <type_traits>

/*
* Problem:
*
* We want to be able to create a new 'Const' type whose properties are determined from a combination of a
* reference type and a list of fields to pick from that reference type. Fields in that list
* should be marked const, other fields should be left as-is. If the field list is empty, then everything
* should be marked const.
*
* Note: Since C++20 doesn't have reflection, we can't do arbitrary field selection like we can in TypeScript.
* So, for this challenge, we will only be picking out three fields: title, description, completed.
* An enum class is provided already for using as input to select each field.
*
* Test cases are provided at the end to make sure the type works.
*
*/

// Switch to #if true when you're ready to attempt

namespace const_challenge {
    /*************************************
     * Setup types, do NOT change these
     *************************************/

    enum class ConstFields {
        TITLE, DESCRIPTION, COMPLETED,
    };

    /*************************************
     * Solution Type, CHANGE THIS (may need some helpers)
     *************************************/

    template<class RefType, ConstFields ... Fields>
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

    template<typename T, typename I, bool isConst>
    constexpr bool titleShouldBeConst = isConst ?
        std::is_same_v<decltype(std::declval<T>().title), std::add_const_t<decltype(std::declval<I>().title)>> :
        std::is_same_v<decltype(std::declval<T>().title), decltype(std::declval<I>().title)>;

    template<typename T, typename I, bool isConst>
    constexpr bool descriptionShouldBeConst = isConst ?
        std::is_same_v<decltype(std::declval<T>().description), std::add_const_t<decltype(std::declval<I>().description)>> :
        std::is_same_v<decltype(std::declval<T>().description), decltype(std::declval<I>().description)>;

    template<typename T, typename I, bool isConst>
    constexpr bool completedShouldBeConst = isConst ?
        std::is_same_v<decltype(std::declval<T>().completed), std::add_const_t<decltype(std::declval<I>().completed)>> :
        std::is_same_v<decltype(std::declval<T>().completed), decltype(std::declval<I>().completed)>;

    using TestType1 = Const<Todo, ConstFields::TITLE, ConstFields::DESCRIPTION>;
    static_assert(titleShouldBeConst<TestType1, Todo, true>);
    static_assert(descriptionShouldBeConst<TestType1, Todo, true>);
    static_assert(descriptionShouldBeConst<TestType1, Todo, false>);
    static_assert(completedShouldBeConst<TestType1, Todo, false>);

    using TestType2 = Const<Todo, ConstFields::DESCRIPTION, ConstFields::COMPLETED>;
    static_assert(titleShouldBeConst<TestType2, Todo, false>);
    static_assert(descriptionShouldBeConst<TestType2, Todo, true>);
    static_assert(descriptionShouldBeConst<TestType2, Todo, false>);
    static_assert(completedShouldBeConst<TestType2, Todo, true>);

    using TestType3 = Const<Assignment, ConstFields::DESCRIPTION, ConstFields::COMPLETED>;
    static_assert(titleShouldBeConst<TestType3, Assignment, false>);
    static_assert(descriptionShouldBeConst<TestType3, Assignment, true>);
    static_assert(completedShouldBeConst<TestType3, Assignment, true>);

    using TestType4 = Const<Assignment, ConstFields::TITLE>;
    static_assert(titleShouldBeConst<TestType4, Assignment, true>);
    static_assert(descriptionShouldBeConst<TestType4, Assignment, false>);
    static_assert(completedShouldBeConst<TestType4, Assignment, false>);

    using TestType5 = Const<Assignment>;
    static_assert(titleShouldBeConst<TestType5, Assignment, true>);
    static_assert(descriptionShouldBeConst<TestType5, Assignment, true>);
    static_assert(completedShouldBeConst<TestType5, Assignment, true>);
}

#endif
