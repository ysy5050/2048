#include "commandsink.h"

Commandsink::Commandsink(View *pview)
{
    view = pview;
}

void Commandsink::OnCommandComplete(const std::string& str, bool bOK)
{
    if(str == "move")
    {
        if(!bOK)
        {
            QMessageBox MSG;
            MSG.setWindowTitle(QString("Error!"));
            MSG.exec();
        }
    }
}
