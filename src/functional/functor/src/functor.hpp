#ifndef _FUNCTOR_HPP_
#define _FUNCTOR_HPP_

namespace std
{

	class abstract_functor
	{
	
		public:
		
			virtual			~abstract_functor ( void ) = default;
			
			virtual void	operator() ( void* data ) const = 0;
			
			virtual void	invoke ( void* data ) const = 0;
			
	};

	template <typename object_type>
	class functor
		:
			public abstract_functor
	{

		public:
			
							functor ( object_type* object , void(object_type::*method)(void*) );
							
			virtual			~functor ( void ) noexcept override = default;
							
			virtual void	operator() ( void* data ) const override final;

			virtual void	invoke ( void* data ) const override final;

			object_type*	object;

			void			(object_type::*method)(void*);

	};

}

#include "functor.tpp"

#endif	// _FUNCTOR_HPP_