#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int _val) : val(_val), next(nullptr) {} //constructor
};

struct list {
    Node *first;
    Node *last;

    list() : first(nullptr), last(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }

    void push_back(int _val) { //a
        Node *p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void push_front(int _val) { //a
        Node *p = new Node(_val);
        p->next = first;
        first = p;
        if (last == nullptr) last = p;
    }

    void print() { //g. print all list
        if (is_empty()) return;
        Node *p = first; //Создается указатель node , который указывает на первый элемент списка
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

    bool value_search (int v){
        Node *node = first;
        while (node != nullptr) {
            if (node->val == v){
                return true;
            }
            node = node->next;
        }
        return false;
    }

        int position_search(int p){
        Node* node = first;
        int count = 1;
        while (node != 0) {
            if (count == p) {
                return node->val;
            }
            count++;
            node = node->next;
        }
        return -1;
    }

    void remove_first() {
        if (is_empty()) return;
        Node *p = first;
        first = p->next;
        delete p;
    }

    void remove_last() {
        if (is_empty()) return;
        if (first == last) {
            remove_first();
            return;
        }
        Node *p = first;
        while (p->next != last) p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }

    void remove(int _val) { //remove for a value
        if (is_empty()) return;
        if (first->val == _val) {
            remove_first();
            return;
        } else if (last->val == _val) {
            remove_last();
            return;
        }
        Node *slow = first;
        Node *fast = first->next;
        while (fast && fast->val != _val) {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast) {
            cout << "This element does not exist" << endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }

    Node *getAt(int k) {
        if (k < 0) return 0;
        Node *node = first;
        int n = 0;
        while (node && n != k && node->next) {
            node = node->next;
            n++;
        }
        return (n == k) ? node : nullptr;
    }


    void insert(int k, int val) {
        Node *left = getAt(k);
        if (left == nullptr) return;

        Node *right = left->next;
        Node *node = new Node(val);

        left->next = node;
        node->next = right;
        if (right == nullptr) last = node;
    }

    void erase(int k) {
        if (k < 0) return;
        if (k == 0) {
            push_front(9);
            return;
        }
        Node *left = getAt(k - 1);
        Node *current = left->next;
        if (current == nullptr) return;
        Node *right = current->next;

        left->next = right;
        if (current == last) last = left;
        delete current;
    }

};

int main()
{

    cout << "Choose the number of operation" << endl;
    cout << "1. Adding an element to the end\n"
            "2. Adding an item to the top of the list\n"
            "3. Adding an element to a given position\n"
            "4. Deleting an element by value\n"
            "5. Deleting an item by item number\n"
            "6. Searching for an element by value\n"
            "7. Searching for an element in a given position\n"
            "8. Output of all list items\n"
            "*Input 0 to finish*"<< endl;
    list l;
    l.push_back(4);
    l.push_back(3);
    l.push_back(8);
    l.print();

    int num;

    while (num != 0) {

        cout << "Choose operation: " << endl;

        cin >> num;

        if (num == 1) {
            l.push_back(3);
            l.print();
        }
        else if (num == 2) {
            l.push_front(2);
            l.print();
        }
        else if (num == 3) {
            l.insert(1, 7);
            l.print();
        }

        else if (num == 4) {
            l.remove(3);
            l.print();
        }
        else if (num == 5) {
            l.erase(1);
            l.print();
        }
        else if (num == 6) {
            cout << "Enter element " << endl;
            int v;
            cin >> v;
            if (l.value_search(v) ){
                cout << "Element found" << endl;
            }
            else {
                cout << "Element not found" << endl;
            }

        }
        else if (num == 7) {
            cout << "Enter position " << endl;
            int p;
            cin >> p;
            if (l.position_search(p) != -1){
                cout << "The value is "<< l.position_search(p) << endl;
            }
            else {
                cout << "Invalid position" << endl;
            }
        }
        else if (num == 8) {
            l.print();
        }
        else {
            cout << "There is no such function" << endl;
        }
    }

    return 0;
}