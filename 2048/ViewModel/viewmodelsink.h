#ifndef VIEWMODELSINK_H
#define VIEWMODELSINK_H

#include "./Common/Command.h"

class ViewModel;

class Viewmodelsink: public IPropertyNotification
{
public:
    Viewmodelsink(ViewModel *pVM_);
    virtual void OnPropertyChanged(const std::string& str);
private:
    ViewModel *pVM;
};

#endif // VIEWMODELSINK_H
