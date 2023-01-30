// # Copyright 2022 CalvinHxx. All rights reserved.
#ifndef SRC_STRUCTURAL_PATTERNS_FLYWEIGHT_H_
#define SRC_STRUCTURAL_PATTERNS_FLYWEIGHT_H_

#include <iostream>
#include <map>
#include <string>

namespace FlyWeight {
class AbstractFlight {
 public:
  virtual void Info() = 0;
};

class Flight : public AbstractFlight {
 public:
  explicit Flight(const std::string &flight_num) : flight_num_(flight_num) {}
  void Info() override {
    std::cout << "flight-num:" << flight_num_ << std::endl;
  }

 protected:
  std::string flight_num_;
};

class FlightSearchFactory {
 public:
  static Flight *SearchFlight(const std::string &num) {
    auto result = map_.find(num);
    if (result != map_.end()) {
      std::cout << "Already exists" << std::endl;
      return result->second;
    } else {
      Flight *flight = new Flight(num);
      map_.insert({num, flight});
      std::cout << "New add" << std::endl;
      return flight;
    }
  }

 private:
  static std::map<std::string, Flight *> map_;
};

std::map<std::string, Flight *> FlightSearchFactory::map_ = {};

void Client() {
  std::cout << "***"
            << "FlyWeight"
            << "***\n";
  Flight *f1 = FlightSearchFactory::SearchFlight("9527");
  f1->Info();
  Flight *f2 = FlightSearchFactory::SearchFlight("9527");
  f2->Info();
  Flight *f3 = FlightSearchFactory::SearchFlight("1111");
  f3->Info();
  Flight *f4 = FlightSearchFactory::SearchFlight("2222");
  f4->Info();
  std::cout << "***"
            << "FlyWeight"
            << "***\n";
}
}  // namespace FlyWeight

#endif  // SRC_STRUCTURAL_PATTERNS_FLYWEIGHT_H_
