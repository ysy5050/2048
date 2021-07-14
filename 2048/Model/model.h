#ifndef MODEL_H
#define MODEL_H

#include <QMessageBox>
#include <memory>
#include <QtGlobal>
#include <QTime>
#include "./Common/Command.h"
#include "./Common/square.h"

class Model: public Proxy_PropertyNotification<Model>
{
public:
    Model();
    ~Model();
    std::shared_ptr<SquareMatrix> getMatrix(); //return data
    void newLayout();  //assign page according to mode
    void DirectionChange(int dir);
private:
    bool Process(int direction);
    bool CreateNumber();
    void Judge(bool flag) ;
    std::shared_ptr<SquareMatrix> sp_Matrix;
};

#endif // MODEL_H
