//
// Created by zakrent on 4/21/17.
//

#ifndef SDL_TILE_2_PATHSYSTEM_H
#define SDL_TILE_2_PATHSYSTEM_H

#include "System.h"
#include "../../map/Map.h"

namespace Entity {

    struct Node{
        Map::Tile* tile;
        int GCost;
        int HCost;
        Node* originateFrom;
        int getFCost() {return GCost*Map::TILE_HEIGHT+HCost;}
        Node(int GCost, Vector2D targetPositionVector, Map::Tile *tile, Node *originateFrom = nullptr) : GCost(GCost), tile(tile), originateFrom(originateFrom) {
            HCost = std::abs(int(tile->getPosition().x-targetPositionVector.x)) + std::abs(int(tile->getPosition().y-targetPositionVector.y));
        }
    };

    inline bool isNodeFSmaller(std::pair<const Vector2D, Node> node1, std::pair<const Vector2D, Node> node2){
        if(node1.second.getFCost() == node2.second.getFCost())
            return node1.second.getFCost() < node2.second.getFCost();
        return node1.second.HCost <= node2.second.HCost;
    }

    class PathSystem : public System {
    public:
        void updateEntity(Entity *entityPointer);

        Map::Map *mainMap;

        PathSystem(Map::Map *mainMap) : mainMap(mainMap) {
            System::name = "PathSystem";
        };

        ~PathSystem() {};
    };
}


#endif //SDL_TILE_2_PATHSYSTEM_H
