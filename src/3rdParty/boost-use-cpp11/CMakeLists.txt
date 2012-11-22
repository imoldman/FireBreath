cmake_minimum_required (VERSION 2.6)
set (CMAKE_BACKWARDS_COMPATIBILITY 2.6)

project(boost-use-cpp11)

include_directories (
    ${FB_BOOST_SOURCE_DIR}  # TODO(lixianliang): tmp, for include boost/ref.hpp
)

file(GLOB common RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    boost/[^.]*.hpp
    CMakeLists.txt
    dummy.cpp
    gen.py
    )
SOURCE_GROUP(common FILES ${common})

file(GLOB asio RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    boost/asio/[^.]*.hpp
    )
SOURCE_GROUP(asio FILES ${asio})


file(GLOB chrono RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    boost/chrono/[^.]*.hpp
    )
SOURCE_GROUP(chrono FILES ${chrono})

file(GLOB smart_ptr RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    boost/smart_ptr/[^.]*.hpp
    )
SOURCE_GROUP(smart_ptr FILES ${smart_ptr})

file(GLOB thread RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    boost/thread/[^.]*.hpp
    )
SOURCE_GROUP(thread FILES ${thread})

file(GLOB tuple RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    boost/tuple/[^.]*.hpp
    )
SOURCE_GROUP(tuple FILES ${tuple})

file(GLOB system RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    boost/system/[^.]*.hpp
    )
SOURCE_GROUP(system FILES ${system})

file(GLOB internal RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    internal/[^.]*.hpp
    )
SOURCE_GROUP(internal FILES ${internal})

set(SOURCES
    ${common}
    ${asio}
    ${chrono}
    ${smart_ptr}
    ${thread}
    ${tuple}
    ${system}
    ${internal}
    )

add_library (boost-use-cpp11 STATIC ${SOURCES})
set_target_properties(boost-use-cpp11 PROPERTIES FOLDER "Libraries")