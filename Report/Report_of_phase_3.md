# **南京大学本科生实验报告**

课程名称：高级程序设计            任课教师：程家俊/左志强          助教：丁鹏

| 学院  | 计算机科学与技术系 | 专业（方向）  | 计算机科学与技术   |
| ----- | ------------------ | ------------- | ------------------ |
| 学号  | 191220013          | 姓名          | 陈奕诺             |
| Email | 1053650507@qq.com  | 开始/完成日期 | 2021.5.11/2021.6.8 |

## **1.** **实验名称**

高程课设第三阶段：植物大战僵尸（GUI）

## 2. 主要内容/要求：

在第二次课设基础上，将项目拓展为GUI版本，并使其有一定的可玩性。

## 3.主要设计思路

针对植物大战僵尸的游戏特点，考虑到后续的内容扩充的需要，目前主要有两种设计思路。一种是将所有的攻击操作作为一个攻击类来实现，另一种则是通过地块攻击法来实现，结合游戏本身的设计特点，为了简化后续编程操作，我最终选择了地块攻击法来实现。

基于这一设计思路，我们可以发现，地块是所有操作的核心，他起到植物、僵尸、子弹、商店等对象间的信息传输功能（比如：僵尸攻击信息先从僵尸传给地块，再由地块传递给相应的植物），从而将所有的对象联系起来，组成一个关联性较强的体系。

以上是游戏逻辑的设计思路，下面是图形化界面的设计思路：

由于我们第二阶段的植物大战僵尸是基于控制台设置的，与本次实验的不同在于所有的信息输入输出是基于键盘和控制台答应来实现的。基于已有的框架，为了充分运用第二阶段已有的设计，我们不妨使用`QPainter`类，通过重载`void paintEvent(QPaintEvent *event)`来实现图片的打印，只是将文字的打印变成了图片的`drawPixmap`。

## 4.主要类/模块设计

##### 1.这是第一、二阶段的模板和类设计，我们基本保持了这些功能：

1、Game: 游戏顶层模块，提供用户接口，统筹所有类操作，控制程序的运行；

2、Map: 地图类，负责庭院的基础布局设计，统筹所有的地块，建立地块间的联系，保障攻击/移动;

3、Grid: 地块类，信息传递和储存操作由它来完成，是本此游戏实现的核心；

4、Zombie: 普通僵尸类， 设置僵尸的基本属性，存储每只僵尸的状态, 提供移动/攻击等功能函数；

5、Plant: 植物基础类，提供植物共有属性，为后续不同植物设计提供良好的继承基础类；

6、Peashooter: 豌豆射手类，设置豌豆射手的属性，存储每个豌豆射手的状态, 提供攻击等功能函数；

7、Bullet: 子弹类，设置子弹的基本属性，提供移动/攻击等功能函数；

8、Store: 商店类， 打印商品信息，存储阳光信息，提供购买、种植等功能函数；

9、Good: 商品类,   设置商品基本属性，通过商品状态存储；

##### 2.第三阶段我们加入了和修改了以下类：

1.MainWindow与Game类似，它是游戏顶层模块，提供用户接口，统筹所有类操作，控制程序的运行；

2.picture类：对设计到的图片进行统一的load，供后续调用所需。

3.Cart类：除草车类，设置除草车的基本属性，提供移动/攻击等功能函数。

## 5.类之间的基本关系：

第三阶段没有改变类之间的基本关系，保留了第二阶段已有的游戏逻辑。其中Game类相当于本次设计中的`MainWindow`类。

简单的对Game类的关键成员函数和作用进行图解：

![](E:\QQ下载文件\picture\g3.png)

不难发现我们所有的操作，实际功能的调用都是由Game来是实现的，Game包含了整体的游戏逻辑。

下面我们来简单的用关系图描绘一下类间的一些主要的关系：

![](E:\QQ下载文件\picture\g4.png)

由上图可知，Game和Map是Store、Plant、Bullet、Zombie实现信息交互的桥梁，他们四类之间不能直接交互，而要通过Game和Map实现间接的信息同步，从而实现整体的同步；

对于植物和僵尸的拓展，采用了继承的方式，以Plant和Zombie为基类进行拓展。

## 6.功能实现

为了实现游戏逻辑，首先我们使用了一个定时器`QTimer myTimer`来实现定时刷新，将刷新频率定在差不多60帧每秒，使得游戏中不会出现卡顿的情况。具体实现如下方代码所示：

```C++
void MainWindow::playgame(){
    myTimer.start();
    //监听定时器
    connect(&myTimer,&QTimer::timeout,[=](){
        if(start){
            //更新游戏中元素的坐标
            bool x=updatePosition();
            if(!x) {
                game_over=true;
                music->stop();
                myTimer.stop();
                update();
             }
            //重新绘制图片
             update();
        }
    });
}
```

