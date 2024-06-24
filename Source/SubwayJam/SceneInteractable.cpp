// Fill out your copyright notice in the Description page of Project Settings.


#include "SceneInteractable.h"

#include "Components/SphereComponent.h"

// Sets default values for this component's properties
USceneInteractable::USceneInteractable()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	TriggerSphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("TriggerSphere"));
}


// Called when the game starts
void USceneInteractable::BeginPlay()
{
	Super::BeginPlay();

	TriggerSphereComp->SetupAttachment(GetOwner()->GetRootComponent());
}


// Called every frame
void USceneInteractable::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USceneInteractable::Interact()
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
			if(TriggerSphereComp != nullptr)
			{
				TriggerSphereComp->SetGenerateOverlapEvents(false);
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
