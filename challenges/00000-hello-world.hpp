#pragma once

// Switch to #if true when you're ready to attempt
#if false

#include <type_traits>
#include <string>

/*
 * Problem:
 *
 * This is a warm-up challenge for making sure things run.
 * The goal is to get the HelloWorld type (specified with using) to match the std::string type.
 *
 */

namespace hello_world_challenge {
    /*************************************
     * Solution Type, CHANGE THIS
     *************************************/

    using HelloWorld = void;

    /*************************************
     *  ____  ____  ____  ____  ____
     * (_  _)(  __)/ ___)(_  _)/ ___)
     *   )(   ) _) \___ \  )(  \___ \
     *  (__) (____)(____/ (__) (____/
     *
     *  Do Not Modify Below This Line
     *  ------------------------------
     *************************************/

    static_assert(std::is_same_v<HelloWorld, std::string>);
}

#endif