#include "viewmodel.h"

ViewModel::ViewModel()
{
    pViewmodelsink = std::make_shared<Viewmodelsink>(this);
    pMoveCommand = std::make_shared<MoveCommand>(this);
    pLayoutCommand = std::make_shared<LayoutCommand>(this);
}
ViewModel::~ViewModel()
{
}

void ViewModel::setModel(std::shared_ptr<Model> pModel_)
{
    pModel = pModel_;
    pModel->AddPropertyNotification(std::static_pointer_cast<IPropertyNotification>(pViewmodelsink));
}

std::shared_ptr<SquareMatrix> ViewModel::getMatrix()
{
    return pModel->getMatrix();
}

std::shared_ptr<CommandBase> ViewModel::getMoveCommand()
{
    return pMoveCommand;
}

std::shared_ptr<CommandBase> ViewModel::getLayoutCommand()
{
    return pLayoutCommand;
}

void ViewModel::execMoveCommand(int direction)
{
    pModel->DirectionChange(direction);
}

void ViewModel::execLayoutCommand()
{
    pModel->newLayout();
}
