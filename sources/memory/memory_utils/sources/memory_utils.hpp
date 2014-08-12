#ifndef _XTD_MEMORY_UTILS_HPP_
#define _XTD_MEMORY_UTILS_HPP_

#include <stdexcept>

/**
 *  @brief A root namespace of the library.
 */
namespace xtd
{

    /**
     *  @brief A namespace containing tools for memory operations.
     */
    namespace memory
    {

        /**
         *  @brief Validates a pointer of arbitrary type.
         *  @param [in] pointer A pointer of arbitrary type.
         *  @exception_safety Strong exception safety.
         *  @throws std::runtime_error Thrown if a `pointer` is a `nullptr`.
         *  @details Validates a pointer of arbitrary type to point to an object of the type.
         */
        template <typename type>
        void validate_pointer ( type* pointer );

    }

}

//  Include definions of templates
#include "memory_utils.tpp"

#endif