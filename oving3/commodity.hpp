#pragma once

#include <string>

class Commodity {
public:
    Commodity(const std::string &name_, int id_, double price_);

    std::string get_name() const;
    int get_id() const;

    double get_price() const;
    double get_price(double quantity) const;
    double get_price_with_sales_tax(double quantity) const;

    void set_price(double price_);

private:
    std::string name;
    int id;
    double price;
};