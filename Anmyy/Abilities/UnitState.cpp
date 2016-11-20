#include "UnitState.h"

UnitState::UnitState(int healthPointsLimit, double magicalResistance, double physicalResistance, int damage)
        : healthPointsLimit(healthPointsLimit), magicalResistance(magicalResistance),
          physicalResistance(physicalResistance), damage(damage) {

}

int UnitState::getHealthPoints() const {
    return this->healthPoints;
}

int UnitState::getHealthPointsLimit() const {
    return this->healthPointsLimit;
}

void UnitState::takeMagicalDamage(int damage) {
    int scaledDamage = damage * (int)(1 - this->magicalResistance);

    if ( scaledDamage > this->healthPoints ) {
        this->healthPoints = 0;

        return;
    }

    this->healthPoints -= scaledDamage;
}

void UnitState::takePhysicalDamage(int damage) {
    int scaledDamage = damage * (int)(1 - this->physicalResistance);

    if ( scaledDamage > this->healthPoints ) {
        this->healthPoints = 0;

        return;
    }

    this->healthPoints -= scaledDamage;
}

double UnitState::getPhysicalResistance() const {
    return this->physicalResistance;
}

double UnitState::getMagicalResistance() const {
    return this->magicalResistance;
}

int UnitState::getDamage() const {
    return this->damage;
}

void UnitState::addHealthPoints(int hp) {
    if ( this->healthPoints + hp >= this->healthPointsLimit ) {
        this->healthPoints = this->healthPointsLimit;

        return;
    }

    this->healthPoints += hp;
}


