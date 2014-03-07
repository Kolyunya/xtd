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

#ifndef _XSTD_PARAMETER_PACK_FOR_EACH_HPP_
#define _XSTD_PARAMETER_PACK_FOR_EACH_HPP_

namespace xstd
{

    namespace pp
    {

        template < typename parameter_processor , typename... parameters_types >
        void for_each ( parameters_types... /* parameters */ )
        {

        }

        template < typename parameter_processor , typename first_parameter_type , typename... other_parameters_types >
        void for_each ( first_parameter_type first_parameter , other_parameters_types... other_parameters )
        {
            parameter_processor::process(first_parameter);
            for_each<parameter_processor,other_parameters_types...>(other_parameters...);
        }

    }

}

#endif  //  _XSTD_PARAMETER_PACK_FOR_EACH_HPP_