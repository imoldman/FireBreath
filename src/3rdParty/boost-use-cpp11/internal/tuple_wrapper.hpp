
#pragma once
#ifndef BOOST_USE_CPP11_INTERNAL_TUPLE_WRAPPER_HPP
#define BOOST_USE_CPP11_INTERNAL_TUPLE_WRAPPER_HPP

#include <tuple>
#include <type_traits>
#include <boost/ref.hpp>

// according to N3376 [tuple] (i.e. 20.4 Tuples)
namespace boost {
namespace tuples {
using std::tuple;
using std::ignore;
using std::make_tuple;
using std::forward_as_tuple;
using std::tie;
using std::tuple_cat;
using std::tuple_size;
using std::tuple_element;
using std::get;
using std::swap;

struct null_type {};

template <int N, typename T> struct element : public std::tuple_element<N, T> {};

template <typename T> struct access_traits {
    typedef const T& const_type;
    typedef T& non_const_type;
    typedef const typename std::remove_cv<T>::type& parameter_type;
};

}
using namespace tuples;
}

#endif // #ifndef BOOST_USE_CPP11_INTERNAL_TUPLE_WRAPPER_HPP
