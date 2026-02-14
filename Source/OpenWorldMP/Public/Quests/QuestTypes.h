#pragma once

#include "CoreMinimal.h"
#include "QuestTypes.generated.h"

UENUM(BlueprintType)
enum class EQuestStatus : uint8
{
    Locked,
    Active,
    Completed,
    Failed
};

USTRUCT(BlueprintType)
struct FQuestState
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName QuestId = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EQuestStatus Status = EQuestStatus::Locked;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 CurrentStep = 0;
};