同时由于僵尸需要平滑移动，故需要额外考虑其在GRID中的具体位置，这一点，我们额外添加了一个函数，用于计算每一帧其在格子内的位置：

```C++
int get_inloction(){return counter*82/speed;}
```

对子弹类等也进行了相应的操作。

同时由于僵尸不同的状态所对应的图片也不同，所以我们额外增加了status状态量，用来标记僵尸状态，供后续加载图片所需。同时增加了一个虚函数func2用来更新僵尸的状态，以增加代码的易读性。

```C++
virtual void func2(Map*& map, MainWindow* game);//额外的一些功能
void Zombie::func2(Map*& map, MainWindow* game){
        if(snow) status=1;
        else status=0;
}
```

对于植物类等也采取了类似的操作，这里不再赘述。

下面是本次实验的图形化方式的简述：

我们主要是通过图形覆盖的方式来实现，具体内容可以看`void paintEvent(QPaintEvent *event)`中的实现：

```C++
void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    //初始界面打印
    if(!start) {
        painter.drawPixmap(0, 0, 1050, 700,p.main_menu);
        return;
    }
    //地图背景打印
    painter.drawPixmap(0, 0, 1402, 700,p.background);
    painter.drawPixmap(300, 0, 610, 90,p.store);
    painter.drawPixmap(900,0,p.ShovelBank);
    //阳光数量打印
    QString s = QString::number(store->sunshine);
    painter.drawText(328,80,s);
	//商品打印（卡片和冷却状态）
    store->store_paint_information(&painter,&p);
	//地图信息打印（包括阳光、植物、僵尸的打印）
    map->map_paint_information(&painter,&p);
	//购买状态，植物随鼠标移动
    if(buying)
    {
        painter.drawPixmap(mouse_x-40,mouse_y-40,temp_plant);
    }
    //游戏结束界面打印
    if(game_over)
        painter.drawPixmap(300,100,p.game_over);
	//暂停和继续按钮打印
    if(pause)
        painter.drawPixmap(100,20,150,45,p.continue_button);
    else
        painter.drawPixmap(100,20,150,45,p.pause_button);
	//铲除状态，铁锹随鼠标移动
    if(root_out)
        painter.drawPixmap(mouse_x-40,mouse_y-40,p.shovel);
    else
        painter.drawPixmap(900,0,p.shovel);
	//除草车打印
    for(int i=0;i<5;i++)
        if(carts[i]!=NULL)
            carts[i]->paintCart(&painter,&p);
}
```

我们简单来看看地图信息的打印：

```C++
void  Map::map_paint_information(QPainter* painter, picture* p){
    for(int i=0;i<COL;i++){
        for(int j=0;j<ROW;j++){
            grid[i][j].paint_informtion(painter,p);
        }
    }
}
```

map类调用每一个格子来打印：

