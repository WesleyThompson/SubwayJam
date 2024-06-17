// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interactable.generated.h"


class ATriggerSphere;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteractSignature);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SUBWAYJAM_API UInteractable : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInteractable();

protected:
	UPROPERTY(EditAnywhere)
	ATriggerSphere* TriggerSphere;

	UPROPERTY(EditAnywhere)
	bool IsSingleUse;
	
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintAssignable)
	FOnInteractSignature OnInteractDelegate;

	void Interact();
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	bool HasInteracted = false;	
		
};
