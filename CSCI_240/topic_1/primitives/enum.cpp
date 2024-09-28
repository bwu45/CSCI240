#include <iostream>

//typedef unsigned long long size_t

enum class GameLevel
{
    LEVEL_ONE, // 0
    LEVEL_TWO, // 1
    GAME_OVER  // 2
};

enum class GameState
{
    IN_PLAY,
    WOUNDED,
    GAME_OVER
};

int main(int argc, char const *argv[])
{
    GameLevel gameLevel{GameLevel::GAME_OVER};

    int partingGifts[]{50, 100, 200};

    if (gameLevel == GameLevel::GAME_OVER)
        std::cout << partingGifts[static_cast<unsigned int>(gameLevel)] << std::endl;

    return 0;
}
