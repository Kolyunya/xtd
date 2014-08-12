namespace xtd
{

    namespace chrono
    {

        template <typename clock>
        bool timer<clock>:: get_is_active ( void ) const
        {
            return this->is_active;
        }

    }

}