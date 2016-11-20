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

        double getMagicalResistance() const;
        double getPhysicalResistance() const;

        void takePhysicalDamage(int damage);
        void takeMagicalDamage(int damage);

};


#endif //UNIT_STATE_H
