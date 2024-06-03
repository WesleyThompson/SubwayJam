// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Door.generated.h"


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
	bool Open = false;
	UPROPERTY(EditAnywhere)
	bool Locked = true;
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
	FVector CurrentPosition;
	
};
