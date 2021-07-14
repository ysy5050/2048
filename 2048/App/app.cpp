#include "app.h"

App::App()
{

}

App::~App()
{
}

void App::run()
{
    model = std::make_shared<Model>();
    viewmodel = std::make_shared<ViewModel>();
    view = std::make_shared<View>();
    viewmodel->setModel(model);

    view->setMoveCommand(viewmodel->getMoveCommand());
    view->setLayoutCommand(viewmodel->getLayoutCommand());
    view->setMatrix(viewmodel->getMatrix());
    viewmodel->AddPropertyNotification(view->getPropertySink());
    viewmodel->AddCommandNotification(view->getCommandSink());
    viewmodel->execLayoutCommand();
    view->paint_square();

    view->show();

}
