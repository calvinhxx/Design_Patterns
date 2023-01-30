// # Copyright 2022 CalvinHxx. All rights reserved.
#ifndef DECORATOR_H
#define DECORATOR_H

#include <iostream>

namespace Decorator {
class Instrument {
 public:
  virtual void Play() = 0;
};

class Piano : public Instrument {
 public:
  void Play() override { std::cout << "Piano" << std::endl; }
};

class Guitar : public Instrument {
 public:
  void Play() override { std::cout << "Guitar" << std::endl; }
};

class InstrumentDecorator : public Instrument {
 public:
  InstrumentDecorator(Instrument *instrument) : Instrument_(instrument) {}
  void Play() override { Instrument_->Play(); }

 protected:
  Instrument *Instrument_;
};

class BarBeCueInstrumentDecorator : public InstrumentDecorator {
 public:
  explicit BarBeCueInstrumentDecorator(Instrument *instrument)
      : InstrumentDecorator(instrument) {}
  void Play() override {
    Barbecue();
    Instrument_->Play();
  }
  void Barbecue() { std::cout << "barbecue: "; }
};

void Client() {
  std::cout << "***"
            << "Decorator"
            << "***\n";
  Instrument *piano = new Piano();
  piano->Play();
  InstrumentDecorator bbqPaino = new BarBeCueInstrumentDecorator(piano);
  bbqPaino.Play();
  Instrument *guitar = new Guitar();
  guitar->Play();
  InstrumentDecorator bbqGuitar = new BarBeCueInstrumentDecorator(guitar);
  bbqGuitar.Play();
  std::cout << "***"
            << "Decorator"
            << "***\n";
}
}  // namespace Decorator

#endif  // DECORATOR_H
