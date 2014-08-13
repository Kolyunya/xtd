#ifndef _XTD_SCOUT_HPP_
#define _XTD_SCOUT_HPP_

#include <iostream>
#include <ostream>
#include <string>
#include <memory>
#include <mutex>

/**
 *  @brief A root namespace of the library.
 */
namespace xtd
{

    /**
     *  @brief A namespace containing tools for input and output operations.
     */
    namespace io
    {

        /**
         *  @brief A class which lets you to write to the standard output stream from multiple threads at the time.
         *  @details The class is a synchronized wrapper of the `std::cout` and uses `std::mutex` as a syncronization primitive.
         */
        class scout_singleton
        {

            public:

                /**
                 *  @brief A function template which allows putting arbitrary objects to the output stream.
                 */
                template <typename type>
                friend scout_singleton& operator<< ( scout_singleton& scout_singleton_instance , type object );

                /**
                 *  @brief A function template which allows putting function pointers to the output stream.
                 */
                friend scout_singleton& operator<< ( scout_singleton& scout_singleton_instance , std::ostream&(*function_ptr)(std::ostream&) );

                /**
                 *  @brief A function template which allows putting function pointers to the output stream.
                 */
                friend scout_singleton& operator<< ( scout_singleton& scout_singleton_instance , std::ios&(*function_ptr)(std::ios&) );

                /**
                 *  @brief A function template which allows putting function pointers to the output stream.
                 */
                friend scout_singleton& operator<< ( scout_singleton& scout_singleton_instance , std::ios_base& (*function_ptr)(std::ios_base&) );

                /**
                 *  @brief Returns a singleton instance.
                 */
                static scout_singleton& get_instance ( void );

            private:

                /**
                 *  @brief A private default constructor.
                 *  @note A singleton object should not be constructed in user-space.
                 */
                explicit scout_singleton ( void ) = default;

                /**
                 *  @brief A deleted copy-constructor.
                 *  @note A singleton object should not be copied.
                 */
                explicit scout_singleton ( const scout_singleton& ) = delete;

                /**
                 *  @brief A deleted move-constructor.
                 *  @note A singleton object should not be moved.
                 */
                explicit scout_singleton ( const scout_singleton&& ) = delete;

                /**
                 *  @brief A deleted assignment-operator.
                 *  @note A singleton object should not be assigned to.
                 */
                scout_singleton& operator= ( const scout_singleton& ) = delete;

                /**
                 *  @brief A mutex which is used to synchronize the access to the standard output stream
                 */
                std::mutex scout_mutex;

                /**
                 *  @brief A flag which is used to aknowlege if the singleton instance is already instantinated.
                 */
                bool instance_initialized;

        };

        /**
         *  @brief An instance of the synchronized `cout`.
         */
        static scout_singleton& scout = scout_singleton::get_instance();

    }

}

//  Include definions of templates
#include "scout.tpp"

#endif