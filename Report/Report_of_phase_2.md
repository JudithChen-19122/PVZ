# **南京大学本科生实验报告**

课程名称：高级程序设计            任课教师：程家俊/左志强          助教：丁鹏

| 学院  | 计算机科学与技术系 | 专业（方向）  | 计算机科学与技术    |
| ----- | ------------------ | ------------- | ------------------- |
| 学号  | 191220013          | 姓名          | 陈奕诺              |
| Email | 1053650507@qq.com  | 开始/完成日期 | 2021.4.13/2021.5.11 |

## **1.** **实验名称**

高程课设第二阶段：基于控制台的植物大战僵尸

## 2. 主要内容/要求：

在已经实现的控制台植物大战僵尸的基础上进行相应的拓展，主要包括以下几个方面：

植物和僵尸等的设计尽可能贴合真实的游戏环境，参考了百度百科的相关内容

##### 1.植物设计扩展

攻击型：双发射手、寒冰射手

防御型：坚果墙、高坚果

炸弹型：窝瓜、樱桃炸弹

效果型：大蒜、南瓜头

##### 2.僵尸设计扩展

路障僵尸、读报僵尸、撑杆僵尸、小丑僵尸、投石僵尸

##### 3.商店设计扩展

①商店中植物的购买需要有冷却时间 

②玩家可用键盘控制在商店内进行上下左右的选择

##### 4.界面设计扩展

①显示植物或者僵尸的剩余生命值 

②每个地块中可以有多个僵尸

结果展示（部分）：

![](E:\QQ下载文件\picture\g2-1.png)

![](E:\QQ下载文件\picture\g2-2.png)

![](E:\QQ下载文件\picture\g2-3.png)

![](E:\QQ下载文件\picture\g2-4.png)

## 3.主要设计思路

针对植物大战僵尸的游戏特点，考虑到后续的内容扩充的需要，目前主要有两种设计思路。一种是将所有的攻击操作作为一个攻击类来实现，另一种则是通过地块攻击法来实现，结合游戏本身的设计特点，为了简化后续编程操作，我最终选择了地块攻击法来实现。

基于这一设计思路，我们可以发现，地块是所有操作的核心，他起到植物、僵尸、子弹、商店等对象间的信息传输功能（比如：僵尸攻击信息先从僵尸传给地块，再由地块传递给相应的植物），从而将所有的对象联系起来，组成一个关联性较强的体系。

## 4.主要类/模块设计

##### 1.这是第一阶段的模板和类设计，我们基本保持了这些功能：

1、Game: 游戏顶层模块，提供用户接口，统筹所有类操作，控制程序的运行；

2、Map: 地图类，负责庭院的基础布局设计，统筹所有的地块，建立地块间的联系，保障攻击/移动;

3、Grid: 地块类，信息传递和储存操作由它来完成，是本此游戏实现的核心；

4、Zombie: 普通僵尸类， 设置僵尸的基本属性，存储每只僵尸的状态, 提供移动/攻击等功能函数；

5、Plant: 植物基础类，提供植物共有属性，为后续不同植物设计提供良好的继承基础类；

6、Peashooter: 豌豆射手类，设置豌豆射手的属性，存储每个豌豆射手的状态, 提供攻击等功能函数；

7、Bullet: 子弹类，设置子弹的基本属性，提供移动/攻击等功能函数；

8、Store: 商店类， 打印商品信息，存储阳光信息，提供购买、种植等功能函数；

9、Good: 商品类,   设置商品基本属性，通过商品状态存储；

##### 2.在第二阶段，额外增加了以下类：

1.Pole_Vaulting_Zombie：撑杆僵尸类，设置基本属性，存储每只僵尸的状态, 提供移动/攻击/跳跃等功能函数；

2.Conehead_Zombie : 路障僵尸类，设置基本属性，存储每只僵尸的状态, 提供移动/攻击等功能函数；

3.Newspaper_Zombie： 报纸僵尸类，设置基本属性，存储每只僵尸的状态, 提供移动/攻击/暴走等功能函数；

4.Jack_in_the_box_Zombie: 小丑僵尸类，设置基本属性，存储每只僵尸的状态, 提供移动/攻击/爆炸等功能函数；

5.Catapult_Zombie : 投石僵尸类，设置基本属性，存储每只僵尸的状态, 提供移动/碾压/投石等功能函数；

