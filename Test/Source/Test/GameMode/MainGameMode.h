// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Enum/EObject.h"
#include "Actor/BaseActor.h"
#include "MainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TEST_API AMainGameMode : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
	
protected:

	ABaseActor* FindActor(EObject ObjectType);

};
