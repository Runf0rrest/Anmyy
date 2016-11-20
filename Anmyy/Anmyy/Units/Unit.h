#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "../Abilities/UnitState.h"
#include "UnitExceptions.h"

class UnitIsDead {};

class Unit {
private:
    UnitState* unitState;
    std::string* name;

    void ensureIsAlive();
public:
    Unit(const std::string& name, int hp, int dmg, double physicalResistance, double magicalResistance);
    ~Unit();

    //accessors
    int getDamage() const;
    int getHitPoints() const;
    int getHitPointsLimit() const;
    const std::string& getName() const;

    void takePhysicalDamage(int dmg);
    void takeMagicalDamage(int dmg);
    void addHitPoints(int hp);

    void attack(Unit& enemy);
    void counterAttack(Unit& enemy);
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif //UNIT_H
