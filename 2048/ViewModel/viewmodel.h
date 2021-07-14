#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "./Common/Command.h"
#include "./Model/model.h"
#include "./ViewModel/viewmodelsink.h"
#include "./ViewModel/layoutcommand.h"
#include "./ViewModel/movecommand.h"

class ViewModel: public Proxy_PropertyNotification<ViewModel>, public Proxy_CommandNotification<ViewModel>
{
public:
    ViewModel();
    ~ViewModel();
    void setModel(std::shared_ptr<Model> pModel_);
    std::shared_ptr<SquareMatrix> getMatrix();
    std::shared_ptr<CommandBase> getMoveCommand();
    std::shared_ptr<CommandBase> getLayoutCommand();
    void execMoveCommand(int direction);
    void execLayoutCommand();
private:
    std::shared_ptr<Model> pModel;
    std::shared_ptr<MoveCommand> pMoveCommand;
    std::shared_ptr<Viewmodelsink> pViewmodelsink;
    std::shared_ptr<LayoutCommand> pLayoutCommand;
};

#endif // VIEWMODEL_H
