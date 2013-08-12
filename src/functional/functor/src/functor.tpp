namespace std
{

			template <typename object_type>
			functor<object_type>::functor ( object_type* object , void(object_type::*method)(void*) )
				:
					object ( object ),
					method ( method )
	{

	}

			template <typename object_type>
			functor<object_type>::~functor ( void )
	{
	
	}

			template <typename object_type>
	void	functor<object_type>::operator() ( void* data ) const
	{

		( this->object ->* this->method ) ( data );

	}
	
			template <typename object_type>
	void	functor<object_type>::invoke ( void* data ) const
	{
	
		( *this ) ( data );
	
	}
 
}