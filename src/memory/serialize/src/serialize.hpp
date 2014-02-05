#ifndef _STD_SERIALIZE_HPP_
#define _STD_SERIALIZE_HPP_

#include <cstring>
#include <stdexcept>

namespace std
{

                            template < typename type >
    static std::string      serialize ( const type& object_ptr );

                            template < typename type >
    static type             deserialize ( const std::string& data );

}

#include "serialize.tpp"

#endif  //  _STD_SERIALIZE_HPP_
