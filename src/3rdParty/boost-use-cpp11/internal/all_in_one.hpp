//!
// This file is for compile-force-include, this can avoid some compile error(e.g. Compiler Error C2874 in VC11).
// In general, it like this.
//
//    #include <memory>
//    namespace boost {
//        template<typename T> class shared_ptr;
//        using std::shared_ptr;  // compile complain: using-declaration causes a multiple declaration of "std::shared_ptr"
//    }
//
// In fact, we can use alias-template(http://en.wikipedia.org/wiki/C%2B%2B0x#Alias_templates)to solve this problem, but vc11
// isn't supported(http://blogs.msdn.com/b/vcblog/archive/2011/09/12/10209291.aspx), so we have to modify our source code
// like this
//
//    #include <memory>
//    namespace boost {
//        using std::shared_ptr;                    // OK!
//        template<typename T> class shared_ptr;    // OK!
//    }
//
// Since using-xxx is in boost-use-cpp11 headers, we include them at the top of each source file. it is this file.

#pragma once
#ifndef BOOST_USE_CPP11_INTERNAL_ALL_IN_ONE_HPP
#define BOOST_USE_CPP11_INTERNAL_ALL_IN_ONE_HPP

#ifdef __cplusplus
#include "memory_wrapper.hpp"
#include "tuple_wrapper.hpp"
#endif

#endif // #ifndef BOOST_USE_CPP11_INTERNAL_ALL_IN_ONE_HPP