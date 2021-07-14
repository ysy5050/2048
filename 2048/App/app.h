#ifndef APP_H
#define APP_H

#include "./Common/Command.h"
#include "./Model/model.h"
#include "./ViewModel/viewmodel.h"
#include "./View/view.h"

class App
{
public:
    App();
    ~App();
    void run();
private:
    std::shared_ptr<Model> model;
    std::shared_ptr<ViewModel> viewmodel;
    std::shared_ptr<View> view;
};

#endif // APP_H
