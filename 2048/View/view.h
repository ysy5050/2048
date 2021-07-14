#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QPainter>
#include <QKeyEvent>
#include <QLabel>
#include <QPushButton>
#include <memory>
#include <QSharedPointer>
#include "./Common/Command.h"
#include "./Common/square.h"
#include "./View/commandsink.h"
#include "./View/propertysink.h"

namespace Ui {
class View;
}

class Propertysink;
class Commandsink;

class View : public QMainWindow
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = nullptr);
    ~View();
    void keyPressEvent(QKeyEvent *e);
    void setMatrix(std::shared_ptr<SquareMatrix> Matrix);
    void setMoveCommand(std::shared_ptr<CommandBase> command);
    void setLayoutCommand(std::shared_ptr<CommandBase> command);
    std::shared_ptr<IPropertyNotification> getPropertySink();
    std::shared_ptr<ICommandNotification> getCommandSink();

    void paintEvent(QPaintEvent* event);
    void Animation();
    void paint_square();
private slots:
    void restart_btn_press();

private:
    Ui::View *ui;
    std::shared_ptr<SquareMatrix> pMatrix;
    std::shared_ptr<CommandBase> pMoveCommand;
    std::shared_ptr<CommandBase> pLayoutCommand;
    std::shared_ptr<Commandsink> pCommandsink;
    std::shared_ptr<Propertysink> pPropertysink;
    QPushButton *restart_btn;
    QLabel *square[16];
};

#endif // VIEW_H
