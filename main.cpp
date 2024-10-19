#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <locale>  // Для підключення кирилиці

using namespace std;

struct Node {
    string word;
    string translation;
    int access_count;
    Node* left;
    Node* right;

    Node(string w, string t, int count = 0)
        : word(w), translation(t), access_count(count), left(nullptr), right(nullptr) {}
};

class DictionaryTree {
private:
    Node* root;

    Node* insert(Node* node, const string& word, const string& translation, int count) {
        if (!node)
            return new Node(word, translation, count);
        if (word < node->word)
            node->left = insert(node->left, word, translation, count);
        else if (word > node->word)
            node->right = insert(node->right, word, translation, count);
        return node;
    }

    Node* find(Node* node, const string& word) {
        if (!node || node->word == word)
            return node;
        if (word < node->word)
            return find(node->left, word);
        else
            return find(node->right, word);
    }

    Node* findMin(Node* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    Node* remove(Node* node, const string& word) {
        if (!node)
            return nullptr;
        if (word < node->word)
            node->left = remove(node->left, word);
        else if (word > node->word)
            node->right = remove(node->right, word);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->word = temp->word;
            node->translation = temp->translation;
            node->access_count = temp->access_count;
            node->right = remove(node->right, temp->word);
        }
        return node;
    }

    void inorder(Node* node, vector<Node*>& nodes) {
        if (node) {
            inorder(node->left, nodes);
            nodes.push_back(node);
            inorder(node->right, nodes);
        }
    }

public:
    DictionaryTree() : root(nullptr) {}

    void addWord(const string& word, const string& translation, int count = 0) {
        root = insert(root, word, translation, count);
    }

    void showTranslation(const string& word) {
        Node* result = find(root, word);
        if (result) {
            result->access_count++;
            cout << "Переклад слова '" << word << "': " << result->translation << endl;
        }
        else {
            cout << "Слово '" << word << "' не знайдено." << endl;
        }
    }

    void replaceTranslation(const string& word, const string& newTranslation) {
        Node* result = find(root, word);
        if (result) {
            result->translation = newTranslation;
            cout << "Переклад слова '" << word << "' було замінено." << endl;
        }
        else {
            cout << "Слово '" << word << "' не знайдено." << endl;
        }
    }

    void deleteWord(const string& word) {
        root = remove(root, word);
        cout << "Слово '" << word << "' було видалено." << endl;
    }

    void showTop3Popular() {
        vector<Node*> nodes;
        inorder(root, nodes);
        sort(nodes.begin(), nodes.end(), [](Node* a, Node* b) {
            return a->access_count > b->access_count;
            });
        cout << "Топ-3 найпопулярніших слів:" << endl;
        for (int i = 0; i < 3 && i < nodes.size(); i++) {
            cout << nodes[i]->word << " (" << nodes[i]->access_count << " звернень)" << endl;
        }
    }

    void showTop3Unpopular() {
        vector<Node*> nodes;
        inorder(root, nodes);
        sort(nodes.begin(), nodes.end(), [](Node* a, Node* b) {
            return a->access_count < b->access_count;
            });
        cout << "Топ-3 найменш популярних слів:" << endl;
        for (int i = 0; i < 3 && i < nodes.size(); i++) {
            cout << nodes[i]->word << " (" << nodes[i]->access_count << " звернень)" << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "");  // Включає підтримку кирилиці

    DictionaryTree dict;

    dict.addWord("apple", "яблоко", 5);
    dict.addWord("banana", "банан", 3);
    dict.addWord("orange", "апельсин", 2);
    dict.addWord("grape", "виноград", 1);
    dict.addWord("peach", "персик", 4);

    dict.showTranslation("apple");
    dict.showTranslation("banana");

    dict.replaceTranslation("banana", "бананы");

    dict.deleteWord("orange");

    dict.showTop3Popular();
    dict.showTop3Unpopular();

    return 0;
}
