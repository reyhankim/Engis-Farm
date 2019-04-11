#ifndef ENGISFARM_COUNTER_HPP
#define ENGISFARM_COUNTER_HPP

template <typename T>
class Counter
{
    public:
        Counter()
        {
            objects_created++;
            objects_alive++;
        }

        virtual ~Counter()
        {
            --objects_alive;
        }

        static int objects_created;
        static int objects_alive;
};

template <typename T> int Counter<T>::objects_created( 0 );
template <typename T> int Counter<T>::objects_alive( 0 );

#endif //ENGISFARM_COUNTER_HPP