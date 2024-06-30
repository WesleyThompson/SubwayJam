// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Door.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SUBWAYJAM_API UDoor : public UInteractable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* DoorMesh;
	// Sets default values for this component's properties
	UDoor();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
	float CloseDelay;
	

public:
	UPROPERTY(EditAnywhere)
	bool AutoClose = false;
	UPROPERTY(EditAnywhere)
	bool Locked = false;
	UPROPERTY(EditAnywhere)
	FVector OpenOffset;
	UPROPERTY(EditAnywhere)
	float MoveTime;
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION()
	void OpenDoor();
	UFUNCTION()
	void CloseDoor();

private:
	void DoorStateCheck();
	
	UPROPERTY(EditAnywhere)
	FString OpenSoundEventName;
	UPROPERTY(EditAnywhere)
	FString CloseSoundEventName;

	FVector OpenLocation;
	FVector StartLocation;
	//Location where the door should move to.
	FVector TargetLocation;
	//Controls whether the door will be moving towards it's TargetLocation.
	bool ShouldMove = false;
	bool isOpen = false;
	float MoveSpeed;
	FTimerHandle CloseTimerHandle;
};
