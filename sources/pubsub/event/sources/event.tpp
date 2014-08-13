namespace xtd
{

    namespace pubsub
    {

        template <typename... data_type>
        event<data_type...>::~event ( void ) noexcept
        {
            try
            {
                for ( abstract_functor_listener* abstract_functor_listener_ptr : this->functor_listeners )
                {
                    try
                    {
                        delete abstract_functor_listener_ptr;
                    }
                    catch ( ... )
                    {

                    }
                }
            }
            catch ( ... )
            {

            }
        }

        template <typename... data_type>
        unsigned int event<data_type...>::get_listeners_count ( void ) const
        {
            std::lock_guard<std::recursive_mutex> master_lock_guard(this->master_mutex);
            return
            (
                this->get_free_listeners_count()
                    +
                this->get_functor_listeners_count()
            );
        }

        template <typename... data_type>
        unsigned int event<data_type...>::get_free_listeners_count ( void ) const
        {
            std::lock_guard<std::recursive_mutex> master_lock_guard(this->master_mutex);
            return this->free_listeners.size();
        }

        template <typename... data_type>
        unsigned int event<data_type...>::get_functor_listeners_count ( void ) const
        {
            std::lock_guard<std::recursive_mutex> master_lock_guard(this->master_mutex);
            return this->functor_listeners.size();
        }

        template <typename... data_type>
        bool event<data_type...>::has_listener ( free_listener free_listener_instance ) const
        {
            std::lock_guard<std::recursive_mutex> master_lock_guard(this->master_mutex);
            return this->get_listener_itr(free_listener_instance) != this->free_listeners.end();
        }

        template <typename... data_type>
        template <typename object_type>
        bool event<data_type...>::has_listener ( object_type* object_ptr , void(object_type::*method_ptr)(data_type...) ) const
        {
            std::lock_guard<std::recursive_mutex> master_lock_guard(this->master_mutex);
            return this->get_listener_itr(object_ptr,method_ptr) != this->functor_listeners.end();
        }

        template <typename... data_type>
        void event<data_type...>::add_listener ( free_listener free_listener_instance )
        {
            std::lock_guard<std::recursive_mutex> master_lock_guard(this->master_mutex);
            this->check_has_no_listener(free_listener_instance);
            this->free_listeners.push_back(free_listener_instance);
        }

        template <typename... data_type>
        template <typename object_type>
        void event<data_type...>::add_listener ( object_type* object_ptr , void(object_type::*method_ptr)(data_type...) )
        {
            std::lock_guard<std::recursive_mutex> master_lock_guard(this->master_mutex);
            this->check_has_no_listener(object_ptr,method_ptr);
            this->functor_listeners.push_back(new functor_listener<object_type>(object_ptr,method_ptr));
        }

        template <typename... data_type>
        void event<data_type...>::remove_listener ( free_listener free_listener_instance )
        {
            std::lock_guard<std::recursive_mutex> master_lock_guard(this->master_mutex);
            this->check_has_listener(free_listener_instance);
            this->free_listeners.erase(this->get_listener_itr(free_listener_instance));
        }

        template <typename... data_type>
        template <typename object_type>
        void event<data_type...>::remove_listener ( object_type* object_ptr , void(object_type::*method_ptr)(data_type...) )
        {
            std::lock_guard<std::recursive_mutex> master_lock_guard(this->master_mutex);
            this->check_has_listener(object_ptr,method_ptr);
            this->functor_listeners.erase(this->get_listener_itr(object_ptr,method_ptr));
        }

        template <typename... data_type>
        void event<data_type...>::dispatch ( data_type... data ) const
        {
            std::lock_guard<std::recursive_mutex> master_lock_guard(this->master_mutex);
            this->dispatch_free_listeners(data...);
            this->dispatch_functor_listeners(data...);
        }

        template <typename... data_type>
        void event<data_type...>::check_has_listener ( free_listener free_listener_instance ) const
        {
            if ( this->has_listener(free_listener_instance) == false )
            {
                throw -1;
            }
        }

        template <typename... data_type>
        template <typename object_type>
        void event<data_type...>::check_has_listener ( object_type* object_ptr , void(object_type::*method_ptr)(data_type...) ) const
        {
            if ( this->has_listener(object_ptr,method_ptr) == false )
            {
                throw -1;
            }
        }

        template <typename... data_type>
        void event<data_type...>::check_has_no_listener ( free_listener free_listener_instance ) const
        {
            if ( this->has_listener(free_listener_instance) == true )
            {
                throw -1;
            }
        }

        template <typename... data_type>
        template <typename object_type>
        void event<data_type...>::check_has_no_listener ( object_type* object_ptr , void(object_type::*method_ptr)(data_type...) ) const
        {
            if ( this->has_listener(object_ptr,method_ptr) == true )
            {
                throw -1;
            }
        }

        template <typename... data_type>
        typename event<data_type...>::free_listeners_collection_itr event<data_type...>::get_listener_itr ( free_listener free_listener_instance ) const
        {
            free_listeners_collection_itr free_listeners_itr = this->free_listeners.begin();
            while ( free_listeners_itr != this->free_listeners.end() )
            {
                if ( *free_listeners_itr == free_listener_instance )
                {
                    break;
                }
                free_listeners_itr++;
            }
            return free_listeners_itr;
        }

        template <typename... data_type>
        template <typename object_type>
        typename event<data_type...>::functor_listeners_collection_itr event<data_type...>::get_listener_itr ( object_type* object_ptr , void(object_type::*method_ptr)(data_type...) ) const
        {
            functor_listeners_collection_itr functor_listeners_itr = this->functor_listeners.begin();
            while ( functor_listeners_itr != this->functor_listeners.end() )
            {
                functor_listener<object_type>* functor_listener_ptr = dynamic_cast<functor_listener<object_type>*>(*functor_listeners_itr);
                if
                (
                    functor_listener_ptr != nullptr
                        &&
                    functor_listener_ptr->object_ptr == object_ptr
                        &&
                    functor_listener_ptr->method_ptr == method_ptr
                )
                {
                    break;
                }
                functor_listeners_itr++;
            }
            return functor_listeners_itr;
        }

        template <typename... data_type>
        void event<data_type...>::dispatch_free_listeners ( data_type... data ) const
        {
            free_listeners_collection freeListeners_copy = this->free_listeners;
            for ( free_listener free_listener_instance : freeListeners_copy )
            {
                free_listener_instance(data...);
            }
        }

        template <typename... data_type>
        void event<data_type...>::dispatch_functor_listeners ( data_type... data ) const
        {
            functor_listeners_collection functorListeners_copy = this->functor_listeners;
            for ( abstract_functor_listener* abstractFunctorListenerPtr : functorListeners_copy )
            {
                (*abstractFunctorListenerPtr)(data...);
            }
        }

    }

}