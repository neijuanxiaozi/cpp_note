# 卡码网设计模式

## 1. 单例模式

```c++
#include <iostream>
#include <map>
using namesapce std;

class ShoppingCartManager 
{
public:
	static ShoppingCartManager& getInstance() 
    {
        static ShoppingCartManager instance;
        return instance;
    }
private:
    // 私有构造函数
    ShoppingCartManager() {}
    // 购物车存储商品和数量的映射
    map<string, int> cart;
};
```

## 2. 工厂模式

工厂方法模式使得每个工厂类的职责单一，每个工厂只负责创建一种产品，当创建对象涉及一系列复杂的初始化逻辑，而这些逻辑在不同的子类中可能有所不同时，可以使用工厂方法模式将这些初始化逻辑封装在子类的工厂中。在现有的工具、库中，工厂方法模式也有广泛的应用，比如

- Spring 框架中的 Bean 工厂：通过配置文件或注解，Spring 可以根据配置信息动态地创建和管理对象。
- JDBC 中的 Connection 工厂：在 Java 数据库连接中，`DriverManager` 使用工厂方法模式来创建数据库连接。不同的数据库驱动（如 MySQL、PostgreSQL 等）都有对应的工厂来创建连接。

```c++
#include <iostream>
#include <vector>

// 抽象积木接口
class Block {
public:
	virtual void produce() = 0;
};

// 具体圆形积木实现
class CircleBlock : public Block {
public:
    void produce override {
        std::cout << "Circle Block" << std::endl;
    }
};

// 具体方形积木实现
class SquareBlock : public Block {
public:
    void produce override {
        std::cout << "Square Block" << std::endl;
    }
};
// 抽象积木工厂接口
class BlockFactory {
public:
    virtual Block* createBlock() = 0;
};

// 具体圆型积木工厂实现
class CircleBlockFactory : public BlockFactory {
public:
    Block* createBlock() override {
        return new CircleBlock();
    }
};
class SquareBlockFactory : public BlockFactory {
public:
    Block* createBlock() override {
        return new SquareBlock();
    }
};

// 积木工厂系统
class BlockFactorySystem {
private:
    std::vector<Block*> blocks;
public:
    void produceBlocks(BlockFactory *factory, int quantity) {
        for (int i = 0; i < quantity; ++i) {
            Block *block = factory->createBlock();
            blocks.push_back(block);
            block->produce();
        }
    }
    ~BlockFactorySystem() {
        for (auto &block : blocks) {
			delete block;
        }
    }
}
int main() {
    //创建积木工厂系统
    BlockFactorySystem factorySystem;
    int productionCount;
    std::cin >> productionCount;
   	// 读取每次生产的积木类型和数量
    for (int i = 0; i < productionCout; ++i) {
        std::string blockType;
        int quantity;
        std::cin >> blockType >> quantity;
        if (blockType == "Circle") {
            factorySystem.produceBlocks(new CircleBlockFactory(), quantity);
        } else if (blockType == "Square") {
            factorySystem.produceBlocks(new SquarelockFactory(), quantity);
        } 
    }
    return 0;
}
```

