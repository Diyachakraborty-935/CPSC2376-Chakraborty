#include <iostream>
#include <deque>
#include <string>

using namespace std;

class UndoableTextEditor {
private:
    deque<string> textEdits;

public:
    // Add text to the editor
    void addText(const string& text) {
        textEdits.push_back(text);
        cout << "Text added: " << text << endl;
    }

    // Undo the last edit
    void undoLastEdit() {
        if (!textEdits.empty()) {
            textEdits.pop_back();
            cout << "Undo successful!" << endl;
        }
        else {
            cout << "No edits to undo!" << endl;
        }
    }

    // Show current content
    void showContent() {
        if (textEdits.empty()) {
            cout << "No content yet!" << endl;
        }
        else {
            cout << "Current Content: ";
            for (const string& text : textEdits) {
                cout << text << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    UndoableTextEditor editor;
    int choice;
    string inputText;

    do {
        cout << "1. Add Text" << endl;
        cout << "2. Undo Last Edit" << endl;
        cout << "3. Show Content" << endl;
        cout << "4. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();  // To ignore the newline character left by cin

        switch (choice) {
        case 1:
            cout << "Enter text: ";
            getline(cin, inputText);
            editor.addText(inputText);
            break;
        case 2:
            editor.undoLastEdit();
            break;
        case 3:
            editor.showContent();
            break;
        case 4:
            cout << "Exiting editor..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