```C++
void Grid::paint_informtion(QPainter* painter , picture* p){
    for(int i=0;i<zombies.size();i++){
        switch(zombies[i]->gettype()){
        case 0:
            switch(zombies[i]->getstatus()){
            case 0:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, p->walking_zombie); break;
            case 1:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, p->waling_zombie_frozen); break;
            }
            break;
        case 1:
            switch(zombies[i]->getstatus()){
            case 0:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, p->pole_vaulting_zombie); break;
            case 1:painter->drawPixmap(290 + 82 * x - zombies[i]->get_inloction(), 10 + 116 * y, 150,225, p->pole_vaulting_zombie_jumping); break;
            case 2:painter->drawPixmap(290 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, p->pole_vaulting_zombie_jumped); break;
            case 3:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, p->pole_vaulting_zombie_frozen); break;
            case 4:painter->drawPixmap(290 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, p->pole_vaulting_zombie_jumped_frozen); break;
            }
            break;
        case 2:
            switch(zombies[i]->getstatus()){
            case 0:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y,75,120, p-> conehead_zombie); break;
            case 1:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y,p-> walking_zombie); break;
            case 2:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y,75,120,p-> conehead_zombie_frozen); break;
            case 3:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, p-> waling_zombie_frozen); break;
            }
            break;
        case 3:
            switch(zombies[i]->getstatus()){
            case 0:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, p->newspaper_zombie); break;
            case 1:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, p->newspaper_zombie_empty); break;
            case 2:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, p->newspaper_zombie_frozen);break;
            case 3:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, p->newspaper_zombie_empty_frozen);break;
            }
            break;
        case 4:
            switch(zombies[i]->getstatus()){
            case 0:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, 75,120,p->jack_in_the_box_zombie); break;
            case 1:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 80 + 116 * y, 75,120,p->jack_in_the_box_zombie_frozen); break;
            }
            break;
        case 5:
            switch(zombies[i]->getstatus()){
            case 0:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 50 + 116 * y, p->capture_zombie); break;
            case 1:painter->drawPixmap(300 + 82 * x - zombies[i]->get_inloction(), 50 + 116 * y, p->capture_zombie_frozen); break;
            }
            break;
        }
    }

    if(plant!=NULL){
        switch(plant->gettype()){
        case 0:painter->drawPixmap(290 + 82 * x - 41,110 + 116 * y, p->shooter); break;
        case 1:painter->drawPixmap(290 + 82 * x - 41,110 + 116 * y, p->sun_flower); break;
        case 2:painter->drawPixmap(290 + 82 * x - 41,110 + 116 * y, p->repeater); break;
        case 3:painter->drawPixmap(290 + 82 * x - 41,110 + 116 * y, p->ice_shooter); break;
        case 4:switch(plant->getstatus()){
            case 0:painter->drawPixmap(290 + 82 * x - 41,110 + 116 * y, p->nut); break;
            case 1:painter->drawPixmap(290 + 82 * x - 41,110 + 116 * y, p->nut2);break;
            case 2:painter->drawPixmap(290 + 82 * x - 41,110 + 116 * y, p->nut3);break;
            }
            break;
        case 5:switch(plant->getstatus()){
            case 0:painter->drawPixmap(290 + 82 * x - 41,90 + 116 * y,80,120, p->tall_nut); break;
            case 1:painter->drawPixmap(290 + 82 * x - 41,90 + 116 * y,80,120, p->tallnut2);break;
            case 2:painter->drawPixmap(290 + 82 * x - 41,90 + 116 * y,80,120, p->tallnut3);break;
            }
            break;
        case 6:switch(plant->getstatus()){
            case 0:painter->drawPixmap(290 + 82 * x - 55,110 + 116 * y, 120,100,p->squash); break;
            case 1:painter->drawPixmap(290 + 82 * x - 55,110 + 116 * y, 120,100,p->squash); break;
            case 2:painter->drawPixmap(290 + 82 * x + 82 - 55,110 + 116 * y, 120,100,p->squash); break;
            }
            break;
        case 7:switch(plant->getstatus()){
            case 0:painter->drawPixmap(290 + 82 * x - 41,110 + 116 * y, p->cherry_bomb); break;
            case 1:painter->drawPixmap(290 + 82 * x - 41,110 + 116 * y, p->boom); break;
            }
            break;
        case 8:painter->drawPixmap(290 + 82 * x - 41,110 + 116 * y, 70,70,p->garlic); break;
        }
    }
    if(pumpkin!=NULL){
        painter->drawPixmap(290 + 82 * x - 41,150 + 116 * y,70,35, p->pumpkin);
    }
    for(int i=0;i<bullets.size();i++){
        if(!bullets[i]->ifsnow()){
            painter->drawPixmap(300 - 41 + 82 * x + bullets[i]->get_inloction(),
                                110 + 116 * y, p->pea);
        }
        else{
            painter->drawPixmap(300 - 41 + 82 * x + bullets[i]->get_inloction(),
                                110 + 116 * y, p->snow_pea);
        }
    }

    if(sunshine_droped>0)
        painter->drawPixmap(300 - 50 + 82 * x , 130 + 116 * y, 60, 60, p->sunshine_p);
}

```

Grid类则根据格子中的植物和僵尸种类、状态来选择不同的`QPixmap`，计算每一个对象的位置来进行draw, 同时阳光的打印则通过判断阳光的有无来实现;

接下来是关于鼠标事件的监听，我们可以发现鼠标事件有系统调用函数，我们不妨和之前打印的方式一样，进行函数重载来实现，具体实现如下：

