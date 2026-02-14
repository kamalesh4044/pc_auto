#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "OWGameState.generated.h"

UCLASS()
class OPENWORLDMP_API AOWGameState : public AGameStateBase
{
    GENERATED_BODY()

public:
    AOWGameState();

    UFUNCTION(BlueprintPure, Category = "Story")
    int32 GetMainStoryStage() const { return MainStoryStage; }

    void SetMainStoryStage(int32 NewStage);

protected:
    UPROPERTY(ReplicatedUsing = OnRep_MainStoryStage, BlueprintReadOnly, Category = "Story")
    int32 MainStoryStage = 0;

    UFUNCTION()
    void OnRep_MainStoryStage();

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
