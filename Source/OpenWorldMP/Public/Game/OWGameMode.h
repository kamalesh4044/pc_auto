#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "OWGameMode.generated.h"

UCLASS()
class OPENWORLDMP_API AOWGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    AOWGameMode();

    UFUNCTION(BlueprintCallable, Category = "Story")
    void AdvanceMainStoryStage(int32 NewStage);

protected:
    UPROPERTY(BlueprintReadOnly, Category = "Story")
    int32 MainStoryStage = 0;
};
