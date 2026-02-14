#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "OWPlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UOWQuestComponent;

UCLASS()
class OPENWORLDMP_API AOWPlayerCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AOWPlayerCharacter();

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
    virtual void BeginPlay() override;

    void MoveForward(float Value);
    void MoveRight(float Value);
    void LookUp(float Value);
    void Turn(float Value);

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    TObjectPtr<USpringArmComponent> SpringArm;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    TObjectPtr<UCameraComponent> FollowCamera;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Quests")
    TObjectPtr<UOWQuestComponent> QuestComponent;
};
