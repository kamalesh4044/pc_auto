#include "Game/OWGameState.h"
#include "Net/UnrealNetwork.h"

AOWGameState::AOWGameState()
{
    bReplicates = true;
}

void AOWGameState::SetMainStoryStage(int32 NewStage)
{
    MainStoryStage = NewStage;
    OnRep_MainStoryStage();
}

void AOWGameState::OnRep_MainStoryStage()
{
    UE_LOG(LogTemp, Log, TEXT("Main story stage updated to: %d"), MainStoryStage);
}

void AOWGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(AOWGameState, MainStoryStage);
}
