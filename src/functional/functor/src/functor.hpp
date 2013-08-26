#ifndef _FUNCTOR_HPP_
#define _FUNCTOR_HPP_

namespace std
{

	class abstract_functor
	{
	
		public:
		
			virtual			~abstract_functor ( void ) = default;
			
			virtual void	operator() ( void* parameter_ptr ) const = 0;

			virtual void	invoke ( void* parameter_ptr ) const = 0;
			
	};

	template <typename object_type , typename parameter_type>
	class functor
		:
			public abstract_functor
	{

		public:
			
							functor ( object_type* object , void(object_type::*method)(parameter_type*) );
							
			virtual			~functor ( void ) noexcept override = default;
							
			virtual void	operator() ( void* parameter_ptr ) const override final;

			virtual void	invoke ( void* parameter_ptr ) const override final;

			object_type*	object;

			void			(object_type::*method)(parameter_type*);

	};

}

#include "functor.tpp"

#endif	// _FUNCTOR_HPP_