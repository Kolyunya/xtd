//  xstd - extension of the C++ standard library
//  Copyright (C) 2013 Oleynikov Nikolay
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//  Author email: OleynikovNY@mail.ru

#ifndef _XSTD_RAII_THREAD_BASE_HPP_
#define _XSTD_RAII_THREAD_BASE_HPP_

#include <functional>
#include <thread>
#include <mutex>

namespace xstd
{
    class raii_thread_base
    {
        public:
            inline explicit             raii_thread_base ( std::function<void()> client_routine );
            inline virtual              ~raii_thread_base ( void ) noexcept;
            inline bool                 get_is_initialized ( void ) const;
        protected:
            inline void                 initialize_routine ( void );
            inline void                 deinitialize_routine ( void );
            inline void                 check_is_initialized ( void ) const;
            inline void                 check_is_not_initialized ( void ) const;
            inline static void          routine ( raii_thread_base* raii_thread_base_ptr );
            bool                        terminate_flag;
            std::function<void()>       client_routine;
            std::thread                 thread;
            std::recursive_mutex        mutex;
        private:
            inline explicit             raii_thread_base ( const raii_thread_base& rhs ) = delete;
            inline raii_thread_base&    operator= ( const raii_thread_base& rhs ) = delete;
    };
}

#include "raii_thread_base.ipp"

#endif  //  _XSTD_RAII_THREAD_BASE_HPP_