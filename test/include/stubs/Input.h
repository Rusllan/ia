#ifndef INPUT_H
#define INPUT_H

#include "SDL/SDL.h"

#include "CommonData.h"

class Engine;

struct KeyboardReadReturnData {
public:
  KeyboardReadReturnData() {}

  KeyboardReadReturnData(char, SDLKey, bool, bool) {}

  KeyboardReadReturnData(char) {}

  KeyboardReadReturnData(SDLKey) {}

  char key_;
  SDLKey sdlKey_;
  bool isShiftHeld_, isCtrlHeld_;
};

class Input {
public:
  Input(Engine*, bool*) {}

  void handleMapModeInputUntilFound() {}

  KeyboardReadReturnData readKeysUntilFound() {return KeyboardReadReturnData();}

  void clearEvents() {}

  void setKeyRepeatDelays() {}

private:
  friend class Bot;
  void handleKeyPress(const KeyboardReadReturnData&) {}
  void clearLogMessages() {}
//  SDL_Event event_;
//  int* dungeonLevel_;
//  Engine* eng;
//  bool* quitToMainMenu_;
};

#endif