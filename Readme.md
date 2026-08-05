# C++ Type Challenge

Recently inspired by the TypeScript type challenge,
I decided to port it over to C++20 (at least the parts I could -
TypeScript has some type concepts that don't map cleanly over).

Currently, tests aren't categorized, just numbered based on the number
in the TypeScript challenge. I'm adding them in the order I attempt them
and port them over.

To get started, download this code and a modern C++ compiler.

> Note: I've only tested this with GCC 16 on Linux; other compilers may have their own quirks which requires changes to the tests.

## How to Attempt a Challenge

To attempt a challenge, change the `#if false` to `#if true` to enable the challenge.
Attempt your solution, and then compile `compile_checks.cpp` with C++20 (e.g. `g++ -std=c++20 compile_checks.cpp -c`).
When you're done with a challenge, feel free to turn the `#if true` back to `#if false` so you're not
recompiling that challenge every time.

## Resources for learning more about C++ types

* Websites/Blogs
  * [cppreference.com](https://cppreference.com/)
  * [My blog where I present the challenges (and cover solutions)](https://matthewtolman.com)
    * Note: my blog posts are scheduled, so challenges may come out here before they're presented on my blog. Think of it as an early preview!
* YouTube
  * [C++ Weekly](https://www.youtube.com/channel/UCxHAlbZQNFU2LgEtiqd2Maw)
* Books
  * C++ Template Metaprogramming by David Abrahams, Aleksey Gurtovoy (ISBN 0321227255)
  * Advanced Metaprogramming in Classic C++ by Davide Di Gennaro (ISBN-13 978-1-4842-1011-6)

