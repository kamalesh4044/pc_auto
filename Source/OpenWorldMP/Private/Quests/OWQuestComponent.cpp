#include "Quests/OWQuestComponent.h"
#include "Net/UnrealNetwork.h"

UOWQuestComponent::UOWQuestComponent()
{
    SetIsReplicatedByDefault(true);
}

void UOWQuestComponent::ActivateQuest(FName QuestId)
{
    FQuestState* ExistingQuest = QuestStates.FindByPredicate([QuestId](const FQuestState& State)
    {
        return State.QuestId == QuestId;
    });

    if (ExistingQuest)
    {
        ExistingQuest->Status = EQuestStatus::Active;
        ExistingQuest->CurrentStep = 0;
        OnQuestUpdated.Broadcast(*ExistingQuest);
        return;
    }

    FQuestState NewQuest;
    NewQuest.QuestId = QuestId;
    NewQuest.Status = EQuestStatus::Active;
    QuestStates.Add(NewQuest);
    OnQuestUpdated.Broadcast(NewQuest);
}

void UOWQuestComponent::CompleteQuestStep(FName QuestId)
{
    FQuestState* Quest = QuestStates.FindByPredicate([QuestId](const FQuestState& State)
    {
        return State.QuestId == QuestId;
    });

    if (!Quest || Quest->Status != EQuestStatus::Active)
    {
        return;
    }

    Quest->CurrentStep++;
    if (Quest->CurrentStep >= 3)
    {
        Quest->Status = EQuestStatus::Completed;
    }

    OnQuestUpdated.Broadcast(*Quest);
}

bool UOWQuestComponent::GetQuestState(FName QuestId, FQuestState& OutState) const
{
    if (const FQuestState* Quest = QuestStates.FindByPredicate([QuestId](const FQuestState& State)
    {
        return State.QuestId == QuestId;
    }))
    {
        OutState = *Quest;
        return true;
    }

    return false;
}

void UOWQuestComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(UOWQuestComponent, QuestStates);
}
