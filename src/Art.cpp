#include "Art.h"

#include "Engine.h"


Pos Art::getColumnAndRowGlyph(const char glyph) {
  switch(glyph) {
    default:  return Pos(-1, -1);  break;
    case ' ': return Pos(0, 0);  break;
    case '!': return Pos(1, 0); break;
    case '"': return Pos(2, 0); break;
    case '#': return Pos(3, 0); break;
    case '%': return Pos(4, 0); break;
    case '&': return Pos(5, 0); break;
    case  39: return Pos(6, 0); break;
    case '(': return Pos(7, 0); break;
    case ')': return Pos(8, 0); break;
    case '*': return Pos(9, 0); break;
    case '+': return Pos(10, 0); break;
    case ',': return Pos(11, 0); break;
    case '-': return Pos(12, 0); break;
    case '.': return Pos(13, 0); break;
    case '/': return Pos(14, 0); break;
    case '0': return Pos(15, 0); break;
    case '1': return Pos(0, 1); break;
    case '2': return Pos(1, 1); break;
    case '3': return Pos(2, 1); break;
    case '4': return Pos(3, 1); break;
    case '5': return Pos(4, 1); break;
    case '6': return Pos(5, 1); break;
    case '7': return Pos(6, 1); break;
    case '8': return Pos(7, 1); break;
    case '9': return Pos(8, 1); break;
    case ':': return Pos(9, 1); break;
    case ';': return Pos(10, 1); break;
    case '<': return Pos(11, 1); break;
    case '=': return Pos(12, 1); break;
    case '>': return Pos(13, 1); break;
    case '?': return Pos(14, 1); break;
    case '@': return Pos(15, 1); break;
    case 'A': return Pos(0, 2); break;
    case 'B': return Pos(1, 2); break;
    case 'C': return Pos(2, 2); break;
    case 'D': return Pos(3, 2); break;
    case 'E': return Pos(4, 2); break;
    case 'F': return Pos(5, 2); break;
    case 'G': return Pos(6, 2); break;
    case 'H': return Pos(7, 2); break;
    case 'I': return Pos(8, 2); break;
    case 'J': return Pos(9, 2); break;
    case 'K': return Pos(10, 2); break;
    case 'L': return Pos(11, 2); break;
    case 'M': return Pos(12, 2); break;
    case 'N': return Pos(13, 2); break;
    case 'O': return Pos(14, 2); break;
    case 'P': return Pos(15, 2); break;
    case 'Q': return Pos(0, 3); break;
    case 'R': return Pos(1, 3); break;
    case 'S': return Pos(2, 3); break;
    case 'T': return Pos(3, 3); break;
    case 'U': return Pos(4, 3); break;
    case 'V': return Pos(5, 3); break;
    case 'W': return Pos(6, 3); break;
    case 'X': return Pos(7, 3); break;
    case 'Y': return Pos(8, 3); break;
    case 'Z': return Pos(9, 3); break;
    case '[': return Pos(10, 3); break;
    case  92: return Pos(11, 3);  break;
    case ']': return Pos(12, 3);  break;
    case '^': return Pos(13, 3);  break;
    case '_': return Pos(14, 3);  break;
    case '`': return Pos(15, 3);  break;
    case 'a': return Pos(0, 4);  break;
    case 'b': return Pos(1, 4);  break;
    case 'c': return Pos(2, 4);  break;
    case 'd': return Pos(3, 4);  break;
    case 'e': return Pos(4, 4);  break;
    case 'f': return Pos(5, 4);  break;
    case 'g': return Pos(6, 4);  break;
    case 'h': return Pos(7, 4);  break;
    case 'i': return Pos(8, 4);  break;
    case 'j': return Pos(9, 4);  break;
    case 'k': return Pos(10, 4);  break;
    case 'l': return Pos(11, 4);  break;
    case 'm': return Pos(12, 4);  break;
    case 'n': return Pos(13, 4);  break;
    case 'o': return Pos(14, 4);  break;
    case 'p': return Pos(15, 4);  break;
    case 'q': return Pos(0, 5);  break;
    case 'r': return Pos(1, 5);  break;
    case 's': return Pos(2, 5);  break;
    case 't': return Pos(3, 5);  break;
    case 'u': return Pos(4, 5);  break;
    case 'v': return Pos(5, 5);  break;
    case 'w': return Pos(6, 5);  break;
    case 'x': return Pos(7, 5);  break;
    case 'y': return Pos(8, 5);  break;
    case 'z': return Pos(9, 5);  break;
    case '{': return Pos(10, 5);  break;
    case '|': return Pos(11, 5);  break;
    case '}': return Pos(12, 5);  break;
    case '~': return Pos(13, 5);  break;
    case   1: return Pos(14, 5);  break;
    case   2: return Pos(0, 6);  break;
    case   3: return Pos(1, 6);  break;
    case   4: return Pos(2, 6);  break;
    case   5: return Pos(3, 6); break;
    case   6: return Pos(4, 6); break;
    case   7: return Pos(5, 6); break;
    case   8: return Pos(6, 6); break;
    case   9: return Pos(7, 6); break;
    case  10: return Pos(8, 6); break;
  }
}



