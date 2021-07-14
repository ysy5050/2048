#include "viewmodelsink.h"
#include "./ViewModel/viewmodel.h"

Viewmodelsink::Viewmodelsink(ViewModel *pVM_)
{
    pVM = pVM_;
}

void Viewmodelsink::OnPropertyChanged(const std::string& str)
{
    pVM->Fire_OnPropertyChanged(str);
}
