#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

const int N_max = 5240; //2000 для первого, 5240 для 2-3
const int alph = 26; //английский алфавит


bool isPalindrome(const std::string& word)
{
	int len = word.length();
	for (int i = 0; i < len/2; i++)
	{
		if (word[i] != word[len - i - 1])
		{
			return false;
		}
	}
	return true;
}

/*

//========================= 1 =========================

int main ()
{
	std::ifstream input("input.txt"); //Открыли файл и проверили, открыт ли он
	if (!input.is_open())
	{
		std::cerr << "File is not open!" << std::endl;
		return -1;
	}
	else std::cout << "*File is open*" << std::endl; //Отладка

	std::string words[N_max];
	int cnt = 0;

	while (!input.eof() && cnt < N_max)
	{	
		
		input >> words[cnt];
		cnt++;
		if (cnt > 2000)
		{
			std::cerr << "The word limit has been exceeded" << std::endl;
			return 0;
		}


		int countLetters[N_max] = {0};

		for(int i=0;i<cnt;i++)
		{
			char letters[256] = {0};
			for(int j=0;j<words[i].length();j++)
			{
				letters[words[i][j]]++;
			}

			int max = INT_MIN;
			for(int k=0;k<256;k++)
				if(letters[k] > max)
					max = letters[k];
			countLetters[i] = max;
		}


		std::ofstream output("output.txt");
		for (int i=0; i<cnt-1; i++)
		{
			for (int j=i+1; j<cnt; j++)
			{
				if (words[i] == words[j])
				{
					words[j].clear();
					countLetters[j]=0;
					continue;
				}

				if (countLetters[i] < countLetters[j])
				{
					std::swap(words[i], words[j]);
					std::swap(countLetters[i], countLetters[j]);
				}

			}

			if (countLetters[i] != 0)
				output << words[i] << "---"  << countLetters[i]<< std::endl;
		}
	}

	return 0;
}

*/





/*

//========================= 2 =========================

int main ()
{
	std::ifstream input("input.txt"); //Открыли файл и проверили, открыт ли он
	if (!input.is_open())
	{
		std::cerr << "File is not open!" << std::endl;
		return -1;
	}
	else std::cout << "*File is open*" << std::endl; //Отладка

	std::string words[N_max];
	int cnt = 0;

	while (!input.eof() && cnt < N_max)
	{	
		
		input >> words[cnt];
		cnt++;
		if (cnt > N_max)
		{
			std::cerr << "The word limit has been exceeded" << std::endl;
			return 0;
		}
		for (int i = 0; i < cnt; i++) //Пробегаем по словам
		{
			for (int j = 0; j<words[i].length(); j++) //Пробегаем по символам в слове
			{
				if(!isalpha(words[i][j]))
				{
					words[i].erase(j, 1);
					j--;
												//Итог: если j-ый символ i-го слова не является буквой, то этот j-ый символ удаляется (1 шт.) 
				}
				else // Приводим буквы к нижнему регистру
            	{
                	words[i][j] = tolower(words[i][j]);
            	}
			}
		}
	}
	
	bool PalindromeExist = false;
	for (int i = 0; i < cnt; i++)
	{
		if (words[i].length() > 1 && isPalindrome(words[i]))
		{
			PalindromeExist = true;
			std::cout << words[i] << std::endl;
			break;
		}
	}

	int cntCons[N_max] = {0};
	if (!PalindromeExist)
	{
		std::string consonant = "bcdfghjklmnpqrstvwxz";
		for (int i = 0; i < cnt; i++) //Пробегаем по словам
		{
			int cntC = 0;
			for (int j = 0; j<words[i].length(); j++) //Пробегаем по символам в слове
			{
				if (consonant.find(words[i][j]) != std::string::npos)
				{
					cntC++;
				}
				cntCons[i] = cntC;
			}

			std::cout << words[i] << "---" << cntCons[i] << std::endl; //Отдладочный вывод
		}

		for (int i1 = 0; i1 < cnt-1; i1++)
		{
			for (int i2 = i1+1; i2<cnt; i2++)
			{
				if (cntCons[i1] < cntCons[i2])
				{
					std::swap(words[i1],words[i2]);
					std::swap(cntCons[i1],cntCons[i2]);
				}
			}
		}
	}
	else
	{
		std::string Vowels = "aeiouy";
		for (int i = 0; i < cnt; i++) //Пробегаем по словам
		{
			for (int j = 0; j<words[i].length(); j++) //Пробегаем по символам в слове
			{
				if (Vowels.find(words[i][j]) != std::string::npos)
				{
					words[i].insert(j + 1, 1, words[i][j]);
					j++;
				}
			}
		}
		for (int i1 = 0; i1 < cnt-1; i1++)
		{
			for (int i2 = i1+1; i2<cnt; i2++)
			{
				if (words[i1] < words[i2])
				{
					std::swap(words[i1],words[i2]);
				}
			}
		}
	}

	for (int i = 0; i < cnt; i++)
		{
			std::cout << words[i] << std::endl;
		}
	return 0;
}

*/





