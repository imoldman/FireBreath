
#pragma once
#ifndef BOOST_USE_CPP11_INTERNAL_MEMORY_WRAPPER_HPP
#define BOOST_USE_CPP11_INTERNAL_MEMORY_WRAPPER_HPP

#include <memory>

// according to N3376 [memory] (i.e. 20.6 Memory)
namespace boost {
//using ::std::memory_order;                            // not in Clang 4.1 and GCC 4.6
using ::std::bad_weak_ptr;
using ::std::shared_ptr;
using ::std::make_shared;
using ::std::static_pointer_cast;
using ::std::dynamic_pointer_cast;
using ::std::const_pointer_cast;
using ::std::get_deleter;
using ::std::weak_ptr;
using ::std::owner_less;
using ::std::enable_shared_from_this;
//using ::std::atomic_is_lock_free;                       // not in Clang 4.1 and GCC 4.6
//using ::std::atomic_load;                               // not in Clang 4.1 and GCC 4.6
//using ::std::atomic_load_explicit;                      // not in Clang 4.1 and GCC 4.6
//using ::std::atomic_store;                              // not in Clang 4.1 and GCC 4.6
//using ::std::atomic_store_explicit;                     // not in Clang 4.1 and GCC 4.6
//using ::std::atomic_exchange;                           // not in Clang 4.1 and GCC 4.6
//using ::std::atomic_exchange_explicit;                  // not in Clang 4.1 and GCC 4.6
//using ::std::atomic_compare_exchange_weak;              // not in Clang 4.1 and GCC 4.6
//using ::std::atomic_compare_exchange_strong;            // not in Clang 4.1 and GCC 4.6
//using ::std::atomic_compare_exchange_weak_explicit;     // not in Clang 4.1 and GCC 4.6
//using ::std::atomic_compare_exchange_strong_explicit;   // not in Clang 4.1 and GCC 4.6

template<typename T> inline void swap(shared_ptr<T> & a, shared_ptr<T> & b) {
    a.swap(b);
}

template<typename T> inline void swap(weak_ptr<T> & a, weak_ptr<T> & b) {
    a.swap(b);
}

template<typename T> inline T * get_pointer(shared_ptr<T> const & p)
{
    return p.get();
}
}

template<typename T, typename U> inline bool operator<(boost::weak_ptr<T> const & a, boost::weak_ptr<U> const & b) {
    return a.owner_before(b);
}

#endif // #ifndef BOOST_USE_CPP11_INTERNAL_MEMORY_WRAPPER_HPP
