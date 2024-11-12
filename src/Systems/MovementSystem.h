#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

class MovementSystem: public System{
public:
//TODO: RequireComponent<TransformComponents>
//TODO: RequireComponent<>
    MovementSystem(){

    }


    //TODO:
    //Update entity position on its velocity very frame of the game loop 
    
    //Loop through all entities the sys is interested
    void Update(){
        for(auto entity: GetEntities()){

        }
        
    }

}


#endif MOVEMENTSYSTEM_H