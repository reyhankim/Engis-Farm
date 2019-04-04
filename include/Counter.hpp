template <typename T>
class Counter
{


    public:
        // CTOR
        Counter(){
            objects_created++;
            objects_alive++;
        }
        // DTOR
        virtual ~Counter() {
            --objects_alive;
        }

    static int objects_alive;
    // atribut yang mencatat obyek yang telah diinstansiasi
    static int objects_created;
};

template <typename T> int Counter<T>::objects_created( 0 );
template <typename T> int Counter<T>::objects_alive( 0 );