#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std; // namespace std 사용

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
            cout << "대여불가" << endl;
        }
    }
    void returnBook(string& title) {
        stock[title]++;

    }
    void displayStock() {
        cout << "책 재고 현황" << endl;

        for (auto& pair : stock) {
            cout << "=> " << pair.first << "의 남은 재고 : " << pair.second << endl;

        }
    }
    int getCount(string& title) {//대여 가능 횟수 카운트 함수
        auto book = stock.find(title);//책 찾기
        if (book != stock.end()) {//찾아서 없지않으면 (=있으면), 두번쨰 pair 반환하기
            return book->second;
        }
        else
            return 0;
    }
};

class BookManager {
private:
    vector<Book> books; // 책 목록 저장
    BorrowManager* borrowmanager;

public:
    BookManager() = default;
    BookManager(BorrowManager* bm) : borrowmanager(bm) {} 

    // 책 추가 메서드
    void addBook(const string& title, const string& author) {
        Book initbook = Book(title, author);
        books.push_back(initbook); // push_back 사용
        cout << "책이 추가되었습니다: " << title << " by " << author << endl;
        
        borrowmanager->initializeStock(initbook);
    }
    // 모든 책 출력 메서드
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "현재 등록된 책이 없습니다." << endl;
            return;
        }
        cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
        cout << "현재 도서 목록:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }
    void searchByTitle(const string title) {
        cout << "검색 결과 : "<<title<<endl;
        vector<Book> results;
        for (auto book : books) {
            if (book.title.find(title) != string::npos) {//npos : 값을 못찾았을때 반환값. => 검색어가 있을때
                results.push_back(book);
            }
        }

        if (results.empty()) {
            cout << "검색된 책이 없습니다." << endl;
        }
        else {
            cout << "검색된 책" << endl;
            for (auto book : results) {
                cout << "=> " << book.title << "-" << book.author << "/ 대여 가능 횟수:  "<< borrowmanager->getCount(book.title) << endl;
            }
        }
    }
    void searchByAuthor(const string author) {
        cout << "검색할 저자 : "<< author << endl;
        vector<Book> results;
        for (auto book : books) {
            if (book.author.find(author) != string::npos) {//npos : 값을 못찾았을때 반환값. => 검색어가 있을때
                results.push_back(book);
            }
        }

        if (results.empty()) {
            cout << "검색된 책이 없습니다." << endl;
        }
        else {
            cout << "검색된 책" << endl;
            for (auto book : results) {
                cout << "=> " << book.title << "-" << book.author << "/ 대여 가능 횟수:  " << borrowmanager->getCount(book.title)<<endl;
            }
        }

    }


};


int main() {
    
    BorrowManager borrowmanager;
    BookManager manager(&borrowmanager);
    // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
    // 프로그램 종료를 선택하기 전까지 계속 동작합니다.

    manager.addBook("예시책1", "예시저자1");
    manager.addBook("예시책2", "예시저자2");
    manager.addBook("예시책3", "예시저자3");
    manager.addBook("예시북1", "예시저자1");
    manager.addBook("예시북2", "예시저자2");
    manager.addBook("예시북3", "예시저자3");

    while (true) {
        cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl; // 책 정보를 입력받아 책 목록에 추가
        cout << "2. 모든 책 출력" << endl; // 현재 책 목록에 있는 모든 책 출력
        cout << "3. 책 검색" << endl;
        cout << "4. 책 대여" << endl;
        cout << "5. 책 반납" << endl;
        cout << "6. 책 재고 현황" << endl;
        cout << "7. 종료" << endl; // 프로그램 종료
        cout << "선택: ";

        int choice; // 사용자의 메뉴 선택을 저장
        cin >> choice;
        string title, author;
        if (choice == 1) {
            // 1번 선택: 책 추가
            // 사용자로부터 책 제목과 저자명을 입력받아 BookManager에 추가합니다.
            cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
            cout << "책 추가하기" << endl;
            cout << "책 제목: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, title); // 제목 입력 (공백 포함)
            cout << "책 저자: ";
            getline(cin, author); // 저자명 입력 (공백 포함)
            manager.addBook(title, author); // 입력받은 책 정보를 추가
        }
        else if (choice == 2) {
            // 2번 선택: 모든 책 출력
            // 현재 BookManager에 저장된 책 목록을 출력합니다.
            manager.displayAllBooks();
        }
        else if (choice == 3) {
            // 3번 선택: 검색
            // 책 제목으로 검색 or 저자로 검색
            cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
            cout << "어떤 방식으로 검색할까요?" << endl;
            cout << "1. 책 제목"<< endl;
            cout << "2. 책 저자" << endl;
            cout << "선택 : " << endl;
            int choice2 = 0;
            cin >> choice2;
            if (choice2 == 1) {
                cout << "검색할 책 이름 : " ;
                cin.ignore();
                getline(cin,title);
                manager.searchByTitle(title);
            }
            else if(choice2 == 2) {
                cout << "검색할 저자 이름 : ";
                cin.ignore();
                getline(cin, author);
                manager.searchByAuthor(author);
            }
        }
        else if (choice == 4) {
            // 4번 선택 : 책 대여
            cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
            cout << "대여할 책 이름: ";
            cin.ignore();
            getline(cin, title);
            borrowmanager.borrowBook(title);

        }

        else if (choice == 5) {
            // 5번 선택 : 책 반납
            cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
            cout << "반납할 책 이름: ";
            cin.ignore();
            getline(cin, title);
            borrowmanager.returnBook(title);

        }
        else if (choice == 6) {
            // 6번 선택 : 책 재고 확인
            cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
            borrowmanager.displayStock();
        }

        else if (choice == 7) {
            // 3번 선택: 종료
            // 프로그램을 종료하고 사용자에게 메시지를 출력합니다.
            cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
            cout << "프로그램을 종료합니다." << endl;
            break; // while 루프 종료
        }
        else {
            // 잘못된 입력 처리
            // 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
            cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0; // 프로그램 정상 종료
}
