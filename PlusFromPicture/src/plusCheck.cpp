#include "plusCheck.h"

#define CHAR    '*'

enum class State
{
    IDLE,
    UP,
    MIDDLE,
    DOWN,
    FINISH,
};

static int countEmpty(const std::vector<char>& r, int start)
{
    int count = 0;
    for (int i = start; i < r.size() && r[i] != CHAR; ++i, ++count);
    return count;
}

static int countPlus(const std::vector<char>& r, int start)
{
    int count = 0;
    for (int i = start; i < r.size() && r[i] == CHAR; ++i, ++count);
    return count;
}

bool plusCheck(const std::vector<std::vector<char>>& m)
{
    State state = State::IDLE;
    int center = -1;
    for (const auto& row : m) {
        switch (state) {
            case State::IDLE: {
                int nEmpty = countEmpty(row, 0);
                int pos = nEmpty;
                if (pos < row.size()) {
                    center = pos;
                    int nPlus = countPlus(row, pos);
                    pos += nPlus;
                    if (nPlus > 1)
                        return false;
                    nEmpty += countEmpty(row, pos);
                    if ((nEmpty + nPlus) != row.size())
                        return false;
                    state = State::UP;
                }
                break;
            }
            case State::UP: {
                int nEmpty = countEmpty(row, 0);
                int pos = nEmpty;
                int nPlus = countPlus(row, pos);
                if (nPlus == 0)
                    return false;
                if (nPlus > 1 && pos == center)
                    return false;
                pos += nPlus;
                if (nPlus > 1 && pos == (center + 1))
                    return false;
                nEmpty += countEmpty(row, pos);
                if ((nEmpty + nPlus) != row.size())
                    return false;
                if (nPlus > 1)
                    state = State::MIDDLE;
                break;
            }
            case State::MIDDLE: {
                int nEmpty = countEmpty(row, 0);
                int pos = nEmpty;
                if (pos != center)
                    return false;
                int nPlus = countPlus(row, pos);
                if (nPlus != 1)
                    return false;
                pos += nPlus;
                nEmpty += countEmpty(row, pos);
                if ((nEmpty + nPlus) != row.size())
                    return false;
                state = State::DOWN;
            }
            case State::DOWN: {
                int nEmpty = countEmpty(row, 0);
                int pos = nEmpty;
                int nPlus = countPlus(row, pos);
                if (nPlus > 1)
                    return false;
                if (nPlus == 1 && pos != center)
                    return false;
                pos += nPlus;
                nEmpty += countEmpty(row, pos);
                if ((nEmpty + nPlus) != row.size())
                    return false;
                if (nPlus == 0)
                    state = State::FINISH;
                break;
            }
            case State::FINISH: {
                int nEmpty = countEmpty(row, 0);
                if (nEmpty != row.size())
                    return false;
                break;
            }
        }
    }

    return state == State::DOWN || state == State::FINISH;
}
