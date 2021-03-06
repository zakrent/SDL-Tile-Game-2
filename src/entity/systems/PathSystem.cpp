//
// Created by zakrent on 4/21/17.
//

#include "PathSystem.h"
#include <algorithm>
#include <set>
#include <unordered_map>


namespace Entity {

    class Hash{
    public:
        size_t operator()(const Vector2D &k) const{
            return size_t(k.x) * 100 + size_t(k.y);
        }
    };

    std::vector<Node> traceback(Node lastNode){
        std::vector<Node> path;
        path.push_back(lastNode);
        while(lastNode.originateFrom != NULL) {
            path.push_back(*lastNode.originateFrom);
            lastNode = *lastNode.originateFrom;
        }
        path.pop_back(); //Removes entity pos from path
        return path;
    }

    void PathSystem::updateEntity(Entity *entityPointer) {

        std::string name = "Position";
        PositionComponent *positionComponent = entityPointer->getComponent<PositionComponent>(name);
        if (!positionComponent)
            return;
        name = "Path";
        PathComponent *pathComponent = entityPointer->getComponent<PathComponent>(name);
        if (!pathComponent || !pathComponent->target)
            return;
        name = "Position";
        PositionComponent *targetPositionComponent = pathComponent->target->getComponent<PositionComponent>(name);
        if (!targetPositionComponent)
            return;


        if (!pathComponent->isOnMove) {
            std::unordered_map<Vector2D, Node, Hash> openSet;
            std::unordered_map<Vector2D, Node, Hash> closedSet;
            std::vector<Node> path;

            Vector2D targetPositionVector = mainMap->getTileAtPxPos(targetPositionComponent->position)->getPosition();

            Vector2D position = mainMap->getTileAtPxPos(positionComponent->position)->getPosition();
            openSet.insert(std::make_pair(position, Node(0, targetPositionVector,
                                                         mainMap->getTileAtPxPos(positionComponent->position),
                                                         nullptr)));

            while (!openSet.empty()) {
                std::unordered_map<Vector2D, Node, Hash>::iterator nextNodeIt = std::min_element(openSet.begin(),
                                                                                                 openSet.end(),
                                                                                                 isNodeFSmaller);
                Node nextNode = nextNodeIt->second;
                closedSet.insert(*nextNodeIt);
                openSet.erase(nextNodeIt);

                if (nextNode.tile->getPosition() == targetPositionVector) {
                    path = traceback(nextNode);
                    break;
                }

                for (std::pair<const Map::direction, Map::Tile *> &tilePair : nextNode.tile->neighbours) {
                    Map::Tile *tile = tilePair.second;
                    if (tile == nullptr)
                        continue;
                    if (closedSet.find(tile->getPosition()) != closedSet.end() || tile->isSolid())
                        continue;
                    if (openSet.find(tile->getPosition()) == openSet.end() ||
                        nextNode.GCost < openSet.find(tile->getPosition())->second.GCost) {
                        if (openSet.find(tile->getPosition()) == openSet.end()) {
                            openSet.insert(std::make_pair(tile->getPosition(),
                                                          Node(nextNode.GCost + 1, targetPositionVector, tile,
                                                               &closedSet.at(nextNode.tile->getPosition()))));
                        } else {
                            openSet.find(tile->getPosition())->second.GCost = nextNode.GCost + 1;
                        }
                    }
                }
            }
            if(path.size() != -1 && path.size() != 0){
                pathComponent->moveDestination = path.back().tile->getPosition();
                pathComponent->isOnMove = true;
            }

        }else{
            Vector2D positionVector = positionComponent->position;
            Vector2D destinationVector = pathComponent->moveDestination;
            int velMul = 1;

            if(positionVector.x != destinationVector.x) {
                if (positionVector.x < destinationVector.x)
                    positionComponent->velocity.x = 1 * velMul;
                if (positionVector.x > destinationVector.x)
                    positionComponent->velocity.x = -1 * velMul;
            }else {
                positionComponent->velocity.x = 0;
            }

            if(positionVector.y != destinationVector.y) {
                if (positionVector.y < destinationVector.y)
                    positionComponent->velocity.y = 1 * velMul;
                if (positionVector.y > destinationVector.y)
                    positionComponent->velocity.y = -1 * velMul;
            }else {
                positionComponent->velocity.y = 0;
            }

            if(positionVector.y == destinationVector.y && positionVector.x == destinationVector.x){
                pathComponent->isOnMove=false;
            }

        }
    }

}
