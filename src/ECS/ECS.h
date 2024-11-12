#ifndef ECS_H
#define ECS_H
#include <bitset>
#include <vector>
#include <unordered_map>
#include <typeindex>

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

class IPool{
    public:
        virtual ~IPool() {}
};

template <typename T>
class Pool: IPool{
    private:
        std::vector<T> data;

    public:
        Pool(size_t size = 1000){
            data.resize(size);
        }
        ~Pool() = default;
        bool isEmpty(){
            return data.empty();
        } 
        int GetSize(){
            return data.size();
        }
        
        void Resize(int n){
            data.resize(n);
        }

        void Clear(){
            data.clear();
        }
        
        void Add(T obj){
            data.push_back(obj);
        }

        void Set(int index, T obj){
            data.at(index) = obj;
        }

        T& Get(int index){
            return static_cast<T&>(data[index]);
        }

        T& operator [](unsigned int index){
            return static_cast<T&>(data[index]);
        }
};
class Registery{
    private:
        int numEntities = 0;
        //pool certain component data
        std::vector<IPool*> componentPool;
        std::vector<Signature> entityComponentSignature;
        std::unordered_map<std::type_index, System*> systems;
    public:
        Registery() = default;
        ~Registery() = default;
};



#endif