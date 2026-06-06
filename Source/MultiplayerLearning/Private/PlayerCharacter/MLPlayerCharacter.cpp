// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter/MLPlayerCharacter.h"

#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AMLPlayerCharacter::AMLPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMeshComponent->SetupAttachment(RootComponent);
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->bUsePawnControlRotation = true;
	// SpringArmComponent->bInheritPitch = false;
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);
	CameraComponent->bUsePawnControlRotation = false;
	
	SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
}

// Called when the game starts or when spawned
void AMLPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMLPlayerCharacter::HandleMove2D(const FInputActionValue& Value)
{
	auto inputValue = Value.Get<FVector2D>();
	
	FRotator controllerRotation = GetControlRotation();
	const FRotator YawRotation {0, controllerRotation.Yaw, 0};
	
	const FVector forwardVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector rightVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	if (inputValue.X != 0.f)
	{
		AddMovementInput(rightVector, inputValue.X);
	}
	
	if (inputValue.Y != 0.f)
	{
		AddMovementInput(forwardVector, inputValue.Y);
	}
}

void AMLPlayerCharacter::HandleLook2D(const FInputActionValue& Value)
{
	auto lookValue = Value.Get<FVector2D>();
	AddControllerPitchInput(lookValue.Y);
	AddControllerYawInput(lookValue.X);
}

// Called every frame
void AMLPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMLPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (auto playerController = GetLocalViewingPlayerController())
	{
		playerController->PlayerCameraManager->ViewPitchMin = -80.f;
		playerController->PlayerCameraManager->ViewPitchMax = 80.f;
	}
	
	if (auto inputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		inputComponent->BindAction(IA_Move2D, ETriggerEvent::Triggered, this, &AMLPlayerCharacter::HandleMove2D);
		inputComponent->BindAction(IA_Look2D, ETriggerEvent::Triggered, this, &AMLPlayerCharacter::HandleLook2D);
	}

}

