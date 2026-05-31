// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ThirdPersonLitePlayerController.generated.h"

class UInputMappingContext;
/**
 * 
 */
UCLASS()
class LITE3DTEMPLATE_API AThirdPersonLitePlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> DefaultInputMappingContext;
	
	virtual void SetupInputComponent() override;	
	
};
