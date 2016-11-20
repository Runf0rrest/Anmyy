#include "Unit.h"
#include <iostream>

Unit::Unit(const std::string& name, int hp, int dmg, double physicalResistance, double magicalResistance) : {
    *(this->name) = name;
    this->unitState = new UnitState(hp, magicalResistance, physicalResistance, dmg);
}

Unit::~Unit() {
    delete this->unitState;
    delete this->name;
}

void Unit::ensureIsAlive() {
    if ( this->unitState->getHealthPoints() == 0 ) {
        throw UnitIsDead();
    }
}

int Unit::getDamage() const {
    return this->unitState->getDamage();
}

int Unit::getHitPoints() const {
    return this->unitState->getHealthPoints();
}

int Unit::getHitPointsLimit() const {
    return this->unitState->getHealthPointsLimit();
}

const std::string& Unit::getName() const {
    return *(this->name);
}

void Unit::takePhysicalDamage(int dmg) {
    ensureIsAlive();

    unitState->takePhysicalDamage(dmg);
}

void Unit::addHitPoints(int hp) {
    ensureIsAlive();

    this->unitState->addHealthPoints(hp);
}

void Unit::attack(Unit& enemy) {
    ensureIsAlive();

    enemy.takePhysicalDamage(this->unitState->getDamage());

    try {
        enemy.counterAttack(*this);
    } catch (UnitIsDeadException) {
        return;
    }
}
void Unit::counterAttack(Unit& enemy) {
    ensureIsAlive();

    enemy.takePhysicalDamage(this->unitState->getDamage() / 2);
}

void Unit::takeMagicalDamage(int dmg) {
    ensureIsAlive();

    this->unitState->takeMagicalDamage(dmg);
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << unit.getName();
    out << ", Max HP = " << unit.getHitPointsLimit();
    out << ", Current HP = " << unit.getHitPoints();
    out << ", Damage = " << unit.getDamage();
    out << std::endl;

    return out;
}
