// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPersonLitePlayerController.h"

#include "EnhancedInputSubsystems.h"


void AThirdPersonLitePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	if (auto localPlayer = GetLocalPlayer())
	{
		if (auto inputSubSystem = localPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			inputSubSystem->AddMappingContext(DefaultInputMappingContext, 0);
		}
	}
}
