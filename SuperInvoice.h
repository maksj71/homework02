#ifndef SUPERINVOICE_H
#define SUPERINVOICE_H
#include <vector>
#include <string>


class Item{
    std::string name;
    double price;
    char vat;
    int quantity;

public:
    Item(std::string name, double price, char vat, int quantity);
    double price_before() const;
    double price_after() const;
    int get_quantity() const;
    friend std::ostream &operator<<(std::ostream &out, const Item &item);
    bool operator==(const Item &other) const;
    void add_quantity(int quantity);
};

class Invoice{
    long long nip_sel;
    long long nip_buy;
    std::vector<Item> items;

public:
    Invoice(long long seller, long long buyer);
    void add_item(const Item &item);
    friend std::ostream &operator<<(std::ostream &out, const Invoice &invoice);
};

#endif // SUPERINVOICE_H
