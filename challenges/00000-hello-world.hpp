#pragma once

// Switch to #if true when you're ready to attempt
#if false

#include <type_traits>
#include <string>

// Change this type to get the static assert to pass
using HelloWorld = void;

/*
 *  ____  ____  ____  ____  ____
 * (_  _)(  __)/ ___)(_  _)/ ___)
 *   )(   ) _) \___ \  )(  \___ \
 *  (__) (____)(____/ (__) (____/
 *
 *  Do Not Modify Below This Line
 *  ------------------------------
 */

static_assert(std::is_same_v<HelloWorld, std::string>);

#endif