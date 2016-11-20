#ifndef UNIT_STATE_H
#define UNIT_STATE_H


class UnitState {
    private:
        int healthPoints;
        int healthPointsLimit;
        int damage;
        double magicalResistance;
        double physicalResistance;

    public:
        UnitState(int healthPointsLimit, double magicalResistance, double physicalResistance, int damage);

        int getHealthPoints() const;
        int getHealthPointsLimit() const;

        int getDamage() const;

        double getMagicalResistance() const;
        double getPhysicalResistance() const;

        void takePhysicalDamage(int damage);
        void takeMagicalDamage(int damage);
        void addHealthPoints(int hp);

};


#endif //UNIT_STATE_H
