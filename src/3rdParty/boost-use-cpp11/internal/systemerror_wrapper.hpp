
#pragma once
#ifndef BOOST_USE_CPP11_INTERNAL_SYSTEMERROR_WRAPPER_HPP
#define BOOST_USE_CPP11_INTERNAL_SYSTEMERROR_WRAPPER_HPP

#include <system_error>

// according to N3376 [syserr] (i.e. 19.5 System error support)
namespace boost {
namespace system {
using ::std::error_category;
using ::std::generic_category;
using ::std::system_category;
using ::std::error_code;
using ::std::error_condition;
using ::std::system_error;
namespace errc = ::std::errc;
using ::std::make_error_code;
using ::std::make_error_condition;

template <typename T> struct is_error_code_enum : public ::std::is_error_code_enum<T> {};
template <typename T> struct is_error_condition_enum : public ::std::is_error_condition_enum<T> {};
}
}

#endif // #ifndef BOOST_USE_CPP11_INTERNAL_SYSTEMERROR_WRAPPER_HPP
