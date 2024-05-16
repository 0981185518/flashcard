#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
#include <ctime>

class FlashCard 
{
private:
    std::map<std::string, std::string> cardDeck;

public:
    void addCard(const std::string& front, const std::string& back) 
	{
        cardDeck[front] = back;
    }

    void removeCard(const std::string& front) 
	{
        cardDeck.erase(front);
    }

    void study() 
	{
        if (cardDeck.empty()) 
		{
            std::cout << "Khong co flash card nao trong bo suu tap.\n";
            return;
        }

        srand(static_cast<unsigned int>(time(nullptr)));
        for (const auto& card : cardDeck) 
		{
            std::cout << "Mat truoc cua card: " << card.first << "\n";
            std::cout << "Nhan Enter de xem mat sau...";
            std::cin.get();
            std::cout << "Mat sau cua card: " << card.second << "\n\n";
        }
    }

    void quiz() 
	{
        if (cardDeck.empty()) 
		{
            std::cout << "Khong co flash card nao de kiem tra.\n";
            return;
        }

        srand(static_cast<unsigned int>(time(nullptr)));
        auto it = cardDeck.begin();
        std::advance(it, rand() % cardDeck.size());

        std::string answer;
        std::cout << "Cau hoi: " << it->first << "\n";
        std::cout << "Cau tra loi cua ban: ";
        std::getline(std::cin, answer);

        if (answer == it->second) 
		{
            std::cout << "Chinh xac!\n";
        } 
		else 
		{
            std::cout << "Sai roi! Cau tra loi dung la: " << it->second << "\n";
        }
    }
};

int main() 
{
    FlashCard myFlashCards;
    myFlashCards.addCard("C++", "Mot ngon ngu lap trinh");
    myFlashCards.addCard("Polymorphism", "Kha nang mot doi tuong co the co nhieu hinh thuc");

    char option;
    do {
        std::cout << "Chon chuc nang: (1) Hoc, (2) Kiem tra, (3) Thoat: ";
        std::cin >> option;
        std::cin.ignore();

        switch (option) 
		{
            case '1':
                myFlashCards.study();
                break;
            case '2':
                myFlashCards.quiz();
                break;
            case '3':
                std::cout << "Thoat chuong trinh.\n";
                break;
            default:
                std::cout << "Lua chon khong hop le.\n";
                break;
        }
    } while (option != '3');

    return 0;
}