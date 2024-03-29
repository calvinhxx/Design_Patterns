[![CI/CD](https://github.com/calvinhxx/Design_Patterns/actions/workflows/github-actions.yml/badge.svg)](https://github.com/calvinhxx/Design_Patterns/actions/workflows/github-actions.yml) ![Platfrom](https://img.shields.io/badge/platfrom-windows%7Cmac%7Clinux-brightgreen) ![GitHub](https://img.shields.io/github/license/calvinhxx/Design_Patterns) [![standards-compliant readme](https://img.shields.io/badge/standard--readme-OK-green.svg?style=flat-square)](https://github.com/RichardLitt/standard-readme)

[中文](./README.zh-CN.md) / [English](./README.md)

# 设计模式

设计模式简介

## 目录

- [设计模式](#设计模式)
  - [目录](#目录)
  - [设计模式类别](#设计模式类别)
    - [创建型](#创建型)
      - [🏠简单工厂](#简单工厂)
      - [🏭工厂方法](#工厂方法)
      - [🔨抽象工厂](#抽象工厂)
      - [👷建造者](#建造者)
      - [🐑原型](#原型)
      - [💍单例](#单例)
    - [结构型](#结构型)
      - [🔌适配](#适配)
      - [🚡桥接](#桥接)
      - [🌿组合](#组合)
      - [☕装饰](#装饰)
      - [📦外观](#外观)
      - [🍃享元](#享元)
      - [🎱代理](#代理)
    - [行为型](#行为型)
      - [🔗责任链](#责任链)
      - [👮命令](#命令)
      - [➿迭代器](#迭代器)
      - [👽中介](#中介)
      - [💾备忘录](#备忘录)
      - [😎观察者](#观察者)
      - [💢状态](#状态)
      - [💡策略](#策略)
      - [📒模板方法](#模板方法)
      - [🏃访客](#访客)
  - [参考](#参考)
  - [维护者](#维护者)
  - [许可](#许可)

## 设计模式类别
  - 创建型
  - 结构型
  - 行为型

---

### 创建型
>关注的是对象的创建, 创建型模式将创建对象的过程进行了抽象, 也可以理解为将创建对象的过程进行了封装, 作为客户程序仅仅需要去使用对象, 而不再关系创建对象过程中的逻辑, 社会化的分工越来越细, 自然在软件设计方面也是如此, 因此对象的创建和对象的使用分开也就成为了必然趋势. 因为对象的创建会消耗掉系统的很多资源, 所以单独对对象的创建进行研究, 从而能够高效地创建对象就是创建型模式要探讨的问题.

简单理解: 

***关注于如何实例化一个或者一组对象***

- 简单工厂
- 工厂方法
- 抽象工厂
- 建造者
- 原型
- 单例

#### 🏠简单工厂
简单理解: 
>比如你要盖房子需要门, 打电话给建材供应商给你提供门, 你自己不需要了解建造门的任何知识.

动机: 
>重复创建复杂对象.

实现方式: 
>通过接口向客户端返回实例, 不向客户端暴露任何实例化逻辑.

类图: 
![类图](.github/assets/simplefactory.png "简单工厂")
[代码例子](src/Creational_Patterns/simplefactory.h)

#### 🏭工厂方法
简单理解: 
>就像公司招聘主管, 自己不可能面试所有求职者, 会根据职位空缺如技术、销售、管理、将面试委托给不同的负责人.

动机: 
>重复创建复杂对象、且不确定子类确切类型.

实现方式: 
>也是通过接口向客户端返回实例, 不向客户端暴露任何实例化逻辑, 不过是通过子类去实例化接口.

类图: 
![类图](.github/assets/factorymethod.png "工厂方法")
[代码例子](src/Creational_Patterns/factorymethod.h)

#### 🔨抽象工厂
简单理解: 
>还是装修门, 根据需求不仅需要木门还需要铁门, 另外木门需要专门的木匠师傅、铁门需要焊工.

动机: 
>重复创建复杂对象、且需要依赖某些特性的产品, 但是不想关联具体的产品类.

实现方式: 
>工厂的工厂, 将具有相同特性的产品封装到一个工厂.

类图: 
![类图](.github/assets/abstractfactory.png "抽象工厂")
[代码例子](src/Creational_Patterns/abstractfactory.h)

#### 👷建造者
简单理解: 
>比如在会员制餐厅定制巨无霸汉堡, 要啥馅🐷肉还是🐂肉, 啥酱🍅还是萨拉等等.

动机: 
>大量创建不同阶段复杂对象.

实现方式: 
>分步骤创建复杂对象, 使用相同代码生成不同类型、形式的对象.

类图: 
![类图](.github/assets/builder.png "建造者")
[代码例子](src/Creational_Patterns/builder.h)

#### 🐑原型
简单理解: 
>dolly 克隆羊.

动机: 
>借助已存在对象, 克隆生成新对象。优化创建复杂对象的繁琐流程.

实现方式: 
>提供克隆接口从已有对象创建新对象.

类图: 
![类图](.github/assets/prototype.png "原型")
[代码例子](src/Creational_Patterns/prototype.h)

#### 💍单例
简单理解: 
>一个国家只有一个主席.

动机: 
>一个类只有一个实例, 提供一个全局的访问节点.

实现方式: 
>私有化构造，提供返回静态局部对象.

类图: 
![类图](.github/assets/singleton.png "单例")
[代码例子](src/Creational_Patterns/singleton.h)

---

### 结构型
>在解决了对象的创建问题之后, 对象的组成以及对象之间的依赖关系就成了开发人员关注的焦点, 因为如何设计对象的结构、继承和依赖关系会影响到后续程序的维护性、代码的健壮性、耦合性等

简单理解: 

***对象之间如何使用***

- 适配
- 桥接
- 组合
- 装饰
- 外观
- 享元
- 代理

#### 🔌适配
简单理解: 
>港版switch电源在大陆使用需要一个转接头.

动机: 
>不修改原有的适配类, 新对象兼容旧接口.

实现方式: 
>继承适配类, 扩展兼容旧接口.

类图: 
![类图](.github/assets/adapter.png "适配")
[代码例子](src/Structural_Patterns/adapter.h)

#### 🚡桥接
简单理解: 
>一座桥, 两端是抽象和实现.

动机: 
>将抽象层与实现层分离, 用组合的方式取代继承, 将m*n个类优化为m+n个类.

实现方式: 
>实现层定义接口关联抽象对象(架桥).

类图: 
![类图](.github/assets/bridge.png "桥接")
[代码例子](src/Structural_Patterns/bridge.h)

#### 🌿组合
简单理解: 
>遍历抽象树.

动机: 
>让客户端以统一的方式处理每个对象.

实现方式: 
>抽象出公共属性, 以树的数据结构存储.

类图: 
![类图](.github/assets/composite.png "组合")
[代码例子](src/Structural_Patterns/composite.h)

#### ☕装饰
简单理解: 
>俄罗斯套娃🪆.

动机: 
>在不影响原对象的前提下, 动态的添加新行为。

实现方式: 
>将对象包装在装饰器类中.

类图: 
![类图](.github/assets/decorator.png "装饰")
[代码例子](src/Structural_Patterns/decorator.h)

**装饰与适配的差别:**
>装饰器模式要做到对被装饰类的使用者透明, 接口在装饰前与装饰后均可用.
>适配是将两个不匹配的接口进行适配, 让其可用.

#### 📦外观
简单理解: 
>电脑一键启动按钮, 开机即用.

动机: 
>对外提供简单的交互接口, 隐藏内部的复杂性。

实现方式: 
>提供一个高层次的接口, 封装子系统行为.

类图: 
![类图](.github/assets/facade.png "外观")
[代码例子](src/Structural_Patterns/facade.h)

#### 🍃享元
简单理解: 
>类似线程池、进程池.

动机: 
>重用现有的同类对象, 如果未找到匹配的对象, 则创建新对象。

实现方式: 
>通过工厂封装键值对数据结构.

类图: 
![类图](.github/assets/flyweight.png "享元")
[代码例子](src/Structural_Patterns/flyweight.h)

#### 🎱代理
简单理解: 
>中介.

动机: 
>目标对象不方便直接操作的前提下，一个对象代理另一个对象的功能.

实现方式: 
>通过代理转发到目标对象实现目的.

类图: 
![类图](.github/assets/proxy.png "代理")
[代码例子](src/Structural_Patterns/proxy.h)

---

### 行为型
>在对象的结构和对象的创建问题都解决了之后, 就剩下对象的行为问题了, 如果对象的行为设计的好, 那么对象的行为就会更清晰, 它们之间的协作效率就会提高

简单理解: 
***对象之间如何通信***

- 责任链
- 命令
- 迭代器
- 中介
- 备忘录
- 观察者
- 状态
- 策略
- 模板方法
- 访客

#### 🔗责任链
简单理解: 
>类似预算审批, 从组长->财务->总监->CFO.

动机: 
>希望数据能像审批工作流一样沿着责任链传递处理.

实现方式: 
>构建非环形的责任链, 解耦发送者与接收者.

类图: 
![类图](.github/assets/chain-of-responsibility.png "责任链")
[代码例子](src/Behavioral_Patterns/chain-of-responsibility.h)

#### 👮命令
简单理解: 
>遥控器操控电视.

动机: 
>将发送者、接收者完全解耦，发送者与接收者之间没有直接引用关系.

实现方式: 
>通过抽象命令层封装接受者行为.

类图: 
![类图](.github/assets/commond.png "命令")
[代码例子](src/Behavioral_Patterns/commond.h)

#### ➿迭代器
简单理解: 
>类似C++中stl容器.

动机: 
>在不暴露底层实现的前提下, 提供一种遍历对象的方法.

实现方式: 
>通过数据结构存储数据, 抽象迭代方法.

类图: 
![类图](.github/assets/lterator.png "迭代器")
[代码例子](src/Behavioral_Patterns/lterator.h)

#### 👽中介
简单理解: 
>WTO成立之前各个国家相互贸易、错综复杂, 成立WTO后所有国家通过WTO交易.

动机: 
>类之间不耦合不直接交互通过中间层进行数据交互.

实现方式: 
>抽象中介类进行数据的双向交互.

类图: 
![类图](.github/assets/mediator.png "中介")
[代码例子](src/Behavioral_Patterns/mediator.h)

**中介与代理的差别:**
>代理是A代理B单向.
>中介是多对多且数据交互双向.

#### 💾备忘录
简单理解: 
>游戏存档.

动机: 
>希望对象支持快照能力.

实现方式: 
>实现快照生成接口, 通过快照管理类管理快照.

类图: 
![类图](.github/assets/memento.png "备忘录")
[代码例子](src/Behavioral_Patterns/memento.h)

#### 😎观察者
简单理解: 
>招聘软件, 有岗位更新就会收到通知.

动机: 
>实现一对多异步通信.

实现方式: 
>主体维护观察者列表, 主体修改时自动通知观察者.

类图: 
![类图](.github/assets/observer.png "观察者")
[代码例子](src/Behavioral_Patterns/observer.h)

#### 💢状态
简单理解: 
>低配finite-state machine(有限状态机), 状态机State、Transition 对应有向图Node、Link, 状态模式是借鉴了状态机State、Transition概念.

动机: 
>在对象状态更改时变化对象行为.

实现方式: 
>借鉴有向图中的Node、Link概念, 抽象State、Transition.

类图: 
![类图](.github/assets/state.png "状态")
[代码例子](src/Behavioral_Patterns/state.h)

#### 💡策略
简单理解: 
>出门旅行, 飞机, 火车, 汽车根据里程、价格选择合适的方式.

动机: 
>同样的行为在不同情况下执行不同的操作.

实现方式: 
>抽象策略行为, 通过委托类完成策略的切换和行为执行.

类图: 
![类图](.github/assets/strategy.png "策略")
[代码例子](src/Behavioral_Patterns/strategy.h)

#### 📒模板方法
简单理解: 
>搭建程序架构.

动机: 
>流程固定的接口固定模板.

实现方式: 
>抽象模板方法, 实现置于子类.

类图: 
![类图](.github/assets/template-method.png "模板方法")
[代码例子](src/Behavioral_Patterns/template-method.h)

#### 🏃访客
简单理解: 
>跟着旅行团跨境旅游, 按照固定线路游览.

动机: 
>当底层操作过于复杂时, 通过访客模式规范约束行为.

实现方式: 
>抽象访客接口、被访问者接口, 实现协调者组合元素.

类图: 
![类图](.github/assets/visitor.png "访客")
[代码例子](src/Behavioral_Patterns/visitor.h)


## 参考
[design-patterns-for-humans](https://github.com/kamranahmedse/design-patterns-for-humans)
[java-design-patterns](https://github.com/iluwatar/java-design-patterns)

## 维护者

[@calvinhxx](https://github.com/calvinhxx)

## 许可

MIT © 2023 calvinhxx

