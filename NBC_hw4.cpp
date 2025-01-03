#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std; // namespace std ���

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {}
};


class BorrowManager {
private:
    unordered_map<string,int> stock;
    vector<Book> books;

public:
    void initializeStock(Book& book, int quanity = 3) {
        stock[book.title] = quanity;
    }
    void borrowBook(string& title) {
        if (stock[title] > 0) {
            stock[title]--;
        }
        else {
            cout << "�뿩�Ұ�" << endl;
        }
    }
    void returnBook(string& title) {
        stock[title]++;

    }
    void displayStock() {
        cout << "å ��� ��Ȳ" << endl;

        for (auto& pair : stock) {
            cout << "=> " << pair.first << "�� ���� ��� : " << pair.second << endl;

        }
    }
    int getCount(string& title) {//�뿩 ���� Ƚ�� ī��Ʈ �Լ�
        auto book = stock.find(title);//å ã��
        if (book != stock.end()) {//ã�Ƽ� ���������� (=������), �ι��� pair ��ȯ�ϱ�
            return book->second;
        }
        else
            return 0;
    }
};

class BookManager {
private:
    vector<Book> books; // å ��� ����
    BorrowManager* borrowmanager;

public:
    BookManager() = default;
    BookManager(BorrowManager* bm) : borrowmanager(bm) {} 

    // å �߰� �޼���
    void addBook(const string& title, const string& author) {
        Book initbook = Book(title, author);
        books.push_back(initbook); // push_back ���
        cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
        
        borrowmanager->initializeStock(initbook);
    }
    // ��� å ��� �޼���
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }
        cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
        cout << "���� ���� ���:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }
    void searchByTitle(const string title) {
        cout << "�˻� ��� : "<<title<<endl;
        vector<Book> results;
        for (auto book : books) {
            if (book.title.find(title) != string::npos) {//npos : ���� ��ã������ ��ȯ��. => �˻�� ������
                results.push_back(book);
            }
        }

        if (results.empty()) {
            cout << "�˻��� å�� �����ϴ�." << endl;
        }
        else {
            cout << "�˻��� å" << endl;
            for (auto book : results) {
                cout << "=> " << book.title << "-" << book.author << "/ �뿩 ���� Ƚ��:  "<< borrowmanager->getCount(book.title) << endl;
            }
        }
    }
    void searchByAuthor(const string author) {
        cout << "�˻��� ���� : "<< author << endl;
        vector<Book> results;
        for (auto book : books) {
            if (book.author.find(author) != string::npos) {//npos : ���� ��ã������ ��ȯ��. => �˻�� ������
                results.push_back(book);
            }
        }

        if (results.empty()) {
            cout << "�˻��� å�� �����ϴ�." << endl;
        }
        else {
            cout << "�˻��� å" << endl;
            for (auto book : results) {
                cout << "=> " << book.title << "-" << book.author << "/ �뿩 ���� Ƚ��:  " << borrowmanager->getCount(book.title)<<endl;
            }
        }

    }


};


int main() {
    
    BorrowManager borrowmanager;
    BookManager manager(&borrowmanager);
    // ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
    // ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.

    manager.addBook("����å1", "��������1");
    manager.addBook("����å2", "��������2");
    manager.addBook("����å3", "��������3");
    manager.addBook("���ú�1", "��������1");
    manager.addBook("���ú�2", "��������2");
    manager.addBook("���ú�3", "��������3");

    while (true) {
        cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl; // å ������ �Է¹޾� å ��Ͽ� �߰�
        cout << "2. ��� å ���" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
        cout << "3. å �˻�" << endl;
        cout << "4. å �뿩" << endl;
        cout << "5. å �ݳ�" << endl;
        cout << "6. å ��� ��Ȳ" << endl;
        cout << "7. ����" << endl; // ���α׷� ����
        cout << "����: ";

        int choice; // ������� �޴� ������ ����
        cin >> choice;
        string title, author;
        if (choice == 1) {
            // 1�� ����: å �߰�
            // ����ڷκ��� å ����� ���ڸ��� �Է¹޾� BookManager�� �߰��մϴ�.
            cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
            cout << "å �߰��ϱ�" << endl;
            cout << "å ����: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, title); // ���� �Է� (���� ����)
            cout << "å ����: ";
            getline(cin, author); // ���ڸ� �Է� (���� ����)
            manager.addBook(title, author); // �Է¹��� å ������ �߰�
        }
        else if (choice == 2) {
            // 2�� ����: ��� å ���
            // ���� BookManager�� ����� å ����� ����մϴ�.
            manager.displayAllBooks();
        }
        else if (choice == 3) {
            // 3�� ����: �˻�
            // å �������� �˻� or ���ڷ� �˻�
            cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
            cout << "� ������� �˻��ұ��?" << endl;
            cout << "1. å ����"<< endl;
            cout << "2. å ����" << endl;
            cout << "���� : " << endl;
            int choice2 = 0;
            cin >> choice2;
            if (choice2 == 1) {
                cout << "�˻��� å �̸� : " ;
                cin.ignore();
                getline(cin,title);
                manager.searchByTitle(title);
            }
            else if(choice2 == 2) {
                cout << "�˻��� ���� �̸� : ";
                cin.ignore();
                getline(cin, author);
                manager.searchByAuthor(author);
            }
        }
        else if (choice == 4) {
            // 4�� ���� : å �뿩
            cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
            cout << "�뿩�� å �̸�: ";
            cin.ignore();
            getline(cin, title);
            borrowmanager.borrowBook(title);

        }

        else if (choice == 5) {
            // 5�� ���� : å �ݳ�
            cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
            cout << "�ݳ��� å �̸�: ";
            cin.ignore();
            getline(cin, title);
            borrowmanager.returnBook(title);

        }
        else if (choice == 6) {
            // 6�� ���� : å ��� Ȯ��
            cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
            borrowmanager.displayStock();
        }

        else if (choice == 7) {
            // 3�� ����: ����
            // ���α׷��� �����ϰ� ����ڿ��� �޽����� ����մϴ�.
            cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
            cout << "���α׷��� �����մϴ�." << endl;
            break; // while ���� ����
        }
        else {
            // �߸��� �Է� ó��
            // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
            cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0; // ���α׷� ���� ����
}
