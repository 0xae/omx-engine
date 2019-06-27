#ifndef WRAPPER_H
#define WRAPPER_H

template<class T>
class Wrapper {
public:
    Wrapper() {
        DataPtr=0;
    }

    Wrapper(const T& inner) {
        DataPtr=inner.Clone();
    }

    Wrapper(const Wrapper<T>& original) {
        if (original.DataPtr != 0) {
            DataPtr=original.DataPtr.Clone();

        } else {
            DataPtr=0;            
        }
    }

    Wrapper& operator(const Wrapper<T>& original) {
        if (this != &original) {
            if (original.DataPtr != 0) {
                DataPtr=original.DataPtr.Clone();

            } else {
                DataPtr=0;
            }

        } else {
            DataPtr=0;            
        }
    }

    ~Wrapper() {
        if (DataPtr!=0) {            
        }
    }
};

#endif
