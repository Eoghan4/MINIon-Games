#include "dsgm_gfx.h"
#include "custom_gfx.h"
#include "Defines.h"
#include "ActionWorks.h"



int SortMinionScore = 0;
int SortPurpleScore = 0;
int SortFinalScore = 0;
int SortHighScore = 0;


enum ObjectEnums { titlescreenController = 1, gameSelectSort = 2, minionSort = 3, SortMinionScoreDisplay = 4, purpleMinionSort = 5, SortGameOverScoreDisplayOnes = 6, SortGameOverScoreDisplay10s = 7,  };
void Set_Sprite(u8 InstanceID, char *SpriteName, bool DeleteOld);
void Create_Object(u8 ObjectEnum, u8 InstanceID, bool Screen, s16 X, s16 Y);
u8 Sprite_Get_ID(char *SpriteName);
u8 Room_Get_Index(char *RoomName);
void Goto_Room_Backend(u8 RoomIndex);
u8 Count_Instances(u8 ObjectEnum);
void Goto_Next_Room(void);

void SortMinionScoreDisplayStep_Event(u8 DAppliesTo) {
  PA_OutputText(1, 8, 10, "     ");
  PA_OutputText(1, 8, 10, "%d", SortMinionScore);
  PA_OutputText(1, 24, 10, "     ");
  PA_OutputText(1, 24, 10, "%d", SortPurpleScore);
}
void SortMinionScoreDisplayCreate_Event(u8 DAppliesTo) {
  PA_LoadText(1, 0, &ComicSans);
}
void SortGameOverScoreDisplayOnesCreate_Event(u8 DAppliesTo) {
  u16 AppliesTo0 = DAppliesTo;
  Set_XY(AppliesTo0, 220, 85);
  u16 AppliesTo1 = DAppliesTo;
  Set_Frame(AppliesTo1, SortFinalScore%10);
}
void SortGameOverScoreDisplay10sCreate_Event(u8 DAppliesTo) {
  u16 AppliesTo0 = DAppliesTo;
  Set_XY(AppliesTo0, -100, -100);
  if (SortFinalScore >= 10) {
    u16 AppliesTo3 = DAppliesTo;
    Set_XY(AppliesTo3, 200, 85);
    u16 AppliesTo4 = DAppliesTo;
    Set_Frame(AppliesTo4, (SortFinalScore-(SortFinalScore%10))/10);
  }
}
void gameSelectSortTouchNewPress_Event(u8 DAppliesTo) {
  CurrentRoom = Room_Get_Index("sortGame");
  RoomFrames = 0;
  RoomSeconds = 0;
  sortGame();
}
void titlescreenControllerStep_Event(u8 DAppliesTo) {
  if (Stylus.Newpress) {
    CurrentRoom = Room_Get_Index("gameselectscreen");
    RoomFrames = 0;
    RoomSeconds = 0;
    gameselectscreen();
  }
}
void minionSortTouchHeld_Event(u8 DAppliesTo) {
  u16 AppliesTo0 = DAppliesTo;
  Set_XY(AppliesTo0, (Stylus.X)-40, (Stylus.Y)-20);
  u16 AppliesTo1 = DAppliesTo;
  if (Instances[AppliesTo1].X < 7) {
    SortMinionScore = SortMinionScore+1;
    PA_LoadBackground(1, 2, &sort_top_yellow);
    u16 AppliesTo5 = DAppliesTo;
    Set_XY(AppliesTo5, 100, -100);
  }
  u16 AppliesTo7 = DAppliesTo;
  if (Instances[AppliesTo7].X > 200) {
    PA_LoadBackground(1, 2, &sort_top_oops);
    SortPurpleScore = 0;
    SortFinalScore = SortMinionScore;
    u16 AppliesTo12 = 0;
    for (AppliesTo12 = 0; AppliesTo12 < 256; AppliesTo12++) {
      if (Instances[AppliesTo12].InUse && Instances[AppliesTo12].EName == purpleMinionSort) {
        Delete_Instance(AppliesTo12);
      }
    }
    u16 AppliesTo13 = 0;
    for (AppliesTo13 = 0; AppliesTo13 < 256; AppliesTo13++) {
      if (Instances[AppliesTo13].InUse && Instances[AppliesTo13].EName == minionSort) {
        Delete_Instance(AppliesTo13);
      }
    }
    for (DSGML = 0; DSGML <= (2 * 60); DSGML++) {
    PA_WaitForVBL();
    }
    CurrentRoom = Room_Get_Index("sortGameOver");
    RoomFrames = 0;
    RoomSeconds = 0;
    sortGameOver();
  }
}
void minionSortStep_Event(u8 DAppliesTo) {
  int randomInt = 0;
  randomInt = Random(0,180);
  if (randomInt == 1) {
    PA_LoadBackground(1, 2, &sort_top);
    u16 AppliesTo5 = DAppliesTo;
    if (Instances[AppliesTo5].Y <= -90) {
      u16 AppliesTo7 = DAppliesTo;
      Set_XY(AppliesTo7, Random(70,150), Random(10,50));
    }
  }
}
void minionSortCreate_Event(u8 DAppliesTo) {
  u16 AppliesTo0 = DAppliesTo;
  //PA_StartSpriteAnim(Instances[AppliesTo0].Screen, AppliesTo0, 0, 1, 3);
  Animate(AppliesTo0, 0, 1, 3);
  u16 AppliesTo1 = DAppliesTo;
  Set_XY(AppliesTo1, 100, -100);
  u16 AppliesTo2 = DAppliesTo;
  Enable_Rotation(AppliesTo2);
}
void purpleMinionSortTouchHeld_Event(u8 DAppliesTo) {
  u16 AppliesTo0 = DAppliesTo;
  Set_XY(AppliesTo0, (Stylus.X)-20, (Stylus.Y)-30);
  u16 AppliesTo1 = DAppliesTo;
  if (Instances[AppliesTo1].X > 200) {
    SortPurpleScore = SortPurpleScore+1;
    PA_LoadBackground(1, 2, &sort_top_purple);
    u16 AppliesTo5 = DAppliesTo;
    Set_XY(AppliesTo5, 100, -100);
  }
  u16 AppliesTo7 = DAppliesTo;
  if (Instances[AppliesTo7].X < 7) {
    PA_LoadBackground(1, 2, &sort_top_oops);
    SortMinionScore = 0;
    SortFinalScore = SortPurpleScore;
    u16 AppliesTo12 = 0;
    for (AppliesTo12 = 0; AppliesTo12 < 256; AppliesTo12++) {
      if (Instances[AppliesTo12].InUse && Instances[AppliesTo12].EName == minionSort) {
        Delete_Instance(AppliesTo12);
      }
    }
    u16 AppliesTo13 = 0;
    for (AppliesTo13 = 0; AppliesTo13 < 256; AppliesTo13++) {
      if (Instances[AppliesTo13].InUse && Instances[AppliesTo13].EName == purpleMinionSort) {
        Delete_Instance(AppliesTo13);
      }
    }
    for (DSGML = 0; DSGML <= (2 * 60); DSGML++) {
    PA_WaitForVBL();
    }
    CurrentRoom = Room_Get_Index("sortGameOver");
    RoomFrames = 0;
    RoomSeconds = 0;
    sortGameOver();
  }
}
void purpleMinionSortStep_Event(u8 DAppliesTo) {
  int randomInt = 0;
  randomInt = Random(0,180);
  if (randomInt == 1) {
    PA_LoadBackground(1, 2, &sort_top);
    u16 AppliesTo5 = DAppliesTo;
    if (Instances[AppliesTo5].Y <= -90) {
      u16 AppliesTo7 = DAppliesTo;
      Set_XY(AppliesTo7, Random(70,150), Random(10,50));
    }
  }
}
void purpleMinionSortCreate_Event(u8 DAppliesTo) {
  u16 AppliesTo0 = DAppliesTo;
  //PA_StartSpriteAnim(Instances[AppliesTo0].Screen, AppliesTo0, 0, 1, 3);
  Animate(AppliesTo0, 0, 1, 3);
  u16 AppliesTo1 = DAppliesTo;
  Set_XY(AppliesTo1, 100, -100);
}


