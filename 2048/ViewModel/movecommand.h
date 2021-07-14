#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "./Common/Command.h"

class ViewModel;

class MoveCommand: public CommandBase
{
public:
    MoveCommand(ViewModel *pVM_);
    virtual void SetParameter(const int& parameter);
    virtual void Exec();
private:
    ViewModel *pVM;
    int direction;
};

#endif // MOVECOMMAND_H
