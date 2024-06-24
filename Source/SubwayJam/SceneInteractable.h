// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "SceneInteractable.generated.h"


class USphereComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteractedSignature);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SUBWAYJAM_API USceneInteractable : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USceneInteractable();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	bool IsSingleUse = false;

	UPROPERTY(EditAnywhere)
	USphereComponent* TriggerSphereComp;
public:
	UPROPERTY(BlueprintAssignable)
	FOnInteractedSignature OnInteractDelegate;

	UFUNCTION(BlueprintCallable)
	void Interact();
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	bool HasInteracted = false;
};
