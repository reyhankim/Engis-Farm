template <typename T>
class Counter
{
    private:
        // atribut yang mencatat obyek yang telah diinstansiasi
        static int objects_created;
        static int objects_alive;

    public:
        // CTOR
        Counter();
        // DTOR
        virtual ~Counter();
};

template <typename T> int Counter<T>::objects_created( 0 );
template <typename T> int Counter<T>::objects_alive( 0 );