#ifndef _STD_COUTMT_HPP_
#define _STD_COUTMT_HPP_

#include <iostream>
#include <ostream>
#include <string>
#include <mutex>

namespace std
{
    class coutmt_singleton
        :
            public ostream
    {
        public:
                                        template <typename Type>
            friend coutmt_singleton&    operator<< ( coutmt_singleton& coutmt_singleton_instance , Type object );
            friend coutmt_singleton&    operator<< ( coutmt_singleton& coutmt_singleton_instance ,  std::ostream& (*func)(std::ostream&) );
            static coutmt_singleton&    get_instance ( void );
        private:
            inline explicit             coutmt_singleton ( void ) = default;
            inline virtual              ~coutmt_singleton ( void ) noexcept;
            mutex                       coutmt_mutex;
            static coutmt_singleton*    instance_ptr;
    };

    coutmt_singleton& coutmt = coutmt_singleton::get_instance();

}

#include "coutmt.ipp"

#endif  //  _STD_COUTMT_HPP_