// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/MainGameMode.h"

#include "Actor/ProcessManager.h"
#include "Kismet/GameplayStatics.h"

void AMainGameMode::BeginPlay()
{

	//AActor* Actor = UGameplayStatics::GetActorOfClass(GetWorld(), AProcessManager::StaticClass());
	//AProcessManager* Manger = (AProcessManager*)Actor;
	//Manger->SelectActor = FindActor(Manger->ObejctType);

}

ABaseActor* AMainGameMode::FindActor(EObject ObjectType)
{
	TArray<AActor*> Finds;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABaseActor::StaticClass(), Finds);

	for (auto Actor : Finds)
	{
		ABaseActor* BaseActor = (ABaseActor*)Actor;

		if (BaseActor->ObjectType == ObjectType)
			return BaseActor;
	}

	return nullptr;
}


