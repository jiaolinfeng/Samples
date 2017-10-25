#include <iostream>
#include <string>
#include <set>
#include <memory>

class Observable;

class Observer
{
public:
    virtual ~Observer()
    {

    }

    void observe(Observable *observable);

    void unobserver(Observable *observable);

    virtual void update() = 0;
};

class Observable
{
public:
    virtual ~Observable()
    {

    }

    void add(Observer* observer)
    {
        observers_.insert(observer);
    }

    void remove(Observer* observer)
    {
        observers_.erase(observer);
    }

    void notify()
    {
        for (auto it = observers_.begin(); it != observers_.end(); ++it)
        {
            (*it)->update();
        }
    }

private:
    using Container = std::set<Observer*>;
    Container observers_;
};

void Observer::observe(Observable *observable)
{
    observable->add(this);
}

void Observer::unobserver(Observable *observable)
{
    observable->remove(this);
}

class BloodLess : public Observable
{

};

class Friend : public Observer
{
public:
    virtual void update() override
    {
        std::cout << "A friend try to heal him!" << std::endl;
    }
};

class Enemy : public Observer
{
public:
    virtual void update() override
    {
        std::cout << "An enemy try to kill him!" << std::endl;
    }
};

int main()
{
    // observable
    std::shared_ptr<Observable> p_blood_less(new(std::nothrow) BloodLess);
    if (!p_blood_less.get())
    {
        return -1;
    }
    // observer1
    std::shared_ptr<Friend> p_friend(new(std::nothrow) Friend);
    if (!p_friend.get())
    {
        return -1;
    }
    // observer2
    std::shared_ptr<Enemy> p_enemy(new(std::nothrow) Enemy);
    if (!p_enemy.get())
    {
        return -1;
    }
    // observe
    std::cout << "A solder is injured and bleeding." << std::endl;
    p_friend->observe(p_blood_less.get());
    p_enemy->observe(p_blood_less.get());
    p_blood_less->notify();

    return 0;
}
