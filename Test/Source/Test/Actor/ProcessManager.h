// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enum/EObject.h"
#include "Enum/EAction.h"
#include "ProcessManager.generated.h"

UCLASS()
class TEST_API AProcessManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProcessManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	void MoveAction(float DeltaTime);
	void RotAction(float DeltaTime);

public :

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Find"))
	class ABaseActor* SelectActor;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "What Object"))
	EObject ObejctType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "What Action"))
	EAction ObejctActionType;



	//MOVE
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = MOVE,  meta = (AllowPrivateAccess = "true"))
	FVector MoveDir;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = MOVE, meta = (AllowPrivateAccess = "true"))
	float MoveSpeed;

	//Rot
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ROT, meta = (AllowPrivateAccess = "true"))
	FRotator RotDir;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ROT, meta = (AllowPrivateAccess = "true"))
	float RotSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ROT, meta = (AllowPrivateAccess = "true"))
	bool bWorldRot;
};