6.Sunflower：向日葵类，设置向日葵的属性，存储每个向日葵的状态, 提供阳光生产等功能函数；

7.Repeater: 双发射手类，设置双发射手的属性，存储每个双发射手的状态, 提供攻击等功能函数；

8.SnowPea: 寒冰射手类，设置寒冰射手的属性，存储每个寒冰射手的状态, 提供攻击等功能函数；

9.Wallnut: 坚果墙类，设置坚果墙的属性，存储每个坚果墙的状态；

10.Tallnut: 高坚果类，设置高坚果的属性，存储每个高坚果的状态；

11.Squash: 倭瓜类，设置倭瓜的属性，存储每个倭瓜的状态, 提供攻击等功能函数；

12.Cherry_Bomb: 樱桃炸弹类，设置樱桃炸弹的属性，存储每个樱桃炸弹的状态, 提供攻击等功能函数；

13.Garlic: 大蒜类，设置大蒜的属性，存储每个大蒜的状态；

14.Pumpkin: 南瓜头类，设置南瓜头的属性，存储每个南瓜头的状态；

## 5.类之间的基本关系：

第二阶段没有改变类之间的基本关系，但是将原有的Game和map原本作为其他模块的友元，考虑到对于数据的封装和保护，去掉了所有的友元关系，而添加了恰当的public函数，供其他类调用所需。

简单的对Game类的关键成员函数和作用进行图解：

![](E:\QQ下载文件\picture\g3.png)

不难发现我们所有的操作，实际功能的调用都是由Game来是实现的，Game包含了整体的游戏逻辑。

下面我们来简单的用关系图描绘一下类间的一些主要的关系：

![](E:\QQ下载文件\picture\g4.png)

由上图可知，Game和Map是Store、Plant、Bullet、Zombie实现信息交互的桥梁，他们四类之间不能直接交互，而要通过Game和Map实现间接的信息同步，从而实现整体的同步；

对于植物和僵尸的拓展，采用了继承的方式，以Plant和Zombie为基类进行拓展：

![](E:\QQ下载文件\picture\g11.png)

![](E:\QQ下载文件\picture\g12.png)

我们可以首先看一下Plant基类：

```c++
class Plant {
protected:
	//种植位置
	int x;
	int y;
	string name;
	int HP;
	int maxHP;
	int ATK;
	int speed; 
	int counter;
	bool jump;//是否可跳过
	bool pushaway;//是否驱赶到相邻行
	void init(const string& str, int health, int tspeed, int tATK);
public:
	void plantloc(int tx, int ty);//种植位置
	int getHP() { return HP; }//返回生命值
	const string& getName() const { return name; } //返回名字
	virtual void func1(Game* game, Map* map, Store* store) { ; };
	bool jumpable() { return jump; }
	bool ifpushaway() { return pushaway; }
	friend class Grid;
};
```

其中虚函数func1 是为了提供不同植物所需的不同功能，供不同植物类重载所需，包括发射炮弹、爆炸、生产阳光。其余模块不需要调用具体的类，只需要用Plant类的指针调用相应的功能函数即可，从而简化设计。

同样的，这一设计也适用于僵尸：

```c++
class Zombie {
protected:
	string name;
	int HP;
	int maxHP;
	int x, y;//当前所处位置
	int ATK;  //攻击力/s
	int speed; //移动速度  （数值越大，速度越小)
	int counter;
	void init(const string& str, int health, int tspeed, int attack);
	bool eating;//是否正在吃植物（停止不动，攻击前一格的植物）
	bool snow;
	int snowcounter;
	int snowtime;
	int snow_wait;
public:
	Zombie() { init("普通僵尸", 270, 10, 100);  }
	const string& getName() const { return name; } //返回僵尸名字
	int getHP() { return HP; }//返回生命值
	void setstartloc(int tx, int ty);//设置起始位置
	virtual bool move(Map*& map, Game* game);//僵尸移动/攻击
	void judgeifeating(Map*& map); //判断是否在吃植物
	void snow_attack();
	bool ifsnow() { return snow; }
	virtual void func2(Map*& map, Game* game) { ; }//额外的一些功能
	friend class Grid;
};
```

其中虚函数func2是为了提供不同植物除了移动和攻击以外的其他功能。

虚函数move函数对于不同的僵尸也有不同的设计。

## 6.功能实现

### 1.在进行本次的功能拓展之前，我首先解决了阶段一遗留的一些问题：

①子弹有时出现“隔山打牛”（子弹错过僵尸）现象：

