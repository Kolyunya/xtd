#ifndef _STD_EVENT_HPP_
#define _STD_EVENT_HPP_

#include <vector>
#include <functional.hpp>

namespace std
{
    template <typename... data_type>
    class event
    {
        public:
            using FreeListener = void(*)(data_type...);
            using FreeListeners = std::vector<FreeListener>;
            using FreeListenersCitr = typename FreeListeners::const_iterator;
            using FreeListenersItr = typename FreeListeners::iterator;

            template <typename Object>
            using FunctorListener = std::functor<Object,data_type...>;
            using AbstractFunctorListener = typename std::abstract_functor<data_type...>;
            using FunctorListeners = std::vector<AbstractFunctorListener*>;
            using FunctorListenersCitr = typename FunctorListeners::const_iterator;
            using FunctorListenersItr = typename FunctorListeners::iterator;

            unsigned int                    getListenersCount ( void ) const
            {
                return
                (
                    this->getFreeListenersCount()
                        +
                    this->getFunctorListenersCount()
                );
            }

            unsigned int                    getFreeListenersCount ( void ) const
            {
                return this->freeListeners.size();
            }

            unsigned int                    getFunctorListenersCount ( void ) const
            {
                return this->functorListeners.size();
            }

            bool                            hasListener ( FreeListener freeListener ) const
            {
                return this->getListenerItr(freeListener) != this->freeListeners.end();
            }

                                            template <typename Object>
            bool                            hasListener ( Object* objectPtr , void(Object::*methodPtr)(data_type...) ) const
            {
                return this->getListenerItr(objectPtr,methodPtr) != this->functorListeners.end();
            }

            void                            addListener ( FreeListener freeListener )
            {
                this->checkHasNoListener(freeListener);
                this->freeListeners.push_back(freeListener);
            }

                                            template <typename Object>
            void                            addListener ( Object* objectPtr , void(Object::*methodPtr)(data_type...) )
            {
                this->checkHasNoListener(objectPtr,methodPtr);
                this->functorListeners.push_back(new FunctorListener<Object>(objectPtr,methodPtr));
            }

            void                            removeListener ( FreeListener freeListener )
            {
                this->checkHasListener(freeListener);
                this->freeListeners.erase(this->getListenerItr(freeListener));
            }

                                            template <typename Object>
            void                            removeListener ( Object* objectPtr , void(Object::*methodPtr)(data_type...) )
            {
                this->checkHasListener(objectPtr,methodPtr);
                this->functorListeners.erase(this->getListenerItr(objectPtr,methodPtr));
            }

            void                            dispatch ( data_type... data ) const
            {
                this->dispatchFreeListeners(data...);
                this->dispatchFunctorListeners(data...);
            }

        protected:

            void                            checkHasListener ( FreeListener freeListener ) const
            {
                if ( this->hasListener(freeListener) == false )
                {
                    throw -1;
                }
            }

                                            template <typename Object>
            void                            checkHasListener ( Object* objectPtr , void(Object::*methodPtr)(data_type...) ) const
            {
                if ( this->hasListener(objectPtr,methodPtr) == false )
                {
                    throw -1;
                }
            }

            void                            checkHasNoListener ( FreeListener freeListener ) const
            {
                if ( this->hasListener(freeListener) == true )
                {
                    throw -1;
                }
            }

                                            template <typename Object>
            void                            checkHasNoListener ( Object* objectPtr , void(Object::*methodPtr)(data_type...) ) const
            {
                if ( this->hasListener(objectPtr,methodPtr) == true )
                {
                    throw -1;
                }
            }

            FreeListenersItr                getListenerItr ( FreeListener freeListener ) const
            {
                FreeListenersItr freeListenersItr = this->freeListeners.begin();
                while ( freeListenersItr != this->freeListeners.end() )
                {
                    if ( *freeListenersItr == freeListener )
                    {
                        break;
                    }
                    freeListenersItr++;
                }
                return freeListenersItr;
            }

                                            template <typename Object>
            FunctorListenersItr             getListenerItr ( Object* objectPtr , void(Object::*methodPtr)(data_type...) ) const
            {
                FunctorListenersItr functorListenersItr = this->functorListeners.begin();
                while ( functorListenersItr != this->functorListeners.end() )
                {
                    FunctorListener<Object>* functorListenerPtr = dynamic_cast<FunctorListener<Object>*>(*functorListenersItr);
                    if
                    (
                        functorListenerPtr != nullptr
                            &&
                        functorListenerPtr->objectPtr == objectPtr
                            &&
                        functorListenerPtr->methodPtr == methodPtr
                    )
                    {
                        break;
                    }
                    functorListenersItr++;
                }
                return functorListenersItr;
            }

            void                            dispatchFreeListeners ( data_type... data ) const
            {
                for ( FreeListener freeListener : this->freeListeners )
                {
                    std::cout << "FREE LISTENER" << std::endl;
                    freeListener(data...);
                }
            }

            void                            dispatchFunctorListeners ( data_type... data ) const
            {
                for ( AbstractFunctorListener* abstractFunctorListenerPtr : this->functorListeners )
                {
                    std::cout << "FUNCTOR LISTENER" << std::endl;
                    (*abstractFunctorListenerPtr)(data...);
                }
            }

            mutable FreeListeners           freeListeners;

            mutable FunctorListeners        functorListeners;

    };
}

#endif  //  _STD_EVENT_HPP_