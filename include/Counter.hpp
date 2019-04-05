#ifndef ENGISFARM_COUNTER_HPP
#define ENGISFARM_COUNTER_HPP

template <typename T>
class Counter
{
    public:
        // CTOR
        Counter();
        // DTOR
        virtual ~Counter();

    static int objects_alive;
    // atribut yang mencatat obyek yang telah diinstansiasi
    static int objects_created;
};

#endif //ENGISFARM_COUNTER_HPP