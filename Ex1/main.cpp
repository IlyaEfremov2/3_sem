#include <iostream>
#include <vector>
#include <memory>
#include <limits>
#include <Windows.h>
#include "../Decision3/MusicWork.h"
#include "../Decision3/MusicStorage.h"
#include "../Decision3/MusicStore.h"

using namespace std;

enum MenuOption
{
    EXIT,
    SHOW_ALL_WORKS,
    SEARCH_BY_TITLE,
    SEARCH_BY_GENRE,
    SEARCH_BY_COMPOSER,
    SHOW_AVAILABLE_MEDIA,
    SELL_WORK,
    SHOW_TOTAL_SALES,
    SHOW_POPULAR_WORKS,
    DEMONSTRATE_POLYMORPHISM
};


string inputString();
double inputDouble();
void clearInputBuffer();
void displayMenu();
void initializeTestData(MusicStore& musicStore);
void displayAllWorks(const MusicStore& musicStore);
void searchByTitle(const MusicStore& musicStore);
void searchByGenre(const MusicStore& musicStore);
void searchByComposer(const MusicStore& musicStore);
void showAvailableMedia(const MusicStore& musicStore);
void sellWork(MusicStore& musicStore);
void showTotalSales(const MusicStore& musicStore);
void showPopularWorks(const MusicStore& musicStore);
void demonstratePolymorphism();

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    MusicStore musicStore;
    initializeTestData(musicStore);

    cout << "ДОБРО ПОЖАЛОВАТЬ В МАГАЗИН МУЗЫКАЛЬНЫХ ПРОИЗВЕДЕНИЙ!" << endl;
    cout << "База данных инициализирована тестовыми данными." << endl;

    int choice;
    bool running = true;

    while (running) {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case SHOW_ALL_WORKS:
            displayAllWorks(musicStore);
            break;
        case SEARCH_BY_TITLE:
            searchByTitle(musicStore);
            break;
        case SEARCH_BY_GENRE:
            searchByGenre(musicStore);
            break;
        case SEARCH_BY_COMPOSER:
            searchByComposer(musicStore);
            break;
        case SHOW_AVAILABLE_MEDIA:
            showAvailableMedia(musicStore);
            break;
        case SELL_WORK:
            sellWork(musicStore);
            break;
        case SHOW_TOTAL_SALES:
            showTotalSales(musicStore);
            break;
        case SHOW_POPULAR_WORKS:
            showPopularWorks(musicStore);
            break;
        case DEMONSTRATE_POLYMORPHISM:
            demonstratePolymorphism();
            break;
        case EXIT:
            running = false;
            cout << "Спасибо за использование магазина! До свидания!" << endl;
            break;
        default:
            cout << "Ошибка: неверный выбор! Попробуйте снова." << endl;
            clearInputBuffer();
            break;
        }
    }

    return 0;
}

string inputString() {
    string input;
    clearInputBuffer();
    getline(cin, input);
    return input;
}

double inputDouble() {
    double value = 0.0;
    cin >> value;

    if (cin.fail()) {
        cin.clear();
        clearInputBuffer();
        cout << "Ошибка: введите корректное число: ";
        cin >> value;
    }

    clearInputBuffer();
    return value;
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(10000, '\n');
}

void displayMenu() {
    cout << "\nМАГАЗИН МУЗЫКАЛЬНЫХ ПРОИЗВЕДЕНИЙ - ГЛАВНОЕ МЕНЮ" << endl;
    cout << EXIT << ". Выход" << endl;
    cout << SHOW_ALL_WORKS << ". Показать все произведения" << endl;
    cout << SEARCH_BY_TITLE << ". Найти произведение по названию" << endl;
    cout << SEARCH_BY_GENRE << ". Найти произведения по жанру" << endl;
    cout << SEARCH_BY_COMPOSER << ". Найти произведения по композитору" << endl;
    cout << SHOW_AVAILABLE_MEDIA << ". Показать доступные носители для произведения" << endl;
    cout << SELL_WORK << ". Продать произведение" << endl;
    cout << SHOW_TOTAL_SALES << ". Показать общие продажи" << endl;
    cout << SHOW_POPULAR_WORKS << ". Показать популярные произведения" << endl;
    cout << DEMONSTRATE_POLYMORPHISM << ". Демонстрация полиморфизма" << endl;
    cout << "Выберите опцию: ";
}

