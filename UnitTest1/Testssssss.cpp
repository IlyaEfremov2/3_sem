#include <gtest/gtest.h>
#include "MusicWork.h"
#include "MusicCollection.h"
#include "MusicStorage.h"
#include "MusicStore.h"
#include <memory>

using namespace std;

TEST(MusicWorkTest, BasicCreation) {
    MusicWork work("Соната", "Моцарт", "Классика", 1785, "Сонаты", 850.0);
    EXPECT_EQ(work.getTitle(), "Соната");
    EXPECT_EQ(work.getComposer(), "Моцарт");
    EXPECT_EQ(work.getGenre(), "Классика");
    EXPECT_EQ(work.getYear(), 1785);
    EXPECT_EQ(work.getAlbum(), "Сонаты");
    EXPECT_DOUBLE_EQ(work.getPrice(), 850.0);
}

TEST(MusicWorkTest, GetInfoContainsData) {
    MusicWork work("Концерт", "Чайковский", "Романтизм", 1878, "Концерты", 1200.0);
    string info = work.getInfo();
    EXPECT_TRUE(info.find("Концерт") != string::npos);
    EXPECT_TRUE(info.find("Чайковский") != string::npos);
    EXPECT_TRUE(info.find("Романтизм") != string::npos);
    EXPECT_TRUE(info.find("1878") != string::npos);
    EXPECT_TRUE(info.find("1200") != string::npos);
}

TEST(MusicWorkTest, InheritanceWorks) {
    class ExtendedMusic : public MusicWork {
        string edition;
    public:
        ExtendedMusic(string t, string c, string g, int y, string a, double p, string e)
            : MusicWork(t, c, g, y, a, p), edition(e) {}

        string getInfo() const override {
            return MusicWork::getInfo() + ", Издание: " + edition;
        }
    };

    ExtendedMusic ext("Сюита", "Бах", "Барокко", 1720, "Сюиты", 950.0, "Golden Edition");
    EXPECT_TRUE(ext.getInfo().find("Golden Edition") != string::npos);
}

TEST(MusicStorageTest, StorageCreation) {
    MusicStorage storage("Vinyl", "Секция B", 8);
    EXPECT_EQ(storage.getMediaType(), "Vinyl");
    EXPECT_EQ(storage.getLocation(), "Секция B");
    EXPECT_EQ(storage.getQuantity(), 8);
}

TEST(MusicStorageTest, StorageInfo) {
    MusicStorage storage("CD", "Стеллаж 3", 15);
    string info = storage.getInfo();
    EXPECT_TRUE(info.find("CD") != string::npos);
    EXPECT_TRUE(info.find("Стеллаж 3") != string::npos);
    EXPECT_TRUE(info.find("15") != string::npos);
}

TEST(MusicCollectionTest, CreateWithWork) {
    auto work = make_shared<MusicWork>("Балет", "Чайковский", "Классика", 1890, "Балеты", 1100.0);
    MusicCollection collection(work);
    EXPECT_EQ(collection.getWork(), work);
}

TEST(MusicCollectionTest, AddAndGetStorages) {
    auto work = make_shared<MusicWork>("Опера", "Верди", "Опера", 1850, "Оперы", 1300.0);
    MusicCollection collection(work);

    collection.addStorage(MusicStorage("CD", "A1", 10));
    collection.addStorage(MusicStorage("Digital", "Онлайн", 50));

    auto types = collection.getAvailableMediaTypes();
    EXPECT_EQ(types.size(), 2);
    EXPECT_EQ(types[0], "CD");
    EXPECT_EQ(types[1], "Digital");
}

TEST(MusicCollectionTest, CollectionInfo) {
    auto work = make_shared<MusicWork>("Симфония", "Брамс", "Классика", 1880, "Симфонии", 900.0);
    MusicCollection collection(work);
    collection.addStorage(MusicStorage("Vinyl", "B2", 5));

    string info = collection.getInfo();
    EXPECT_TRUE(info.find("Симфония") != string::npos);
    EXPECT_TRUE(info.find("Брамс") != string::npos);
    EXPECT_TRUE(info.find("Vinyl") != string::npos);
}

