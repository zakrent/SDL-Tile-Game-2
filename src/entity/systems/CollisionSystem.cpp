//
// Created by zakrent on 4/15/17.
//

#include "CollisionSystem.h"
namespace Entity{
    void CollisionSystem::updateEntity(Entity *entityPointer) {
        std::string name = "Position";
        PositionComponent* positionComponent = entityPointer->getComponent<PositionComponent>(name);
        if(!positionComponent)
            return;
        name = "Collider";
        ColliderComponent* colliderComponent = entityPointer->getComponent<ColliderComponent>(name);
        if(!colliderComponent)
            return;
        colliderComponent->collider.x = int(positionComponent->position.x);
        colliderComponent->collider.y = int(positionComponent->position.y);
        Map::Tile* standingOn = mainMap->getTileAtPxPos(positionComponent->position);
        if(!standingOn)
            return;
        std::vector<Map::Tile*> tilesToTest;
        tilesToTest.push_back(standingOn);
        tilesToTest.push_back(standingOn->neighbours[Map::Up]);
        tilesToTest.push_back(standingOn->neighbours[Map::Down]);
        tilesToTest.push_back(standingOn->neighbours[Map::Right]);
        tilesToTest.push_back(standingOn->neighbours[Map::Left]);
        if(standingOn->neighbours[Map::Up]) {
            tilesToTest.push_back(standingOn->neighbours[Map::Up]->neighbours[Map::Right]);
            tilesToTest.push_back(standingOn->neighbours[Map::Up]->neighbours[Map::Left]);
        }
        if(standingOn->neighbours[Map::Down]) {
            tilesToTest.push_back(standingOn->neighbours[Map::Down]->neighbours[Map::Right]);
            tilesToTest.push_back(standingOn->neighbours[Map::Down]->neighbours[Map::Left]);
        }

        for(Map::Tile* tile : tilesToTest){
            if(tile){
                if(tile->isSolid() && CollisionDetection::boundingBox(tile->getCollider(), colliderComponent->collider)){
                    positionComponent->position -= positionComponent->velocity;
                    break;
                }
            }
        }

    }
}