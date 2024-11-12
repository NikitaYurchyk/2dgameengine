#include "ECS.h"
#include <algorithm>
#include <iostream>
int Entity::GetId() const{
    return id;
}

void System::AddEntityToSystem(Entity entity){
    entities.push_back(entity);    
};
void System::RemoveEntitFromSystem(Entity entity){
    entities.erase(std::remove_if(entities.begin(), entities.end(), [&entity](Entity other) {
        return entity == other;
    }), entities.end());
};

std::vector<Entity> System::GetSystemEntities() const {
    return entities;
};
const Signature& System::GetComponentSignature() const{
    return componetSignature;
};