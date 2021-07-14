#ifndef LAYOUTCOMMAND_H
#define LAYOUTCOMMAND_H

#include "./Common/Command.h"

class ViewModel;

class LayoutCommand: public CommandBase
{
public:
    LayoutCommand(ViewModel *pVM_);
    virtual void SetParameter(const int& parameter);
    virtual void Exec();
private:
    ViewModel *pVM;
};

#endif // LAYOUTCOMMAND_H
