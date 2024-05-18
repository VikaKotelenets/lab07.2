#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HelpText {
private:
    struct Component {
        string term;
        string explanation;
    };

    vector<Component> components;

public:
    void addComponent(const string& term, const string& explanation) {
        components.push_back({term, explanation});
    }

    void displayHelp() const {
       cout << "Help Text:\n";
        for (const auto& component : components) {
            cout << component.term << ": " << component.explanation << "\n";
        }
    }

    void displayExplanation(const string& term) const {
        bool found = false;
        for (const auto& component : components) {
            if (component.term == term) {
                cout << "Explanation for " << term << ":\n" << component.explanation << "\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Term not found in help text.\n";
        }
    }
};

int main() {
    HelpText help;

    help.addComponent("term1", "Explanation for term1.");
    help.addComponent("term2", "Explanation for term2.");
    help.addComponent("term3", "Explanation for term3.");

    int choice;
   string term;

    do {
        cout << "\nMenu:\n1. Display Help Text\n2. Display Explanation for a Term\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                help.displayHelp();
                break;
            case 2:
                cout << "Enter the term you want to know about: ";
                cin >> term;
                help.displayExplanation(term);
                break;
            case 3:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
