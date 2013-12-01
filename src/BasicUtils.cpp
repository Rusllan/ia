#include "BasicUtils.h"

#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <algorithm>

#include "Engine.h"

#include "Converters.h"
#include "GameTime.h"

// Function for lexicographically comparing two StringAndClr structs
struct LexicograhicalCompareStringAndClr {
public:
  LexicograhicalCompareStringAndClr() {
  }
  bool operator()(const StringAndClr& entry1, const StringAndClr& entry2) {
    return std::lexicographical_compare(
             entry1.str.begin(), entry1.str.end(),
             entry2.str.begin(), entry2.str.end());
  }
};

void BasicUtils::makeVectorFromBoolMap(const bool VALUE_TO_STORE,
                                       bool a[MAP_X_CELLS][MAP_Y_CELLS],
                                       vector<Pos>& vectorToFill) {
  vectorToFill.resize(0);
  for(int y = 0; y < MAP_Y_CELLS; y++) {
    for(int x = 0; x < MAP_X_CELLS; x++) {
      if(a[x][y] == VALUE_TO_STORE) {
        vectorToFill.push_back(Pos(x, y));
      }
    }
  }
}

Actor* BasicUtils::getActorAtPos(const Pos& pos) const {
  const int NR_ACTORS = eng->gameTime->getNrActors();
  for(int i = 0; i < NR_ACTORS; i++) {
    Actor& actor = eng->gameTime->getActorAtElement(i);
    if(actor.pos == pos && actor.deadState == actorDeadState_alive) {
      return &actor;
    }
  }
  return NULL;
}

void BasicUtils::makeActorArray(Actor* a[MAP_X_CELLS][MAP_Y_CELLS]) {
  resetArray(a);

  const int NR_ACTORS = eng->gameTime->getNrActors();
  for(int i = 0; i < NR_ACTORS; i++) {
    Actor& actor = eng->gameTime->getActorAtElement(i);
    const Pos& p = actor.pos;
    a[p.x][p.y] = &actor;
  }
}

Pos BasicUtils::getClosestPos(
  const Pos& c, const vector<Pos>& positions) const {
  int distToNearest = INT_MAX;
  int closestElement = 0;
  const int NR_POSITIONS = positions.size();
  for(int i = 0; i < NR_POSITIONS; i++) {
    const int CUR_DIST = eng->basicUtils->chebyshevDist(c, positions.at(i));
    if(CUR_DIST < distToNearest) {
      distToNearest = CUR_DIST;
      closestElement = i;
    }
  }

  return positions.at(closestElement);
}


Actor* BasicUtils::getClosestActor(const Pos& c,
                                   const vector<Actor*>& actors) const {
  if(actors.size() == 0) return NULL;

  int distToNearest = INT_MAX;
  int closestElement = 0;
  for(unsigned int i = 0; i < actors.size(); i++) {
    const int CUR_DIST = eng->basicUtils->chebyshevDist(c, actors.at(i)->pos);
    if(CUR_DIST < distToNearest) {
      distToNearest = CUR_DIST;
      closestElement = i;
    }
  }

  return actors.at(closestElement);
}



bool BasicUtils::isPosAdj(
  const Pos& pos1, const Pos& pos2,
  const bool COUNT_SAME_CELL_AS_NEIGHBOUR) const {

  if(pos1.x == pos2.x && pos1.y == pos2.y) {
    return COUNT_SAME_CELL_AS_NEIGHBOUR;
  }
  if(pos1.x < pos2.x - 1) {
    return false;
  }
  if(pos1.x > pos2.x + 1) {
    return false;
  }
  if(pos1.y < pos2.y - 1) {
    return false;
  }
  if(pos1.y > pos2.y + 1) {
    return false;
  }
  return true;
}

void BasicUtils::lexicographicalSortStringAndClrVector(
  vector<StringAndClr>& vect) {

  LexicograhicalCompareStringAndClr cmp;
  std::sort(vect.begin(), vect.end(), cmp);
}

string TimeData::getTimeStr(const Time_t lowest,
                            const bool ADD_SEPARATORS) const {
  string ret = toString(year_);

  string monthStr   = (month_   < 10 ? "0" : "") + toString(month_);
  string dayStr     = (day_     < 10 ? "0" : "") + toString(day_);
  string hourStr    = (hour_    < 10 ? "0" : "") + toString(hour_);
  string minuteStr  = (minute_  < 10 ? "0" : "") + toString(minute_);
  string secondStr  = (second_  < 10 ? "0" : "") + toString(second_);

  if(lowest >= time_month)  ret += (ADD_SEPARATORS ? "-" : "") + monthStr;
  if(lowest >= time_day)    ret += (ADD_SEPARATORS ? "-" : "") + dayStr;
  if(lowest >= time_hour)   ret += (ADD_SEPARATORS ? " " : "") + hourStr;
  if(lowest >= time_minute) ret += (ADD_SEPARATORS ? ":" : "") + minuteStr;
  if(lowest >= time_second) ret += (ADD_SEPARATORS ? ":" : "") + secondStr;

  return ret;
}

TimeData BasicUtils::getCurrentTime() const {
  time_t t = time(0);
  struct tm* now = localtime(&t);
  return TimeData(now->tm_year + 1900, now->tm_mon + 1, now->tm_mday,
                  now->tm_hour, now->tm_min, now->tm_sec);
}
