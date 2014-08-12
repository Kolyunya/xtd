#ifndef _XTD_COUTMT_HPP_
#define _XTD_COUTMT_HPP_

#include <iostream>
#include <ostream>
#include <string>
#include <memory>
#include <mutex>

namespace xstd
{
    class coutmt_singleton
        :
            public std::ostream
    {
        public:
            template <typename Type>
            friend coutmt_singleton& operator<< ( coutmt_singleton& coutmt_singleton_instance , Type object );
            friend coutmt_singleton& operator<< ( coutmt_singleton& coutmt_singleton_instance ,  std::ostream&(*function_ptr)(std::ostream&) );
            friend coutmt_singleton& operator<< ( coutmt_singleton& coutmt_singleton_instance ,  std::ios&(*function_ptr)(std::ios&) );
            friend coutmt_singleton& operator<< ( coutmt_singleton& coutmt_singleton_instance ,  std::ios_base& (*function_ptr)(std::ios_base&) );
            static coutmt_singleton& get_instance ( void );
        private:
            explicit coutmt_singleton ( void ) = default;
            std::mutex coutmt_mutex;
            bool instance_initialized;
    };

    static coutmt_singleton& coutmt = coutmt_singleton::get_instance();
}

//  Include definions of templates
#include "coutmt.tpp"

#endif