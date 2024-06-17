// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable.h"
#include "Engine/TriggerSphere.h"

// Sets default values for this component's properties
UInteractable::UInteractable()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteractable::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInteractable::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInteractable::Interact()
{
	if(IsSingleUse)
	{
		if(HasInteracted)
		{
			return;
		}
		else
		{
			HasInteracted = true;
			TriggerSphere->SetActorEnableCollision(false);
		}
	}

	
	if(OnInteractDelegate.IsBound())
	{
		OnInteractDelegate.Broadcast();
	}

	UE_LOG(LogTemp, Display, TEXT("Interacted with %s"), *GetOwner()->GetName());
}