void initializeTestData(MusicStore& musicStore) {
    auto work1 = make_shared<MusicWork>("Симфония №5", "Бетховен", "Классика",
        1808, "Симфонии Бетховена", 999.99);

    auto work2 = make_shared<MusicWork>("Лунная соната", "Бетховен", "Классика",
        1801, "Сонаты для фортепиано", 799.99);

    auto work3 = make_shared<MusicWork>("Времена года", "Вивальди", "Барокко",
        1723, "Концерты для скрипки", 899.99);

    auto work4 = make_shared<MusicWork>("Кармен", "Бизе", "Опера",
        1875, "Опера в четырех актах", 1299.99);

    auto work5 = make_shared<MusicWork>("Болеро", "Равель", "Балет",
        1928, "Одночастное оркестровое произведение", 1099.99);

    MusicStorage storage1("CD", "Секция A, полка 1", 10);
    MusicStorage storage2("Vinyl", "Секция B, полка 3", 5);
    MusicStorage storage3("Digital", "Онлайн магазин", 100);
    MusicStorage storage4("Cassette", "Секция C, полка 2", 3);

    MusicItem item1(work1);
    item1.addStorage(storage1);
    item1.addStorage(storage2);
    item1.addStorage(storage4);

    MusicItem item2(work2);
    item2.addStorage(storage1);
    item2.addStorage(storage3);

    MusicItem item3(work3);
    item3.addStorage(storage2);
    item3.addStorage(storage3);

    MusicItem item4(work4);
    item4.addStorage(storage1);
    item4.addStorage(storage2);
    item4.addStorage(storage3);
    item4.addStorage(storage4);

    MusicItem item5(work5);
    item5.addStorage(storage2);
    item5.addStorage(storage4);

    musicStore.addMusicItem(item1);
    musicStore.addMusicItem(item2);
    musicStore.addMusicItem(item3);
    musicStore.addMusicItem(item4);
    musicStore.addMusicItem(item5);
}

void displayAllWorks(const MusicStore& musicStore) {
    cout << "\nВСЕ ПРОИЗВЕДЕНИЯ В МАГАЗИНЕ" << endl;

    vector<string> testTitles = { "Симфония №5", "Лунная соната", "Времена года", "Кармен", "Болеро" };

    for (const auto& title : testTitles) {
        string info = musicStore.getWorkInfo(title);
        if (info != "Произведение не найдено") {
            cout << info << endl;
        }
    }
}

void searchByTitle(const MusicStore& musicStore) {
    cout << "\nПОИСК ПРОИЗВЕДЕНИЯ ПО НАЗВАНИЮ" << endl;
    cout << "Введите название произведения: ";
    string title = inputString();

    auto works = musicStore.findWorkByTitle(title);

    if (!works.empty()) {
        cout << "\nРезультат поиска:" << endl;
        for (const auto& item : works) {
            cout << item.getInfo() << endl;
        }
    }
    else {
        cout << "Произведение с названием '" << title << "' не найдено." << endl;
    }
}

void searchByGenre(const MusicStore& musicStore) {
    cout << "\nПОИСК ПРОИЗВЕДЕНИЙ ПО ЖАНРУ" << endl;
    cout << "Доступные жанры: Классика, Барокко, Опера, Балет" << endl;
    cout << "Введите жанр: ";
    string genre = inputString();

    auto works = musicStore.getWorksByGenre(genre);

    cout << "\nНайдено произведений в жанре '" << genre << "': " << works.size() << endl;
    for (const auto& item : works) {
        auto musicWork = item.getWork();
        if (musicWork) {
            cout << musicWork->getTitle() << " (" << musicWork->getYear() << ")" << endl;
        }
    }
}

void searchByComposer(const MusicStore& musicStore) {
    cout << "\nПОИСК ПРОИЗВЕДЕНИЙ ПО КОМПОЗИТОРУ" << endl;
    cout << "Доступные композиторы: Бетховен, Вивальди, Бизе, Равель" << endl;
    cout << "Введите имя композитора: ";
    string composer = inputString();

    auto works = musicStore.findWorkByComposer(composer);

    cout << "\nНайдено произведений композитора '" << composer << "': " << works.size() << endl;
    for (const auto& item : works) {
        auto musicWork = item.getWork();
        if (musicWork) {
            cout << musicWork->getTitle() << " (" << musicWork->getYear() << ")" << endl;
        }
    }
}

