#include "model.h"

Model::Model()
{
    sp_Matrix = std::make_shared<SquareMatrix>();
}

Model::~Model()
{

}

std::shared_ptr<SquareMatrix> Model::getMatrix()
{
    return sp_Matrix;
}

void Model::newLayout()
{
    sp_Matrix->ResetMoode1();
}

void Model::DirectionChange(int dir)
{
    bool flag = Model::Process(dir);
    Model::Judge(flag);
    Fire_OnPropertyChanged("Square");
}

bool Model::CreateNumber()
{
    int x = -1;
    int y = -1;
    int times = 0;
    int maxTimes = 4 * 4;
    //三分之二的概率生成2，三分之一的概率生成4
    int whitch = rand() % 3;
    do
    {
        x = rand() % 4;
        y = rand() % 4;
        ++times;
    } while (sp_Matrix->getChildNumber(x,y)!= 0 && times <= maxTimes);

    //说明格子已经满了
    if(times >= maxTimes)
    {
        return false;
    }
    else
    {
        int num=0;
        if(whitch == 0)
        {
            num = 4;
        }
        else if(whitch)
        {
            num = 2;
        }
        sp_Matrix->setChildNumber(x,y,num);
    }

    return true;
}

bool Model::Process(int direction)
{
    bool mapFlag=false;//记录是否引起棋盘改变
    switch (direction)
    {
    case 2:
        //最上面一行不动

        for(int row = 1; row < 4; ++row)
        {
            for(int tmpr = row; tmpr >= 1; --tmpr)
            {
                for(int col = 0; col < 4; ++col)
                {
                    //上一个格子为空

                    if(sp_Matrix->getChildNumber(tmpr-1,col) == 0&&sp_Matrix->getChildNumber(tmpr,col) != 0)
                    {
                        sp_Matrix->setChildNumber(tmpr-1,col,sp_Matrix->getChildNumber(tmpr,col));
                        sp_Matrix->setChildNumber(tmpr,col, 0);
                        mapFlag=true;
                    }
                    else if(sp_Matrix->getChildNumber(tmpr-1,col) != 0){
                        //合并

                        if(sp_Matrix->getChildNumber(tmpr-1,col)==sp_Matrix->getChildNumber(tmpr,col))
                        {
                            int tmp=sp_Matrix->getChildNumber(tmpr-1,col);
                            tmp*=2;
                            sp_Matrix->changeScore(tmp);
                            sp_Matrix->setChildNumber(tmpr - 1,col, tmp);
                            sp_Matrix->setChildNumber(tmpr,col, 0);
                             mapFlag=true;
                        }

                    }
                };
            };
        };
        break;
    case 1:

        //最下面一行不动

        for(int row = 4 - 2; row >= 0; --row)
        {
            for(int tmpr = row; tmpr < 4 - 1; ++tmpr)
            {
                for(int col = 0; col < 4; ++col)
                {
                    //上一个格子为空

                    if(sp_Matrix->getChildNumber(tmpr + 1,col) == 0&&sp_Matrix->getChildNumber(tmpr,col) != 0)
                    {
                        sp_Matrix->setChildNumber(tmpr+1,col,sp_Matrix->getChildNumber(tmpr,col));
                        sp_Matrix->setChildNumber(tmpr,col, 0);
                         mapFlag=true;
                    }else if(sp_Matrix->getChildNumber(tmpr+1,col) != 0){
                        //合并

                        if(sp_Matrix->getChildNumber(tmpr+1,col)==sp_Matrix->getChildNumber(tmpr,col))
                        {
                            int tmp=sp_Matrix->getChildNumber(tmpr+1,col);
                            tmp*=2;
                            sp_Matrix->changeScore(tmp);
                            sp_Matrix->setChildNumber(tmpr + 1,col, tmp);
                            sp_Matrix->setChildNumber(tmpr,col, 0);
                             mapFlag=true;
                        }

                    }
                }
            }
        }
        break;
    case 3:

        //最左边一列不动

        for(int  col = 1; col < 4; ++col)
        {
            for(int tmpc = col; tmpc >= 1; --tmpc)
            {
                for(int row = 0; row < 4; ++row)
                {
                    //上一个格子为空

                    if(sp_Matrix->getChildNumber( row,tmpc-1) == 0&&sp_Matrix->getChildNumber(row,tmpc) != 0)
                    {
                        sp_Matrix->setChildNumber( row,tmpc - 1,sp_Matrix->getChildNumber(row,tmpc));
                        sp_Matrix->setChildNumber( row,tmpc ,0);
                         mapFlag=true;
                    }
                    else if(sp_Matrix->getChildNumber(row,tmpc-1) != 0)
                    {
                        //合并

                        if(sp_Matrix->getChildNumber( row,tmpc-1) == sp_Matrix->getChildNumber( row,tmpc))
                        {
                            int tmp=sp_Matrix->getChildNumber( row,tmpc-1);
                            tmp*=2;
                            sp_Matrix->changeScore(tmp);
                            sp_Matrix->setChildNumber( row,tmpc - 1,tmp);
                            sp_Matrix->setChildNumber( row,tmpc ,0);
                             mapFlag=true;
                        }

                    }
                }
            }
        }
        break;
    case 4:

        //最右边一列不动

        for(int  col = 4-2; col >= 0; --col)
        {
            for(int tmpc = col; tmpc <=4-2; ++tmpc)
            {
                for(int row = 0; row < 4; ++row)
                {
                    //上一个格子为空

                    if(sp_Matrix->getChildNumber( row,tmpc+1) == 0&&sp_Matrix->getChildNumber(row,tmpc) != 0)
                    {
                        sp_Matrix->setChildNumber( row,tmpc + 1,sp_Matrix->getChildNumber(row,tmpc));
                        sp_Matrix->setChildNumber( row,tmpc ,0);
                         mapFlag=true;
                    }
                    else if(sp_Matrix->getChildNumber(row,tmpc+1) != 0)
                    {
                        //合并

                        if(sp_Matrix->getChildNumber( row,tmpc+1) == sp_Matrix->getChildNumber( row,tmpc))
                        {
                            int tmp=sp_Matrix->getChildNumber( row,tmpc+1);
                            tmp*=2;
                             sp_Matrix->changeScore(tmp);
                            sp_Matrix->setChildNumber( row,tmpc + 1,tmp);
                            sp_Matrix->setChildNumber( row,tmpc ,0);
                             mapFlag=true;
                        }

                    }
                }
            }
        }
        break;
    }
    return mapFlag;
}