/*

//========================= 3 =========================

int main()
{

	std::ifstream input("input.txt"); //Открыли файл и проверили, открыт ли он
	if (!input.is_open())
	{
		std::cerr << "File is not open!" << std::endl;
		return -1;
	}
	else std::cout << "*File is open*" << std::endl; //Отладка

	std::string words[N_max]; //Массив для слов (№3 - пока здесь не нужен)
	int cnt = 0;
	int cntL[alph] = {0};	//массив для исследования частоты букв
	char c; 	 

	while (input.get(c)) // читаем пока дают символ
	{
        if (isalpha(c))	// Проверяем, является ли символ буквой
		{ 
            c = tolower(c); // Приводим к нижнему регистру
            cntL[c - 'a']++; // Увеличиваем счетчик для буквы
        }
    }
	std::cout << "Frequency of letters:" << std::endl;
    for (int i = 0; i < alph; i++)
	{
        std::cout << char('a' + i) << ": " << cntL[i] << std::endl; // Печатаем буквы и их частоту
    }

	// Находим 5 самых частых букв
    char topLetters[5] = {0};
    for (int i = 0; i < 5; i++)
	{
        int maxIndex = -1;
        int maxCount = -1;
        for (int j = 0; j < alph; j++)
		{
            if (cntL[j] > maxCount)
			{
                maxCount = cntL[j];
                maxIndex = j;
            }
        }
        if (maxIndex != -1)
		{
            topLetters[i] = 'a' + maxIndex;
            cntL[maxIndex] = -1; // Убираем эту букву из дальнейшего поиска
        }
    }

	input.clear(); // Это сброс, нужно для повторного считывания файла
    input.seekg(0); // Вернуться в начало

	while (!input.eof() && cnt < N_max)
	{
        input >> words[cnt];
        cnt++;
	}
		std::ofstream output("output.txt");
		for (int i = 0; i < cnt; i++) //Пробегаем по словам
		{
			int topletterCount = 0;
			std::string foundLetters;
			for (int j = 0; j<words[i].length(); j++) //Пробегаем по символам в слове
			{
				char currentChar = tolower(words[i][j]);
				// Проверяем наличие текущего символа в topLetters
				for (int k = 0; k < 5; k++) // Проходим по topLetters
				{
					if (currentChar == topLetters[k])
					{
						topletterCount++;
						if (foundLetters.find(currentChar) == std::string::npos)
						{
                        	foundLetters += currentChar;
						}
						break; // Если нашли букву, выходим из внутреннего цикла
					}
				}
        	}

			if (topletterCount >= 4)
			{
				// Преобразование слова в верхний регистр
				for (int j = 0; j < words[i].length(); j++)
				{
					words[i][j] = toupper(words[i][j]);
				}
				output << words[i] << "(" << foundLetters << ")" << " "; // Отладка: вывод найденного слова
			}
			else
			{
            	output << words[i] << " ";
        	}
		
		}

	return 0;
}

*/