在Game的run_normal()中，我们是先对僵尸做了移动/攻击操作，再对子弹操作的，这可能导致在子弹判断格子中是否有僵尸时，僵尸已经移动到前面的格子里了，导致攻击的僵尸是后面的僵尸，而非前面的僵尸。

首先我们可以将子弹操作提前到对僵尸操作之前。发现还是存在同样的问题。进一步观察发现存在这样的情况，子弹本格子没有僵尸，于是移动而不攻击，下一步僵尸移动到之前的格，而子弹已经移动到下一格，于是没有攻击而是移动。于是我们对子弹的攻击和移动判断加以改进，在移动后立即对于本格僵尸进行攻击判断。

已经实现了更改：

![](E:\QQ下载文件\picture\g7.png)

②僵尸只吃前一格的植物，但是增加僵尸时没有排除和植物出现在同一格的情况：

更改了僵尸的攻击模式，僵尸到植物的同一格才攻击，允许植物和僵尸出现在同一格。

③前期为了简化书写，运用了大量的友元操作，导致程序数据不够安全，尽可能进行封装，并添加了相应的public函数，同时将一些不用公用的函数，修改为私有函数。

④没有恰当运用虚函数，所有的植物默认为peashooter。使用了继承机制，将外部对植物的操作用基类指针Plant* 代替，简化了操作，便于拓展，也使用了相应的奇函数实现重定义，具体内容在上面已经提过了，这里不再赘述。

⑤一些信息打印的位置错误，尤其是int类型的数据打印可能没有清除上一次打印的内容。已经进行了相应的修改。

⑥.选择框美化。添加了彩色的选择框显示。

### 2.界面设计扩展

##### ①显示植物或者僵尸的剩余生命值 

这个内容在第一阶段为了方便调试已经完成了。

##### ②每个地块中可以有多个僵尸

将map中每个grid存储僵尸的结构改为vector类型，统计每个格子中僵尸的数量，并打印出来，对子弹对僵尸的攻击作用在第一个进入该地块的僵尸生上，修改了地块攻击的僵尸模式，僵尸删除的时候要先在vector中删除对应的僵尸，再删除类对象。注意这里由于条件限制，同一格中的僵尸只打印最先进入的那只僵尸的信息。

![](E:\QQ下载文件\picture\g13.png)

### 3.植物设计扩展

##### ①攻击型：双发射手、寒冰射手

与豌豆射手类似，但是双发射手的射击速度改为豌豆射手的两倍，其他与豌豆射手保持一致。

寒冰射手射出的子弹是寒冰子弹（SnowBullet），其他与豌豆射手保持一致。

```c++
class SnowBullet: public Bullet{
public:
	SnowBullet() { x = 0; y = 0; ATK = 20; speed = 1; counter = 0; snow = true; }
	void move(Map* map, Game* game);//子弹移动/攻击
};
```

为了实现寒冰效果给僵尸和子弹增加了snow属性，用于判断是否有寒冰效果，并将其作为判断条件添加到僵尸的move函数中，填写不同的移动和攻击效果，同时增加了蓝色的冷冻效果。（展示部分代码）

```c++
	if (eating) {
		if(snow)
			temp = map->map_been_eating(x,y, ATK/2, game);
```

```c++
if (snow) {
		snowcounter++;
		if (snowcounter >= snowtime) { snow_wait = 0; snow = false; counter++; }
		else {
			snow_wait++;
			if (snow_wait >= 2)
			{
				snow_wait = 0;
				counter++;
			}
		}
	}
```

![](E:\QQ下载文件\picture\g14.png)

##### ②防御型：坚果墙、高坚果

坚果墙与豌豆射手类似，更改生命值，去除发射子弹的能力。

高坚果与豌豆射手类似，更改生命值，去除发射子弹的能力，增加撑杆僵尸跳不过的判断。

为了实现这一功能给所有的植物添加了jump属性，判断是否可以跳过，并在撑杆僵尸中添加了判断。

```c++
//高坚果
class Tallnut :public Plant {
public:
	Tallnut() { init("高坚果", 8000, 2, 0); jump = false; }
	void func1(Game* game, Map* map, Store* store) { ; };
};
```

##### ③炸弹型：窝瓜、樱桃炸弹

与豌豆射手类似，功能由发射子弹，改为爆炸。

