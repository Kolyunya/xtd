#ifndef _STD_COUTMT_HPP_
#define _STD_COUTMT_HPP_

#include <iostream>
#include <ostream>
#include <string>
#include <memory>
#include <mutex>

namespace std
{
    class coutmt_singleton
        :
            public ostream
    {
        public:
                                                template <typename Type>
            friend inline coutmt_singleton&     operator<< ( coutmt_singleton& coutmt_singleton_instance , Type object );
            friend inline coutmt_singleton&     operator<< ( coutmt_singleton& coutmt_singleton_instance ,  std::ostream&(*function_ptr)(std::ostream&) );
            friend inline coutmt_singleton&     operator<< ( coutmt_singleton& coutmt_singleton_instance ,  ios&(*function_ptr)(ios&) );
            friend inline coutmt_singleton&     operator<< ( coutmt_singleton& coutmt_singleton_instance ,  ios_base& (*function_ptr)(ios_base&) );
            static inline coutmt_singleton&     get_instance ( void );
        private:
            inline explicit                     coutmt_singleton ( void ) = default;
            mutex                               coutmt_mutex;
            bool                                instance_initialized;
    };

    static coutmt_singleton& coutmt = coutmt_singleton::get_instance();
}

#include "coutmt.ipp"

#endif  //  _STD_COUTMT_HPP_