[![CI/CD](https://github.com/calvinhxx/Design_Patterns/actions/workflows/github-actions.yml/badge.svg)](https://github.com/calvinhxx/Design_Patterns/actions/workflows/github-actions.yml) ![Platfrom](https://img.shields.io/badge/platfrom-windows%7Cmac%7Clinux-brightgreen) ![GitHub](https://img.shields.io/github/license/calvinhxx/Design_Patterns) [![standards-compliant readme](https://img.shields.io/badge/standard--readme-OK-green.svg?style=flat-square)](https://github.com/RichardLitt/standard-readme)

[中文](./README.zh-CN.md) / [English](./README.md)

# Design Patterns

Introduction to Design Patterns

## Contents

- [Design Patterns](#design-patterns)
  - [Contents](#contents)
  - [Types of Design Patterns](#types-of-design-patterns)
    - [Creational Design Patterns](#creational-design-patterns)
      - [🏠Simple Factory](#simple-factory)
      - [🏭Factory Method](#factory-method)
      - [🔨Abstract Factory](#abstract-factory)
      - [👷Builder](#builder)
      - [🐑Prototype](#prototype)
      - [💍Singleton](#singleton)
    - [Structural Design Patterns](#structural-design-patterns)
      - [🔌Adapter](#adapter)
      - [🚡Bridge](#bridge)
      - [🌿Composite](#composite)
      - [☕Decorator](#decorator)
      - [📦Facade](#facade)
      - [🍃Flyweight](#flyweight)
      - [🎱Proxy](#proxy)
    - [Behavioral Design Patterns](#behavioral-design-patterns)
      - [🔗Chain of Responsibility](#chain-of-responsibility)
      - [👮Command](#command)
      - [➿Iterator](#iterator)
      - [👽Mediator](#mediator)
      - [💾Memento](#memento)
      - [😎Observer](#observer)
      - [💢State](#state)
      - [💡Strategy](#strategy)
      - [📒Template Method](#template-method)
      - [🏃Visitor](#visitor)
  - [Reference](#reference)
  - [Maintainers](#maintainers)
  - [License](#license)

## Types of Design Patterns
  - Creational
  - Structural
  - Behavioral

---

### Creational Design Patterns
>The creation pattern abstracts the process of creating objects, which can be understood as encapsulating the process of creating objects, so that the client program only needs to use the objects, and does not care about the logic of the process of creating objects. the inevitable trend. Since the creation of objects consumes a lot of resources in the system, it is important to study the creation of objects separately so that they can be created efficiently.

In briefing: 

***Creational patterns are focused towards how to instantiate an object or group of related objects***

- Simple Factory
- Factory Method
- Abstract Factory
- Builder
- Prototype
- Singleton

#### 🏠Simple Factory
In brief: 
>For example, if you want to build a house and need a door, call a building material supplier to provide you with a door, you don't need to know anything about building doors yourself.

Motivation: 
>Repeatedly create complex objects.

Implementation: 
>return instances to the client through the interface, without exposing any instantiation logic to the client.

Class diagram: 
![class diagram](.github/assets/simplefactory.png "simplefactory")
[Code example](src/Creational_Patterns/simplefactory.h)

#### 🏭Factory Method
In brief: 
>Like a company hiring supervisor, who can't interview all applicants himself, will delegate interviews to different people in charge depending on job openings such as technical, sales, management, etc.

Motivation: 
>Repeated creation of complex objects and uncertainty about the exact type of subclasses.

Implementation: 
>Also return instances to the client through the interface, without exposing any instantiation logic to the client, but instantiating the interface through subclasses.

Class diagram: 
![class diagram](.github/assets/factorymethod.png "factorymethod")
[Code example](src/Creational_Patterns/factorymethod.h)

#### 🔨Abstract Factory
In brief: 
>Or renovate the door, according to the demand not only need wood doors also need iron doors, in addition to wood doors need special carpenter master, iron doors need welders.

Motivation: 
>repeatedly create complex objects, and need to rely on certain characteristics of the product, but do not want to be associated with a specific product class.

Implementation: 
>Factory of factories, encapsulating products with the same characteristics into a single factory.

Class diagram: 
![class diagram](.github/assets/abstractfactory.png "abstractfactory")
[code example](src/Creational_Patterns/abstractfactory.h)

#### 👷Builder
In brief: 
>For example, if you want a custom Big Mac burger at a membership restaurant, what kind of filling 🐷 meat or 🐂 meat, what kind of sauce 🍅 or salad, etc.

Motivation: 
>Create a lot of complex objects at different stages.

Implementation: 
> Create complex objects in steps, using the same code to generate different types and forms of objects.

Class diagram: 
![class diagram](.github/assets/builder.png "builder")
[code example](src/Creational_Patterns/builder.h)

#### 🐑Prototype
In brief: 
>Dolly Cloning sheep.

Motivation: 
>Generate new objects by cloning with existing objects. Optimize the tedious process of creating complex objects.

Implementation: 
>Provide cloning interface to create new objects from existing objects.

Class diagram: 
![class diagram](.github/assets/prototype.png "prototype")
[code example](src/Creational_Patterns/prototype.h)

#### 💍Singleton
In brief: 
>A country has only one president.

Motivation: 
>only one instance of a class, providing a global access node.

Implementation: 
>privatization construct, providing return static local objects.

Class diagram: 
![class diagram](.github/assets/singleton.png "singleton")
[code example](src/Creational_Patterns/singleton.h)

---

### Structural Design Patterns
>After solving the problem of object creation, the composition of objects and the dependencies between objects become the focus of developers, because how to design the structure of objects, inheritance and dependencies will affect the maintainability of subsequent programs, code robustness, coupling, etc.

In brief: 

***How to use between objects***

- Adapter
- Bridge
- Composite
- Decorator
- Facade
- Flyweight
- Proxy

#### 🔌Adapter
In brief: 
>The Hong Kong version of the switch power supply needs an adapter for use in mainland China.

Motivation: 
>Do not modify the original adapter class, the new object is compatible with the old interface.

Implementation: 
>Inherit the adapter class, extend the old interface.

Class diagram: 
![class diagram](.github/assets/adapter.png "adapter")
[code example](src/Structural_Patterns/adapter.h)

#### 🚡Bridge
In brief: 
>A bridge, with abstraction and implementation at both ends.

Motivation: 
>Separate the abstraction layer from the implementation layer, replace inheritance with combination, optimize m*n classes into m+n classes.

Implementation: 
>Implementation layer defines interfaces to associate abstract objects (bridge).

Class diagram: 
![class diagram](.github/assets/bridge.png "bridge")
[code example](src/Structural_Patterns/bridge.h)

#### 🌿Composite
In brief: 
>traverse the abstract tree.

Motivation: 
>Let the client handle each object in a uniform way.

Implementation: 
>Abstract the common properties, and store them in a tree data structure.

Class diagram: 
![class diagram](.github/assets/composite.png "composite")
[code example](src/Structural_Patterns/composite.h)

#### ☕Decorator
In brief: 
>Russian nesting dolls🪆.

Motivation: 
>Add new behavior dynamically without affecting the original object.

Implementation: 
>Wrap the object in a decorator class.

Class diagram: 
![class diagram](.github/assets/decorator.png "decorator")
[code example](src/Structural_Patterns/decorator.h)

**The difference between decoration and adaptation:**
>The decorator pattern is transparent to the user of the decorated class, and the interface is available both before and after decoration.
>Adaptation is to adapt two mismatched interfaces and make them available.

#### 📦Facade
In brief: 
>Computer one-button start button, ready to use.

Motivation: 
>Provide a simple interface for external interaction, hiding the internal complexity.

Implementation: 
>Provide a high-level interface that encapsulates subsystem behavior.

Class diagram: 
![class diagram](.github/assets/facade.png "facade")
[code example](src/Structural_Patterns/facade.h)

#### 🍃Flyweight
In brief: 
>Similar to thread pools, process pools.

Motivation: 
>Reuse existing objects of the same kind, or create new objects if no match is found.

Implementation: 
>With factory encapsulated key-value pair data structure.

Class diagram: 
![class diagram](.github/assets/flyweight.png "flyweight")
[code example](src/Structural_Patterns/flyweight.h)

#### 🎱Proxy
In brief: 
>intermediary.

Motivation: 
>Proxy of one object to another object if the target object is not convenient for direct manipulation.

Implementation: 
>Forwarding to the target object through the proxy to achieve the purpose.

Class diagram: 
![class diagram](.github/assets/proxy.png "proxy")
[code example](src/Structural_Patterns/proxy.h)

---

### Behavioral Design Patterns
>After the structure of the object and the creation of the object are solved, the behavior of the object remains, if the behavior of the object is well designed, then the behavior of the object will be clearer, and the efficiency of collaboration between them will increase.

In brief: 
***How objects communicate with each other***

- Chain of Responsibility
- Command
- Iterator
- Mediator
- Memento
- Observer
- State
- Strategy
- Template Method
- Visitor

#### 🔗Chain of Responsibility
In brief: 
> Similar to budget approval, from Team Leader -> Finance -> Director -> CFO.

Motivation: 
>Want data to be processed along the chain of responsibility like an approval workflow.

Implementation: 
>Build an acyclic chain of responsibility, decoupling senders and receivers.

Class diagram: 
![class diagram](.github/assets/chain-of-responsibility.png "chain-of-responsibility")
[code example](src/Behavioral_Patterns/chain-of-responsibility.h)

#### 👮Command
In brief: 
>Remote control TV.

Motivation: 
> decouple sender and receiver completely, no direct reference between sender and receiver.

Implementation: 
>Encapsulate receiver's behavior by abstract command layer.

Class diagram: 
![class diagram](.github/assets/commond.png "commond")
[code example](src/Behavioral_Patterns/commond.h)

#### ➿Iterator
In brief: 
> similar to stl container in C++.

Motivation: 
>Provide a way to iterate over objects without exposing the underlying implementation.

Implementation: 
>Store data by data structure, abstract iteration method.

Class diagram: 
![class diagram](.github/assets/lterator.png "lterator")
[code example](src/Behavioral_Patterns/lterator.h)

#### 👽Mediator
In brief: 
>Before the establishment of WTO, all countries traded with each other in a complicated way, after the establishment of WTO, all countries traded through WTO.

Motivation: 
>No coupling between classes and no direct interaction through the intermediate layer for data interaction.

Implementation: 
>Abstract intermediary class for two-way data interaction.

Class diagram: 
![class diagram](.github/assets/mediator.png "mediator")
[code example](src/Behavioral_Patterns/mediator.h)

**Difference between Mediator and proxy:**
>Proxy is A proxy B one-way.
>Mediator is many-to-many and data interaction is bidirectional.

#### 💾Memento
In brief: 
>Game archive.

Motivation: 
>Want objects to support snapshot capabilities.

Implementation: 
>Implement snapshot generation interface, and manage snapshots through snapshot management class.

Class diagram: 
![class diagram](.github/assets/memento.png "memento")
[code example](src/Behavioral_Patterns/memento.h)

#### 😎Observer
In brief: 
>Recruiting software, receive notifications when there are job updates.

Motivation: 
>Implement one-to-many asynchronous communication.

Implementation: 
>Subject maintains a list of observers, and automatically notifies observers when the subject is modified.

Class diagram: 
![class diagram](.github/assets/observer.png "observer")
[code example](src/Behavioral_Patterns/observer.h)

#### 💢State
In brief: 
> Low-cost finite state machine, state machine State, Transition corresponds to directed graph Node, Link, state pattern is borrowed from the concept of state machine State, Transition.

Motivation: 
>Change the object behavior when the object state changes.

Implementation: 
>Based on the concept of Node and Link in directed graph, abstract State and Transition.

Class diagram: 
![class diagram](.github/assets/state.png "state")
[code example](src/Behavioral_Patterns/state.h)

#### 💡Strategy
In brief: 
>Travel, airplane, train, car choose the appropriate mode based on mileage, price.

Motivation: 
>The same behavior performs different actions in different situations.

Implementation: 
>Abstract policy behavior, through the delegate class to complete the policy switch and behavior execution.

Class diagram: 
![class diagram](.github/assets/strategy.png "strategy")
[code example](src/Behavioral_Patterns/strategy.h)

#### 📒Template Method
In brief: 
> Build the program architecture.

Motivation: 
>Fixed templates for process-fixed interfaces.

Implementation: 
>abstract template methods, implementation in subclasses.

Class diagram: 
![class diagram](.github/assets/template-method.png "template-method")
[code example](src/Behavioral_Patterns/template-method.h)

#### 🏃Visitor
In brief: 
>Follow a tour group on a cross-border trip, following a fixed route.

Motivation: 
>When the underlying operation is too complex, constrain the behavior through the guest pattern.

Implementation: 
>Abstract visitor interface, visitor interface, implement coordinator combination element.

Class diagram: 
![class diagram](.github/assets/visitor.png "visitor")
[code example](src/Behavioral_Patterns/visitor.h)


## Reference
[design-patterns-for-humans](https://github.com/kamranahmedse/design-patterns-for-humans)
[java-design-patterns](https://github.com/iluwatar/java-design-patterns)

## Maintainers

[@calvinhxx](https://github.com/calvinhxx)

## License

MIT © 2023 calvinhxx

