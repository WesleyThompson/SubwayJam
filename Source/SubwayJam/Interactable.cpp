// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable.h"
#include "Components/SphereComponent.h"

// Sets default values for this component's properties
UInteractable::UInteractable()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
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
			if(TriggerSphere != nullptr)
			{
				UE_LOG(LogTemp, Display, TEXT("Turning off overlap events on %s."), *TriggerSphere->GetName());
				TriggerSphere->SetGenerateOverlapEvents(false);
				TriggerSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Missing TriggerSphere."));
			}
		}
	}

	
	if(OnInteractDelegate.IsBound())
	{
		OnInteractDelegate.Broadcast();
	}

	UE_LOG(LogTemp, Display, TEXT("Interacted with %s"), *GetOwner()->GetName());
}