```c++
void Squash::func1(Game* game, Map* map, Store* store) {
	int temp = 3;
	if (x < 6)
		if (map->map_haszombie(x+1, y))
			temp = 1;
	if (map->map_haszombie(x, y))
		temp = 0;

	if (temp == 3) return;

	map->map_killallZombie(x+temp,y,game);
	map->map_delplant(x,y,game);
}
```

```c++
void Cherry_Bomb::func1(Game* game, Map* map, Store* store) {
	counter += 1;
	if (counter >= speed) {
		map->map_killallZombie(x, y, game);
		map->map_killallZombie(x + 1, y, game);
		map->map_killallZombie(x - 1, y, game);
		map->map_killallZombie(x, y - 1, game);
		map->map_killallZombie(x + 1, y - 1, game);
		map->map_killallZombie(x - 1, y - 1, game);
		map->map_killallZombie(x, y + 1, game);
		map->map_killallZombie(x + 1, y + 1, game);
		map->map_killallZombie(x - 1, y + 1, game);
		map->map_delplant(x, y, game);
	}
}
```

##### ④效果型：大蒜、南瓜头

大蒜与坚果墙类似，为了实现其功能，给所有植物增加了pushaway功能，并在僵尸吃植物时，进行判断，驱赶僵尸。

```c++
class Garlic:public Plant {
public:
	Garlic() { init("大蒜", 400, 3, 0); pushaway = true; }
	void func1(Game* game, Map* map, Store* store) { ; }
};
```

```c++
if (eating) {
		if(snow)
			temp = map->map_been_eating(x,y, ATK/2, game);
		else
			temp = map->map_been_eating(x,y, ATK, game);

		if (temp)//吃到大蒜
		{
			map->map_delZombie(x, y, this);
			if (y < 2) {
				y++;
				map->map_addZombie(x, y, this);
			}
			else {
				y--;
				map->map_addZombie(x, y, this);
			}
		}

	    return true;
	}
```

南瓜头与坚果墙类似，但由于它种在植物外面，且没有额外的功能，为了方便管理，其信息独立存储在MAP的Grid中，而不再存在Game中，方便删除和操作，同时修改僵尸吃植物时的操作，先吃完南瓜头。

```c++
class Pumpkin :public Plant {
public:
	Pumpkin() { init("南瓜头", 4000, 3, 0); }
	friend class Grid;
};
```

```c++
class Grid {
private:
	//格子所处的位置(针对游戏庭院布置)
	int x;
	int y;
	//偏移量，针对绘图
	int dx;
	int dy;
	vector<Zombie*> zombies;
	Plant* plant;  
	Pumpkin* pumpkin;//南瓜头 由于没有其他功能，只存在map里, 不存在game里，简化删除操作
	vector<Bullet*> bullets;

	bool refresh;  //是否刷新

	void snowdraw(const string s); //寒冰效果输出
```

南瓜头信息要独立打印：

![](E:\QQ下载文件\picture\g16.png)

### 4.僵尸设计扩展

##### ①路障僵尸：与普通僵尸类似，更改生命值。

##### ②读报僵尸：与普通僵尸类似，在生命值到达临界区后更改速度。

##### ③撑杆僵尸：与普通僵尸类似， 移动功能move函数中添加了跳过与否的判断和相应操作。

```c++
class Pole_Vaulting_Zombie : public Zombie {
private:
	int speed2;
	bool jumped;//有无跳过、有无杆子
	bool jumpable(Map*& map);//是否可以跳过（高坚果）
public:
	Pole_Vaulting_Zombie() { init("撑杆僵尸", 500, 5, 100); jumped = false; speed2 = 9; }
	bool move(Map*& map, Game* game);

};
```

```c++
bool j=jumpable(map);
	if (eating && jumped) {
		if (snow)
			temp = map->map_been_eating(x, y, ATK / 2, game);
		else
			temp = map->map_been_eating(x, y, ATK, game);
            if (temp)//吃到大蒜
	{
		map->map_delZombie(x, y, this);
		if (y < 2) {
			y++;
			map->map_addZombie(x, y, this);
		}
		else {
			y--;
			map->map_addZombie(x, y, this);
		}
	}
	return true;
}
if (eating && !jumped) { //闪现一秒钟跳过
	if (!j) { jumped = true; speed = speed2; return true; }
	eating = false;
	jumped = true;
	counter = 0;
	speed = speed2;
	if (x <= 0) return false;
	map->map_delZombie(x, y, this);
	x--;
	map->map_addZombie(x, y, this);
	return true;
}
```
##### ④小丑僵尸

