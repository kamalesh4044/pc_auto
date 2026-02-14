#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "QuestTypes.h"
#include "OWQuestComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestUpdated, const FQuestState&, QuestState);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class OPENWORLDMP_API UOWQuestComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UOWQuestComponent();

    UFUNCTION(BlueprintCallable, Category = "Quests")
    void ActivateQuest(FName QuestId);

    UFUNCTION(BlueprintCallable, Category = "Quests")
    void CompleteQuestStep(FName QuestId);

    UFUNCTION(BlueprintPure, Category = "Quests")
    bool GetQuestState(FName QuestId, FQuestState& OutState) const;

    UPROPERTY(BlueprintAssignable, Category = "Quests")
    FOnQuestUpdated OnQuestUpdated;

protected:
    UPROPERTY(Replicated)
    TArray<FQuestState> QuestStates;

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
