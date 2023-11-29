// MyHangman.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <math.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <typeinfo>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
//#include <cstdlib>
#include <ctype.h>
#include <fstream>
#include <map>
#include <vector>


using namespace std;

class Hangman
{
private:
    vector<string> _words;;
    map<string, vector<string>> _topics;
public:
    Hangman() {};
    Hangman(const string& Topics, const string& Words)
    {
        ifstream inT(Topics + ".txt");
        ifstream inW(Words + ".txt");
        string Topic;
        if (inT.is_open())
        {
            while (getline(inT, Topic))
            {
                if (inW.is_open()) {
                    for (auto item : _words) {
                        while (getline(inW, item))
                        {
                            _words.push_back(item);
                        }
                    }
                }
                _topics.insert(pair<string, vector<string>>(Topic, _words));
            }
        }
        inT.close();
        inW.close();
    };

 /*   bool TopicCheck(const string& Topic)
    {
	    for(auto item : _topics)
	    {
            if (item.first == Topic) return 1;
	    }
        return 0;
    }*/

    bool CharCheck(const char& Letter)
    {
	    for(auto item : _topics)
	    {
		    for(auto item2 : item.second)
		    {
                for (int i = 0; i < item2.length(); i++)
                {
                    if (item2[i] == Letter)
                    {
                        return 1;
                    }
                }
		    }
	    }
        return 0;
    }

    bool WordCheck(const string& Word)
    {
        for (auto item : _topics)
        {
            for (auto item2 : item.second)
            {
                if (item2 == Word) return 1;
                return 0;
            }
        }
    }

};
int main()
{
    setlocale(LC_ALL, "RUS");

    bool choice;
    string tempchoice;
    string topics[5]{ "Animals", "People", "Food", "Transport", "Globe" };


    cout << "\t\t\t\tДобро пожаловать в игру \"Висилица\"\n";
    cout << "\t\t\t\t1-Начало игры, 0-Выход\n";
    cin >> choice;

    if (choice == true)
    {

        string topic;
        cout << "Выберите одну из тем\n";
        for (int i = 0; i < topics->length(); i++)
        {
            cout << topics[i]<<endl;
        }
        cin >> tempchoice;
        for (int i = 0; i < topics->length(); i++)
        {
            if (tempchoice == topics[i])
            {
                Hangman player(tempchoice, tempchoice + "Слова");
                cout << "У Вас 20 попыток\n";
                int count = 20;
                do
                {
                    cout << "Введите букву\n";
                    char letter;
                    string Word;

                    cin >> letter;
                    Word += letter + ",";
                    for (int i = 0; i < Word.length(); i++)
                    {
                        if (Word[i] != letter)
                        {
                            count--;
                            if(player.CharCheck(letter))
                            {
                                cout << "Ваша буква" << letter << "есть в слове\n";
                                count--;
                            }else
                            {
                                cout << "Вашей буквы" << letter << " нет в слове\n";
                                count--;
                            }

                            if(player.WordCheck(Word))
                            {
                                cout << "Вы угадали слова\n";
                                cout << "Попытки:" << count << endl;
                                system("Pause");
                            }
                        }
                    }

                } while (count != 0);

            }
        }
    }
}
