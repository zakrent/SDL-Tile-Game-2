//
// Created by zakrent on 5/1/17.
//

#include "BulletSystem.h"

namespace CollisionDetection{
    std::vector<Map::Tile*> getTilesToTest(Map::Tile* s);
    bool boundingBox(SDL_Rect a, SDL_Rect b);
}

namespace Entity {
    void BulletSystem::updateEntity(Entity *entityPointer) {
        std::string name = "Bullet";
        BulletComponent* bulletComponent = entityPointer->getComponent<BulletComponent>(name);
        if(!bulletComponent)
            return;
        name = "Position";
        PositionComponent* positionComponent = entityPointer->getComponent<PositionComponent>(name);
        if(!positionComponent)
            return;

        if(bulletComponent->aliveTime < bulletComponent->timeCounter){
            entityPointer->shouldBeDestroyed=true;
            return;
        }
        bulletComponent->timeCounter++;

        Map::Tile* standingOn = mainMap->getTileAtPxPos(positionComponent->position);
        if(!standingOn)
            return;

        std::vector<Map::Tile*> tilesToTest = CollisionDetection::getTilesToTest(standingOn);

        SDL_Rect collider = {int(positionComponent->position.x), int(positionComponent->position.y), 0, 0};

        for(Map::Tile* tile : tilesToTest){
            if(tile){
                if(tile->isSolid() && CollisionDetection::boundingBox(tile->getCollider(), collider)){
                    entityPointer->shouldBeDestroyed = true;
                    break;
                }
            }
        }

        if(bulletComponent->timeCounter == 0)
            return;

        for(Entity* entity : mainMap->entities){
            if(entity){
                name = "Collider";
                ColliderComponent* colliderComponent = entity->getComponent<ColliderComponent>(name);
                name = "Health";
                HealthComponent* healthComponent = entity->getComponent<HealthComponent>(name);
                if(colliderComponent && healthComponent){
                    if(CollisionDetection::boundingBox(colliderComponent->collider, collider)){
                        entityPointer->shouldBeDestroyed = true;
                        healthComponent->health -= bulletComponent->damage;
                        break;
                    }
                }
            }
        }

    }
}