//判断游戏状态

void Model::Judge(bool flag)
{
    //赢得游戏

    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            if(sp_Matrix->getChildNumber(i,j) == 2048)
            {
                 sp_Matrix->setWin(1);
                // return GAME_WIN;
                break;
            }
        }
    }

    //横向检查

    int loseflag=1;
    for(int i = 0 ; i < 4; ++i)
    {
        for(int j = 0; j < 4 - 1; ++j)
        {
            if(!sp_Matrix->getChildNumber(i,j) || (sp_Matrix->getChildNumber(i,j) == sp_Matrix->getChildNumber(i,j+1)))
            {
               loseflag=0;
                break;
            }
        }
    }
    //纵向检查
    for(int j = 0; j< 4; ++j)
    {
        for(int i = 0; i < 4 -1; ++i)
        {
            if(!sp_Matrix->getChildNumber(i,j) || (sp_Matrix->getChildNumber(i,j) == sp_Matrix->getChildNumber(i+1,j)))
            {
                loseflag=0;
                 // return GAME_CONTINUE;
                break;
            }
        }
    }

    //不符合上述两种状况，游戏结束
    if(loseflag==1){sp_Matrix->setLose(1);}
    else if(flag==true) {Model::CreateNumber();}
  //  return GAME_OVER;

}
