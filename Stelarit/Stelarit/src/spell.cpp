#include "spell.h"

Spell::Spell(spellName sN, dmgType dT, spellType sT, int am) {
    spellname = sN;
    dmgtype = dT;
    spelltype = sT;
    amount = am;
}
string Spell::getSpellName() {
    if(spellname == fireBolt) {
        return "firebolt";
    }
    else if(spellname == iceBolt) {
        return "icebolt";
    }
    else if(spellname == holyHeal) {
        return "holy heal";
    }
    else if(spellname == darkSpear) {
        return "darkspear";
    }
    else if(spellname == sN_none) {
        return "none";
    }
    return "error";
}
string Spell::getDmgType() {
    if(dmgtype == fire) {
        return "fire";
    }
    else if(dmgtype == ice) {
        return "ice";
    }
    else if(dmgtype == holy) {
        return "holy";
    }
    else if(dmgtype == dark) {
        return "dark";
    }
    return "error";
}
spellType Spell::getSpellType() {
    return spelltype;
}
int Spell::getAmount() {
    return amount;
}
