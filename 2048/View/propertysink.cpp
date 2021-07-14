#include "propertysink.h"
#include "View/view.h"

Propertysink::Propertysink(View *pview)
{
    view = pview;
}

void Propertysink::OnPropertyChanged(const std::string& str)
{
    if(str == "SquareMatrix")
    {
        view->update();
    }
}
