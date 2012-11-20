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

file(GLOB smart_ptr RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    boost/smart_ptr/[^.]*.hpp
    )
SOURCE_GROUP(smart_ptr FILES ${smart_ptr})

file(GLOB tuple RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    boost/tuple/[^.]*.hpp
    )
SOURCE_GROUP(tuple FILES ${tuple})

file(GLOB internal RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    internal/[^.]*.hpp
    )
SOURCE_GROUP(internal FILES ${internal})

set(SOURCES
    ${common}
    ${smart_ptr}
    ${tuple}
    ${internal}
    )

add_library (boost-use-cpp11 STATIC ${SOURCES})
set_target_properties(boost-use-cpp11 PROPERTIES FOLDER "Libraries")