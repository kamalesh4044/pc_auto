#include "Characters/OWPlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Quests/OWQuestComponent.h"

AOWPlayerCharacter::AOWPlayerCharacter()
{
    bReplicates = true;

    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 350.0f;
    SpringArm->bUsePawnControlRotation = true;

    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;

    QuestComponent = CreateDefaultSubobject<UOWQuestComponent>(TEXT("QuestComponent"));

    GetCharacterMovement()->MaxWalkSpeed = 550.0f;
    bUseControllerRotationYaw = false;
    GetCharacterMovement()->bOrientRotationToMovement = true;
}

void AOWPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AOWPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &AOWPlayerCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &AOWPlayerCharacter::MoveRight);
    PlayerInputComponent->BindAxis("LookUp", this, &AOWPlayerCharacter::LookUp);
    PlayerInputComponent->BindAxis("Turn", this, &AOWPlayerCharacter::Turn);
}

void AOWPlayerCharacter::MoveForward(float Value)
{
    if (Controller && Value != 0.0f)
    {
        AddMovementInput(GetActorForwardVector(), Value);
    }
}

void AOWPlayerCharacter::MoveRight(float Value)
{
    if (Controller && Value != 0.0f)
    {
        AddMovementInput(GetActorRightVector(), Value);
    }
}

void AOWPlayerCharacter::LookUp(float Value)
{
    AddControllerPitchInput(Value);
}

void AOWPlayerCharacter::Turn(float Value)
{
    AddControllerYawInput(Value);
}
