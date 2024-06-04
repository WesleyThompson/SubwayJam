// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Door.generated.h"

class USoundBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SUBWAYJAM_API UDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere)
	bool Locked = false;
	UPROPERTY(EditAnywhere)
	FVector OpenPosition;
	UPROPERTY(EditAnywhere)
	FVector ClosedPosition;
	UPROPERTY(EditAnywhere)
	float MoveSpeed;
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor();
	void CloseDoor();

private:
	UPROPERTY(EditAnywhere)
	USoundBase* OpenSound;
	UPROPERTY(EditAnywhere)
	USoundBase* CloseSound;
	
	FVector CurrentPosition;
	
};
