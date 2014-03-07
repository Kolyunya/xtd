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

namespace std
{

            template <typename object_type , typename parameter_type>
            functor<object_type,parameter_type>::functor ( object_type* object_ptr , void(object_type::*method_ptr)(parameter_type*) )
    {
        if
        (
            object_ptr == nullptr
                ||
            method_ptr == nullptr
        )
        {
            throw -1;
        }
        this->object_ptr = object_ptr;
        this->method_ptr = method_ptr;
    }

            template <typename object_type , typename parameter_type>
    void    functor<object_type,parameter_type>::operator() ( void* parameter_void_ptr ) const
    {
        this->invoke(arguments...);
    }

            template <typename object_type , typename parameter_type>
    void    functor<object_type,parameter_type>::invoke ( void* parameter_void_ptr ) const
    {
        ((this->object_ptr)->*(this->method_ptr))(arguments...);
    }

}