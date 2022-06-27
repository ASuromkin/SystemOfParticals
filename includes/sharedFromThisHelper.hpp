#ifndef SYSTEMOFPARTICALS_SHAREDFROMTHISHELPER_HPP
#define SYSTEMOFPARTICALS_SHAREDFROMTHISHELPER_HPP

#include <memory>
class MultipleInheritableEnableSharedFromThis: public std::enable_shared_from_this<MultipleInheritableEnableSharedFromThis>
{
public:
    virtual ~MultipleInheritableEnableSharedFromThis() = default;
};

template <class T>
class InheritableEnableSharedFromThis : virtual public MultipleInheritableEnableSharedFromThis
{
public:
    template <class Down>
    std::shared_ptr<Down> shared_this() {
        return std::dynamic_pointer_cast<Down>(MultipleInheritableEnableSharedFromThis::shared_from_this());
    }
};

#endif //SYSTEMOFPARTICALS_SHAREDFROMTHISHELPER_HPP
