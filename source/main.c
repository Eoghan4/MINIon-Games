#include <PA9.h>
#include <dirent.h>
#include <filesystem.h>
#include <unistd.h>
#include "dsgm_gfx.h"
#include "GameWorks.h"


int main (void) {
  RoomCount = 4;
  score = 0;
  lives = 3;
  health = 100;
  CurrentRoom = Room_Get_Index("titlescreen");
  swiWaitForVBlank();
  PA_InitFifo();
  PA_Init();
  DSGM_Init_PAlib();
  Reset_Alarms();
  nitroFSInit();
  chdir("nitro:/");
  titlescreen();
  return 0;
}
bool titlescreen(void) {
  PA_ResetSpriteSys();
  PA_ResetBgSys();
  PA_LoadBackground(1, 2, &titletop);
  PA_LoadBackground(0, 2, &titlebottom);
  PA_LoadSpritePal(1, 0, (void*)DSGMPal0_Pal); PA_LoadSpritePal(0, 0, (void*)DSGMPal0_Pal);
  DSGM_Setup_Room(256, 192, 256, 192, 0, 0, 0, 0);
  PA_LoadText(1, 0, &Default); PA_LoadText(0, 0, &Default);
  Create_Object(titlescreenController, 0, false, 80, 72);
  DSGM_Complete_Room();
  while(true) {
    for (DSGMPL = 0; DSGMPL <= 127; DSGMPL++) {
      if (Instances[DSGMPL].InUse) {
        if (Instances[DSGMPL].EName == titlescreenController) titlescreenControllerStep_Event(DSGMPL);
        if (Instances[DSGMPL].EName == minionSort) minionSortStep_Event(DSGMPL);
        if (Instances[DSGMPL].EName == SortMinionScoreDisplay) SortMinionScoreDisplayStep_Event(DSGMPL);
        if (Instances[DSGMPL].EName == purpleMinionSort) purpleMinionSortStep_Event(DSGMPL);
      }
    }
    for (DSGMPL = 0; DSGMPL <= 127; DSGMPL++) {
      if (Instances[DSGMPL].InUse) {
        if (Instances[DSGMPL].EName == gameSelectSort && Stylus.Newpress && PA_SpriteTouched(DSGMPL)) gameSelectSortTouchNewPress_Event(DSGMPL);
        if (Instances[DSGMPL].EName == minionSort && Stylus.Held && PA_SpriteTouched(DSGMPL)) minionSortTouchHeld_Event(DSGMPL);
        if (Instances[DSGMPL].EName == purpleMinionSort && Stylus.Held && PA_SpriteTouched(DSGMPL)) purpleMinionSortTouchHeld_Event(DSGMPL);
      }
    }
    Frames += 1;
    RoomFrames += 1;
    if (Frames % 60 == 0) Seconds += 1;
    if (Frames % 60 == 0) RoomSeconds += 1;
    DSGM_ObjectsSync();
    DSGM_AlarmsSync();
    PA_WaitForVBL();
    PA_EasyBgScrollXY(1, 2, RoomData.TopX, RoomData.TopY);
    PA_EasyBgScrollXY(0, 2, RoomData.BottomX, RoomData.BottomY);
  }
  return true;
}
bool gameselectscreen(void) {
  PA_ResetSpriteSys();
  PA_ResetBgSys();
  PA_LoadBackground(1, 2, &selectgametop);
  PA_LoadBackground(0, 2, &select_game_bottom);
  PA_LoadSpritePal(1, 0, (void*)DSGMPal0_Pal); PA_LoadSpritePal(0, 0, (void*)DSGMPal0_Pal);
  DSGM_Setup_Room(256, 192, 256, 192, 0, 0, 0, 0);
  PA_LoadText(1, 0, &Default); PA_LoadText(0, 0, &Default);
  Create_Object(gameSelectSort, 0, false, 16, 24);
  DSGM_Complete_Room();
  while(true) {
    for (DSGMPL = 0; DSGMPL <= 127; DSGMPL++) {
      if (Instances[DSGMPL].InUse) {
        if (Instances[DSGMPL].EName == titlescreenController) titlescreenControllerStep_Event(DSGMPL);
        if (Instances[DSGMPL].EName == minionSort) minionSortStep_Event(DSGMPL);
        if (Instances[DSGMPL].EName == SortMinionScoreDisplay) SortMinionScoreDisplayStep_Event(DSGMPL);
        if (Instances[DSGMPL].EName == purpleMinionSort) purpleMinionSortStep_Event(DSGMPL);
      }
    }
    for (DSGMPL = 0; DSGMPL <= 127; DSGMPL++) {
      if (Instances[DSGMPL].InUse) {
        if (Instances[DSGMPL].EName == gameSelectSort && Stylus.Newpress && PA_SpriteTouched(DSGMPL)) gameSelectSortTouchNewPress_Event(DSGMPL);
        if (Instances[DSGMPL].EName == minionSort && Stylus.Held && PA_SpriteTouched(DSGMPL)) minionSortTouchHeld_Event(DSGMPL);
        if (Instances[DSGMPL].EName == purpleMinionSort && Stylus.Held && PA_SpriteTouched(DSGMPL)) purpleMinionSortTouchHeld_Event(DSGMPL);
      }
    }
    Frames += 1;
    RoomFrames += 1;
    if (Frames % 60 == 0) Seconds += 1;
    if (Frames % 60 == 0) RoomSeconds += 1;
    DSGM_ObjectsSync();
    DSGM_AlarmsSync();
    PA_WaitForVBL();
    PA_EasyBgScrollXY(1, 2, RoomData.TopX, RoomData.TopY);
    PA_EasyBgScrollXY(0, 2, RoomData.BottomX, RoomData.BottomY);
  }
  return true;
}
bool sortGame(void) {
  PA_ResetSpriteSys();
  PA_ResetBgSys();
  PA_LoadBackground(1, 2, &sort_top);
  PA_LoadBackground(0, 2, &sort_bottom);
  PA_LoadSpritePal(1, 0, (void*)DSGMPal0_Pal); PA_LoadSpritePal(0, 0, (void*)DSGMPal0_Pal);
  DSGM_Setup_Room(256, 192, 256, 192, 0, 0, 0, 0);
  PA_LoadText(1, 0, &Default); PA_LoadText(0, 0, &Default);
  Create_Object(SortMinionScoreDisplay, 0, true, 112, 112);
  Create_Object(minionSort, 1, false, 32, 32);
  Create_Object(minionSort, 2, false, 16, 120);
  Create_Object(minionSort, 3, false, 80, 112);
  Create_Object(purpleMinionSort, 4, false, 112, 48);
  Create_Object(purpleMinionSort, 5, false, 160, 24);
  Create_Object(purpleMinionSort, 6, false, 160, 104);
  DSGM_Complete_Room();
  while(true) {
    for (DSGMPL = 0; DSGMPL <= 127; DSGMPL++) {
      if (Instances[DSGMPL].InUse) {
        if (Instances[DSGMPL].EName == titlescreenController) titlescreenControllerStep_Event(DSGMPL);
        if (Instances[DSGMPL].EName == minionSort) minionSortStep_Event(DSGMPL);
        if (Instances[DSGMPL].EName == SortMinionScoreDisplay) SortMinionScoreDisplayStep_Event(DSGMPL);
        if (Instances[DSGMPL].EName == purpleMinionSort) purpleMinionSortStep_Event(DSGMPL);
      }
    }
    for (DSGMPL = 0; DSGMPL <= 127; DSGMPL++) {
      if (Instances[DSGMPL].InUse) {
        if (Instances[DSGMPL].EName == gameSelectSort && Stylus.Newpress && PA_SpriteTouched(DSGMPL)) gameSelectSortTouchNewPress_Event(DSGMPL);
        if (Instances[DSGMPL].EName == minionSort && Stylus.Held && PA_SpriteTouched(DSGMPL)) minionSortTouchHeld_Event(DSGMPL);
        if (Instances[DSGMPL].EName == purpleMinionSort && Stylus.Held && PA_SpriteTouched(DSGMPL)) purpleMinionSortTouchHeld_Event(DSGMPL);
      }
    }
    Frames += 1;
    RoomFrames += 1;
    if (Frames % 60 == 0) Seconds += 1;
    if (Frames % 60 == 0) RoomSeconds += 1;
    DSGM_ObjectsSync();
    DSGM_AlarmsSync();
    PA_WaitForVBL();
    PA_EasyBgScrollXY(1, 2, RoomData.TopX, RoomData.TopY);
    PA_EasyBgScrollXY(0, 2, RoomData.BottomX, RoomData.BottomY);
  }
  return true;
}
bool sortGameOver(void) {
  PA_ResetSpriteSys();
  PA_ResetBgSys();
  PA_LoadBackground(1, 2, &sort_top_game_over);
  PA_LoadBackground(0, 2, &sort_bottom_game_over);
  PA_LoadSpritePal(1, 0, (void*)DSGMPal0_Pal); PA_LoadSpritePal(0, 0, (void*)DSGMPal0_Pal);
  DSGM_Setup_Room(256, 192, 256, 192, 0, 0, 0, 0);
  PA_LoadText(1, 0, &Default); PA_LoadText(0, 0, &Default);
  Create_Object(titlescreenController, 0, false, 128, 80);
  Create_Object(SortGameOverScoreDisplayOnes, 1, true, 224, 96);
  Create_Object(SortGameOverScoreDisplay10s, 2, true, 192, 88);
  DSGM_Complete_Room();
  while(true) {
    for (DSGMPL = 0; DSGMPL <= 127; DSGMPL++) {
      if (Instances[DSGMPL].InUse) {
        if (Instances[DSGMPL].EName == titlescreenController) titlescreenControllerStep_Event(DSGMPL);
        if (Instances[DSGMPL].EName == minionSort) minionSortStep_Event(DSGMPL);
        if (Instances[DSGMPL].EName == SortMinionScoreDisplay) SortMinionScoreDisplayStep_Event(DSGMPL);
        if (Instances[DSGMPL].EName == purpleMinionSort) purpleMinionSortStep_Event(DSGMPL);
      }
    }
    for (DSGMPL = 0; DSGMPL <= 127; DSGMPL++) {
      if (Instances[DSGMPL].InUse) {
        if (Instances[DSGMPL].EName == gameSelectSort && Stylus.Newpress && PA_SpriteTouched(DSGMPL)) gameSelectSortTouchNewPress_Event(DSGMPL);
        if (Instances[DSGMPL].EName == minionSort && Stylus.Held && PA_SpriteTouched(DSGMPL)) minionSortTouchHeld_Event(DSGMPL);
        if (Instances[DSGMPL].EName == purpleMinionSort && Stylus.Held && PA_SpriteTouched(DSGMPL)) purpleMinionSortTouchHeld_Event(DSGMPL);
      }
    }
    Frames += 1;
    RoomFrames += 1;
    if (Frames % 60 == 0) Seconds += 1;
    if (Frames % 60 == 0) RoomSeconds += 1;
    DSGM_ObjectsSync();
    DSGM_AlarmsSync();
    PA_WaitForVBL();
    PA_EasyBgScrollXY(1, 2, RoomData.TopX, RoomData.TopY);
    PA_EasyBgScrollXY(0, 2, RoomData.BottomX, RoomData.BottomY);
  }
  return true;
}
