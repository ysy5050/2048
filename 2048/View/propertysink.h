#ifndef PROPERTYSINK_H
#define PROPERTYSINK_H

#include "./Common/Command.h"
#include "./View/view.h"

class View;

class Propertysink: public IPropertyNotification
{
public:
    Propertysink(View *pview);
    virtual void OnPropertyChanged(const std::string& str);
private:
    View *view;
};

#endif // PROPERTYSINK_H
