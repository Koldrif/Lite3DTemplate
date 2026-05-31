// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPersonLitePlayerCharacter.h"

// Sets default values
AThirdPersonLitePlayerCharacter::AThirdPersonLitePlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AThirdPersonLitePlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AThirdPersonLitePlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AThirdPersonLitePlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

