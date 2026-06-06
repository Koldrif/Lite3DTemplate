// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/MLPlayerController.h"

#include "EnhancedInputSubsystems.h"


void AMLPlayerController::SetupInputComponent()
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
