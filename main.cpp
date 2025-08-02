#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
using namespace std;
#include<iostream>
#include<utility>
#include<vector>

class MazeGraph
{
private:
    struct CellNode
    {
        int x, y;
        bool wall;
        bool checked;
        CellNode *parent;
        CellNode *top;
        CellNode *right;
        CellNode *bottom;
        CellNode *left;
        CellNode() : x(0), y(0), wall(false), checked(false), parent(nullptr), top(nullptr), left(nullptr),
        right(nullptr), bottom(nullptr) {}
        CellNode(const int m, const int n, const int status) : x(m), y(n), checked(false), top(nullptr), left(nullptr),
        right(nullptr), bottom(nullptr) { if (status == 1) wall = true;}
    };

    CellNode* root = nullptr;
    int value = 0;

public:


};

int main() {

    ifstream inputFile("/Users/federicocamargo/CLionProjects/Final Project/maze0_dim42.txt");

    std::vector<std::vector<int>> maze;
    std::string line;

    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        int val;
        std::vector<int> row;
        while (ss >> val) {
            row.push_back(val);
        }
        if (!row.empty()) maze.push_back(row);
    }
    inputFile.close();

    auto window = sf::RenderWindow(sf::VideoMode({850, 850}), "CMake SFML Project");
    window.setFramerateLimit(144);

    while (window.isOpen()) {
        while (const optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear(sf::Color::Yellow);

        sf::RectangleShape rect({12.f, 12.f});
        rect.setFillColor(sf::Color::White);
        rect.setOutlineThickness(1.f);
        rect.setOutlineColor(sf::Color::Black);
        rect.setPosition({50.f, 50.f});
        window.draw(rect);

        for (int i = 0; i < maze.size(); i++) {
            for (int j = 0; j < maze[0].size(); j++) {
                int x = j*10;
                int y = i*10;
                sf::RectangleShape rect({12.f, 12.f});
                if (maze[j][i] == 1) {
                    rect.setFillColor(sf::Color::Red);
                } else {
                    rect.setFillColor(sf::Color::White);
                }
                rect.setOutlineThickness(1.f);
                rect.setOutlineColor(sf::Color::Black);
                rect.setPosition({float(x), float(y)});
                window.draw(rect);
            }
        }

        window.display();
    }
}
