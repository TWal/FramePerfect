#pragma once

#include <memory>

template<typename T>
class copy_ptr : public std::unique_ptr<T>{
public:
    using std::unique_ptr<T>::unique_ptr;
    copy_ptr(const copy_ptr& oth) : std::unique_ptr<T>(oth->copy()){}
    copy_ptr& operator=(const copy_ptr& oth){
        this->std::unique_ptr<T>::operator=(std::unique_ptr<T>(oth->copy()));
        return *this;
    }
};



