#ifndef _XTD_EVENT_HPP_
#define _XTD_EVENT_HPP_

#include <vector>
#include <thread>
#include <mutex>
#include <xtd/functional/functor.hpp>

namespace xtd
{

    namespace pubsub
    {

        template <typename... data_type>
        class event
        {

            public:

                using free_listener = void(*)(data_type...);

                using free_listeners_collection = std::vector<free_listener>;

                using free_listeners_collection_citr = typename free_listeners_collection::const_iterator;

                using free_listeners_collection_itr = typename free_listeners_collection::iterator;

                template <typename object_type>
                using functor_listener = xtd::functional::functor<object_type,data_type...>;

                using abstract_functor_listener = typename xtd::functional::abstract_functor<data_type...>;

                using functor_listeners_collection = std::vector<abstract_functor_listener*>;

                using functor_listeners_collection_citr = typename functor_listeners_collection::const_iterator;

                using functor_listeners_collection_itr = typename functor_listeners_collection::iterator;

                virtual ~event ( void ) noexcept;

                unsigned int get_listeners_count ( void ) const;

                unsigned int get_free_listeners_count ( void ) const;

                unsigned int get_functor_listeners_count ( void ) const;

                bool has_listener ( free_listener free_listener_instance ) const;

                template <typename object_type>
                bool has_listener ( object_type* object_ptr , void(object_type::*method_ptr)(data_type...) ) const;

                void add_listener ( free_listener free_listener_instance );

                template <typename object_type>
                void add_listener ( object_type* object_ptr , void(object_type::*method_ptr)(data_type...) );

                void remove_listener ( free_listener free_listener_instance );

                template <typename object_type>
                void remove_listener ( object_type* object_ptr , void(object_type::*method_ptr)(data_type...) );

                void dispatch ( data_type... data ) const;

            protected:

                void check_has_listener ( free_listener free_listener_instance ) const;

                template <typename object_type>
                void check_has_listener ( object_type* object_ptr , void(object_type::*method_ptr)(data_type...) ) const;

                void check_has_no_listener ( free_listener free_listener_instance ) const;

                template <typename object_type>
                void check_has_no_listener ( object_type* object_ptr , void(object_type::*method_ptr)(data_type...) ) const;

                free_listeners_collection_itr get_listener_itr ( free_listener free_listener_instance ) const;

                template <typename object_type>
                functor_listeners_collection_itr get_listener_itr ( object_type* object_ptr , void(object_type::*method_ptr)(data_type...) ) const;

                void dispatch_free_listeners ( data_type... data ) const;

                void dispatch_functor_listeners ( data_type... data ) const;

                mutable free_listeners_collection free_listeners;

                mutable functor_listeners_collection functor_listeners;

                mutable std::recursive_mutex master_mutex;

        };

    }

}

//  Include definions of templates
#include "event.tpp"

#endif