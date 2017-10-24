/**
 * @file builder.cpp
 * @brief builder
 * @author JiaoLinfeng, jiaolinfeng@esunny.cc
 * @version 1.0
 * @date 2017-10-24
 */

#include <assert.h>
#include <iostream>
#include <string>

class Hero
{
public:
    Hero()
    {

    }

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
    HeroBuilder(Hero *hero) : hero_(hero)
    {
    }

    virtual ~HeroBuilder()
    {

    }

    virtual HeroBuilder* buildBody() = 0;

    virtual HeroBuilder* buildArmour() = 0;

    virtual HeroBuilder* buildWeapon() = 0;

    Hero* build()
    {
        buildBody();
        buildArmour();
        buildWeapon();
        return hero_;
    }
protected:
    void setBody(const std::string body)
    {
        hero_->body = body;
    }

    void setArmour(const std::string armour)
    {
        hero_->armour = armour;
    }

    void setWeapon(const std::string weapon)
    {
        hero_->weapon = weapon;
    }
private:
    Hero *hero_;
};

class WeakHeroBuilder : public HeroBuilder
{
public:
    WeakHeroBuilder(Hero *hero) : HeroBuilder(hero)
    {

    }

    virtual ~WeakHeroBuilder()
    {

    }

    virtual HeroBuilder* buildBody()
    {
        setBody("thin");
        return this;
    }

    virtual HeroBuilder* buildArmour()
    {
        setArmour("poor");
        return this;
    }

    virtual HeroBuilder* buildWeapon()
    {
        setWeapon("rusty");
        return this;
    }

};

class StrongHeroBuilder : public HeroBuilder
{
public:
    StrongHeroBuilder(Hero *hero) : HeroBuilder(hero)
    {

    }

    virtual ~StrongHeroBuilder()
    {
    }

    virtual HeroBuilder* buildBody()
    {
        setBody("strong");
        return this;
    }

    virtual HeroBuilder* buildArmour()
    {
        setArmour("solid");
        return this;
    }

    virtual HeroBuilder* buildWeapon()
    {
        setWeapon("sharp");
        return this;
    }
};

int main()
{
    Hero *hero = new Hero;
    assert(hero != nullptr);
    HeroBuilder *builder = new(std::nothrow) WeakHeroBuilder(hero);
    assert(builder != nullptr);
    hero = builder->build();
    hero->show();
    delete builder;
    builder = nullptr;

    builder = new(std::nothrow) StrongHeroBuilder(hero);
    hero = builder->build();
    hero->show();
    delete builder;
    builder = nullptr;

    delete hero;
    hero = nullptr;
    return 0;
}
