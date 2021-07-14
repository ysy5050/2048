#include "movecommand.h"
#include "./ViewModel/viewmodel.h"

MoveCommand::MoveCommand(ViewModel *pVM_)
{
    pVM = pVM_;
}

void MoveCommand::SetParameter(const int& parameter)
{
    direction = parameter;
}

void MoveCommand::Exec()
{
    pVM->execMoveCommand(direction);
}
