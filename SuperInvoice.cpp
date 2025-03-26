#include "SuperInvoice.h"
#include <iostream>
#include <iomanip>

Item::Item(std::string name, double price, char vat, int quantity)
    : name(name), price(price), vat(vat), quantity(quantity) {}

double Item::price_before() const{
    return price * quantity;
}

double Item::price_after() const{
    double tax_rate = (vat == 'A') ? 0.23 : (vat == 'B') ? 0.08 : 0.0;
    return price_before() * (1 + tax_rate);
}

int Item::get_quantity() const{
    return quantity;
}

void Item::add_quantity(int qty){
    quantity += qty;
}

std::ostream &operator<<(std::ostream &out, const Item &item){
    out << std::fixed << std::setprecision(2);
    out << item.name << " | " << item.price << " | " << item.vat << " | " << item.quantity << " | " << item.price_before() << " | " << item.price_after();
    return out;
}

bool Item::operator==(const Item &other) const{
    return name == other.name && price == other.price && vat == other.vat;
}

Invoice::Invoice(long long seller, long long buyer)
    : nip_sel(seller), nip_buy(buyer) {}

void Invoice::add_item(const Item &item){
    for(auto &existing : items){
        if(existing == item){
            existing.add_quantity(item.get_quantity());
            return;
        }
    }
    items.push_back(item);
}

std::ostream &operator<<(std::ostream &out, const Invoice &invoice){
    out << "----------------VAT Invoice----------------\n";
    out << "==========================================\n";
    out << "Seller: " << invoice.nip_sel << "  Buyer: " << invoice.nip_buy << "\n";
    out << "Name | Price | VAT | Qty | Net  | Total \n";
    out << "------------------------------------------------\n";

    double total_net = 0, total_gross = 0;

    for(const auto &item : invoice.items){
        out << item << "\n";
        total_net += item.price_before();
        total_gross += item.price_after();
    }

    out << "------------------------------------------------\n";
    out << "TOTAL: " << total_net << " | " << total_gross << "\n";

    return out;
}

int main(){
    Invoice inv(7770003699, 123456789);
    inv.add_item(Item("M3 screw", 0.37, 'A', 100));
    inv.add_item(Item("2 mm drill", 2.54, 'B', 2));
    std::cout << inv << std::endl;
    return 0;
}
