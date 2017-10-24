/**
 * @file builder.cpp
 * @brief builder
 * @author JiaoLinfeng, jiaolinfeng@esunny.cc
 * @version 1.0
 * @date 2017-10-24
 */

#include <iostream>
#include <string>

class Hero
{
public:
    void show()
    {
        std::cout << "I'm a hero with "
                  << body << " body, "
                  << armour << " armour and "
                  << weapon << " weapon."
                  << std::endl;
    }

public:
    std::string body;
    std::string armour;
    std::string weapon;
};

class HeroBuilder
{
public:
    HeroBuilder()
    {
        hero_ = new Hero;
    }

    HeroBuilder* setBody(const std::string& body)
    {
        std::cout << "set hero body " << body  << std::endl;
        hero_->body = body;
        return this;
    }

    HeroBuilder* setArmour(const std::string&  armour)
    {
        std::cout << "set hero armour " << armour << std::endl;
        hero_->armour = armour;
        return this;
    }

    HeroBuilder* setWeapon(const std::string&  weapon)
    {
        std::cout << "set hero weapon " << weapon << std::endl;
        hero_->weapon = weapon;
        return this;
    }

    Hero* build()
    {
        return hero_;
    }
private:
    Hero *hero_;
};

int main()
{
    HeroBuilder *builder = new HeroBuilder;
    Hero *hero = builder->setBody("strong")
                        ->setArmour("solid")
                        ->setWeapon("sharp")
                        ->build();
    if (hero)
    {
        hero->show();
        delete hero;
        hero = nullptr;
    }
    return 0;
}
