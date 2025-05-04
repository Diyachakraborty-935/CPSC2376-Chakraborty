#include <iostream>
#include <vector>
#include <memory>
#include <numeric>

// Observer interface
class Observer {
public:
    virtual void update(int newGrade) = 0;
    virtual ~Observer() = default;
};

// Subject (GradeBook)
class GradeBook {
private:
    std::vector<Observer*> observers;
    std::vector<int> grades;

public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void addGrade(int grade) {
        grades.push_back(grade);
        notifyObservers(grade);
    }

    void notifyObservers(int grade) {
        for (Observer* obs : observers) {
            obs->update(grade);
        }
    }

    const std::vector<int>& getGrades() const {
        return grades;
    }
};

// Concrete Observer: Averager
class Averager : public Observer {
private:
    double average = 0.0;
    int count = 0;
    int total = 0;

public:
    void update(int newGrade) override {
        total += newGrade;
        ++count;
        average = static_cast<double>(total) / count;
        std::cout << "Updated Average: " << average << "\n";
    }
};

// Concrete Observer: Notifier
class Notifier : public Observer {
private:
    int threshold;

public:
    Notifier(int threshold) : threshold(threshold) {}

    void update(int newGrade) override {
        if (newGrade < threshold) {
            std::cout << "Email sent to student@example.com (grade below "
                << threshold << "%)\n";
        }
    }
};

// --- Main Program ---
int main() {
    GradeBook gradeBook;

    Averager averager;
    Notifier notifier(60); // threshold set to 60%

    gradeBook.addObserver(&averager);
    gradeBook.addObserver(&notifier);

    int input;
    std::cout << "Enter grades (negative number to stop):\n";
    while (true) {
        std::cout << "Grade: ";
        std::cin >> input;
        if (input < 0) break;
        gradeBook.addGrade(input);
    }

    return 0;
}
