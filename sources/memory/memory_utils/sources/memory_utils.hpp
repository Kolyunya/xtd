#ifndef _XTD_MEMORY_UTILS_HPP_
#define _XTD_MEMORY_UTILS_HPP_

#include <stdexcept>

namespace xtd
{

    namespace mem
    {

        template <typename type>
        void validate_pointer ( type* pointer );

    }

}

//  Include definions of templates
#include "memory_utils.tpp"

#endif