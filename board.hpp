#ifndef BOARD_HPP
#define BOARD_HPP

#include <map>
#include <set>
#include <utility>
#include "tile.hpp"
#include "intersection.hpp"
#include "edge.hpp"


namespace ariel {
    
    class Board 
    {
        private:
            map<pair<int, int>, Tile> tiles;            // Map of tiles by their coordinates
            map<int, std::set<int>> settlements;        // Tracks settlements at vertices by player ID
            map<Edge, int> roads;                       // Tracks roads along edges by player ID
            // map<int, Intersection> intersections;       // Map of all valid intersections

        public:

            // Constructor and setup
            Board();
            void setupTiles();
            void linkTilesAndIntersections(); 

            // Setup methods for GUI
            // void loadResources();
            // void draw(sf::RenderWindow& window);

            // Utility methods
            const Tile& getTile(const pair<int, int>& position) const;
            void printBoard() const;
            void printBoardByTiles() const;
            string tileString(const std::pair<int, int>& position) const;
            void addTile(const pair<int, int>& position, const Tile& tile);
            bool isTileAvailable(const pair<int, int>& position) const;

            // Settlement and road management
            bool canPlaceSettlement(int intersectionID, int playerID);
            void placeSettlement(int intersectionID, int playerID);
            bool canPlaceRoad(const Edge& edge, int playerID);
            void placeRoad(const Edge& edge, int playerID);

            // Get intersection by ID
            // Intersection getIntersection(int intersectionID) const;
            int getIntersectionID(const Intersection& intersection) const;

           
    };
}

#endif