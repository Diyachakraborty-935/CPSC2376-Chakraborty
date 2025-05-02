#include <string>
#include <iostream>
class Writer {
public:
	virtual void write() const = 0;
	virtual ~Writer() = default;
};

class PlainWriter : public Writer {
public:
	void write() const override {
		std::cout << "[TEXT]";
	}
};

class TimestampDecorator : public Writer {
	std::shared_ptr<Writer> base;
public:
	TimestampDecorator(std::shared_ptr<Writer> b) : base(std::move(b)) {}
	void write() const override {
		std::cout << "[Start]";
		base->write();
		std::cout << "[End]";
	}
};
int main() {
	std::shared_ptr<Writer> w = std::make_shared<TimestampDecorator>(
		std::make_shared<PlainWriter>());
	w->write();
	return 0;
}