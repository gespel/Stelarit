#pragma once
#include <iostream>
#include <string.h>

using namespace std;

enum spellType {dmg, heal, buff, debuff, sT_none};
enum dmgType {fire, ice, holy, dark, dT_none};
enum spellName {fireBolt, iceBolt, holyHeal, darkSpear, sN_none};

class Spell {
    public:
        Spell(spellName sN, dmgType dT, spellType sT, int am);
        string getSpellName();
        string getDmgType();
        spellType getSpellType();
        int getAmount();
    private:
        spellType spelltype;
        dmgType dmgtype;
        spellName spellname;
        int amount;
};
