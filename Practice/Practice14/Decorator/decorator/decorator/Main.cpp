#include <iostream>
#include <memory>

// Base interface
class Purchase {
public:
    virtual double getCost() const = 0;
    virtual ~Purchase() = default;
};

// Concrete component
class SimplePurchase : public Purchase {
    double baseCost;
public:
    SimplePurchase(double cost) : baseCost(cost) {}
    double getCost() const override {
        return baseCost;
    }
};

// Base decorator
class PurchaseDecorator : public Purchase {
protected:
    std::shared_ptr<Purchase> wrappedPurchase;
public:
    PurchaseDecorator(std::shared_ptr<Purchase> purchase) : wrappedPurchase(purchase) {}
};

// Tax decorator
class TaxDecorator : public PurchaseDecorator {
public:
    TaxDecorator(std::shared_ptr<Purchase> purchase) : PurchaseDecorator(purchase) {}
    double getCost() const override {
        return wrappedPurchase->getCost() * 1.10; // Adds 10% tax
    }
};

// Shipping fee decorator
class ShippingFeeDecorator : public PurchaseDecorator {
    double shippingFee;
public:
    ShippingFeeDecorator(std::shared_ptr<Purchase> purchase, double fee = 5.0)
        : PurchaseDecorator(purchase), shippingFee(fee) {
    }
    double getCost() const override {
        return wrappedPurchase->getCost() + shippingFee;
    }
};

// Discount decorator
class DiscountDecorator : public PurchaseDecorator {
    double discountPercent; // e.g., 0.15 for 15%
public:
    DiscountDecorator(std::shared_ptr<Purchase> purchase, double discount)
        : PurchaseDecorator(purchase), discountPercent(discount) {
    }
    double getCost() const override {
        return wrappedPurchase->getCost() * (1.0 - discountPercent);
    }
};

// Main function
int main() {
    double baseCost;
    std::cout << "Enter base cost of purchase: $";
    std::cin >> baseCost;

    std::shared_ptr<Purchase> purchase = std::make_shared<SimplePurchase>(baseCost);

    char applyTax, applyShipping, applyDiscount;
    std::cout << "Apply tax (10%)? (y/n): ";
    std::cin >> applyTax;

    std::cout << "Apply shipping fee ($5.00)? (y/n): ";
    std::cin >> applyShipping;

    std::cout << "Apply discount? (y/n): ";
    std::cin >> applyDiscount;

    if (applyTax == 'y' || applyTax == 'Y') {
        purchase = std::make_shared<TaxDecorator>(purchase);
    }

    if (applyShipping == 'y' || applyShipping == 'Y') {
        purchase = std::make_shared<ShippingFeeDecorator>(purchase);
    }

    if (applyDiscount == 'y' || applyDiscount == 'Y') {
        double discount;
        std::cout << "Enter discount percent (e.g., 15 for 15%): ";
        std::cin >> discount;
        purchase = std::make_shared<DiscountDecorator>(purchase, discount / 100.0);
    }

    std::cout << "Final cost: $" << purchase->getCost() << std::endl;

    return 0;
}
