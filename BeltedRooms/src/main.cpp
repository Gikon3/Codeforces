#include <iostream>

#define MEMORY_UNUSE    1

#if MEMORY_UNUSE == 1
static long long numberRooms(int nChars)
{
    long long count = 0;
    bool right = true;
    bool left = true;
    char prev = '\0';
    char first = '\0';
    for (int i = 0; i < nChars; ++i) {
        const char c = std::getchar();
        if (i == 0)
            first = c;
        switch (c) {
            case '-':
                if (prev == '-')
                    ++count;
                else
                    count += 2;
                break;
            case '>':
                left = false;
                break;
            case '<':
                right = false;
                break;
        }
        prev = c;
    }

    const char last = prev;

    if (first == '-' && last == '-')
        --count;

    if (left || right || count > nChars)
        count = nChars;

    return count;
}
#else
static long long numberRooms(const std::string& str)
{
    long long count = 0;
    bool right = true;
    bool left = true;
    char prev = '\0';
    for (char c : str) {
        switch (c) {
            case '-':
                if (prev == '-')
                    ++count;
                else
                    count += 2;
                break;
            case '>':
                left = false;
                break;
            case '<':
                right = false;
                break;
        }
        prev = c;
    }

    if (str.front() == '-' && str.back() == '-')
        --count;

    if (left || right || count > str.size())
        count = str.size();

    return count;
}
#endif

int main()
{
    int nTests = 0;
    std::cin >> nTests;
    for (int i = 0; i < nTests; ++i) {
        int nChars = 0;
        std::cin >> nChars;
#if MEMORY_UNUSE == 1
        char _ = std::getchar();
        std::cout << numberRooms(nChars) << std::endl;
#else
        std::string str;
        std::cin >> str;
        std::cout << numberRooms(str) << std::endl;
#endif
    }
}