int Script_1(void) {
  return 0;
}

void Set_Sprite(u8 InstanceID, char *SpriteName, bool DeleteOld) {
  Instances[InstanceID].HasSprite = true;
  if (DeleteOld) PA_DeleteSprite(Instances[InstanceID].Screen, InstanceID);
  switch(Sprite_Get_ID(SpriteName)) {
    case 0:
      Instances[InstanceID].Width = 64; Instances[InstanceID].Height = 64;
      PA_CreateSprite(Instances[InstanceID].Screen, InstanceID, (void*)SortSelect_Sprite, OBJ_SIZE_64X64, 1, 0, 256, 192);
      break;
    case 1:
      Instances[InstanceID].Width = 64; Instances[InstanceID].Height = 64;
      PA_CreateSprite(Instances[InstanceID].Screen, InstanceID, (void*)minion_Sprite, OBJ_SIZE_64X64, 1, 0, 256, 192);
      break;
    case 2:
      Instances[InstanceID].Width = 64; Instances[InstanceID].Height = 64;
      PA_CreateSprite(Instances[InstanceID].Screen, InstanceID, (void*)purpleMinion_Sprite, OBJ_SIZE_64X64, 1, 0, 256, 192);
      break;
    case 3:
      Instances[InstanceID].Width = 32; Instances[InstanceID].Height = 32;
      PA_CreateSprite(Instances[InstanceID].Screen, InstanceID, (void*)Numbers_Sprite, OBJ_SIZE_32X32, 1, 0, 256, 192);
      break;
  }
}

