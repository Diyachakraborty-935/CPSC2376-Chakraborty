This program is a lightweight board game management system designed for a local board game café. It allows café staff to manage their collection of board games, track checkouts to customers, and log returns. The system keeps a record of each game, how many copies are in stock, and who currently has a copy. It enables basic operations such as viewing inventory, lending out games, and handling returns.
Entities involved include board games, customers, and lending records. The system should be simple and functional, with an emphasis on usability in a real-world café setting.
Key Nouns (Potential Classes or Attributes)
• BoardGame
• Customer
• LendingRecord
• Inventory
• Copy
• DueDate
Key Verbs (Potential Methods)
• CheckOut
• ReturnGame
• ViewAvailableGames
• AddGame
• RemoveGame
• GetLendingStatus
Class Design
BoardGame Class
class BoardGame {
public:
    std::string title;
    int totalCopies;
    int availableCopies;

    BoardGame(std::string t, int total);

    void addCopies(int count);
    void removeCopies(int count);
    bool isAvailable() const;
};
Customer Class
class Customer {
public:
    std::string name;
    std::string customerId;

    Customer(std::string n, std::string id);
};
LendingRecord Class
class LendingRecord {
public:
    std::string customerId;
    std::string gameTitle;
    std::string dueDate;

    LendingRecord(std::string cid, std::string title, std::string date);
};
LendingSystem Class
class LendingSystem {
public:
    void addGame(std::string title, int copies);
    void viewInventory() const;
    bool checkOutGame(std::string gameTitle, std::string customerId, std::string dueDate);
    bool returnGame(std::string gameTitle, std::string customerId);

private:
    std::vector<BoardGame> games;
    std::vector<Customer> customers;
    std::vector<LendingRecord> records;

    BoardGame* findGame(const std::string& title);
    LendingRecord* findRecord(const std::string& title, const std::string& customerId);
};
classDiagram
    class BoardGame {
        +string title
        +int totalCopies
        +int availableCopies
        +BoardGame(string t, int total)
        +void addCopies(int count)
        +void removeCopies(int count)
        +bool isAvailable() const
    }

    class Customer {
        +string name
        +string customerId
        +Customer(string n, string id)
    }

    class LendingRecord {
        +string customerId
        +string gameTitle
        +string dueDate
        +LendingRecord(string cid, string title, string date)
    }

    class LendingSystem {
        +void addGame(string title, int copies)
        +void viewInventory() const
        +bool checkOutGame(string gameTitle, string customerId, string dueDate)
        +bool returnGame(string gameTitle, string customerId)
        -vector~BoardGame~ games
        -vector~Customer~ customers
        -vector~LendingRecord~ records
        -BoardGame* findGame(string title)
        -LendingRecord* findRecord(string title, string customerId)
    }

    LendingSystem --> BoardGame : has a
    LendingSystem --> Customer : manages
    LendingSystem --> LendingRecord : tracks
