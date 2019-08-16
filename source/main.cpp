#include "sfmlgraph/GameSFML.h"

int main()
{
        GameSFML g;
        try {
                g.run();
        } catch (std::exception& ex) {
                std::cout << ex.what();
        }
        return 0;
}