Pos Art::getColumnAndRowTile(const Tile_t tile) {
  switch(tile) {
    case tile_playerFirearm: return Pos(0, 0); break;
    case tile_playerMelee: return Pos(1, 0); break;
    case tile_zombieUnarmed: return Pos(2, 0); break;
    case tile_zombieArmed: return Pos(3, 0); break;
    case tile_zombieBloated: return Pos(4, 0); break;
    case tile_cultistFirearm: return Pos(5, 0); break;
    case tile_cultistDagger: return Pos(6, 0); break;
    case tile_witchOrWarlock: return Pos(7, 0); break;
    case tile_ghoul: return Pos(8, 0); break;
    case tile_mummy: return Pos(9, 0); break;
    case tile_deepOne: return Pos(10, 0); break;
    case tile_shadow: return Pos(11, 0); break;
    case tile_armor: return Pos(0, 1); break;
    case tile_potion: return Pos(2, 1); break;
    case tile_ammo: return Pos(4, 1); break;
    case tile_scroll: return Pos(8, 1); break;
    case tile_elderSign: return Pos(10, 1); break;
    case tile_chestClosed: return Pos(11, 1); break;
    case tile_chestOpen: return Pos(12, 1); break;
    case tile_electricLantern: return Pos(16, 1); break;
    case tile_medicalBag: return Pos(17, 1); break;
    case tile_rat: return Pos(1, 2); break;
    case tile_spider: return Pos(2, 2); break;
    case tile_wolf: return Pos(3, 2); break;
    case tile_phantasm: return Pos(4, 2); break;
    case tile_ratThing: return Pos(5, 2); break;
    case tile_hound: return Pos(6, 2); break;
    case tile_bat: return Pos(7, 2); break;
    case tile_byakhee: return Pos(8, 2); break;
    case tile_massOfWorms: return Pos(9, 2); break;
    case tile_ooze: return Pos(10, 2); break;
    case tile_polyp: return Pos(7, 5); break;
    case tile_vortex: return Pos(5, 5); break;
    case tile_ghost: return Pos(12, 2); break;
    case tile_wraith: return Pos(13, 2); break;
    case tile_mantis: return Pos(14, 2); break;
    case tile_locust: return Pos(15, 2); break;
    case tile_pistol: return Pos(1, 3); break;
    case tile_tommyGun: return Pos(3, 3); break;
    case tile_shotgun: return Pos(4, 3); break;
    case tile_dynamite: return Pos(5, 3); break;
    case tile_dynamiteLit: return Pos(6, 3); break;
    case tile_molotov: return Pos(7, 3); break;
    case tile_incinerator: return Pos(8, 3); break;
    case tile_teslaCannon: return Pos(9, 3); break;
    case tile_flare: return Pos(10, 3); break;
    case tile_flareGun: return Pos(11, 3); break;
    case tile_flareLit: return Pos(12, 3); break;
    case tile_dagger: return Pos(0, 4); break;
    case tile_crowbar: return Pos(3, 4); break;
    case tile_axe: return Pos(9, 4); break;
    case tile_club: return Pos(10, 4); break;
    case tile_hammer: return Pos(11, 4); break;
    case tile_machete: return Pos(12, 4); break;
    case tile_pitchfork: return Pos(13, 4); break;
    case tile_sledgeHammer: return Pos(14, 4); break;
    case tile_rock: return Pos(15, 4); break;
    case tile_ironSpike: return Pos(16, 4); break;
    case tile_lockpick: return Pos(17, 4); break;
    case tile_huntingHorror: return Pos(4, 5); break;
    case tile_spiderLeng: return Pos(10, 5); break;
    case tile_migo: return Pos(12, 5); break;
    case tile_floor: return Pos(1, 6); break;
    case tile_aimMarkerHead: return Pos(2, 6); break;
    case tile_aimMarkerTrail: return Pos(3, 6); break;
    case tile_wallTop: return Pos(5, 6); break;
    case tile_wallFront: return Pos(3, 7); break;
    case tile_squareCheckered: return Pos(5, 6); break;
    case tile_rubbleHigh: return Pos(7, 6); break;
    case tile_rubbleLow: return Pos(8, 6); break;
    case tile_stairsDown: return Pos(9, 6); break;
    case tile_brazier: return Pos(11, 6); break;
    case tile_altar: return Pos(12, 6); break;
    case tile_spiderWeb: return Pos(13, 6); break;
    case tile_doorClosed: return Pos(14, 6); break;
    case tile_doorOpen: return Pos(15, 6); break;
    case tile_doorBroken: return Pos(16, 6); break;
    case tile_fountain: return Pos(18, 6); break;
    case tile_tree: return Pos(1, 7); break;
    case tile_bush: return Pos(2, 7); break;
    case tile_churchBench: return Pos(4, 7); break;
    case tile_graveStone: return Pos(5, 7); break;
    case tile_tomb: return Pos(14, 5); break;
    case tile_water1: return Pos(7, 7); break;
    case tile_water2: return Pos(8, 7); break;
    case tile_trapGeneral: return Pos(17, 5); break;
    case tile_cocoon: return Pos(10, 7); break;
    case tile_blast1: return Pos(11, 7); break;
    case tile_blast2: return Pos(12, 7); break;
    case tile_corpse: return Pos(13, 7); break;
    case tile_corpse2: return Pos(14, 7); break;
    case tile_projectileStandardFrontSlash: return Pos(15, 7); break;
    case tile_projectileStandardBackSlash: return Pos(16, 7); break;
    case tile_projectileStandardDash: return Pos(17, 7); break;
    case tile_projectileStandardVerticalBar: return Pos(18, 7); break;
    case tile_gore1: return Pos(0, 8); break;
    case tile_gore2: return Pos(1, 8); break;
    case tile_gore3: return Pos(2, 8); break;
    case tile_gore4: return Pos(3, 8); break;
    case tile_gore5: return Pos(4, 8); break;
    case tile_gore6: return Pos(5, 8); break;
    case tile_gore7: return Pos(6, 8); break;
    case tile_gore8: return Pos(7, 8); break;
    case tile_smoke: return Pos(9, 8); break;
    case tile_wallFrontAlt1: return Pos(1, 9); break;
    case tile_wallFrontAlt2: return Pos(0, 9); break;
    case tile_trapezohedron: return Pos(11, 8); break;
    case tile_pit: return Pos(12, 8); break;
    case tile_leverRight: return Pos(13, 8); break;
    case tile_leverLeft: return Pos(14, 8); break;
    case tile_device1: return Pos(15, 8); break;
    case tile_device2: return Pos(16, 8); break;
    case tile_cabinetClosd: return Pos(3, 9); break;
    case tile_cabinetOpen: return Pos(4, 9); break;
    case tile_pillarBroken: return Pos(5, 9); break;
    case tile_pillar: return Pos(6, 9); break;
    case tile_pillarCarved: return Pos(7, 9); break;
    case tile_barrel: return Pos(8, 9); break;
    case tile_sarcophagus: return Pos(9, 9); break;
    case tile_caveWallFront: return Pos(10, 9); break;
    case tile_caveWallTop: return Pos(11, 9); break;
    case tile_egyptWallFront: return Pos(16, 9); break;
    case tile_egyptWallTop: return Pos(17, 9); break;
    case tile_popupCornerTopLeft: return Pos(0, 10); break;
    case tile_popupCornerTopRight: return Pos(1, 10); break;
    case tile_popupCornerBottomLeft: return Pos(2, 10); break;
    case tile_popupCornerBottomRight: return Pos(3, 10); break;
    case tile_popupHorizontalBar: return Pos(4, 10); break;
    case tile_popupVerticalBar: return Pos(5, 10); break;
    case tile_empty: return Pos(18, 9); break;
    default: return Pos(18, 8); break;
  }
}


Pos Art::getGlyphPoss(const char glyph) {
  return getColumnAndRowGlyph(glyph);
}

Pos Art::getTilePoss(const Tile_t tile) {
  return getColumnAndRowTile(tile);
}
