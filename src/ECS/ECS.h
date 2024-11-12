#ifndef ECS_H
#define ECS_H
#include <bitset>
#include <vector>
const unsigned int MAX_COMPONENTS = 32;

typedef std::bitset<MAX_COMPONENTS> Signature;

struct IComponent{
    protected:
        static int nextId;
};

template <typename TComponent>
class Component: public IComponent{
    private:
    public:
    static int GetId() {
        static auto id = nextId++;
        return id;
    }
};

class Entity{
    private:
        int id;
    public:
        Entity(int id): id(id){};
        
        int GetId() const;

        Entity& operator =(const Entity& other) = default;

        bool operator ==(const Entity& other) const{
            return other.GetId() == id;
        }
        bool operator !=(const Entity& other) const{
            return other.GetId() != id;
        }
};

class System{
    private:
        Signature componetSignature;
        std::vector<Entity> entities;
    public:
        System() = default;
        ~System() = default;
        void AddEntityToSystem(Entity entity);
        void RemoveEntitFromSystem(Entity entity);
        std::vector<Entity> GetSystemEntities() const;
        const Signature& GetComponentSignature() const;   
        template<typename IComponent> void RequiredComponent();
};


template <typename TComponent>
void System::RequiredComponent(){
    const auto& componentId = Component<TComponent>::GetId();
    componetSignature.set(componentId);
}



class Registery{

};


#endif