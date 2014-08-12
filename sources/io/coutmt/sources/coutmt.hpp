#ifndef _XTD_COUTMT_HPP_
#define _XTD_COUTMT_HPP_

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
     *  @brief A namespace containing tools for processing input and out put operations.
     */
    namespace io
    {

        /**
         *  @brief A class which lets you to write to the standard output stream from multiple threads at the time.
         *  @details The class uses `std::mutex` as a syncronization primitive.
         */
        class coutmt_singleton
        {

            public:

                /**
                 *  @brief A function template which allows putting arbitrary objects to the output stream.
                 */
                template <typename type>
                friend coutmt_singleton& operator<< ( coutmt_singleton& coutmt_singleton_instance , type object );

                /**
                 *  @brief A function template which allows putting function pointers to the output stream.
                 */
                friend coutmt_singleton& operator<< ( coutmt_singleton& coutmt_singleton_instance , std::ostream&(*function_ptr)(std::ostream&) );

                /**
                 *  @brief A function template which allows putting function pointers to the output stream.
                 */
                friend coutmt_singleton& operator<< ( coutmt_singleton& coutmt_singleton_instance , std::ios&(*function_ptr)(std::ios&) );

                /**
                 *  @brief A function template which allows putting function pointers to the output stream.
                 */
                friend coutmt_singleton& operator<< ( coutmt_singleton& coutmt_singleton_instance , std::ios_base& (*function_ptr)(std::ios_base&) );

                /**
                 *  @brief Returns a singleton instance.
                 */
                static coutmt_singleton& get_instance ( void );

            private:

                /**
                 *  @brief A private default constructor.
                 *  @note A singleton object should not be constructed in user-space.
                 */
                explicit coutmt_singleton ( void ) = default;

                /**
                 *  @brief A deleted copy-constructor.
                 *  @note A singleton object should not be copied.
                 */
                explicit coutmt_singleton ( const coutmt_singleton& ) = delete;

                /**
                 *  @brief A deleted move-constructor.
                 *  @note A singleton object should not be moved.
                 */
                explicit coutmt_singleton ( const coutmt_singleton&& ) = delete;

                /**
                 *  @brief A deleted assignment-operator.
                 *  @note A singleton object should not be assigned to.
                 */
                coutmt_singleton& operator= ( const coutmt_singleton& ) = delete;

                /**
                 *  @brief A mutex which is used to synchronize the access to the standard output stream
                 */
                std::mutex coutmt_mutex;

                /**
                 *  @brief A flag which is used to aknowlege if the singleton instance is already instantinated.
                 */
                bool instance_initialized;

        };

        /**
         *  @brief An instance of the multithreaded standard output stream.
         */
        static coutmt_singleton& coutmt = coutmt_singleton::get_instance();

    }

}

//  Include definions of templates
#include "coutmt.tpp"

#endif