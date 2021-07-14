#ifndef COMMANDSINK_H
#define COMMANDSINK_H

#include <qmessagebox.h>
#include "./Common/Command.h"
#include "./View/view.h"

class View;

class Commandsink: public ICommandNotification
{
public:
    Commandsink(View *pview);
    virtual void OnCommandComplete(const std::string& str, bool bOK);
private:
    View *view;
};

#endif // COMMANDSINK_H
