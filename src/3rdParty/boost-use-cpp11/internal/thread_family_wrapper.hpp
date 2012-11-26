
#pragma once
#ifndef BOOST_USE_CPP11_INTERNAL_THREAD_FAMILY_WRAPPER_HPP
#define BOOST_USE_CPP11_INTERNAL_THREAD_FAMILY_WRAPPER_HPP

#include <condition_variable>
#include <future>
#include <mutex>
#include <thread>

// according to N3376 [thread.condition] (i.e. 30.5 Condition variables)
// according to N3376 [thread.mutex] (i.e. 30.4 Mutual exclusion)
// according to N3376 [thread.threads] (i.e. 30.3 Threads)
// according to N3376 [futures] (i.e. 30.6 Futures)
namespace boost {
using ::std::condition_variable;
using ::std::condition_variable_any;
//using ::std::mutex;
//using ::std::recursive_mutex;
//using ::std::timed_mutex;
//using ::std::recursive_timed_mutex;
using ::std::lock_guard;
using ::std::unique_lock;
//using ::std::swap;                       invalid in GCC and Clang
using ::std::try_lock;
using ::std::lock;
using ::std::once_flag;
using ::std::call_once;
using ::std::thread;
namespace this_thread = ::std::this_thread;

#ifdef _MSC_VER
    namespace future_errc = ::std::future_errc;
    namespace launch = ::std::launch;
    namespace future_status = ::std::future_status;
#else
    using ::std::future_errc;
    using ::std::launch;
    using ::std::future_status;
#endif

using ::std::make_error_code;
using ::std::make_error_condition;
using ::std::future_error;
using ::std::promise;
using ::std::future;
using ::std::shared_future;
using ::std::async;
using ::std::packaged_task;

class mutex : public ::std::mutex {
public:
    typedef unique_lock< ::std::mutex> scoped_lock;
};
class recursive_mutex : public ::std::recursive_mutex {
public:
    typedef unique_lock< ::std::recursive_mutex> scoped_lock;
};
class timed_mutex : public ::std::timed_mutex {
public:
    typedef unique_lock< ::std::timed_mutex> scoped_lock;
};
class recursive_timed_mutex : public ::std::recursive_timed_mutex {
public:
    typedef unique_lock< ::std::recursive_timed_mutex> scoped_lock;
};

typedef mutex shared_mutex;
#define upgrade_lock unique_lock 
#define shared_lock unique_lock
}

#endif // #ifndef BOOST_USE_CPP11_INTERNAL_THREAD_FAMILY_WRAPPER_HPP
