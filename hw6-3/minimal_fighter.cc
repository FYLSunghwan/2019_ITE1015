#include "minimal_fighter.h"

MinimalFighter::MinimalFighter()
{
    mHp = 0;
    mPower = 0;
    mStatus = EFighterStatus::Invalid;
}

MinimalFighter::MinimalFighter(int _hp, int _power)
{
    mHp = _hp;
    mPower = _power;
    mStatus = _hp > 0 ? EFighterStatus::Alive : EFighterStatus::Dead;
}
    
int MinimalFighter::hp() const
{
    return mHp;
}

int MinimalFighter::power() const
{
    return mPower;
}

FighterStatus MinimalFighter::status() const
{
    return mStatus;
}
    
void MinimalFighter::setHp(int _hp)
{
    mHp = _hp;
}

void MinimalFighter::setStatus()
{
    if(mHp <= 0) mStatus = FighterStatus::Dead;
}
    
void MinimalFighter::hit(MinimalFighter *_enemy)
{
    mHp -= _enemy->power();
    const int enemyHp = _enemy->hp() - mPower;
    _enemy->setHp(enemyHp);
    _enemy->setStatus();
}

void MinimalFighter::attack(MinimalFighter *_target)
{
    const int enemyHp = _target->hp() - mPower;
    _target->setHp(enemyHp);
    mPower = 0;
    _target->setStatus();
}

void MinimalFighter::fight(MinimalFighter *_enemy)
{
    while(mStatus == FighterStatus::Alive && _enemy->mStatus == FighterStatus::Alive)
    {
        hit(_enemy);
    }
}