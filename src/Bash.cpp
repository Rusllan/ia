#include "Bash.h"

#include "Engine.h"

#include "GameTime.h"
#include "Feature.h"
#include "ActorPlayer.h"
#include "Map.h"
#include "Log.h"
#include "Query.h"
#include "Renderer.h"
#include "MapParsing.h"

void Bash::playerBash() const {
  trace << "Bash::playerBash()" << endl;

  eng->log->clearLog();
  eng->log->addMsg("Which direction? | space/esc cancel", clrWhiteHigh);
  eng->renderer->drawMapAndInterface();
  Pos bashPos(eng->player->pos + eng->query->dir());
  eng->log->clearLog();

  if(bashPos != eng->player->pos) {
    Actor* actor = eng->basicUtils->getActorAtPos(bashPos);

    if(actor == NULL) {
      trace << "Bash: No actor at bash pos, ";
      trace << "attempting to bash feature instead" << endl;
      playerBashFeature(eng->map->cells[bashPos.x][bashPos.y].featureStatic);
    }  else {
      trace << "Bash: Actor found at bash pos, attempt kicking actor" << endl;
      if(eng->player->getPropHandler()->allowAttackMelee(true)) {
        trace << "Bash: Player is allowed to do melee attack" << endl;
        bool blockers[MAP_X_CELLS][MAP_Y_CELLS];
        MapParser::parse(CellPredBlocksVision(eng), blockers);

        if(eng->player->checkIfSeeActor(*actor, blockers)) {
          trace << "Bash: Player can see actor" << endl;
          eng->player->kick(*actor);
          return;
        }
      }
    }
  }
}

void Bash::playerBashFeature(Feature* const feature) const {
  bool bashableObjectFound = false;

  if(feature->getId() == feature_door) {
    Door* const door = dynamic_cast<Door*>(feature);
    door->tryBash(eng->player);
    bashableObjectFound = true;
  }

  if(bashableObjectFound == false) {
    const bool PLAYER_IS_BLIND = eng->player->getPropHandler()->allowSee();
    if(PLAYER_IS_BLIND == false) {
      eng->log->addMsg("I see nothing there to bash.");
    } else {
      eng->log->addMsg("I find nothing there to bash.");
    }
  }
}