TEST(MusicStoreTest, EmptyStore) {
    MusicStore store;
    EXPECT_DOUBLE_EQ(store.getSalesForPeriod(), 0.0);
    EXPECT_TRUE(store.findWorkByTitle("Тест").empty());
}

TEST(MusicStoreTest, AddAndFindWork) {
    MusicStore store;
    auto work = make_shared<MusicWork>("Рапсодия", "Лист", "Романтизм", 1845, "Рапсодии", 800.0);
    MusicCollection collection(work);
    store.addCollection(collection);

    auto found = store.findWorkByTitle("Рапсодия");
    EXPECT_EQ(found.size(), 1);

    auto notFound = store.findWorkByTitle("Несуществующая");
    EXPECT_TRUE(notFound.empty());
}

TEST(MusicStoreTest, SearchByComposerAndGenre) {
    MusicStore store;

    auto work1 = make_shared<MusicWork>("Вальс", "Шопен", "Романтизм", 1830, "Вальсы", 750.0);
    auto work2 = make_shared<MusicWork>("Ноктюрн", "Шопен", "Романтизм", 1835, "Ноктюрны", 780.0);
    auto work3 = make_shared<MusicWork>("Марш", "Свиридов", "Современная", 1970, "Марши", 650.0);

    store.addCollection(MusicCollection(work1));
    store.addCollection(MusicCollection(work2));
    store.addCollection(MusicCollection(work3));

    EXPECT_EQ(store.findWorkByComposer("Шопен").size(), 2);
    EXPECT_EQ(store.findWorkByGenre("Романтизм").size(), 2);
    EXPECT_EQ(store.getWorksByGenre("Современная").size(), 1);
}

TEST(MusicStoreTest, GetWorkInfo) {
    MusicStore store;
    auto work = make_shared<MusicWork>("Концерт", "Рахманинов", "Романтизм", 1901, "Концерты", 1400.0);
    MusicCollection collection(work);
    collection.addStorage(MusicStorage("CD", "C3", 12));

    store.addCollection(collection);

    string info = store.getWorkInfo("Концерт");
    EXPECT_TRUE(info.find("Концерт") != string::npos);
    EXPECT_TRUE(info.find("Рахманинов") != string::npos);
    EXPECT_TRUE(info.find("CD") != string::npos);

    EXPECT_EQ(store.getWorkInfo("Нет"), "Произведение не найдено");
}

TEST(MusicStoreTest, AvailableMediaTypes) {
    MusicStore store;
    auto work = make_shared<MusicWork>("Сюита", "Григ", "Романтизм", 1888, "Сюиты", 950.0);
    MusicCollection collection(work);
    collection.addStorage(MusicStorage("CD", "D1", 8));
    collection.addStorage(MusicStorage("Vinyl", "D2", 4));

    store.addCollection(collection);

    auto media = store.getAvailableMediaTypes("Сюита");
    EXPECT_EQ(media.size(), 2);
    EXPECT_EQ(media[0], "CD");
    EXPECT_EQ(media[1], "Vinyl");

    EXPECT_TRUE(store.getAvailableMediaTypes("Нет").empty());
}

TEST(MusicStoreTest, SellWorkUpdatesSales) {
    MusicStore store;
    auto work = make_shared<MusicWork>("Симфония", "Малера", "Поздний романтизм", 1905, "Симфонии", 1600.0);
    MusicCollection collection(work);
    store.addCollection(collection);

    EXPECT_DOUBLE_EQ(store.getSalesForPeriod(), 0.0);

    store.sellWork("Симфония", "CD", 2);
    EXPECT_DOUBLE_EQ(store.getSalesForPeriod(), 3200.0);

    store.sellWork("Симфония", "Digital", 1);
    EXPECT_DOUBLE_EQ(store.getSalesForPeriod(), 4800.0);

    store.sellWork("Несуществующая", "CD", 5);
    EXPECT_DOUBLE_EQ(store.getSalesForPeriod(), 4800.0);
}

