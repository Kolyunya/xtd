#ifndef _STD_MEMORY_UTIL_HPP_
#define _STD_MEMORY_UTIL_HPP_

#include <stdexcept>    // std::runtime_error

namespace std
{

                            template <typename Type>
    inline static void      validate_pointer ( Type* pointer );

}

// Include implementation file
#include "memory_util.tpp"

#endif  //  _STD_MEMORY_UTIL_HPP_
