#include "Game/OWGameMode.h"
#include "Game/OWGameState.h"

AOWGameMode::AOWGameMode()
{
    GameStateClass = AOWGameState::StaticClass();
}

void AOWGameMode::AdvanceMainStoryStage(int32 NewStage)
{
    MainStoryStage = FMath::Max(NewStage, MainStoryStage);

    if (AOWGameState* OWGameState = GetGameState<AOWGameState>())
    {
        OWGameState->SetMainStoryStage(MainStoryStage);
    }
}