TEST(MusicStoreTest, MostSoldWorks) {
    MusicStore store;

    auto work1 = make_shared<MusicWork>("Произведение 1", "Автор", "Жанр", 2000, "Альбом", 100.0);
    auto work2 = make_shared<MusicWork>("Произведение 2", "Автор", "Жанр", 2001, "Альбом", 200.0);
    auto work3 = make_shared<MusicWork>("Произведение 3", "Автор", "Жанр", 2002, "Альбом", 300.0);

    store.addCollection(MusicCollection(work1));
    store.addCollection(MusicCollection(work2));
    store.addCollection(MusicCollection(work3));

    auto popular = store.getMostSoldWorks(2);
    EXPECT_EQ(popular.size(), 2);
    EXPECT_EQ(popular[0], "Произведение 1");
    EXPECT_EQ(popular[1], "Произведение 2");

    auto all = store.getMostSoldWorks(10);
    EXPECT_EQ(all.size(), 3);
}

TEST(MusicStoreTest, MultipleSameTitle) {
    MusicStore store;

    auto work1 = make_shared<MusicWork>("Соната", "Бетховен", "Классика", 1800, "Сонаты", 850.0);
    auto work2 = make_shared<MusicWork>("Соната", "Моцарт", "Классика", 1780, "Сонаты", 820.0);

    store.addCollection(MusicCollection(work1));
    store.addCollection(MusicCollection(work2));

    EXPECT_EQ(store.findWorkByTitle("Соната").size(), 2);
}

TEST(IntegrationTest, CompleteScenario) {
    MusicStore store;

    auto work = make_shared<MusicWork>("Кармен", "Бизе", "Опера", 1875, "Оперы", 1250.0);
    MusicCollection collection(work);
    collection.addStorage(MusicStorage("CD", "Оперы", 15));
    collection.addStorage(MusicStorage("Vinyl", "Коллекция", 8));

    store.addCollection(collection);

    EXPECT_EQ(store.findWorkByTitle("Кармен").size(), 1);
    EXPECT_EQ(store.findWorkByComposer("Бизе").size(), 1);

    auto media = store.getAvailableMediaTypes("Кармен");
    EXPECT_EQ(media.size(), 2);

    store.sellWork("Кармен", "CD", 3);
    EXPECT_DOUBLE_EQ(store.getSalesForPeriod(), 3750.0);

    store.sellWork("Кармен", "Vinyl", 2);
    EXPECT_DOUBLE_EQ(store.getSalesForPeriod(), 6250.0);

    auto popular = store.getMostSoldWorks(1);
    EXPECT_EQ(popular.size(), 1);
    EXPECT_EQ(popular[0], "Кармен");
}

TEST(IntegrationTest, UserMenuSimulation) {
    MusicStore store;

    auto work1 = make_shared<MusicWork>("Времена года", "Вивальди", "Барокко", 1725, "Концерты", 950.0);
    auto work2 = make_shared<MusicWork>("Лебединое озеро", "Чайковский", "Балет", 1877, "Балеты", 1350.0);

    MusicCollection col1(work1);
    MusicCollection col2(work2);

    col1.addStorage(MusicStorage("CD", "Классика", 20));
    col2.addStorage(MusicStorage("Digital", "Балеты", 100));

    store.addCollection(col1);
    store.addCollection(col2);

    EXPECT_EQ(store.getWorksByGenre("Барокко").size(), 1);
    EXPECT_EQ(store.getWorksByGenre("Балет").size(), 1);

    store.sellWork("Времена года", "CD", 2);
    store.sellWork("Лебединое озеро", "Digital", 3);

    EXPECT_DOUBLE_EQ(store.getSalesForPeriod(), 1900.0 + 4050.0);

    string info = store.getWorkInfo("Времена года");
    EXPECT_TRUE(info.find("Вивальди") != string::npos);
    EXPECT_TRUE(info.find("Барокко") != string::npos);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
