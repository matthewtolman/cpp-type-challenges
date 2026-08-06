#pragma once

#if false

#include <concepts>
#include <string>
#include <type_traits>

#include "../utilities/type_checks.h"

/*
* Problem:
*
* We want to be able to create a new 'Pick' type whose properties are determined from a combination of a
* reference type and a list of fields to pick from that reference type. Only the fields in that list
* should be part of the 'Pick' type. Their types should match the types on the reference type.
*
* Note: Since C++20 doesn't have reflection, we can't do arbitrary field selection like we can in TypeScript.
* So, for this challenge, we will only be picking out three fields: title, description, completed.
* An enum class is provided already for using as input to select each field.
*
* Test cases are provided at the end to make sure the type works.
*
*/

// Switch to #if true when you're ready to attempt

namespace pick_challenge {
    /*************************************
     * Setup types, do NOT change these
     *************************************/

    enum class PickFields {
        TITLE, DESCRIPTION, COMPLETED,
    };

    /*************************************
     * Solution Type, CHANGE THIS
     *************************************/

    template<class RefType, PickFields ... Fields>
    struct Pick;


    /*************************************
     *  ____  ____  ____  ____  ____
     * (_  _)(  __)/ ___)(_  _)/ ___)
     *   )(   ) _) \___ \  )(  \___ \
     *  (__) (____)(____/ (__) (____/
     *
     *  Do Not Modify Below This Line
     *  ------------------------------
     *************************************/

    template<class T, class U>
    concept HasTitle = requires()
    {
        {
            HoldsTrue<std::is_same_v<decltype(std::declval<T>().title), decltype(std::declval<U>().title)> >{}
        } -> std::same_as<std::true_type>;
    };

    template<class T, class U>
    concept HasDescription = requires()
    {
        {
            HoldsTrue<std::is_same_v<decltype(std::declval<T>().description), decltype(std::declval<U>().description)> >
            {}
        } -> std::same_as<std::true_type>;
    };

    template<class T, class U>
    concept HasCompleted = requires()
    {
        {
            HoldsTrue<std::is_same_v<decltype(std::declval<T>().completed), decltype(std::declval<U>().completed)> >{}
        } -> std::same_as<std::true_type>;
    };

    struct Todo {
        std::string title;
        std::string description;
        bool completed;
    };

    struct Assignment {
        std::string_view title;
        std::string_view description;
        int completed;
    };

    using TestType1 = Pick<Todo, PickFields::TITLE, PickFields::DESCRIPTION>;
    static_assert(HasTitle<TestType1, Todo>);
    static_assert(HasDescription<TestType1, Todo>);
    static_assert(!HasCompleted<TestType1, Todo>);

    using TestType2 = Pick<Todo, PickFields::DESCRIPTION, PickFields::COMPLETED>;
    static_assert(!HasTitle<TestType2, Todo>);
    static_assert(HasDescription<TestType2, Todo>);
    static_assert(HasCompleted<TestType2, Todo>);

    using TestType3 = Pick<Assignment, PickFields::DESCRIPTION, PickFields::COMPLETED>;
    static_assert(!HasTitle<TestType3, Assignment>);
    static_assert(HasDescription<TestType3, Assignment>);
    static_assert(HasCompleted<TestType3, Assignment>);

    using TestType4 = Pick<Assignment, PickFields::TITLE>;
    static_assert(HasTitle<TestType4, Assignment>);
    static_assert(!HasDescription<TestType4, Assignment>);
    static_assert(!HasCompleted<TestType4, Assignment>);
}

#endif