void showAvailableMedia(const MusicStore& musicStore) {
    cout << "\nДОСТУПНЫЕ НОСИТЕЛИ ДЛЯ ПРОИЗВЕДЕНИЯ" << endl;
    cout << "Введите название произведения: ";
    string title = inputString();

    auto mediaTypes = musicStore.getAvailableMediaTypes(title);

    if (!mediaTypes.empty()) {
        cout << "\nДоступные носители для произведения '" << title << "':" << endl;
        for (const auto& media : mediaTypes) {
            cout << "- " << media << endl;
        }
    }
    else {
        cout << "Произведение не найдено или нет доступных носителей." << endl;
    }
}

void sellWork(MusicStore& musicStore) {
    cout << "\nПРОДАЖА ПРОИЗВЕДЕНИЯ" << endl;
    cout << "Введите название произведения: ";
    string title = inputString();

    cout << "Введите тип носителя: ";
    string mediaType = inputString();

    cout << "Введите количество: ";
    int quantity;
    cin >> quantity;
    clearInputBuffer();

    if (quantity <= 0) {
        cout << "Ошибка: введите корректное количество!" << endl;
        return;
    }

    try {
        musicStore.sellWork(title, mediaType, quantity);
        cout << "Продажа успешно завершена!" << endl;
    }
    catch (const exception& e) {
        cout << "Ошибка при продаже: " << e.what() << endl;
    }
}

void showPopularWorks(const MusicStore& musicStore) {
    cout << "\nПОПУЛЯРНЫЕ ПРОИЗВЕДЕНИЯ" << endl;
    cout << "Сколько произведений показать? ";
    int count;
    cin >> count;
    clearInputBuffer();

    if (count <= 0) {
        cout << "Ошибка: введите корректное число!" << endl;
        return;
    }

    auto popularWorks = musicStore.getMostSoldWorks(count);

    cout << "\nСамые популярные произведения:" << endl;
    for (size_t i = 0; i < popularWorks.size(); i++) {
        cout << i + 1 << ". " << popularWorks[i] << endl;
    }
}

void showTotalSales(const MusicStore& musicStore) {
    cout << "\nОБЩИЕ ПРОДАЖИ" << endl;
    cout << "Общая сумма продаж: " << musicStore.getSalesForPeriod() << " руб." << endl;
}

void demonstratePolymorphism() {
    cout << "\n=== ДЕМОНСТРАЦИЯ ПОЛИМОРФИЗМА ===" << endl;

    vector<shared_ptr<MusicWork>> musicWorks;

    class ClassicMusic : public MusicWork {
    private:
        string period;
    public:
        ClassicMusic(const string& title, const string& composer, const string& genre,
            int year, const string& album, double price, const string& period)
            : MusicWork(title, composer, genre, year, album, price), period(period) {}

        string getInfo() const override {
            return MusicWork::getInfo() + ", Период: " + period;
        }

        string getExtendedInfo() const {
            return MusicWork::getInfo() + ", Период: " + period;
        }
    };

    class ModernMusic : public MusicWork {
    private:
        string label;
    public:
        ModernMusic(const string& title, const string& composer, const string& genre,
            int year, const string& album, double price, const string& label)
            : MusicWork(title, composer, genre, year, album, price), label(label) {}

        string getInfo() const override {
            return MusicWork::getInfo() + ", Лейбл: " + label;
        }

        string getExtendedInfo() const {
            return MusicWork::getInfo() + ", Лейбл: " + label;
        }
    };

    musicWorks.push_back(make_shared<ClassicMusic>(
        "Симфония №9", "Бетховен", "Классика",
        1824, "Симфонии", 1299.99, "Поздний классицизм"));

    musicWorks.push_back(make_shared<ModernMusic>(
        "Thriller", "Майкл Джексон", "Поп",
        1982, "Thriller", 599.99, "Epic Records"));

    musicWorks.push_back(make_shared<ClassicMusic>(
        "Реквием", "Моцарт", "Классика",
        1791, "Реквиемы", 1499.99, "Классицизм"));

    musicWorks.push_back(make_shared<ModernMusic>(
        "Nevermind", "Nirvana", "Гранж",
        1991, "Nevermind", 799.99, "DGC Records"));

    cout << "Коллекция музыкальных произведений:" << endl;
    for (const auto& work : musicWorks) {
        cout << "• " << work->getInfo() << endl;
    }
}