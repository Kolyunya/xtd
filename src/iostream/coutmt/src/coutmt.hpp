#ifndef _STD_COUTMT_HPP_
#define _STD_COUTMT_HPP_

#include <iostream>
#include <mutex>

namespace std
{
    class coutmt_singleton
    {
        public:
            static coutmt_singleton&    get_instance ( void );
            friend coutmt_singleton&    operator<< ( coutmt_singleton& ostream , const char* string );
        private:
            inline explicit             coutmt_singleton ( void ) = default;
            virtual                     ~coutmt_singleton ( void ) noexcept;
            std::mutex                  mutex;
            static coutmt_singleton*    instance_ptr;
    };

    coutmt_singleton& coutmt = coutmt_singleton::get_instance();

}

#include "coutmt.ipp"

#endif  //  _STD_COUTMT_HPP_