class Game {
public:
    std::string title;
    int totalCopies;
    int availableCopies;

    Game(std::string title, int totalCopies);

    void addCopies(int count);
    void removeCopies(int count);
    void displayInfo() const;
};
class Customer {
    public:
        std::string name;
        std::string customerID;
    
        Customer(std::string name, std::string customerID);
    };
    class Loan {
        public:
            std::string customerID;
            std::string gameTitle;
            std::string dueDate;
        
            Loan(std::string customerID, std::string gameTitle, std::string dueDate);
        };
        class GameManager {
            public:
                void addGame(const Game& game);
                void checkOutGame(const std::string& title, const Customer& customer, const std::string& dueDate);
                void returnGame(const std::string& title, const Customer& customer);
                void listAllGames() const;
                void listLoans() const;
            
            private:
                std::vector<Game> games;
                std::vector<Loan> activeLoans;
            };
            classDiagram
    class Game {
        +string title
        +int totalCopies
        +int availableCopies
        +Game(string title, int totalCopies)
        +void addCopies(int count)
        +void removeCopies(int count)
        +void displayInfo()
    }

    class Customer {
        +string name
        +string customerID
        +Customer(string name, string customerID)
    }

    class Loan {
        +string customerID
        +string gameTitle
        +string dueDate
        +Loan(string customerID, string gameTitle, string dueDate)
    }

    class GameManager {
        +void addGame(Game game)
        +void checkOutGame(string title, Customer customer, string dueDate)
        +void returnGame(string title, Customer customer)
        +void listAllGames()
        +void listLoans()
        -vector~Game~ games
        -vector~Loan~ activeLoans
    }

    GameManager --> Game : manages
    GameManager --> Loan : tracks
    GameManager --> Customer : interacts with
    Loan --> Customer : linked to
    Loan --> Game : refers to
