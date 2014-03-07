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

#ifndef _XSTD_FUNCTOR_HPP_
#define _XSTD_FUNCTOR_HPP_

#include <functional/abstract_functor.hpp>

namespace xstd
{

    template <typename object_type , typename... arguments_type>
    class functor
        :
            public abstract_functor<arguments_type...>
    {

        public:

            inline explicit         functor ( object_type* object_ptr , void(object_type::*method_ptr)(arguments_type...) );

            inline virtual          ~functor ( void ) noexcept override = default;

            inline virtual void     operator() ( arguments_type... arguments ) const override final;

            inline virtual void     invoke ( arguments_type... arguments ) const override final;

            void                    (object_type::*method_ptr)(arguments_type...);

            object_type*            object_ptr;

    };

}

// Include implementation file
//#include "functor.tpp"

#endif  // _XSTD_FUNCTOR_HPP_