#include "Close.h"

#include "GameTime.h"
#include "Feature.h"
#include "Actor.h"
#include "ActorPlayer.h"
#include "FeatureDoor.h"
#include "Map.h"
#include "Log.h"
#include "Query.h"
#include "Renderer.h"

namespace Close {

void playerCloseFeature(Feature* const feature) {
  bool closeAbleObjectFound = false;

  if(feature->getId() == FeatureId::door) {
    Door* const door = dynamic_cast<Door*>(feature);
    door->tryClose(Map::player);
    closeAbleObjectFound = true;
  }

  if(!closeAbleObjectFound) {
    const bool PLAYER_CAN_SEE = Map::player->getPropHandler().allowSee();
    if(PLAYER_CAN_SEE) {
      Log::addMsg("I see nothing there to close.");
    } else {
      Log::addMsg("I find nothing there to close.");
    }
  }
}

void playerClose() {
  Log::clearLog();
  Log::addMsg("Which direction?" + cancelInfoStr, clrWhiteHigh);
  Renderer::drawMapAndInterface();
  Pos closePos(Map::player->pos + Query::dir());
  Log::clearLog();

  if(closePos != Map::player->pos) {
    playerCloseFeature(Map::cells[closePos.x][closePos.y].featureStatic);
  }

  Renderer::drawMapAndInterface();
}

} //Close
