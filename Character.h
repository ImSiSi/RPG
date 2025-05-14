#ifndef CHARACTER_H
#define CHARACTER_H
#include<cstdlib>
#include<iostream>
#include<string>

class Character {
    protected:
        int level;
        int health;
        int mana;
        int attack;
        int defend;
        double critChance;
        int critDamage;
        int exp;
        std::string name;
    public:
        Character(int level, int health, int mana, int attack, int defend, double critChance, int critDamage, const std::string& name, int exp) 
            : level(level), health(health), mana(mana), attack(attack), defend(defend), critChance(critChance), critDamage(critDamage), name(name) ,exp(exp){}
        Character() {}
    
        // 可提供 getter、setter（視需要）
        int getHealth() const { return health; }
        std::string getName() const { return name; }
    };

class Warrior : public Character {
    public:
        Warrior(const std::string& name) 
            : Character(1, 200, 50, 15, 30, 5, 1, name, 0) {}
    };
class Archer : public Character {
    public:
        Archer(const std::string& name) 
            : Character(1, 100, 100, 30, 20, 5, 1, name, 0) {}
    };
class Mage : public Character {
    public:
        Mage(const std::string& name) 
            : Character(1, 80, 200, 30, 15, 5, 1, name, 0) {}
    };
#endif