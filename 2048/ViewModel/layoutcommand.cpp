#include "layoutcommand.h"
#include "./ViewModel/viewmodel.h"

LayoutCommand::LayoutCommand(ViewModel *pVM_)
{
    pVM = pVM_;
}

void LayoutCommand::SetParameter(const int& parameter)
{
}

void LayoutCommand::Exec()
{
    pVM->execLayoutCommand();
}
