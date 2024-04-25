// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/ProcessManager.h"
#include "Actor/BaseActor.h"

// Sets default values
AProcessManager::AProcessManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProcessManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProcessManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!SelectActor)
	{
		return;
	}

	switch (ObejctActionType)
	{
	case EAction::NONE:
		break;
	case EAction::MOVE:
	{
		MoveAction(DeltaTime);
		break;
	}
	case EAction::ROT: 
	{
		RotAction(DeltaTime);
		break;
	}
	case EAction::SPAWN:
		break;
	default:
		break;
	}


}

void AProcessManager::MoveAction(float DeltaTime)
{
	FVector ActorLocation = SelectActor->GetActorLocation();

	ActorLocation += (MoveDir * (MoveSpeed * DeltaTime));

	SelectActor->SetActorLocation(ActorLocation, false);

}

void AProcessManager::RotAction(float DeltaTime)
{
	if (bWorldRot)
	{
		SelectActor->AddActorWorldRotation(RotDir * (RotSpeed * DeltaTime));

	}
	else
	{
		SelectActor->AddActorLocalRotation(RotDir * (RotSpeed * DeltaTime));

	}

	
}