void Create_Object(u8 ObjectEnum, u8 InstanceID, bool Screen, s16 X, s16 Y) {
  Instances[InstanceID].EName = ObjectEnum;  Instances[InstanceID].InUse = true; Instances[InstanceID].Screen = Screen;
  Instances[InstanceID].OriginalX = X; Instances[InstanceID].OriginalY = Y;
  Instances[InstanceID].X = X; Instances[InstanceID].Y = Y;
  Instances[InstanceID].VX = 0; Instances[InstanceID].VY = 0;
  if (ObjectEnum == titlescreenController) {
     Instances[InstanceID].HasSprite = false;
  } else if (ObjectEnum == gameSelectSort) {
     Instances[InstanceID].HasSprite = true;
     Set_Sprite(InstanceID, "SortSelect", false);
  } else if (ObjectEnum == minionSort) {
     Instances[InstanceID].HasSprite = true;
     Set_Sprite(InstanceID, "minion", false);
     minionSortCreate_Event(InstanceID);
  } else if (ObjectEnum == SortMinionScoreDisplay) {
     Instances[InstanceID].HasSprite = false;
     SortMinionScoreDisplayCreate_Event(InstanceID);
  } else if (ObjectEnum == purpleMinionSort) {
     Instances[InstanceID].HasSprite = true;
     Set_Sprite(InstanceID, "purpleMinion", false);
     purpleMinionSortCreate_Event(InstanceID);
  } else if (ObjectEnum == SortGameOverScoreDisplayOnes) {
     Instances[InstanceID].HasSprite = true;
     Set_Sprite(InstanceID, "Numbers", false);
     SortGameOverScoreDisplayOnesCreate_Event(InstanceID);
  } else if (ObjectEnum == SortGameOverScoreDisplay10s) {
     Instances[InstanceID].HasSprite = true;
     Set_Sprite(InstanceID, "Numbers", false);
     SortGameOverScoreDisplay10sCreate_Event(InstanceID);
  }

}
u8 Sprite_Get_ID(char *SpriteName) {
 if (strcmp(SpriteName, "SortSelect") == 0) return 0;
 if (strcmp(SpriteName, "minion") == 0) return 1;
 if (strcmp(SpriteName, "purpleMinion") == 0) return 2;
 if (strcmp(SpriteName, "Numbers") == 0) return 3;
 return 0;
}

u8 Room_Get_Index(char *RoomName) {
 if (strcmp(RoomName, "titlescreen") == 0) return 0;
 if (strcmp(RoomName, "gameselectscreen") == 0) return 1;
 if (strcmp(RoomName, "sortGame") == 0) return 2;
 if (strcmp(RoomName, "sortGameOver") == 0) return 3;
 return 0;
}

void Goto_Room_Backend(u8 RoomIndex) {
  RoomFrames = 0;
  RoomSeconds = 0;
  if (RoomIndex == 0) titlescreen();
  if (RoomIndex == 1) gameselectscreen();
  if (RoomIndex == 2) sortGame();
  if (RoomIndex == 3) sortGameOver();
}

void Goto_Next_Room(void) {
 if (CurrentRoom < RoomCount) {
  CurrentRoom += 1;
  Goto_Room_Backend(CurrentRoom);
 }
}