```C++
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //开始界面操作
    if(!start){
        if(event->x()>550 && event->x()<845 && event->y()>85 && event->y()<245)
            start=true;
        return;
    }
    //购买操作
    if(event->x()>400 && event->x()<900 && event->y()>12 && event->y()<80)
    {
        if(!root_out && !game_over && !pause){
            if(!buying)
            {
                int col = (event->x() - 400) / 50;
                if(!(store->ifnotcold(col))||(!store->ifpriceok(col)))
                    return;
                switch(col)
                {
                case 0: temp_plant.load(SHOOTER); break;
                case 1: temp_plant.load(SUNFLOWER); break;
                case 2: temp_plant.load(REPEATER); break;
                case 3: temp_plant.load(ICESHOOTER); break;
                case 4: temp_plant.load(NUT); break;
                case 5: temp_plant.load(TALLNUT); break;
                case 6: temp_plant.load(SQUASH); break;
                case 7: temp_plant.load(CHERRY); break;
                case 8: temp_plant.load(GARLIC); break;
                case 9: temp_plant.load(PUMPKIN); break;
                }
                new_plant_type = col;
            }
            buying = !buying;
        }
    }
    //地块操作
    if(event->x()>260 && event->x()<998 && event->y()>90 && event->y()<670){
        if(!game_over && !pause){
            if(buying){ //种植植物
                int px= (event->x()-260)/82;
                int py= (event->y()-90)/116;
                addPlant(px,py,new_plant_type);
                buying=false;
            }
            else{ //收集阳光
                int px= (event->x()-260)/82;
                int py= (event->y()-90)/116;
                get_sunshine(px,py);
            }
            if(root_out){ //铲除植物
                int px= (event->x()-260)/82;
                int py= (event->y()-90)/116;
                root_out_plant(px,py);
                root_out = false;
            }
        }
    }
    //暂停、继续按钮
    if(event->x()>100 && event->x()<250 && event->y()> 20 && event->y()<65){
        if(!game_over){
            if(pause) {
                pause=!pause;
                music->play();
                update();
                myTimer.start();
            }
            else {
                pause=!pause;
                music->pause();
                update();
                myTimer.stop();

            }
        }
    }

    //铲除模式
    if(event->x()>900 && event->x()<970 && event->y()> 0 && event->y()<75){
        if(!buying && !game_over && !pause){
            root_out=!root_out;
        }
    }

}
```

同时我们重载了`void mouseMoveEvent(QMouseEvent * event)`函数来监听鼠标的位置，便于拖拽打印。

```C++
void MainWindow::mouseMoveEvent(QMouseEvent * event)
{
    mouse_x = event->x();
    mouse_y = event->y();
}
```

同时为了实时监听拖拽事件，增加如下设置：

```C++
 QMainWindow::setMouseTracking(true);
 QMainWindow::centralWidget()->setMouseTracking(true);
```

于是到目前为止，我们已经完成了基本的游戏逻辑，包括：

1、僵尸逻辑

2、植物逻辑

3、商店逻辑

4、阳光生成/收集

5、铲除植物

6、开始界面

7、失败界面

8、暂停/继续

接下来，我们来看一下：

9、背景音乐播放

10、除草车逻辑

背景音乐播放：我在网上找到了相应的循环播放方式，并与暂停/继续模式进行了结合。

```C++
playlist = new QMediaPlaylist();
playlist->addMedia(QUrl("qrc:/sound/Grasswalk.mp3"));
playlist->setPlaybackMode(QMediaPlaylist::Loop);

music = new QMediaPlayer();
music->setPlaylist(playlist);
music->play()
```

除草车逻辑：

```c++
class Cart{
private:
    bool carting;
    int dx;//打印位置
    int y;
public:
    void init_location(int ty){ y=ty; dx=0; carting=false;};
    void func0(MainWindow *game, Map* map);
    void paintCart(QPainter* painter, picture* p);
};
```

具体实现：

```C++
void Cart::func0(MainWindow *game, Map* map){
    if(!carting){
        if(map->map_judge_if_cart(y)) //通过地图类来判断是否要开动
            carting=true;
    }
    if(carting){//开动
        dx++;//前进
        int temp = dx / 82;//获取坐标
        map->map_boomplant(temp,y,game);//除去格子里所有植物
        map->map_killallZombie(temp,y,game);//除去格子里所有僵尸
    }
    if(dx>=930){//跑出地图
                game->killcart(y);//删除除草机
    }
}
```

## 7.实现的功能

1、僵尸逻辑

2、植物逻辑

3、商店逻辑

4、阳光生成/收集

5、铲除植物

6、开始界面

7、失败界面

8、暂停/继续

9、背景音乐播放

10、除草车逻辑

## 8.一些截图展示

![](E:\QQ下载文件\picture\g3-1.png)

![](E:\QQ下载文件\picture\g3-2.png)

![](E:\QQ下载文件\picture\g3-3.png)

![](E:\QQ下载文件\picture\g3-4.png)

![](E:\QQ下载文件\picture\g3-5.png)

![](E:\QQ下载文件\picture\g3-6.png)

![](E:\QQ下载文件\picture\g3-7.png)

![](E:\QQ下载文件\picture\g3-8.png)

![](E:\QQ下载文件\picture\g3-9.png)

![](E:\QQ下载文件\picture\g3-10.png)

## 9.收获

本学期通过连续三个阶段的连续设计任务，充分展现了底层架构设计对于后续设计的重要性，也有力的训练了我们面向对象的debug能力，实现了一个比较完整的C++程序设计。

本阶段的收获主要是对QT的设计有了进一步的了解，自主学习了相关库函数的用法，也锻炼了我们查找相关资料的能力。