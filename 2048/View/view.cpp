#include "view.h"
#include "ui_view.h"

View::View(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);
    this->setWindowTitle(QString("2048"));
    this->setFocusPolicy(Qt::StrongFocus);

    restart_btn = new QPushButton("RESTART",this);
    restart_btn->setGeometry(550,350,200,100);

    int i, j;
    for(i=0;i<4;i++)
       for(j=0;j<4;j++)
       {
            square[4*i+j]=new QLabel(this);
            square[4*i+j]->raise();
        }

    connect(restart_btn,SIGNAL(clicked(bool)),this,SLOT(restart_btn_press()));

    pPropertysink = std::make_shared<Propertysink>(Propertysink(this));
    pCommandsink = std::make_shared<Commandsink>(Commandsink(this));
}

View::~View(){
    delete ui;
}

void View::keyPressEvent(QKeyEvent *e){
    if(e->key()==Qt::Key_S||e->key()==Qt::Key_Down){
        pMoveCommand->SetParameter(1);
        pMoveCommand->Exec();
        paint_square();
    }
    if(e->key()==Qt::Key_W||e->key()==Qt::Key::Key_Up){
        pMoveCommand->SetParameter(2);
        pMoveCommand->Exec();
        paint_square();
    }
    if(e->key()==Qt::Key_A||e->key()==Qt::Key::Key_Left){
        pMoveCommand->SetParameter(3);
        pMoveCommand->Exec();
        paint_square();
    }
    if(e->key()==Qt::Key_D||e->key()==Qt::Key::Key_Right){
        pMoveCommand->SetParameter(4);
        pMoveCommand->Exec();
        paint_square();
    }
}

void View::setMatrix(std::shared_ptr<SquareMatrix> Matrix){
    this->pMatrix = Matrix;
}

void View::setMoveCommand(std::shared_ptr<CommandBase> command){
    this->pMoveCommand = command;
}

void View::setLayoutCommand(std::shared_ptr<CommandBase> command){
    this->pLayoutCommand = command;
}

std::shared_ptr<IPropertyNotification> View::getPropertySink(){
    return std::static_pointer_cast<IPropertyNotification>(pPropertysink);
}

std::shared_ptr<ICommandNotification> View::getCommandSink(){
    return std::static_pointer_cast<ICommandNotification>(pCommandsink);
}

void View::paintEvent(QPaintEvent* event){
    Q_UNUSED(event);
    int i,j;
    QPainter painter(this);
    QBrush brush(Qt::black);
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);
    painter.drawRect(100,120,370,370);
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        {
            painter.setPen(Qt::NoPen);
            brush.setColor(Qt::white);
            painter.setBrush(brush);
            painter.drawRoundedRect((110+(90*j)),(130+(90*i)),80,80,4,4);
         }
}

void View::paint_square(){
    int i, j;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        {
            if(this->pMatrix->getChildNumber(i,j) == 0)//如果此处没有块则该处square不显示
                square[4*i+j]->hide();
            else{
                square[4*i+j]->setGeometry((110+(90*j)),(130+(90*i)),80,80);
                square[4*i+j]->setText(QString::number(std::abs(this->pMatrix->getChildNumber(i,j))));
                square[4*i+j]->setAlignment(Qt::AlignCenter);
                square[4*i+j]->show();
            }
        }
    if(pMatrix->LoseSignal()==1)
    {
        QMessageBox Messagebox;
        Messagebox.setText("Lose!");
        Messagebox.exec();
    }
    if(pMatrix->WinSignal()==1)
    {
        QMessageBox Messagebox;
        Messagebox.setText("Win!");
        Messagebox.exec();
    }
}

void View::restart_btn_press()
{
    pLayoutCommand->Exec();
    paint_square();
}