与普通僵尸类似，简化设计后，一定会在到达终点前爆炸，设计func2用于实现爆炸，在僵尸生成时就确定在哪个位置爆炸且越靠近终点越容易爆炸。

```c++
//小丑僵尸
class Jack_in_the_box_Zombie : public Zombie {
private:
	int bomb;
	void init_bomb();
public:
	Jack_in_the_box_Zombie() { init("小丑僵尸", 500, 10, 100); init_bomb(); }
	void func2(Map*& map, Game* game);
};
```

```c++
void Jack_in_the_box_Zombie::init_bomb() {
	int temp = random(280);
	if (temp < 10) bomb = 6;
	else if (temp < 30) bomb = 5;
	else if (temp < 60) bomb = 4;
	else if (temp < 100) bomb = 3;
	else if (temp < 150) bomb = 2;
	else if (temp < 210) bomb = 1;
	else bomb = 0;
}
void Jack_in_the_box_Zombie::func2(Map*& map, Game* game) {
	if (x == bomb) {
		map->map_boomplant(x, y, game);
		map->map_boomplant(x - 1, y, game);
		map->map_boomplant(x + 1, y, game);
		map->map_boomplant(x, y - 1, game);
		map->map_boomplant(x - 1, y - 1, game);
		map->map_boomplant(x + 1, y - 1, game);
		map->map_boomplant(x, y + 1, game);
		map->map_boomplant(x - 1, y + 1, game);
		map->map_boomplant(x + 1, y + 1, game);
		map->map_killZombie(x,y,game,this);
	}
}
```

##### ⑤投石僵尸

在普通僵尸的基础上，将攻击方式由吃改为碾压（大蒜没用），在move函数直接更改，同时增加直接攻击最后植物，先攻击植物再攻击南瓜头的投篮攻击攻击方式。在map中添加投石攻击的函数map_attack_plant。

```c++
bool Catapult_Zombie::move(Map*& map, Game* game) {
	if (x > 4 || ball == 0) {  //先压三格, 或者篮球投完了，直接前进
		if (snow) {
			snowcounter++;
			if (snowcounter >= snowtime) { snow_wait = 0; snow = false; counter++; }
			else {
				snow_wait++;
				if (snow_wait >= 2)
				{
					snow_wait = 0;
					counter++;
				}
			}
		}
		else
		    counter += 1;
		if (counter >= speed) {
			map->map_delZombie(x, y, this);
			x--;
			if (x < 0) //Zombies ate your brain
				return false;
			map->map_addZombie(x, y, this);
			counter = 0;
		}
		map->map_boomplant(x, y, game);
		return true;
	}
	//检查有无植物，没有，前进；有, 投石(已经排除了没球的情况)
	int i = 0;
	for (; i < x; i++) {
		if (map->map_hasplant(i, y))
			break;
	}
	if (i < x) {
		ball--;//投石
		map->map_attack_plant(i, y, ATK, game);//投石攻击
		return true;
	}
	else {
		if (snow) {
			snowcounter++;
			if (snowcounter >= snowtime) { snow_wait = 0; snow = false; counter++; }
			else {
				snow_wait++;
				if (snow_wait >= 2)
				{
					snow_wait = 0;
					counter++;
				}
			}
		}
		else
			counter += 1;
		if (counter >= speed) {
			map->map_delZombie(x, y, this);
			x--;
			if (x < 0) //Zombies ate your brain
				return false;
			map->map_addZombie(x, y, this);
			counter = 0;
		}
		return true;
	}
}
```

### 5.商店设计扩展

##### ①商店中植物的购买需要有冷却时间 

​    这个在第一阶段已经实现了

##### ②玩家可用键盘控制在商店内进行上下左右的选择

​    更改了植物的种植控制形式，主要还是通过之前的键盘监听，用黄色表示选择的植物

![](E:\QQ下载文件\picture\g15.png)

## 7.下一阶段可以关注的问题

①没有做投石车投石的动画，只有效果，没有投石动画，后续要添加

②转化为图形化界面后，使得动画更连贯，要提高刷新率到60帧左右，这里才1帧，反应比较慢

③转化为图形化界面后，对于僵尸应该有不同阶段的状态判断，选用不同的图片，这里没有进行临界值的判断

④可以增加一些功能，比如铲除植物、积分机制、产生僵尸的机制等等