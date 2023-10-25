#include <iostream>
#include <vector>

static char colorInvert(char c)
{
    return c == 'W' ? 'B' : 'W';
}

static std::vector<int> process(std::string& blocks, char pat, std::vector<int>& poses)
{
    int i = 0;
    while (i < blocks.size() - 1) {
        if (blocks[i] != pat && blocks[i + 1] != pat) {
            blocks[i] = colorInvert(blocks[i]);
            blocks[i + 1] = colorInvert(blocks[i + 1]);
            poses.push_back(i + 1);
            i += 2;
        }
        else if (blocks[i] != pat && blocks[i + 1] == pat) {
            blocks[i] = colorInvert(blocks[i]);
            blocks[i + 1] = colorInvert(blocks[i + 1]);
            poses.push_back(i + 1);
            ++i;
        }
        else {
            ++i;
        }
    }

    return poses;
}

static std::vector<int> blocksProcess(std::string& blocks)
{
    char pat = blocks[0];
    std::vector<int> poses;

    process(blocks, blocks[0], poses);

    if (blocks.back() != pat || blocks.size() < 2) {
        pat = colorInvert(pat);
        process(blocks, pat, poses);
    }

    if (blocks.back() != pat || blocks.size() < 2)
        return std::vector{-1};

    return poses;
}

int main()
{
    int nBlocks = 0;
    std::cin >> nBlocks;

    std::string blocks;
    std::cin >> blocks;

    std::vector<int> poses = blocksProcess(blocks);

    if (!(poses.size() == 1 && poses[0] == -1))
        std::cout << poses.size() << '\n';
    for (const auto& p : poses)
        std::cout << p << " ";
    std::cout << std::endl;

    return 0;
}
